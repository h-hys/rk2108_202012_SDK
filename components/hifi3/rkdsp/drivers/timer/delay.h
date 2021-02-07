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

#ifndef _DELAY_H_
#define _DELAY_H_

#include <stdint.h>

#if CONFIG_SOC_RK2108
#define DSP_FREQ  (400) /* Mhz */
#else
#define DSP_FREQ  (164)
#endif

#define MHZ (1000 * 1000)

extern void delay_cycles(uint32_t cycles);
extern void udelay(uint32_t microseconds);
extern void mdelay(uint32_t milliseconds);
extern void idle_compute_enter();
extern void idle_compute_exit();

#endif
