/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */

#include "hal_bsp.h"
#include "hal_base.h"

#ifdef HAL_UART_MODULE_ENABLED
const struct HAL_UART_DEV g_uart0Dev =
{
    .pReg = UART0,
    .irqNum = UART0_IRQn,
    .isAutoFlow = false,
};

const struct HAL_UART_DEV g_uart1Dev =
{
    .pReg = UART1,
    .irqNum = UART1_IRQn,
    .isAutoFlow = true,
};
#endif

/********************* Private MACRO Definition ******************************/

/********************* Private Structure Definition **************************/

/********************* Private Variable Definition ***************************/

/********************* Private Function Definition ***************************/

/* BSP POWER Init */
static void BSP_POWER_Init(void)
{
    HAL_PINCTRL_SetIOMUX(GPIO_BANK2, GPIO_PIN_A6, PIN_CONFIG_MUX_FUNC0);

    HAL_GPIO_SetPinDirection(GPIO2, GPIO_PIN_A6, GPIO_OUT);
    HAL_GPIO_SetPinLevel(GPIO2, GPIO_PIN_A6, GPIO_HIGH);
}

/* BSP UART Init */
static void BSP_UART_Init(void)
{
    struct CRU_REG *pCRU = (struct CRU_REG *)(CRU_BASE);
    struct GRF_REG *pGRF = (struct GRF_REG *)(GRF_BASE);

    if (0) {
        /* UART 0 */
        pCRU->CRU_CLKSEL_CON[9] =
            (1 << 15) | (0 << 8) | (((0x1 << 15) | (0x3F << 8)) << 16);
        pGRF->GPIO_IO2MUX[1] = (1 << 10) | ((3 << 10) << 16);
    } else {
        pCRU->CRU_CLKSEL_CON[9] =
            (1 << 6) | (0 << 0) | (((0x3 << 6) | (0x3F << 0)) << 16);
        pGRF->GPIO_IO2MUX[2] = (1 << 0) | (3 << 16);
    }
}

/* BSP TIMER Init */
static void BSP_TIMER_Init(void)
{
    struct CRU_REG *pCRU = (struct CRU_REG *)(CRU_BASE);

    pCRU->CRU_CLKSEL_CON[2] = (0xFFFF << 16) | 0; /* 24MHz div 1 */
}

/********************* Public Function Definition ****************************/

void BSP_Init(void)
{
    BSP_POWER_Init();
    BSP_UART_Init();
    BSP_TIMER_Init();
}
