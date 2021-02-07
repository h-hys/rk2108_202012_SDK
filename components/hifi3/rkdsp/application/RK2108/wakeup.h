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

#ifndef __WAKEUP_H__
#define __WAKEUP_H__
#include <stdint.h>

#define WAKE_WORD_LEN    32

enum WAKEUP_STAUTS {
	WAKEUP_NONE,
	WAKEUP_CONFIGED,
	WAKEUP_STARTED,
	WAKEUP_WORKING,
};

struct wake_config_params {
    uint32_t advan_size;
    uint32_t period_size;
    uint32_t ringbuf_size;
    uint32_t ringbuf_addr;
    uint32_t mcu_hw_ptr;
    uint32_t dsp_hw_ptr;
    uint32_t result;
    uint32_t reserved[0];
};

struct store_params {
    uint32_t advan_size;
    uint32_t period_size;
    uint32_t ringbuf_size;
    uint32_t ringbuf_addr;
    uint32_t mcu_hw_ptr;
    uint32_t dsp_hw_ptr;
#if AP_DBG
    uint32_t ap_hw_ptr;
#endif
    uint32_t status;
    enum WAKEUP_STAUTS wakeup_status;
    uint32_t work;
};

enum wakeup_val {
    ALGO_WAKEUP_NONE,
    ALGO_WAKEUP_SUCCESS,
    ALGO_WAKEUP_ERROR,
};

struct wakeup_algo_param {
    int voice_len;
    int advan_len;
    int channel;
    int (*algo_init)(uint32_t param);
    enum wakeup_val (*algo_process)(uint32_t voice_data, uint32_t voice_len, uint32_t param);
    int (*algo_deinit)(uint32_t param);
    void *data;
};

#ifdef __cplusplus
extern "C" {
#endif

extern int rk_wakeup_config(uint32_t params, struct wakeup_algo_param *param);
extern int rk_wakeup_start(uint32_t work);

#ifdef __cplusplus
}
#endif

#endif
