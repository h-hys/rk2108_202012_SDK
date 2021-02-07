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
#include "wdt.h"

#include "error.h"
#include "intc.h"
#include "io.h"
#include "section.h"
#include "trace.h"

#define REG_CRU_CLKSEL0_CON0         (0x0080)
#define REG_CRU_GATE_CON00           (0x0180)
#define REG_CRU_GLB_FST_VALUE        (0x0308)
#define REG_CRU_GLB_SND_VALUE        (0x030c)
#define REG_CRU_GLB_RST_CON          (0x0310)
#define REG_WDT_CR                   (0x0000)
#define REG_WDT_TORR                 (0x0004)
#define REG_WDT_CCVR                 (0x0008)
#define REG_WDT_CRR                  (0x000c)
#define REG_WDT_STAT                 (0x0010)
#define REG_WDT_EIO                  (0x0014)

#define WDT_CR_EN_BIT                BIT(0)
#define WDT_CR_RESP_BIT              BIT(1)

#define WDT_WDT1_RST_GLB_BIT         BIT(9)
#define WDT_WDT1_RST_FST_BIT         BIT(13)

#define CRU_GATE_CTRL0_PCLK_NIU_BIT  BIT(4)
#define CRU_GATE_CTRL0_PCLK_WDT1_BIT BIT(6)

#define WDT_RESTART_KICK_VALUE       (0x76)
#define WDT_MAX_TOP                  (15)


struct wdt_dev g_wdt_dev;

__sys__ uint32_t wdt_top_millisec(uint32_t top)
{
    /*
     * There are 16 possible timeout values in 0..15 where the number of
     * cycles is 2 ^ (16 + i) and the watchdog counts down.
     */
    uint64_t millisec = (1 << (16 + top)) / (g_wdt_dev.freq / 1000 ); // 1000 for micro

    return millisec;
}

__sys__ static    uint32_t wdt_get_freq()
{
    /* Get  dsp_pclk */
#if CONFIG_SOC_RK2108
    uint32_t val = readl(CRU_BASE + REG_CRU_CLKSEL0_CON0);
    uint32_t div = (val >> 8) & 0x3f;
    val = 1200 * MHZ / (div + 1);
    return val;
#else
    return 96000000;
#endif
}

__sys__ void wdt_keep_alive(void)
{
    writel(WDT_BASE + REG_WDT_CRR, WDT_RESTART_KICK_VALUE);
}

__sys__ int wdt_irq_handler(enum irq_num irq_num, void *params)
{
    uint32_t status = readl(WDT_BASE + REG_WDT_STAT);
    uint32_t eio = readl(WDT_BASE + REG_WDT_EIO);
    wdt_keep_alive();
    //LOGD("Get wdt status = 0x%x, interrupt eio = 0x%x\n", status, eio);
    wdt_callback callback = (wdt_callback)params;
    if (callback)
        callback(0);
}

__sys__ void wdt_timeout_set(uint32_t millisec)
{
    uint32_t i;
    for (i = 0; i < WDT_MAX_TOP; i++)
    {
        if (wdt_top_millisec(i) >= millisec)
            break;
    }

    writel(WDT_BASE + REG_WDT_TORR, i);
    wdt_keep_alive();
}

#if CONFIG_SOC_RK2108
__sys__ void wdt_gating_enable(bool enable)
{
    uint32_t val, mask;
    if (enable) {
        mask = CRU_GATE_CTRL0_PCLK_NIU_BIT | CRU_GATE_CTRL0_PCLK_WDT1_BIT;
        writel(CRU_BASE + REG_CRU_GATE_CON00, VAL_MASK_WE(mask, 0));
    } else {
        mask = CRU_GATE_CTRL0_PCLK_WDT1_BIT;
        val = mask;
        writel(CRU_BASE + REG_CRU_GATE_CON00, VAL_MASK_WE(mask, val));
    }
}
#else
__sys__ void wdt_gating_enable(bool enable)
{
    uint32_t val, mask;
    if (enable) {
        mask = BIT(10);
        writel(CRU_BASE + 0x030c, VAL_MASK_WE(mask, 0));
    } else {
        mask = BIT(10);
        val = mask;
        writel(CRU_BASE + 0x030c, VAL_MASK_WE(mask, val));
    }
}
#endif

__sys__ int wdt_init(enum wdt_mode mode, wdt_callback callback)
{
    uint32_t val;
    g_wdt_dev.freq = wdt_get_freq();
 //   LOGD("freq = %d Hz\n", g_wdt_dev.freq);

    /* Enable gateing */
    wdt_gating_enable(true);
    /* Set mode */
    val = readl(WDT_BASE + REG_WDT_CR);
    if (mode == INDIRECT_SYS_RESET) {
        irq_register_isr(IRQ_WDT, wdt_irq_handler, (void *)callback);
        irq_enable(IRQ_WDT);
        val |= WDT_CR_RESP_BIT;
    } else if (mode == DIRECT_SYS_RESET) {
        val &= ~WDT_CR_RESP_BIT;
    }
    writel(WDT_BASE + REG_WDT_CR, val);
    return 0;
}

__sys__ int wdt_deinit()
{
    wdt_gating_enable(false);
}

__sys__ void wdt_start(enum wdt_rst_type type)
{
    uint32_t val;

    /* Set reset type */
    val = readl(CRU_BASE + REG_CRU_GLB_RST_CON);
    if (type == GLB_RST_FST_WDT)
        val |= WDT_WDT1_RST_GLB_BIT | WDT_WDT1_RST_FST_BIT;
    else if (type == GLB_RST_SND_WDT)
        val |= WDT_WDT1_RST_GLB_BIT;
    writel(CRU_BASE + REG_CRU_GLB_RST_CON, val);

    /* Enable wdt */
    val = readl(WDT_BASE + REG_WDT_CR);
    val |= WDT_CR_EN_BIT;
    writel(WDT_BASE + REG_WDT_CR, val);
}

__sys__ void wdt_stop()
{
    uint32_t val = readl(WDT_BASE + REG_WDT_CR);
    val &= ~WDT_CR_EN_BIT;
    writel(WDT_BASE + REG_WDT_CR, val);
}
