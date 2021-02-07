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

#ifndef __IO_H__
#define __IO_H__

#include <stdint.h>
#include <stdlib.h>
#include "iomap.h"

#define MASK_WRITE(a)            (((a) << 16) | (a))
#define MASK_TO_WE(mask)         ((mask) << 16)
#define VAL_MASK_WE(mask, val)   ((MASK_TO_WE(mask)) | (val))

#ifdef __cplusplus
extern "C" {
#endif

inline uint32_t __readl(const volatile void *addr)
{
    return *((volatile uint32_t *)addr);
}

inline void __writel(volatile void *addr, volatile uint32_t val)
{
    *((volatile uint32_t *)addr) = val;
}

inline void *dma_malloc(uint32_t size)
{
    return memalign(CACHE_LINE_SIZE, size);
}

#ifdef __cplusplus
}
#endif

/* These interfaces are used to read/write registers by I/O base address */
#define TCM_ADDR_TO_CM4(addr) ((addr) - 0xfc00000)
#define TCM_ADDR_TO_DSP(addr) ((addr) + 0xfc00000)
#define SET_BIT(REG, BIT)    ((*(volatile uint32_t *)&(REG)) |= (BIT))
#define CLEAR_BIT(REG, MASK) ((*(volatile uint32_t *)&(REG)) &= ~(MASK))
#define READ_BIT(REG, MASK)  ((*(volatile uint32_t *)&(REG)) & (MASK))
#define CLEAR_REG(REG)       ((*(volatile uint32_t *)&(REG)) = (0x0))
#define WRITE_REG(REG, VAL)  ((*(volatile uint32_t *)&(REG)) = (VAL))
#define READ_REG(REG)        ((*(volatile uint32_t *)&(REG)))
#define MODIFY_REG(REG, CLEARMASK, SETMASK) \
        WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

#define readl(b)  __readl((volatile void *)(b))
#define writel(b, v) __writel((volatile void *)(b), v)
#define writel_mask(b, m, v)  __writel((volatile void *)(b), (VAL_MASK_WE(m, v)))
#endif
