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

#ifndef INCLUDE_SYSTEM_WORK_WORK_H_
#define INCLUDE_SYSTEM_WORK_WORK_H_

#include <stdint.h>

#define MAX_IMAGE 16

/* DSP error codes which will be returned in result */
#define DSP_WORK_SUCCESS   0x00000000
#define DSP_WORK_EABANDON  0x80000001
#define DSP_WORK_ECOPY     0x80000002
#define DSP_WORK_ETIMEOUT  0x80000003

/*
 * DSP algorithm types. User application should set type
 * in the type member of struct dsp_render_work
 */
#define DSP_ALGORITHM_COPY                           0x00000001
#define DSP_ALGORITHM_WAKE_CONFIG                    0x40000001
#define DSP_ALGORITHM_WAKE_START                     0x40000002

#define DSP_AUTH_WAIT_FLAG                           0x5A5A5A5A
#define DSP_AUTH_RESP_FLAG                           0xA5A5A5A5

enum work_type {
    ALGORITHM_WORK = 0,
    CONFIG_WORK    = 1,
#ifdef ENABLE_AUDIO_CODEC
    CODEC_WORK     = 2,
#endif
};

enum work_status {
    DSP_WORK_PENDING = 0,
    DSP_WORK_RUNNING,
    DSP_WORK_DONE,
};

struct config_params {
    uint32_t type;
    uint32_t trace_buffer;
    uint32_t trace_buffer_size;
    uint32_t trace_slot_size;
    uint32_t heap;
    uint32_t heap_size;
    int32_t  uart;
    uint32_t reserve[5];
};

struct work {
    uint32_t id;
    uint32_t algo_type;
    uint32_t param;
    uint32_t param_size;
    uint32_t result;
    enum work_type work_type;
    uint32_t rate;
    uint32_t cycles;
};

struct dsp_auth
{
    uint32_t flag;
    uint32_t key;
    uint32_t len;
    uint32_t result;
};

extern int worker_run(void);
extern void work_cache_writeback(struct work *work);
extern void work_set_pwrdown();

#endif /* INCLUDE_SYSTEM_WORK_WORK_H_ */
