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

#ifndef __DMA_H__
#define __DMA_H__

#include <stdint.h>
#include "hal_dma.h"

#ifdef __cplusplus
extern "C" {
#endif

int dma_memcpy_start(void *chan, uint32_t dst, uint32_t src, uint32_t len, uint32_t *flag);
void *dma_request();
int dma_release(void *chan);
int dma_init();
int dma_deinit();

#ifdef __cplusplus
}
#endif

#endif // __DMA_H__
