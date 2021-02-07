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

#include "pm.h"
#include <xtensa/tie/xt_interrupt.h>

#include "error.h"
#include "io.h"
#include "section.h"
#include "typedef.h"
#include "trace.h"
#include "timer.h"
#include "intc.h"
#include "common.h"

#if CONFIG_SOC_RK2108
#include "vad.h"
#include "delay.h"

#define PMU_WAKEUP_CFG2                  0x0008
#define PMU_WAKEUP_CFG3                  0x000c
#define PMU_WAKEUP_CFG6                  0x0018
#define PMU_LDO_CON2                     0x0058
#define PMU_GPIO_POS_INIT                0x0070
#define PMU_GPIO_NEG_INIT                0x0074
#define PMU_GPIO_POS_STATUS              0x0078
#define PMU_GPIO_NEG_STATUS              0x007c
#define PMU_BUS_CLR                      0x00a0
#define PMU_POWER_STATUS                 0x00b0
#define PMU_DSPAPM_CON                   0x00d0
#define PMU_WAKEUP_STATUS                0x0090
#define PMU_LDO_ADJ_CNT                  0x00d8
#define PMU_TIMEOUT_CNT                  0x00dc
#define PMU_DSPTCM_CON0                  0x00e8
#define PMU_DSPTCM_CON1                  0x00ec
#define PMU_DSPTCM_CON2                  0x0104
#define PMU_DSPTCM_CON3                  0x0108

#define GRF_DSP_CON1                     0x0164
#define CRU_CLKSEL_CON0                  0x0080

#define PMU_DSPAPM_TCM_RETETION_EN       BIT(10)
#define PMU_DSPAPM_SFT_WAKEUP_EN         BIT(9)
#define PMU_DSPAPM_VAD_WAKEUP_EN         BIT(8)
#define PMU_DSPAPM_TIMER_WAKEUP_EN       BIT(7)
#define PMU_DSPAPM_TIMEOUT_WAKEUP_EN     BIT(6)
#define PMU_DSPAPM_GPIO_WAKEUP_EN        BIT(5)
#define PMU_DSPAPM_INT_WAKEUP_EN         BIT(4)
#define PMU_DSPAPM_INT_DIS_CFG           BIT(3)
#define PMU_DSPAPM_IDO_ADJ_EN            BIT(2)
#define PMU_DSPAPM_IDLE_EN               BIT(1)
#define PMU_DSPAPM_WFI_PWRDN_EN          BIT(0)

#define PMU_WAKEUP_INT_STATUS            BIT(6)
#define PMU_WAKEUP_SFT_STATUS            BIT(9)
#define PMU_WAKEUP_VAD_STATUS            BIT(11)

/* DSPTCM_CON2 */
#define PMU_CON2_DTCM_PGEN_MASK          (0xFF)
#define PMU_CON2_DTCM_RET1N_MASK         (0xFF << 8)  /* 0x0000FF00 */
/* DSPTCM_CON3 */
#define PMU_CON3_DTCM_RET2N_MASK         (0xFF)       /* 0x000000FF */
#define PMU_CON3_ITCM_PGEN_MASK           BIT(8)      /* 0x00000100 */
#define PMU_CON3_ITCM_RET1N_MASK          BIT(9)      /* 0x00000200 */
#define PMU_CON3_ITCM_RET2N_MASK          BIT(10)     /* 0x00000400 */

#define MAIN_CLK                         (26)         /* 26Mhz / 1000000 */

__sys__ int set_tcm_mode(uint32_t tcm, enum tcm_mode mode, bool isAuto)
{
    uint32_t mask0 = 0;
    uint32_t mask1 = 0;
    uint32_t value0 = 0;
    uint32_t value1 = 0;

    if (tcm == ITCM) {
        mask1 = PMU_CON3_ITCM_PGEN_MASK |
        PMU_CON3_ITCM_RET1N_MASK |
        PMU_CON3_ITCM_RET2N_MASK;
        switch (mode) {
        case NOR_MODE: {
            value1 = PMU_CON3_ITCM_RET1N_MASK |
            PMU_CON3_ITCM_RET2N_MASK;
            break;
        }
        case RET1N_MODE: {
            value1 = PMU_CON3_ITCM_PGEN_MASK |
            PMU_CON3_ITCM_RET2N_MASK;
            break;
        }
        case RET2N_MODE: {
            value1 = PMU_CON3_ITCM_PGEN_MASK |
            PMU_CON3_ITCM_RET1N_MASK;
            break;
        }
        case PWR_DOWN_MODE: {
            value1 = PMU_CON3_ITCM_PGEN_MASK |
            PMU_CON3_ITCM_RET1N_MASK |
            PMU_CON3_ITCM_RET2N_MASK;
            break;
        }
        default:
            break;
        }
    } else {
        mask0 = (PMU_CON2_DTCM_PGEN_MASK & tcm)
                | (PMU_CON2_DTCM_RET1N_MASK & (tcm << 8));
        mask1 = PMU_CON3_DTCM_RET2N_MASK & tcm;
        switch (mode) {
        case NOR_MODE: {
            value0 = PMU_CON2_DTCM_RET1N_MASK & (tcm << 8);
            value1 = PMU_CON3_DTCM_RET2N_MASK & tcm;
            break;
        }
        case RET1N_MODE: {
            value0 = PMU_CON2_DTCM_PGEN_MASK & tcm;
            value1 = PMU_CON3_DTCM_RET2N_MASK & tcm;
            break;
        }
        case RET2N_MODE: {
            value0 = (PMU_CON2_DTCM_PGEN_MASK & tcm)
                    | (PMU_CON2_DTCM_RET1N_MASK & (tcm << 8));
            break;
        }
        case PWR_DOWN_MODE: {
            value0 = (PMU_CON2_DTCM_PGEN_MASK & tcm)
                    | (PMU_CON2_DTCM_RET1N_MASK & (tcm << 8));
            value1 = PMU_CON3_DTCM_RET2N_MASK & tcm;
            break;
        }
        default:
            break;
        }
    }
    if (isAuto) {
        if (mask0)
            writel_mask(PMU_BASE + PMU_DSPTCM_CON2, mask0, value0);
        writel_mask(PMU_BASE + PMU_DSPTCM_CON3, mask1, value1);
    } else {
        if (mask0)
            writel_mask(PMU_BASE + PMU_DSPTCM_CON0, mask0, value0);
        writel_mask(PMU_BASE + PMU_DSPTCM_CON1, mask1, value1);
    }
    return 0;
}

__sys__ int pm_set_tcm_mode(uint32_t tcmSel, enum tcm_mode mode, bool isAuto)
{
    uint32_t sel;

    /* Check itcm select */
    sel = tcmSel & ITCM;
    if (sel)
        set_tcm_mode(sel, mode, isAuto);

    /* Check dtcm select */
    sel = tcmSel & ~sel;
    if (sel)
        set_tcm_mode(sel, mode, isAuto);

    return 0;
}

__sys__ void pm_dspapm_setbit(uint32_t value)
{
    uint32_t val;
    val = MASK_WRITE(value);
    writel(PMU_BASE + PMU_DSPAPM_CON, val);
}

__sys__ void pm_dspapm_clrbit(uint32_t value)
{
    uint32_t val;
    val = MASK_TO_WE(value);
    writel(PMU_BASE + PMU_DSPAPM_CON, val);
}

__sys__ enum pm_wakeup_status pm_get_wakeup_status()
{
    uint32_t val;
    enum pm_wakeup_status status;
    val = readl(PMU_BASE + PMU_WAKEUP_STATUS);

  //  LOGD("wakeup status = %x\n", val);
    if (val & PMU_WAKEUP_INT_STATUS)
        status = WAKEUP_INT;
    else if (val & PMU_WAKEUP_SFT_STATUS)
        status = WAKEUP_SFT;
    else if (val & PMU_WAKEUP_VAD_STATUS)
        status = WAKEUP_VAD;
    writel(PMU_BASE + PMU_WAKEUP_STATUS, val);

    return status;
}

__sys__ void pm_retention_enable(bool enable, uint32_t tcm,  enum tcm_mode mode)
{
    if (enable) {
        pm_set_tcm_mode(tcm, mode, true);
        pm_dspapm_setbit(PMU_DSPAPM_TCM_RETETION_EN);
    } else
        pm_dspapm_clrbit(PMU_DSPAPM_TCM_RETETION_EN);
}

__sys__ void pm_gpio_enable(enum gpio_edge edge, uint32_t value)
{
    if (edge == EDGE_POS) {
        writel(PMU_BASE + PMU_GPIO_POS_STATUS, 0xffff);
        writel(PMU_BASE + PMU_GPIO_POS_INIT, MASK_WRITE(value));
        writel(PMU_BASE + PMU_WAKEUP_CFG2, MASK_WRITE(value));
    } else {
        writel(PMU_BASE + PMU_GPIO_NEG_STATUS, 0xffff);
        writel(PMU_BASE + PMU_GPIO_NEG_INIT, MASK_WRITE(value));
        writel(PMU_BASE + PMU_WAKEUP_CFG3, MASK_WRITE(value));
    }
    pm_dspapm_setbit(PMU_DSPAPM_GPIO_WAKEUP_EN);
}

__sys__ void pm_timeout_enable(bool enable, uint64_t microsec)
{
    uint64_t value = MAIN_CLK * microsec;
    if (enable) {
        if (value > 0xffffffff)
            value = 0xffffffff;
        writel(PMU_BASE + PMU_TIMEOUT_CNT, value);
        pm_dspapm_setbit(PMU_DSPAPM_TIMEOUT_WAKEUP_EN);
    } else
        pm_dspapm_clrbit(PMU_DSPAPM_TIMEOUT_WAKEUP_EN);
}

__sys__ void pm_timer_enable(bool enable, uint64_t microsec)
{
    if (enable) {
        sys_timer_clr_status();
        sys_timer_start(microsec, TIMER_PERIODIC, 0, 0);
        pm_dspapm_setbit(PMU_DSPAPM_TIMER_WAKEUP_EN);
    } else {
        sys_timer_clr_status();
        sys_timer_stop();
        pm_dspapm_clrbit(PMU_DSPAPM_TIMER_WAKEUP_EN);
    }
}

/* Set the bit, when ap set bit to 1 can wakeup */
__sys__ void pm_sft_enable(bool enable)
{
    if (enable)
        pm_dspapm_clrbit(PMU_DSPAPM_SFT_WAKEUP_EN);
    else
        pm_dspapm_setbit(PMU_DSPAPM_SFT_WAKEUP_EN);
}

__sys__ void pm_vad_enable(bool enable)
{
    if (enable) {
        vad_clr_int();
        pm_dspapm_setbit(PMU_DSPAPM_VAD_WAKEUP_EN);
    } else
       pm_dspapm_clrbit(PMU_DSPAPM_VAD_WAKEUP_EN); 
}

/* Write sft bit to wakeup */
__sys__ void pm_soft_wakeup()
{
   writel(PMU_BASE + PMU_WAKEUP_CFG6, 0x00200000);
   writel(PMU_BASE + PMU_WAKEUP_CFG6, 0x00200020);
   return;
}

__sys__ uint32_t pm_get_m4_status()
{
    return readl(PMU_BASE + PMU_POWER_STATUS) & 0x1f;
}

__sys__ int pm_wakeup_m4(uint32_t delayUs)
{
    uint32_t loop = delayUs;

    pm_soft_wakeup();
    while(loop)
    {
        if (pm_get_m4_status() == 0)
            break;
        loop--;
        udelay(1);
    }
    if (delayUs && !loop) {
        LOGD("Wakeup m4 fail\n");
        return -1;
    }
    LOGD("wakeup m4 success, cost %d Us\n", delayUs - loop);
    return 0;
}

__sys__ void pm_set_vol(enum ldo_vol nor_vol, enum ldo_vol pwr_down_vol)
{
    uint32_t val;
    if (nor_vol != VOL_NO_SET) {
        val = MASK_TO_WE(0x7) | nor_vol;
        writel(PMU_BASE + PMU_LDO_CON2, val);
    }

    if (pwr_down_vol != VOL_NO_SET) {
        val = MASK_TO_WE(0x70) | (pwr_down_vol << 4);
        writel(PMU_BASE + PMU_LDO_CON2, val);
    }
    writel(PMU_BASE + PMU_LDO_ADJ_CNT, 0x1ff);
}

__sys__ void pm_clr_bus()
{
    writel(PMU_BASE + PMU_BUS_CLR, MASK_WRITE(1 << 0));
}

__sys__ void pm_pwrdown_config()
{
    pm_retention_enable(true, DTCM0 | DTCM1 | DTCM2 |
                        ITCM, RET2N_MODE);
   // pm_timeout_enable(2000000);
   // pm_timer_enable(2000000);
    pm_sft_enable(true);
    pm_clr_bus();
//    pm_gpio_enable(EDGE_POS, 0xfff8);
//    pm_gpio_enable(EDGE_NEG, 0xfff8);
    pm_set_vol(VOL_0_85, VOL_0_85);
    pm_vad_enable(true);
}

__sys__ void pm_pwrdown_enable(bool enable)
{
    if (enable)
        pm_dspapm_setbit(PMU_DSPAPM_INT_DIS_CFG |
                         PMU_DSPAPM_IDLE_EN     |
                         PMU_DSPAPM_IDO_ADJ_EN  |
                         PMU_DSPAPM_WFI_PWRDN_EN);
    else
        pm_dspapm_clrbit(PMU_DSPAPM_INT_DIS_CFG |
                         PMU_DSPAPM_IDLE_EN     |
                         PMU_DSPAPM_IDO_ADJ_EN  |
                         PMU_DSPAPM_WFI_PWRDN_EN);
}

__sys__ void pm_set_pwr_state(uint32_t value)
{
    writel(GRF_BASE + GRF_DSP_CON1, value);
}

__sys__ uint32_t pm_get_pwr_state(void)
{
    return readl(GRF_BASE + GRF_DSP_CON1);
}

__sys__ void pm_sleep(enum sleep_type type)
{
    if (type == SLEEP_NOR)
        XT_WAITI(0);
    else if (type == SLEEP_SYS) {
        pm_clr_bus();
        pm_pwrdown_enable(true);
        system_exit();
        XT_WAITI(0);
    }
}

__sys__ void pm_freq_reduce(bool enable)
{
    static int freq = -1;
    if (enable) {
        freq = readl(CRU_BASE + CRU_CLKSEL_CON0);
        freq = freq & 0x3f;
        writel(CRU_BASE + CRU_CLKSEL_CON0, MASK_WRITE(0x3f));
        //LOGD("reduce:%x\n", readl(CRU_BASE + CRU_CLKSEL_CON0));
        return;
    } else if (freq > -1) {
        writel(CRU_BASE + CRU_CLKSEL_CON0, 0x3f0000 | freq);
        //LOGD("resume:%x\n", readl(CRU_BASE + CRU_CLKSEL_CON0));
    }
}

#else
__sys__ void pm_sleep(enum sleep_type type)
{
    XT_WAITI(0);
}
#endif
