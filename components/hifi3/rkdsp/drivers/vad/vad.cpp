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
#include "vad.h"

#if CONFIG_SOC_RK2108

#include "error.h"
#include "intc.h"
#include "io.h"
#include "section.h"
#include "trace.h"

#define VAD_SPACE_SEL_ALIGN        (64 * 1024)
#define VAD_SPACE_MAX_NUM          (3)
vad_callback g_callback;

__sys__ void vad_set_period(uint32_t period)
{
    uint32_t value = period / 4 - 1;  /* Get word */
    value |= 0x10000;
    writel(VAD_BASE + VAD_AUX_CONTROL1, value);
}

__sys__ void vad_set_space_sel(uint32_t size)
{
    uint32_t con_val = 0;
    int num = (size - 1) / VAD_SPACE_SEL_ALIGN;
    num = VAD_SPACE_MAX_NUM - num;
    if (num > VAD_SPACE_MAX_NUM)
        num = VAD_SPACE_MAX_NUM;
    con_val = VAD_SPACE_SEL_BIT << 16 | (num) << 8;
    writel(GRF_BASE + DSP_CON2, con_val);
}

__sys__ void vad_get_cur_addr(uint32_t *cur_addr)
{
    *cur_addr = readl(VAD_BASE + VAD_RAM_CUR_ADDR);
}

__sys__ void vad_get_addr(uint32_t *start_addr, uint32_t *end_addr,
                          uint32_t *cur_addr)
{
    *start_addr = readl(VAD_BASE + VAD_RAM_START_ADDR);
    *end_addr = readl(VAD_BASE + VAD_RAM_END_ADDR) + 8;
    *cur_addr = readl(VAD_BASE + VAD_RAM_CUR_ADDR);
}

__sys__ void vad_swich_mode(enum intfc_mode mode)
{
    uint32_t con_val = 0;
    con_val = readl(VAD_BASE + VAD_AUX_CONTROL);
    switch (mode) {
    case RAM_INTFC:
        con_val &= ~BUS_WRITE_EN_BIT & ~ DIS_RAM_ITF_BIT;
        break;
    case BUS_INTFC:
        con_val |= BUS_WRITE_EN_BIT | DIS_RAM_ITF_BIT;
        break;
    }
    writel(VAD_BASE + VAD_AUX_CONTROL, con_val);
}

__sys__ void vad_clr_int()
{
    writel(VAD_BASE + VAD_INT, readl(VAD_BASE + VAD_INT));
}

__sys__ int vad_irq_handler(enum irq_num irq_num, void *params)
{
    irq_disable(IRQ_VAD);
    if (g_callback)
        g_callback(0);
    vad_clr_int();         /* Clear interrupt status */
    irq_enable(IRQ_VAD);
}

__sys__ void vad_int_thd_enable(uint32_t sample, bool enable)
{
    uint32_t sam = sample;
    uint32_t val = readl(VAD_BASE + VAD_AUX_CONTROL);
    if (enable)
        val |= SAMPLE_CNT_EN_BIT | INT_TRIG_CTRL_EN_BIT;
    else
        val &= ~(SAMPLE_CNT_EN_BIT | INT_TRIG_CTRL_EN_BIT);
    if (sam) {
        if (sam > 4096)
            sam = 4096;
        val |= (sam - 1) << INT_TRIG_VALID_THD;
    }
    writel(VAD_BASE + VAD_AUX_CONTROL, val);
}

__sys__ void vad_int_enable(enum vad_int_type type, bool enable)
{
    uint32_t reg = readl(VAD_BASE + VAD_INT);
    uint32_t val = 0;
    switch (type) {
    case DET_INT:
        val = DET_INT_EN_BIT;
        break;
    case TRANS_INT:
        val = DATA_TRANS_INT_EN_BIT;
        break;
    }
    if (enable)
        reg |= val;
    else
        reg &= ~val;
    writel(VAD_BASE + VAD_INT, reg);
}

__sys__ int vad_init(vad_callback callback)
{
    g_callback = callback;
    irq_register_isr(IRQ_VAD, vad_irq_handler, 0);
    vad_int_enable(DET_INT, true);
//    vad_int_enable(TRANS_INT, true);
    vad_swich_mode(RAM_INTFC);
    return 0;
}

__sys__ void vad_enable(bool enable)
{
    uint32_t val = readl(VAD_BASE + VAD_CONTROL);
    if (enable)
        val |= VAD_ENABLE;
    else
        val &= ~VAD_ENABLE;
    writel(VAD_BASE + VAD_CONTROL, val);
}

__sys__ void vad_start(void)
{
    vad_clr_int();
    irq_enable(IRQ_VAD);
}

__sys__ void vad_stop(void)
{
    irq_disable(IRQ_VAD);
    vad_clr_int();
}
#endif

