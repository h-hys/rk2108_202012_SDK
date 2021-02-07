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

#ifndef __IOMAP_H__
#define __IOMAP_H__

#define CACHE_LINE_SIZE  128
#define BLOCK_SIZE       0x10000
#if CONFIG_SOC_RK2108
/* IO map address on RK2108 */
#define DSP_INTC_BASE    0x40010000
#define CRU_BASE         0x40050000
#define DSP_GRF_BASE     0x40090000
#define GRF_BASE         0x400b0000
#define DSP_MBOX0_BASE   0x40100000
#define DSP_MBOX1_BASE   0x40110000
#define DSP_MBOX2_BASE   0x40120000
#define PMU_BASE         0x40130000
#define UART0_BASE       0x40800000
#define UART1_BASE       0x40810000
#define UART2_BASE       0x40820000
#define TIMER0_BASE      0x40900000
#define TIMER1_BASE      0x40900020
#define TIMER2_BASE      0x40900040
#define TIMER3_BASE      0x40900060
#define TIMER4_BASE      0x40900080
#define TIMER5_BASE      0x409000a0
#define WDT1_BASE        0x40a02000
#define FSPI0_BASE       0x40c80000  /* FSPI0 base address */
#define FSPI1_BASE       0x40ca0000  /* FSPI1 base address */
#define VAD_BASE         0x41020000

#define ITCM_BASE        0x30000000
#define ITCM_SIZE        0x10000              /* 64K */
#define DTCM_BASE        0x30200000
#define DTCM_SIZE        0x80000              /* 512K */
#define SHRM_BASE        0x20000000
#define SHRM_SIZE        0x100000             /* 1M */
#define DTCM_VAD_BASE    0x30240000
#define DTCM_VAD_SIZE    0x40000

#elif CONFIG_SOC_RK2206
/* IO map address on RK2206 */
#define DSP_INTC_BASE    0x40130000
#define CRU_BASE         0x41060000
#define GRF_BASE         0x41050000
#define DSP_MBOX0_BASE   0x40100000
#define DSP_MBOX1_BASE   0x40110000
#define PMU_BASE         0x41000000
#define UART0_BASE       0x40070000
#define UART1_BASE       0x40080000
#define UART2_BASE       0x40090000
#define TIMER0_BASE      0x40000000
#define TIMER1_BASE      0x40000020
#define TIMER2_BASE      0x40000040
#define TIMER3_BASE      0x40000060
#define TIMER4_BASE      0x40000080
#define TIMER5_BASE      0x400000a0
#define TIMER_BASE1      0x41030000
#define WDT2_BASE        0x40030000
#define VAD_BASE         0x41130000
#define DMA_BASE         0x40200000

#define ITCM_BASE        0x30000000
#define ITCM_SIZE        0x8000            /* 32K */
#define DTCM_BASE        0x30200000
#define DTCM_SIZE        0x00030000        /* 192K */
#define SHRM_BASE        0x20000000
#define SHRM_SIZE        0x30000           /* 192K  last 64k for wifi*/
#endif

#endif
