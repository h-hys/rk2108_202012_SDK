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

#ifndef __CACHE_H__
#define __CACHE_H__

#include <xtensa/hal.h>

#include "section.h"
#include "typedef.h"

#define CACHE_ALIGN __attribute__((aligned(XCHAL_DCACHE_LINESIZE)));

__sys__ __inline__ int32_t cache_enable()
{
    return xthal_set_cache_prefetch(XTHAL_PREFETCH_BLOCKS(128) |   /* 16K */
                                    XTHAL_DCACHE_PREFETCH_MEDIUM |
                                    XTHAL_ICACHE_PREFETCH_MEDIUM |
                                    XTHAL_DCACHE_PREFETCH_L1);
}

__sys__ __inline__ int32_t cache_disable()
{
    return xthal_set_cache_prefetch(XTHAL_PREFETCH_DISABLE);
}

#endif // __CACHE_H__
