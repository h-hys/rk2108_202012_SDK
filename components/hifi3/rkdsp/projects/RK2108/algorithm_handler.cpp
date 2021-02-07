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

#include <time.h>

#include "error.h"
#include "section.h"
#include "typedef.h"
#include "loader.h"
#include "work.h"

#include "key_verify.h"
#include "wakeup.h"
#include "trace.h"
#include "intc.h"

#define DSP_VAD_WAKE_CONFIG                    0x40000001
#define DSP_VAD_WAKE_START                     0x40000002

#define DSP_ALGO_ASR_CONFIG                    0x40000003
#define DSP_ALGO_ASR_PROCESS                   0x40000004

#define DSP_ALGO_AEC_CONFIG                    0x40000003
#define DSP_ALGO_AEC_PROCESS                   0x40000004

#define DSP_ALGO_AEC_ASR_PROCESS               0x40000007

#define DSP_ALGO_KEY_VERIFY                    0x40000008

#if ENABLE_ASR
#include "libasr.h"
struct wakeup_algo_param algo_param = {
     640, 0, 1, libasr_init, libasr_process, libasr_deinit, NULL
};

#elif ENABLE_KWS
#include "libkws.h"
struct wakeup_algo_param algo_param = {
     49152, 0, 1, libkws_init, libkws_process, libkws_deinit, NULL
};

#elif ENABLE_SPEECH
#include "libspeech.h"
struct wakeup_algo_param algo_param = {
        640, 0, 1, libspeech_init, libspeech_process, libspeech_deinit, NULL
};
#elif ENABLE_SPEECH_AEC
#include "libspeech_aec.h"
struct wakeup_algo_param algo_param = {
        640, 0, 1, libspeech_aec_init, libspeech_aec_process, libspeech_aec_deinit, NULL
};
#elif ENABLE_HSASR
#include "libhsasr.h"
struct wakeup_algo_param algo_param = {
        960, 0, 1, libhsasr_init, libhsasr_process, libhsasr_deinit, NULL
};
#else
struct wakeup_algo_param algo_param;
#endif

#if ENABLE_SPEECH_BF
#include "libspeech_bf.h"
#elif ENABLE_LITE_WAKEUP
#include "liblwakeup_aec.h"
#endif

#if ENABLE_RKVOICE
#include "librkvoice.h"
#endif

__sys__ int algo_handler(struct worker *worker, struct work *work)
{
    int ret = 0;
    uint64_t clock_start = 0, clock_end = 0;
    struct aec_proc_param *param = (struct aec_proc_param *)work->param;
#if ENABLE_ASR_PROCESS
    LOGD("idle percent = %d\n", work->param);
    intc_init();
    asr_init(NULL);
    while(1)
        asr_process_test(work->param);
#endif
    switch (work->algo_type) {
    case DSP_VAD_WAKE_CONFIG:
        ret = rk_wakeup_config(work->param, &algo_param);
        break;
    case DSP_VAD_WAKE_START:
        ret = rk_wakeup_start((uint32_t)work);
        break;
#if ENABLE_AEC
    case DSP_ALGO_AEC_CONFIG:
        ret = aec_init(work->param);
        break;
    case DSP_ALGO_AEC_PROCESS:
        ret = aec_process(param->voice_in, param->voice_ref, param->voice_out);
        break;
#endif

    case DSP_ALGO_ASR_CONFIG:
#if ENABLE_ASR
        ret = libasr_init(work->param);
#elif ENABLE_SPEECH
        ret = libspeech_init(work->param);
#elif ENABLE_SPEECH_AEC
        ret = libspeech_aec_init(work->param);
#elif ENABLE_HSASR
        ret = libhsasr_init((uint32_t)work);
#elif ENABLE_SPEECH_BF
        ret = libsph_bf_init((uint32_t)work);
#elif ENABLE_LITE_WAKEUP
        ret = liblwakeup_aec_init(work->param);
#elif ENABLE_RKVOICE
        ret = librkvoice_init((uint32_t)work);
#endif
        break;
    case DSP_ALGO_ASR_PROCESS:
#if ENABLE_ASR
        ret = libasr_process_pre((uint32_t)work);
#elif ENABLE_SPEECH
        ret = libspeech_process_pre((uint32_t)work);
#elif ENABLE_SPEECH_AEC
        ret = libspeech_aec_process_pre((uint32_t)work);
#elif ENABLE_HSASR
        ret = libhsasr_process_pre((uint32_t)work);
#elif ENABLE_SPEECH_BF
        ret = libsph_bf_process_pre((uint32_t)work);
#elif ENABLE_LITE_WAKEUP
        ret = liblwakeup_aec_process_pre((uint32_t)work);
#elif ENABLE_RKVOICE
        ret = librkvoice_process_pre((uint32_t)work);
#endif
        break;

#if (ENABLE_ASR && ENABLE_AEC)
    case DSP_ALGO_AEC_ASR_PROCESS:
        aec_process(param->voice_in, param->voice_ref, param->voice_out);
        ret = asr_process(param->voice_out, FRAME_SIZE / 2);
        break;
#endif
    case DSP_ALGO_KEY_VERIFY:
        ret = snor_key_verify(NULL);
        break;
    default:
        break;
    }

    return ret;
}
