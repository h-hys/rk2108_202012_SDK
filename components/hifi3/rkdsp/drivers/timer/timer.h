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

#ifndef __TIMER_H__
#define __TIMER_H__

#include <stdint.h>

typedef int (*timeout_handler_t)(void *params);

enum timer_direction {
    TIMER_COUNT_UP,
    TIMER_COUNT_DOWN
};

enum timer_mode {
    TIMER_PERIODIC,
    TIMER_ONESHOT
};

struct timer {
    uint64_t microsecond;
    enum timer_mode mode;
    timeout_handler_t handler;
    void *params;
    void *owner;
};

#ifndef __cplusplus
extern "C" {
#endif

void sys_timer_clr_status();
int sys_timer_init(void);
int sys_timer_deinit(void);
int sys_timer_start(uint64_t microsecond, enum timer_mode mode,
                timeout_handler_t handler, void *params);
int sys_timer_stop();

int timer_init(void);
int timer_deinit(void);
int timer_start(uint64_t microsecond, enum timer_mode mode,
                timeout_handler_t handler, void *params);
int timer_stop();
uint32_t timer_get_tick();

#ifndef __cplusplus
}
#endif

#endif
