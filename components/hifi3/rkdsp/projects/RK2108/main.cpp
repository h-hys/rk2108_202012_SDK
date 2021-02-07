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

#include "cache.h"
#include "intc.h"
#include "init.h"
#include "mailbox.h"
#include "uart.h"
#include "trace.h"

#if CONFIG_VERSION_CHECK
#include "version.h"

__sys_info__ char sys_version[16] = {DSP_VERSION};
__rom_info__ const char xip_version[16] = {DSP_VERSION};
#endif

__sys__ int main(void)
{
    /* Enable golbal cache */
    cache_enable();
    //uart_init();
    intc_init();
    mbox_init(MBOX_ID);
#if CONFIG_VERSION_CHECK
    for (int i = 0; i < sizeof(sys_version); i++)
        RK_ASSERT(sys_version[i] == xip_version[i]);
#endif
    system_init();
    return 0;
}
