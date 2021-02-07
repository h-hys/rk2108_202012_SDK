/*
 * Copyright (c) 2019 Rockchip Electronics Co. Ltd.
 * Author: Huaping Liao <huaping.liao@rock-chips.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "work.h"

#include <asm-dsp.h>
#include <time.h>
#include <xtensa/tie/xt_interrupt.h>

#include "cache.h"
#include "delay.h"
#include "error.h"
#include "intc.h"
#include "loader.h"
#include "mailbox.h"
#include "pm.h"
#include "section.h"
#include "typedef.h"
#include "trace.h"

struct worker {
    int pwr_down;
    struct work *work;
    struct mbox_client mbox;
};

static __sys_data__ struct worker g_worker;

extern int algo_handler(struct worker *worker, struct work *work);
#ifdef ENABLE_AUDIO_CODEC
extern int codec_handler(struct worker *worker, struct work *work);
#endif

__sys__ void work_set_pwrdown()
{
    g_worker.pwr_down = 1;
}

__sys__ void work_cache_writeback(struct work *work)
{
    xthal_dcache_region_writeback((void *)work, sizeof(struct work));
    if (work->param_size && work->param)
        xthal_dcache_region_writeback((void *)work->param,
                                          work->param_size);
}

__sys__ void work_cache_invalidate(struct work *work)
{
    xthal_dcache_region_invalidate((void *)work, sizeof(struct work));
    if (work->param_size && work->param)
        xthal_dcache_region_invalidate((void *)work->param,
                                          work->param_size);
}

static __sys__ int worker_receive_data(struct mbox_client *client,
                                       uint32_t cmd, uint32_t data)
{
    struct work *work = (struct work *)data;
    if (cmd != DSP_CMD_WORK)
        return -EINVALID;

    if (g_worker.work != NULL) {
        LOGE("Worker busy!\n");
        return -EFAULT;
    }
    work_cache_invalidate(work);
    g_worker.work = work;
    return SUCCESS;
}

__sys__ int worker_run(void)
//#pragma func_flags="-O0 -Os0"
{
    g_worker.pwr_down = 0;
    g_worker.work = NULL;
    g_worker.mbox.id = MBOX_ID;
    g_worker.mbox.chan = MBOX_CHAN_0;
    g_worker.mbox.receive_data = worker_receive_data;
    mbox_register_client((struct mbox_client *)&g_worker.mbox);

#if CONFIG_SOC_RK2108
    /* Clear power state machine */
    pm_pwrdown_enable(false);
#endif
    while (1) {
        clock_t clock_start = 0, clock_end = 0;
        int ret = 0;

        /* Nothing to do, enter standby mode */
        pm_sleep(SLEEP_NOR);

#if CONFIG_SOC_RK2108
        /* Enter power down */
        if (g_worker.pwr_down) {
            g_worker.pwr_down = 0;
            pm_sleep(SLEEP_SYS);
        }
#endif
        if (g_worker.work == NULL)
            continue;

        clock_start = clock();
        switch (g_worker.work->work_type) {
        case ALGORITHM_WORK:
            ret = algo_handler((struct worker *)&g_worker, g_worker.work);
            break;
#ifdef ENABLE_AUDIO_CODEC
        case CODEC_WORK:
            ret = codec_handler((struct worker *)&g_worker, g_worker.work);
            break;
#endif
        }
        clock_end = clock();

        /* Inform host work has been done */
        g_worker.work->cycles = clock_end - clock_start;
        g_worker.work->result = ret;
        g_worker.work->rate = DSP_FREQ * MHZ;
        work_cache_writeback(g_worker.work);
        mbox_send_data(MBOX_ID, g_worker.mbox.chan, DSP_CMD_WORK_DONE,
                (uint32_t)g_worker.work);
        g_worker.work = NULL;
    }

    return SUCCESS;
}
