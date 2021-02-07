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

#include "intc.h"

#include <string.h>
#include <stdint.h>
#include <xtensa/hal.h>
#include <xtensa/core-macros.h>
#include <xtensa/xtruntime.h>

#include "error.h"
#include "io.h"
#include "iomap.h"
#include "section.h"

#define REG_L 32
#define INTC_IRQ_TYPE           IRQ_LEVEL0
/* DSP INTC registers */
#define INTC_IRQ_INTEN_L        0x00
#define INTC_IRQ_INTEN_H        0x04
#define INTC_IRQ_INTMASK_L      0x08
#define INTC_IRQ_INTMASK_H      0x0c
#define INTC_IRQ_INTFORCE_L     0x10
#define INTC_IRQ_INTFORCE_H     0x14
#define INTC_IRQ_RAWSTATUS_L    0x18
#define INTC_IRQ_RAWSTATUS_H    0x1c
#define INTC_IRQ_STATUS_L       0x20
#define INTC_IRQ_STATUS_H       0x24
#define INTC_IRQ_MASKSTATUS_L   0x28
#define INTC_IRQ_MASKSTATUS_H   0x2c
#define INTC_IRQ_FINALSTATUS_L  0x30
#define INTC_IRQ_FINALSTATUS_H  0x34
#define INTC_IRQ_PLEVEL         0xd8
#define INTC_IRQ_PR_OFFSET      0xe8

struct irq_info {
    enum irq_num irq_num;
    isr_t isr;
    void *params;
};

struct intc_regs {
    volatile uint32_t inten_l;
    volatile uint32_t inten_h;
    volatile uint32_t intmask_l;
    volatile uint32_t intmask_h;
    volatile uint32_t intforce_l;
    volatile uint32_t intforce_h;
    volatile uint32_t rawstatus_l;
    volatile uint32_t rawstatus_h;
    volatile uint32_t status_l;
    volatile uint32_t status_h;
    volatile uint32_t maskstatus_l;
    volatile uint32_t maskstatus_h;
    volatile uint32_t finalstatus_l;
    volatile uint32_t finalstatus_h;
    volatile uint32_t res0[0xd8 - 0x34];
    volatile uint32_t plevel;
    volatile uint32_t res1[0xe8 - 0xd8];
    volatile uint32_t pr_offset;
};

static __sys_data__ struct irq_info g_irqs[IRQ_MAX_NUM];

extern "C" void intc_irq_handler(void *arg)
{
    uint32_t irq_num;
    uint32_t status_l, status_h;
    struct intc_regs *intc_reg = (struct intc_regs *)DSP_INTC_BASE;

//  _xtos_clear_ints(INTC_IRQ_TYPE);
    status_l = intc_reg->status_l;
    status_h = intc_reg->status_h;

    for (irq_num = 0; irq_num < IRQ_MAX_NUM; irq_num++) {
        if (irq_num < REG_L) {
            if (status_l & 1)
                break;
            status_l >>= 1;
        } else {
            if (status_h & 1)
                break;
            status_h >>= 1;
        }
    }

    if (irq_num < IRQ_MAX_NUM && g_irqs[irq_num].isr)
        g_irqs[irq_num].isr((enum irq_num)irq_num, g_irqs[irq_num].params);

    return;
}

__sys__ int irq_mask(enum irq_num irq_num)
{
    struct intc_regs *intc_reg = (struct intc_regs*)DSP_INTC_BASE;

    if (irq_num >= IRQ_MAX_NUM || irq_num < 0)
        return -EINVALID;

    if (irq_num < REG_L)
        intc_reg->intmask_l |= (0x1 << (irq_num & 0x1f));
    else
        intc_reg->intmask_h |= (0x1 << ((irq_num - REG_L) & 0x1f));

    return 0;
}

__sys__ int irq_unmask(enum irq_num irq_num)
{
    struct intc_regs *intc_reg = (struct intc_regs *)DSP_INTC_BASE;

    if (irq_num >= IRQ_MAX_NUM || irq_num < 0)
        return -EINVALID;

    if (irq_num < REG_L)
        intc_reg->intmask_l &= (~(0x1 << (irq_num & 0x1f)));
    else
        intc_reg->intmask_h &= (~(0x1 << ((irq_num - REG_L) & 0x1f)));

    return 0;
}

__sys__ int irq_register_isr(enum irq_num irq_num, isr_t isr, void* params)
{
    if (irq_num >= IRQ_MAX_NUM || irq_num < 0)
        return -EINVALID;

    g_irqs[irq_num].isr = isr;
    g_irqs[irq_num].irq_num = irq_num;
    g_irqs[irq_num].params = params;

    return 0;
}

__sys__ int irq_unregister_isr(enum irq_num irq_num)
{
    if (irq_num >= IRQ_MAX_NUM || irq_num < 0)
        return -EINVALID;

    g_irqs[irq_num].isr = NULL;
    g_irqs[irq_num].irq_num = IRQ_MAX_NUM;
    g_irqs[irq_num].params = NULL;

    return 0;
}

__sys__ int irq_enable(enum irq_num irq_num)
{
    struct intc_regs *intc_reg = (struct intc_regs *)DSP_INTC_BASE;

    if (irq_num >= IRQ_MAX_NUM || irq_num < 0)
        return -EINVALID;

    if (irq_num < REG_L)
        intc_reg->inten_l |= (0x1 << (irq_num & 0x1f));
    else
        intc_reg->inten_h |= (0x1 << ((irq_num - REG_L) & 0x1f));

    return 0;
}

__sys__ int irq_disable(enum irq_num irq_num)
{
    struct intc_regs *intc_reg = (struct intc_regs *)DSP_INTC_BASE;

    if (irq_num >= IRQ_MAX_NUM || irq_num < 0)
        return -EINVALID;

    if (irq_num < REG_L)
        intc_reg->inten_l &= (~(0x1 << (irq_num & 0x1f)));
    else
        intc_reg->inten_h &= (~(0x1 << ((irq_num - REG_L) & 0x1f)));

    return 0;
}

__sys__ int intc_init(void)
{
    memset(g_irqs, 0, sizeof(g_irqs));
    _xtos_set_interrupt_handler(INTC_IRQ_TYPE,
                                (_xtos_handler)&intc_irq_handler);
    _xtos_interrupt_enable(INTC_IRQ_TYPE);
    return 0;
}

__sys__ int intc_deinit(void)
{
    _xtos_interrupt_disable(INTC_IRQ_TYPE);
    return 0;
}
