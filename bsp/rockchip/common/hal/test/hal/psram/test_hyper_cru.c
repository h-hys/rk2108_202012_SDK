/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */
#include "hal_base.h"
#include "hal_bsp.h"

#if defined(RKMCU_RK2206) && defined(HAL_CRU_MODULE_ENABLED)
static struct PLL_CONFIG pConfig;

static HAL_Status CRU_GPLL_SetFreq(struct PLL_CONFIG *pll_CFG)
{
    /* set gpll freq */
    WRITE_REG_MASK_WE(CRU->MODE_CON00,
                      CRU_MODE_CON00_CLK_GPLL_MODE_MASK,
                      0x0 << CRU_MODE_CON00_CLK_GPLL_MODE_SHIFT);
    WRITE_REG_MASK_WE(CRU->GPLL_CON[1],
                      CRU_GPLL_CON1_PLLPD_MASK,
                      0x1 << CRU_GPLL_CON1_PLLPD_SHIFT);
    WRITE_REG_MASK_WE(CRU->GPLL_CON[1],
                      CRU_GPLL_CON1_REFDIV_MASK |
                      CRU_GPLL_CON1_POSTDIV2_MASK |
                      CRU_GPLL_CON1_DSMPD_MASK,
                      pll_CFG->refDiv << CRU_GPLL_CON1_REFDIV_SHIFT |
                      pll_CFG->postDiv2 << CRU_GPLL_CON1_POSTDIV2_SHIFT |
                      pll_CFG->dsmpd << CRU_GPLL_CON1_DSMPD_SHIFT);
    WRITE_REG_MASK_WE(CRU->GPLL_CON[0],
                      CRU_GPLL_CON0_FBDIV_MASK |
                      CRU_GPLL_CON0_POSTDIV1_MASK,
                      pll_CFG->postDiv1 << CRU_GPLL_CON0_POSTDIV1_SHIFT |
                      pll_CFG->fbDiv << CRU_GPLL_CON0_FBDIV_SHIFT);
    WRITE_REG_MASK_WE(CRU->GPLL_CON[2],
                      CRU_GPLL_CON2_FRACDIV_MASK,
                      pll_CFG->frac << CRU_GPLL_CON2_FRACDIV_SHIFT);
    HAL_CPUDelayUs(2);
    WRITE_REG_MASK_WE(CRU->GPLL_CON[1],
                      CRU_GPLL_CON1_PLLPD_MASK,
                      0x0 << CRU_GPLL_CON1_PLLPD_SHIFT);
    /* wait gpll lock */
    while ((CRU->GPLL_CON[1] & CRU_GPLL_CON1_PLL_LOCK_MASK) == 0)
        HAL_CPUDelayUs(1);

    return HAL_OK;
}

HAL_Status HYPERPSRAM_FreqImprove(uint32_t MHz)
{
    static struct PLL_CONFIG pll_Config;

    pll_Config.refDiv = 8;
    pll_Config.postDiv1 = pll_Config.postDiv2 = 1;
    pll_Config.fbDiv = MHz * pll_Config.postDiv1 * pll_Config.postDiv2 /
                       (40 / pll_Config.refDiv);
    pll_Config.dsmpd = 1;
    pll_Config.frac = 0;

    /* save gpll setting */
    pConfig.postDiv1 = (CRU->GPLL_CON[0] & CRU_GPLL_CON0_POSTDIV1_MASK) >>
                       CRU_GPLL_CON0_POSTDIV1_SHIFT;
    pConfig.fbDiv = (CRU->GPLL_CON[0] & CRU_GPLL_CON0_FBDIV_MASK) >>
                    CRU_GPLL_CON0_FBDIV_SHIFT;
    pConfig.dsmpd = (CRU->GPLL_CON[1] & CRU_GPLL_CON1_DSMPD_MASK) >>
                    CRU_GPLL_CON1_DSMPD_SHIFT;
    pConfig.postDiv2 = (CRU->GPLL_CON[1] & CRU_GPLL_CON1_POSTDIV2_MASK) >>
                       CRU_GPLL_CON1_POSTDIV2_SHIFT;
    pConfig.refDiv = (CRU->GPLL_CON[1] & CRU_GPLL_CON1_REFDIV_MASK) >>
                     CRU_GPLL_CON1_REFDIV_SHIFT;
    pConfig.frac = (CRU->GPLL_CON[2] & CRU_GPLL_CON2_FRACDIV_MASK) >>
                   CRU_GPLL_CON2_FRACDIV_SHIFT;

    CRU_GPLL_SetFreq(&pll_Config);

    /* set hyperbus sclk = gpll = 300MHz, psram clk = 300MHz / 2 = 150MHz */
    WRITE_REG_MASK_WE(CRU->CRU_CLKSEL_CON[17],
                      CRU_CLKSEL_CON17_CLK_XIP_HYPERX8_SEL_MASK |
                      CRU_CLKSEL_CON17_CLK_XIP_HYPERX8_DIV_MASK,
                      0 << CRU_CLKSEL_CON17_CLK_XIP_HYPERX8_SEL_SHIFT |
                      0 << CRU_CLKSEL_CON17_CLK_XIP_HYPERX8_DIV_SHIFT);

    return HAL_OK;
}

HAL_Status HYPERPSRAM_FreqRecover(void)
{
    CRU_GPLL_SetFreq(&pConfig);

    /* hyperbus sclk = xin_soc0 = 40MHz, psram clk = 40MHz / 2 = 20MHz */
    WRITE_REG_MASK_WE(CRU->CRU_CLKSEL_CON[17],
                      CRU_CLKSEL_CON17_CLK_XIP_HYPERX8_SEL_MASK |
                      CRU_CLKSEL_CON17_CLK_XIP_HYPERX8_DIV_MASK,
                      3 << CRU_CLKSEL_CON17_CLK_XIP_HYPERX8_SEL_SHIFT |
                      0 << CRU_CLKSEL_CON17_CLK_XIP_HYPERX8_DIV_SHIFT);

    return HAL_OK;
}

#endif
