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

#ifndef _TRACE_H_
#define _TRACE_H_

#include <stdint.h>
#include "mailbox.h"

#define DEBUG_UART 1
#define DEBUG_HOST 0

#define DEBUG_ERR   0
#define DEBUG_INFO  1
#define DEBUG_DBG   2

#define DEBUG_LEVEL DEBUG_DBG

#ifdef __cplusplus
extern "C" {
#endif
void print_to_host(const char *format, ...);
void print_to_uart(const char *format, ...);
int trace_init(enum mbox_id mbox_id, char *buffer, uint32_t buffer_size,
                   uint32_t slot_size);
void rk_assert_handler(const char *ex_string,
                       const char *func, uint32_t line);
void trace_disable(void);
#ifdef __cplusplus
}
#endif

#if (DEBUG_LEVEL >= DEBUG_ERR)
#define LOGE(str, ...) print_to_host("HiFi3[E]: "str, ##__VA_ARGS__)
#else
#define LOGE(str, ...)
#endif

#if (DEBUG_LEVEL >= DEBUG_INFO)
#define LOGI(str, ...) print_to_uart("HiFi3[I]: "str, ##__VA_ARGS__)
#else
#define LOGI(str, ...)
#endif

#if (DEBUG_LEVEL >= DEBUG_DBG)
#define LOGD(str, ...) print_to_uart("HiFi3[D]: "str, ##__VA_ARGS__);
#else
#define LOGD
#endif

#define RK_ASSERT(value)                                \
if (!(value))                                           \
{                                                       \
    rk_assert_handler(#value, __FUNCTION__, __LINE__);  \
}

#endif
