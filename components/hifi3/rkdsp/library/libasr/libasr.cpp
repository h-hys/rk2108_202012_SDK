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

#if ENABLE_ASR

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <xtensa/tie/xt_interrupt.h>

#include "libasr.h"

#include "io.h"
#include "iomap.h"
#include "section.h"
#include "trace.h"
#include "error.h"
#include "pm.h"
#include "delay.h"
#include "timer.h"
#include "work.h"

#include "kws.h"

#if ENABLE_ASR_PROCESS
#include "xiaoduxiaodu.h"
//#include "myxiaodu1.h"
#endif

static char *ASR_pBufferForEngine = NULL;
static char *AEC_pBufferForEngine = NULL;
static void *kwsInst = NULL;
static void *aec_handle = NULL;
//static short pcm_in[160];
//static short pcm_ref[160];
static short pcm_aec[170];

static int countflag = 0;
extern "C" void xthal_dcache_region_invalidate( void *addr, unsigned size );
static int count = 0;

__sys__ int libasr_process_pre(uint32_t worker)
{
    int ret;

    struct work *work = (struct work *)worker;
    struct wake_work_param *work_param = (struct wake_work_param *)(work->param);
    if (work_param->buf == 0 || work_param->buf_size == 0)
        return 2;
    xthal_dcache_region_invalidate(( void *)work_param->buf, work_param->buf_size);
    ret = libasr_process(work_param->buf, work_param->buf_size, NULL);
    work_param->result = ret;
//    if (*((uint32_t *)0x3024fffc) == 0x55555555) {
//        memcpy((void *)0x30240000, (void *)work_param->buf, work_param->buf_size);
//        count += work_param->buf_size;
//        if (count >= 0x40000);
//            LOGD("full\n");
//    }
    return ret;
}

__sys__ static int kwssetpara()
{
#if 0 //nihaoxiaozhi
    uint16_t shift_frames=5; // 1 (0~10) 3
    uint16_t smooth_frames=6;// 30 (0~30) 6
    uint16_t lock_frames=1;// 60 (0~100) 60
    uint16_t post_max_frames=13;// 100 (0~100) 100
    float threshold=0.38;// 0.60f (0.0f~1.0f) 0.4
#else // xiaoduxiaodu    uint16_t shift_frames=3; // 1 (0~10) 3
    uint16_t smooth_frames=8; // 30 (0~30) 6
    uint16_t lock_frames=1; // 60 (0~100) 60
    uint16_t post_max_frames=13; // 100 (0~100) 100
    float threshold=0.3; // 0.60f (0.0f~1.0f) 0.4
#endif

    if (KWS_CODE_NORMAL
            != kwsSetConfig(kwsInst, kws_shiftFrames, &shift_frames)) {
        return EFAULT;
    }

    if (KWS_CODE_NORMAL
            != kwsSetConfig(kwsInst, kws_smoothFrames, &smooth_frames)) {
        return EFAULT;
    }

    if (KWS_CODE_NORMAL
            != kwsSetConfig(kwsInst, kws_lockFrames, &lock_frames)) {
        return EFAULT;
    }

    if (KWS_CODE_NORMAL
            != kwsSetConfig(kwsInst, kws_postMaxFrames, &post_max_frames)) {
        return EFAULT;
    }

    if (KWS_CODE_NORMAL != kwsSetConfig(kwsInst, kws_threshold, &threshold)) {
        return EFAULT;
    }

    LOGD("kwsSetConfig ok\n");
    return SUCCESS;
}

enum wakeup_val libasr_process(uint32_t input_data, uint32_t input_size, uint32_t param)
{
    int kws_res;
    unsigned short kws_index;
    wakeup_val ret = ALGO_WAKEUP_NONE;

    //UVoiceAec_Process(aec_handle, (const short*)(&asr_input_frame[sample_num]), (const short*)(&asr_input_frame[sample_num*3/2]), pcm_aec, 160);
    kws_index = 0;
    kws_res = kwsProcess(kwsInst, (const short *)(input_data), input_size / 2,
            &kws_index);
    if (kws_res != 0) {
        LOGD("kwsProcess abnormal ,now reset kws_res:%d\n", kws_res);
        kwsReset(kwsInst);
        ret = ALGO_WAKEUP_ERROR;
    }
    //LOGD("kws_index:%d\n", kws_index);
    if (1 == kws_index) {
        if (countflag%5 == 0)
            LOGD("xiaodu_wakeup--------xiaoduxiaodu-------\n");
        ret = ALGO_WAKEUP_SUCCESS;
        countflag++;
    }

    return ret; //wakeup 1; normal 0; reset 2
}

__sys__ int libasr_init(uint32_t param)
{
#if 1
    // LOGD("before kwscreate\n");
    kwsCreate(&kwsInst);

    if (NULL == kwsInst) {
        LOGD("Error to create kwsInst.\n");
        return ENOMEM;
    }
    // LOGD("after kwscreate\n");
    if (KWS_CODE_NORMAL != kwsInit(kwsInst)) {
        LOGD("Error to init kwsInst.\n");
        return EFAULT;
    }

    // LOGD("kws init ok\n");
    if (0 != kwssetpara()) {
        LOGD("kwsSetConfig err \n");
        return EFAULT;
    }

#endif
    LOGD("init uv_asr ok \n");
    return SUCCESS;
}

int libasr_deinit(uint32_t param)
{
    kwsDesrtoy(&kwsInst);
}

#if ENABLE_ASR_PROCESS
void libasr_process_test(uint32_t idle)
{
    uint32_t clock_start, clock_end;
    uint32_t cost_time;

    short *data = (short *)&xiaoduxiaodu;
    int size = sizeof(xiaoduxiaodu) / 2;

    for (int i = 0; i < size; i+=160)
    {
        clock_start = timer_get_tick();
        libasr_process(uint32_t(data + i), 320, NULL);
        clock_end = timer_get_tick();
        if (idle >= 100)
            continue;
        cost_time = (clock_end - clock_start);
        cost_time = cost_time * idle / (100 - idle);
        if (cost_time) {
            sys_timer_init();
            sys_timer_start(cost_time, TIMER_ONESHOT, NULL, 0);
            pm_sleep(SLEEP_NOR);
        }
    }

#if 0
    LOGD("sleep now\n")
    pm_pwrdown_config();
    pm_sleep(SLEEP_NOR);
#endif
}
#endif

#endif // ENABLE_ASR
