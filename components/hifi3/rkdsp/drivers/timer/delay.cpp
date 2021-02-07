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

#include "delay.h"

#include <time.h>

#include "section.h"
#include "typedef.h"
#include "trace.h"

__sys__ void delay_cycles(uint32_t cycles)
{
	volatile uint32_t tick = clock();

	while ((clock() - tick) <= cycles);
}

__sys__ void udelay(uint32_t microseconds)
{
	/* TODO: Suppose the frequency of DSP is DSP_FREQ. */
	delay_cycles(DSP_FREQ * microseconds);
}

__sys__ void mdelay(uint32_t milliseconds)
{
	/* TODO: Suppose the frequency of DSP is DSP_FREQ. */
	for(uint32_t i = 0; i < milliseconds; i++)
		udelay(1000);
}

uint32_t idle_cycle_cnt = 0;
uint32_t idle_cycle_last = 0;
uint32_t work_cycle_cnt = 0;
uint32_t work_cycle_last = 0;
int init_flag = 0;
__sys__ void idle_compute_enter()
{
    if (!init_flag)
    {
        idle_cycle_last = clock();
        work_cycle_last = idle_cycle_last;
        init_flag = 1;
    }
    idle_cycle_last = clock();
    work_cycle_cnt += idle_cycle_last - work_cycle_last;

}

__sys__ void idle_compute_exit()
{
    work_cycle_last = clock();
    idle_cycle_cnt += work_cycle_last - idle_cycle_last;
    init_flag++;
    if (init_flag % 10 == 0)
        LOGD("cnt idle = %x, work = %x\n", idle_cycle_cnt, work_cycle_cnt);
}
