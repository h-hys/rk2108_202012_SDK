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
#include "wakeup.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xtensa/tie/xt_interrupt.h>

#include "cache.h"
#include "intc.h"
#include "io.h"
#include "iomap.h"
#include "pm.h"
#include "section.h"
#include "trace.h"
#include "vad.h"
#include "delay.h"


#define PARAMS_SIZE          (0x400)               /* 1K */
#define PARAMS_ADDR          (0x30200000)          /* reserve 1k in mmp */

#define DTCM_ADDR_END        (DTCM_BASE + DTCM_SIZE)
#define RINGBUF_ADDR(size)   (DTCM_ADDR_END - size)

struct store_params *g_store_params = (struct store_params *)PARAMS_ADDR;
struct wakeup_algo_param *g_algo_param;
char *g_vad_buf = NULL;
short *g_tmp_buf = NULL;

void wakeup_vad_callback(uint32_t params);

__sys__ int wakeup_init(uint32_t in_params)
{
    int ret = 0;

    g_vad_buf = (char *)malloc(g_store_params->period_size);
    if (!g_vad_buf) {
        LOGD("Malloc vad buf fail, size = %d\n", g_algo_param->voice_len);
        return -1;
    }

    if (g_algo_param->channel == 1) {
        g_tmp_buf = (short *)malloc(g_algo_param->voice_len / 2);
        if (!g_tmp_buf) {
            LOGD("Malloc tmp buf fail, size = %d\n", g_algo_param->voice_len / 2);
            return -1;
        }
    }

    if (g_algo_param->algo_init)
        ret = g_algo_param->algo_init(in_params);

    vad_set_period(g_algo_param->voice_len);
    vad_init(wakeup_vad_callback);

    return ret;
}

__sys__ int wakeup_deinit()
{
    if (g_vad_buf) {
        free(g_vad_buf);
        g_vad_buf = NULL;
    }

    if (g_tmp_buf) {
        free(g_tmp_buf);
        g_tmp_buf = NULL;
    }
}

__sys__ int rk_wakeup_config(uint32_t in_params, struct wakeup_algo_param *algo_param)
{
    int ret = 0;
    g_algo_param = algo_param;
    struct wake_config_params *params = (struct wake_config_params *)in_params;
    params->ringbuf_addr = RINGBUF_ADDR(params->ringbuf_size);
    params->mcu_hw_ptr = (uint32_t)(&g_store_params->mcu_hw_ptr);
    params->dsp_hw_ptr = (uint32_t)(&g_store_params->dsp_hw_ptr);
    params->period_size = g_algo_param->voice_len;
    params->advan_size = g_algo_param->advan_len;
    vad_set_space_sel(params->ringbuf_size);

    memcpy(g_store_params, params, sizeof(struct wake_config_params));
//    LOGD("wake_word = %s, advan_size = 0x%08x, period_size = 0x%08x\n"
//          "ringbuf_size = 0x%08x, ringbuf_addr=0x%08x, muc_hwprt=0x%08x, dsp_hw=0x%08x\n",
//          g_store_params->wake_word, g_store_params->advan_size,
//          g_store_params->period_size, g_store_params->ringbuf_size,
//          g_store_params->ringbuf_addr, g_store_params->mcu_hw_ptr,
//          g_store_params->dsp_hw_ptr);
    g_store_params->mcu_hw_ptr = 0;
    g_store_params->dsp_hw_ptr = 0;
    g_store_params->wakeup_status = WAKEUP_CONFIGED;
    xthal_dcache_region_writeback((void *)g_store_params, PARAMS_SIZE);

    ret = wakeup_init(in_params);
    return ret;
}

/* Wait data, enter interupt wait VAD_TRANS_INT interrupt */
__sys__ int wakeup_wait_data()
{
//    idle_compute_enter();
    pm_sleep(SLEEP_NOR); /* Wait data */
//    idle_compute_exit();
}

__sys__ int audio_buf_manager(struct store_params *params,
              enum wakeup_val (*algo_func)(uint32_t, uint32_t, uint32_t))
{
    int ret = 0;
    int tmp, total;
    uint32_t advan_size = params->advan_size;
    uint32_t period_size = params->period_size;
    uint32_t ringbuf_size = params->ringbuf_size;
    uint32_t cur_hw_ptr = params->dsp_hw_ptr;
    uint32_t algo_start_addr, algo_end_addr;
    uint32_t vad_start_addr, vad_end_addr, vad_cur_addr;

    vad_get_addr(&vad_start_addr, &vad_end_addr, &vad_cur_addr);
    /* Get begin algorithm address */
    algo_start_addr = vad_cur_addr - advan_size;
    algo_start_addr = ALIGN(algo_start_addr - period_size, period_size);
    if (algo_start_addr < vad_start_addr)
        algo_start_addr = (vad_end_addr - (vad_start_addr - algo_start_addr));
    algo_end_addr = algo_start_addr + period_size;

    params->dsp_hw_ptr = algo_start_addr - vad_start_addr;
    params->mcu_hw_ptr = vad_cur_addr - vad_start_addr;
    while (1) {
        vad_get_cur_addr(&vad_cur_addr);
        if (algo_end_addr > vad_end_addr) {
            tmp = vad_end_addr - algo_start_addr;
            /* In the vad buf end || in the vad buf begin */
            while ((vad_cur_addr > algo_start_addr) ||
                   (vad_cur_addr < vad_start_addr + period_size - tmp)) {
                cur_hw_ptr = params->mcu_hw_ptr;
                wakeup_wait_data();
                vad_get_cur_addr(&vad_cur_addr);
                if (cur_hw_ptr + period_size <= params->mcu_hw_ptr)
                    break;
            }
            memcpy((void *)g_vad_buf, (void *)algo_start_addr, tmp);
            memcpy((void *)(g_vad_buf + tmp), (void *)vad_start_addr,
                    period_size - tmp);
            ret = algo_func((uint32_t)g_vad_buf, period_size, total);
            algo_start_addr = vad_start_addr + period_size - tmp;
        } else {
            while (algo_start_addr + period_size > vad_cur_addr) {
                cur_hw_ptr = params->mcu_hw_ptr;
                wakeup_wait_data();
                vad_get_cur_addr(&vad_cur_addr);
                if (cur_hw_ptr + period_size <= params->mcu_hw_ptr)
                    break;
            }
            ret = algo_func(algo_start_addr, period_size, total);
            /* Just in the vad buf end */
            if (algo_end_addr == vad_end_addr)
                algo_start_addr = vad_start_addr;
            else
                algo_start_addr = algo_end_addr;
        }
        algo_end_addr = algo_start_addr + period_size;
        total += period_size;
        params->dsp_hw_ptr += period_size;
        /* A full ringbuf size */
        if (total > ringbuf_size)
            total = 0;
        if (ret)
            break;
    }
    return ret;
}

__sys__ void wakeup_vad_callback(uint32_t params)
{
    uint32_t int_status;

    vad_swich_mode(BUS_INTFC);
    int_status = readl(VAD_BASE + VAD_INT);
    if (int_status & DET_INT_BIT &&
        g_store_params->wakeup_status < WAKEUP_WORKING) {
        g_store_params->wakeup_status = WAKEUP_WORKING;
        /* Detect int alway enter, need to close it, remain transfer int */
        vad_int_enable(DET_INT, false);
    }
    if (int_status & DATA_TRANS_INT_BIT) {
        g_store_params->mcu_hw_ptr += g_store_params->period_size;
        if (g_store_params->mcu_hw_ptr < g_store_params->period_size)
            g_store_params->mcu_hw_ptr = 0;
    }
}

__sys__ void get_single_channel_buf(uint32_t *in_buf, short *out_buf, uint32_t len)
{
    int i;
    for(i = 0; i < len; i += 1)
    {
        out_buf[i] = (short)in_buf[i];
    }
}

#define TEST_SHAREMEMORY_ADDR   0x30240000
__sys__ enum wakeup_val wakeup_algo_process(uint32_t buf_addr, uint32_t buf_size,
        uint32_t count)
{
    uint32_t voice_len;
    uint32_t voice_buf;

    enum wakeup_val ret = ALGO_WAKEUP_NONE;

//    LOGD("buf_addr=0x%08x, buf_size=0x%08x count = 0x%08x hw_ptr = 0x%08x, head = 0x%08x\n",
//         buf_addr, buf_size, count + buf_size, g_store_params->dsp_hw_ptr, *((uint32_t * )buf_addr));

    if (g_algo_param->channel == 1) {
        voice_len = g_algo_param->voice_len / 2;
        get_single_channel_buf((uint32_t *)buf_addr, g_tmp_buf, voice_len / 2);
        voice_buf = (uint32_t)g_tmp_buf;
    } else {
        voice_len = g_algo_param->voice_len;
        voice_buf = buf_addr;
    }

//    static int all_count = 0;
//    memcpy((void *)(TEST_SHAREMEMORY_ADDR + all_count), (void *)voice_buf, buf_size / 2);
//    all_count += buf_size / 2;
//    if (all_count > 128 * 1024)
//        LOGD("full \n");

    if (g_algo_param->algo_process)
        ret = g_algo_param->algo_process(voice_buf, voice_len, (uint32_t)g_store_params);
    if (ret)
        LOGD("process return value = %d\n", ret);
    return ret;
}

__sys__ int wakeup_algo(uint32_t params)
{
    int ret;
    g_store_params->work = params;
    ret = audio_buf_manager(g_store_params, &wakeup_algo_process);
    return ret;
}

__sys__ int rk_wakeup_start(uint32_t work)
{
    int ret;

    g_store_params->wakeup_status = WAKEUP_STARTED;
    vad_start();
    while (1) {
        pm_sleep(SLEEP_NOR);
        if (g_store_params->wakeup_status < WAKEUP_WORKING)
            continue;
        ret = wakeup_algo(work);
        break;
    }

    vad_stop();
    g_store_params->wakeup_status = WAKEUP_CONFIGED;
    g_store_params->dsp_hw_ptr = 0;
    return ret;
}
