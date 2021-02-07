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

#include "timer.h"

#include <string.h>
#include <xtensa/core-macros.h>
#include <xtensa/hal.h>
#include <xtensa/xtruntime.h>

#include "delay.h"
#include "intc.h"
#include "iomap.h"
#include "section.h"
#include "trace.h"
#include "io.h"

#define TIMER_BASE                   TIMER0_BASE
#define TIMER_IRQ_TYPE               IRQ_TIMER
#define TIMER_CYCLE_MICSEC           (DSP_FREQ * MHZ / 1000000)
#define TIMER_CLOCK_FREQ (24L)       /* 24M */
#define TIMER_LOAD_COUNT0            0x00
#define TIMER_LOAD_COUNT1            0x04
#define TIMER_CURRENT_VALUE0         0x08
#define TIMER_CURRENT_VALUE1         0x0c
#define TIMER_CONTROL_REG            0x10
#define TIMER_INTSTATUS              0x18

#define TIMER_DISABLE                (0 << 0)
#define TIMER_ENABLE                 (1 << 0)
#define TIMER_FREE_RUNNING_MODE      (0 << 1)
#define TIMER_USER_DEFINED_MODE      (1 << 1)
#define TIMER_INT_MASK               (0 << 2)
#define TIMER_INT_UNMASK             (1 << 2)

#define TIMER_INTSTATUS              0x18

struct timer_regs {
    volatile uint32_t load_count_l;
    volatile uint32_t load_count_h;
    volatile uint32_t current_value_l;
    volatile uint32_t current_value_h;
    volatile uint32_t control_reg;
    volatile uint32_t reserved;
    volatile uint32_t intstatus;
};

struct hw_timer {
    uint32_t base;
    uint32_t feature;
    enum irq_num irq;
    struct timer *timer;
};

/* Use external sys timer to receive the function */
__sys_data__ struct timer hw_timer1;

__sys__ void sys_timer_clr_status()
{
    struct timer* hw_timer = &hw_timer1;
    int timer_id = (int)hw_timer->params;
    writel(TIMER_BASE + 0x20 * timer_id + TIMER_INTSTATUS, 0x01);
}

__sys__ int sys_timer_irq_handler(enum irq_num irq_num, void *params)
{
    struct timer* hw_timer = &hw_timer1;
    int timer_id = (int)hw_timer->params;
    writel(TIMER_BASE + 0x20 * timer_id + TIMER_INTSTATUS, 0x01);
    if (hw_timer->mode == TIMER_PERIODIC) {
        uint64_t value = TIMER_CLOCK_FREQ * hw_timer->microsecond;
        writel(TIMER_BASE + 0x20 * timer_id + TIMER_LOAD_COUNT0, value);
        writel(TIMER_BASE + 0x20 * timer_id + TIMER_LOAD_COUNT1, (value >> 32));
        writel(TIMER_BASE + 0x20 * timer_id + TIMER_CONTROL_REG, TIMER_ENABLE | TIMER_INT_UNMASK | TIMER_FREE_RUNNING_MODE);
    } else {
        writel(TIMER_BASE + 0x20 * timer_id + TIMER_CONTROL_REG, 0);
    }

    if (hw_timer->handler)
        hw_timer->handler(hw_timer->params);
}

__sys__ static int sys_timer_hw_enable(struct timer* timer, uint64_t microsecond,
                                   enum timer_mode mode)
{
    int timer_id = (int)timer->params;
    uint32_t control = TIMER_ENABLE | TIMER_INT_UNMASK;
    uint64_t value = TIMER_CLOCK_FREQ * microsecond;

    writel(TIMER_BASE + 0x20 * timer_id + TIMER_LOAD_COUNT0, value);
    writel(TIMER_BASE + 0x20 * timer_id + TIMER_LOAD_COUNT1, (value >> 32));
    if (timer->mode == TIMER_ONESHOT)
        control |= TIMER_USER_DEFINED_MODE;
    writel(TIMER_BASE + 0x20 * timer_id + TIMER_CONTROL_REG, control);

    return 0;
}

__sys__ static int sys_timer_hw_disable(struct timer* timer)
{
    int timer_id = (int)timer->params;
    writel(TIMER_BASE + 0x20 * timer_id + TIMER_CONTROL_REG, 0);
    return 0;
}

__sys__ int sys_timer_start(uint64_t microsecond, enum timer_mode mode,
                        timeout_handler_t handler, void *params)
{
    /* Default for timer1*/
    struct timer *timer = &hw_timer1;
    int timer_id = (int)params;

    if (timer_id > 5 || timer_id < 0)
        return -1;
    memset(timer, 0, sizeof(*timer));

    timer->microsecond = microsecond;
    timer->mode = mode;
    timer->handler = handler;
    timer->params = params;

    sys_timer_hw_enable(timer, microsecond, mode);

    return 0;
}

__sys__ int sys_timer_stop()
{
    sys_timer_hw_disable(&hw_timer1);

    return 0;
}

__sys__ int sys_timer_init(void)
{
    memset(&hw_timer1, 0, sizeof(hw_timer1));

    irq_register_isr(IRQ_TIMER0, sys_timer_irq_handler, 0);
    irq_enable(IRQ_TIMER0);
    return 0;
}

__sys__ int sys_timer_deinit(void)
{
    _xtos_interrupt_disable(TIMER_IRQ_TYPE);
    return 0;
}

/* Use hifi3 timer to receive the function */
__sys_data__ struct timer hw_timer0;
__sys__ static void timer_irq_handler(void *arg)
{
    struct timer* hw_timer = &hw_timer0;

    if (hw_timer->mode == TIMER_PERIODIC) {
        xthal_set_ccompare((int)hw_timer->params,
               xthal_get_ccount() + hw_timer->microsecond * TIMER_CYCLE_MICSEC);
    } else {
        xthal_set_ccompare((int)hw_timer->params, 0);
    }

    if (hw_timer->handler)
        hw_timer->handler(hw_timer->params);

}

__sys__ static int timer_hw_enable(struct timer* timer, uint64_t microsecond,
                                   enum timer_mode mode)
{
    int timer_id = (int)timer->params;
    unsigned value = xthal_get_ccount();
    xthal_set_ccompare(timer_id,
                       xthal_get_ccount() + microsecond * TIMER_CYCLE_MICSEC);
    return 0;
}

__sys__ static int timer_hw_disable(struct timer* timer)
{
    int timer_id = (int)timer->params;
    xthal_set_ccompare(timer_id, 0);
    return 0;
}

__sys__ int timer_start(uint64_t microsecond, enum timer_mode mode,
                        timeout_handler_t handler, void *params)
{
    /* Default for timer0*/
    struct timer *timer = &hw_timer0;

    memset(timer, 0, sizeof(*timer));

    timer->microsecond = microsecond;
    timer->mode = mode;
    timer->handler = handler;
    timer->params = params;

    timer_hw_enable(timer, microsecond, mode);

    return 0;
}

__sys__ int timer_stop()
{
    timer_hw_disable(&hw_timer0);

    return 0;
}

__sys__ int timer_init(void)
{
    memset(&hw_timer0, 0, sizeof(hw_timer0));
    _xtos_set_interrupt_handler(TIMER_IRQ_TYPE,
                                (_xtos_handler)&timer_irq_handler);
    _xtos_interrupt_enable(TIMER_IRQ_TYPE);

    return 0;
}

__sys__ int timer_deinit(void)
{
    _xtos_interrupt_disable(TIMER_IRQ_TYPE);
    return 0;
}

#define TICK_TIMER_BASE             TIMER5_BASE
#define TIMER_CUR_VALUE0            0x08
#define TIMER_CUR_VALUE1            0x0c
#define PLL_INPUT_OSC_RATE          24           /* 24 Mhz */

uint64_t timer_div64(uint64_t numerator, uint32_t denominator, uint32_t *pRemainder)
{
    uint64_t remainder = numerator;
    uint64_t b = denominator;
    uint64_t result;
    uint64_t d = 1;
    uint32_t high = numerator >> 32;

    result = 0;
    if (high >= denominator) {
        high /= denominator;
        result = (uint64_t)high << 32;
        remainder -= (uint64_t)(high * denominator) << 32;
    }

    while ((int64_t)b > 0 && b < remainder) {
        b = b + b;
        d = d + d;
    }

    do {
        if (remainder >= b) {
            remainder -= b;
            result += d;
        }
        b >>= 1;
        d >>= 1;
    } while (d);

    if (pRemainder)
        *pRemainder = remainder;

    return result;
}

__sys__ uint64_t timer_get_count()
{
    uint32_t high, low, temp;
    do {
        high = readl(TICK_TIMER_BASE + TIMER_CUR_VALUE1);
        low = readl(TICK_TIMER_BASE + TIMER_CUR_VALUE0);
        temp = readl(TICK_TIMER_BASE + TIMER_CUR_VALUE1);
    } while (high != temp);

    return ((uint64_t)high << 32) | low;
}

/* Uints us */
__sys__ uint32_t timer_get_tick()
{
    uint64_t tick = timer_get_count();
    uint32_t base = PLL_INPUT_OSC_RATE;

    if (tick >> 62)
        tick = ~tick;

    return (uint32_t)timer_div64(tick, base, NULL);
}
