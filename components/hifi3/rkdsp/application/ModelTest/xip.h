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

#ifndef __VAD_H__
#define __VAD_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void snor_write_byte(volatile void *addr, uint32_t value);
uint32_t snor_read_byte(void *addr);
void sram_write_byte(volatile void *addr, uint32_t value);
uint32_t sram_read_byte(void *addr);
void xip_test();

#ifdef __cplusplus
}
#endif

#endif
