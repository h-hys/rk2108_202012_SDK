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

#ifndef __LIBASR_H__
#define __LIBASR_H__
#include <stdint.h>
#include "wakeup.h"

struct wake_work_param
{
    uint32_t buf;
    uint32_t buf_size;
    uint32_t result;
    uint32_t reserved;
};

#ifdef __cplusplus
extern "C" {
#endif

enum wakeup_val libasr_process(uint32_t input_data, uint32_t input_size, uint32_t param);
int libasr_process_pre(uint32_t worker);
int libasr_init(uint32_t param);
int libasr_deinit(uint32_t param);
void libasr_process_test(uint32_t idle);

#ifdef __cplusplus
}
#endif

#endif // __LIBASR_H__
