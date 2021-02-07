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
#include "section.h"
#include "test.h"
#include "xip.h"
#include "io.h"

__sys__ int main(void)
{
#if !CONFIG_ENABLE_XIP
    model_test();
#else
//    writel(0x40210000, 0x00000003);
//    writel(0x40210054, 0x00004003);
//    writel(0x4021005c , 0x00000001);
    xip_test();
#endif
}
