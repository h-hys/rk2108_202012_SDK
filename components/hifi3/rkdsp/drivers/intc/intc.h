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

#ifndef __INTC_H__
#define __INTC_H__

#include "typedef.h"

/* Lower 32 interrupt source */
#define IRQ_M4_CACHE_BIT            BIT(0)
#define IRQ_MBOX0_AP_BIT            BIT(2)
#define IRQ_MBOX0_BB_BIT            BIT(3)
#define IRQ_MBOX1_AP_BIT            BIT(4)
#define IRQ_MBOX1_BB_BIT            BIT(5)
#define IRQ_MBOX2_AP_BIT            BIT(6)
#define IRQ_MBOX2_BB_BIT            BIT(7)
#define IRQ_PMU_BIT                 BIT(8)
#define IRQ_DMAC_IRQ_BIT            BIT(9)
#define IRQ_DMAC_ABORT_BIT          BIT(10)
#define IRQ_UART0_BIT               BIT(11)
#define IRQ_UART1_BIT               BIT(12)
#define IRQ_TIMER0_BIT              BIT(14)
#define IRQ_TIMER1_BIT              BIT(15)
#define IRQ_TIMER2_BIT              BIT(16)
#define IRQ_TIMER3_BIT              BIT(17)
#define IRQ_TIMER4_BIT              BIT(18)
#define IRQ_TIMER5_BIT              BIT(19)
#define IRQ_WDT0_BIT                BIT(20)
#define IRQ_WDT1_BIT                BIT(21)
#define IRQ_I2CMST0_BIT             BIT(22)
#define IRQ_I2CMST1_BIT             BIT(23)
#define IRQ_I2CMST2_BIT             BIT(24)
#define IRQ_SPISLV0_BIT             BIT(25)
#define IRQ_SPIMST1_BIT             BIT(26)
#define IRQ_GPIO0_BIT               BIT(29)
#define IRQ_GPIO1_BIT               BIT(30)

/* Upper 32 interrupt source */
#define IRQ_I2S_BIT                 BIT(0)
#define IRQ_PDM_BIT                 BIT(1)
#define IRQ_VAD_BIT                 BIT(2)
#define IRQ_VOP_BIT                 BIT(3)
#define IRQ_VOP_INT_POST_LB_BIT     BIT(4)
#define IRQ_MIPI_DSI_HOST_BIT       BIT(5)
#define IRQ_TP_BIT                  BIT(6)
#define IRQ_DSP_PFATALERROR_BIT     BIT(7)

#if CONFIG_SOC_RK2108
/* Intc irq number */
enum irq_num {
    IRQ_M4_CACHE = 0,
    IRQ_MBOX0_AP = 2,
    IRQ_MBOX0_BB,
    IRQ_MBOX1_AP,
    IRQ_MBOX1_BB,
    IRQ_MBOX2_AP,
    IRQ_MBOX2_BB,
    IRQ_PMU,
    IRQ_DMAC_IRQ,
    IRQ_DMAC_ABORT,
    IRQ_UART0,
    IRQ_UART1,
    IRQ_TIMER0 = 14,
    IRQ_TIMER1,
    IRQ_TIMER2,
    IRQ_TIMER3,
    IRQ_TIMER4,
    IRQ_TIMER5,
    IRQ_WDT0,
    IRQ_WDT1,
    IRQ_I2CMST0,
    IRQ_I2CMST1,
    IRQ_I2CMST2,
    IRQ_SPISLV0,
    IRQ_SPIMST1,
    IRQ_GPIO0 = 29,
    IRQ_GPIO1,
    IRQ_I2S = 32,
    IRQ_PDM,
    IRQ_VAD = 35,
    IRQ_VOP,
    IRQ_VOP_INT_POST_LB,
    IRQ_MIPI_DSI_HOST_INT,
    IRQ_TP,
    IRQ_DSP_PFATAL_ERROR,
    IRQ_MAX_NUM,
};

#elif CONFIG_SOC_RK2206
/* Intc irq number */
enum irq_num {
    /* PD_LOGIC */
    DMAC_CH0 = 0,
    IRQ_WDT2 = 3,
    IRQ_TIMER0 = 4,
    IRQ_TIMER1,
    IRQ_TIMER2,
    IRQ_TIMER3,
    IRQ_TIMER4,
    IRQ_TIMER5,
    TIMER_1CH,
    UART0 = 11,
    UART1,
    UART2,
    A2B1_IRQ0 = 14,
    A2B1_IRQ1,
    A2B1_IRQ2,
    A2B1_IRQ3,
    XIPSFC0 = 18,
    XIPSFC1,
    HYPERx8_IRQ = 20,

    /* TOP */
    PMU_IRQ,
    DMAC_CH1,
    DMAC_CH2,
    DMAC_CH3,
    DMAC_CH4,
    DMAC_CH5,

    IRQ_MAX_NUM,
};

#endif

/* Hifi3 interrupt type */
enum irq_type {
    IRQ_LEVEL0 = 0, /* BInterrupt Pin 0 */
    IRQ_LEVEL1, /* BInterrupt Pin 1 */
    IRQ_LEVEL2, /* BInterrupt Pin 2 */
    IRQ_LEVEL3, /* BInterrupt Pin 3 */
    IRQ_LEVEL4, /* BInterrupt Pin 4 */
    IRQ_LEVEL5, /* BInterrupt Pin 5 */
    IRQ_EDGE0, /* BInterrupt Pin 6 */
    IRQ_EDGE1, /* BInterrupt Pin 7 */
    IRQ_EDGE2, /* BInterrupt Pin 8 */
    IRQ_EDGE3, /* BInterrupt Pin 9 */
    IRQ_EDGE4, /* BInterrupt Pin 10 */
    IRQ_WRITEERR, /* BInterrupt Pin 11 */
    IRQ_TIMER, /* BInterrupt Pin 12 */
    IRQ_SW, /* BInterrupt Pin 13 */
};

typedef int (*isr_t)(enum irq_num irq_num, void *params);

#ifdef __cplusplus
extern "C" {
#endif

int irq_register_isr(enum irq_num irq_num, isr_t isr, void *params);
int irq_unregister_isr(enum irq_num irq_num);
int irq_enable(enum irq_num irq_num);
int irq_disable(enum irq_num irq_num);
int intc_init(void);
int intc_deinit(void);

#ifdef __cplusplus
}
#endif

#endif
