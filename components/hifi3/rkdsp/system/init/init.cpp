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

#include "init.h"

#include "cache.h"
#include "delay.h"
#include "error.h"
#include "intc.h"
#include "loader.h"
#include "mailbox.h"
#include "pm.h"
#include "section.h"
#include "trace.h"
#include "work.h"
#include "uart.h"

#if DSP_VENDOR_VERIFY
extern int snor_key_verify(void *key);
#endif
static __sys_data__ struct mbox_client sys_mbox;
__sys__ int system_receive_data(struct mbox_client *client, uint32_t cmd,
                                uint32_t data)
{
    struct work *work;
    struct config_params *params;
    struct dsp_auth *auth;
    switch (cmd) {
    case DSP_CMD_CONFIG:
        work = (struct work *)data;
        params = (struct config_params *)(work->param);

        /* Config uart set */
        if (params->uart >= 0)
            uart_set_port(params->uart);
        /* Config trace buffer */
        trace_init(sys_mbox.id, (char *)params->trace_buffer,
                   params->trace_buffer_size, params->trace_slot_size);
        //loader_init(params->image_count, params->image_phys);
        work->result = DSP_WORK_SUCCESS;
        work->rate = DSP_FREQ * MHZ;

        work_cache_writeback(work);
        LOGD("Hifi3 config done\n");
        mbox_send_data(sys_mbox.id, sys_mbox.chan, DSP_CMD_CONFIG_DONE, (uint32_t)work);
        break;
    case DSP_CMD_SUSPEND:
        pm_sleep(SLEEP_NOR);
        break;
    case DSP_CMD_SHUTDOWN:
        work_set_pwrdown();
        break;
    case DSP_CMD_SEND_VENDOR_KEY:
        auth = (struct dsp_auth *)data;
        xthal_dcache_region_invalidate((void *)auth, sizeof(struct dsp_auth));
        xthal_dcache_region_invalidate((void *)auth->key, auth->len);
#if DSP_VENDOR_VERIFY
        auth->result = snor_key_verify((char *)auth->key);
#endif
        auth->flag = DSP_AUTH_RESP_FLAG;
        xthal_dcache_region_writeback((void *)auth->key, auth->len);
        xthal_dcache_region_writeback((void *)auth, sizeof(struct dsp_auth));
        break;
    }
}

__init__ int system_init(void)
{
    /* Register chan 1 */
    sys_mbox.id = MBOX_ID;
    sys_mbox.chan = MBOX_CHAN_1;
    sys_mbox.receive_data = system_receive_data;
    mbox_register_client(&sys_mbox);
    /* Notify host DSP is ready to work */
    mbox_send_data(sys_mbox.id, sys_mbox.chan, DSP_CMD_READY, 0x12345678);

    /* Sleep until interrupt occurs */
    worker_run();

    return SUCCESS;
}
