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

#ifndef __WDT_H__
#define __WDT_H__

#include <stdint.h>

#if CONFIG_SOC_RK2108
#define WDT_BASE              WDT1_BASE
#define IRQ_WDT               IRQ_WDT1
#else
#define WDT_BASE              WDT2_BASE
#define IRQ_WDT               IRQ_WDT2
#endif

enum wdt_mode {
    /** Immediately reset system if WDT timeout */
    DIRECT_SYS_RESET,
    /** First generate an interrupt and if the interrupt is not cleard by the time,
      * a second timeout occur then generate a system reset
      */
    INDIRECT_SYS_RESET,
};

enum wdt_rst_type {
    GLB_RST_FST_WDT,        /* Reset all register */
    GLB_RST_SND_WDT         /* Reset section register */
};

struct wdt_dev {
    uint32_t freq;
    wdt_mode mode;
};

typedef void (*wdt_callback)(uint32_t data);

#ifdef __cplusplus
extern "C" {
#endif

void wdt_timeout_set(uint32_t millisec);
void wdt_keep_alive(void);
int wdt_init(enum wdt_mode mode, wdt_callback);
int wdt_deinit();
void wdt_start(enum wdt_rst_type type);
void wdt_stop();

#ifdef __cplusplus
}
#endif

#endif
