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

#include "uart.h"

#include "io.h"
#include "section.h"
#include "typedef.h"

/* Receive Buffer Register */
#define UART_RBR                 0x0000

/* Transmit Holding Register */
#define UART_THR                 0x0000

/* Divisor Latch Register */
#define UART_DLL                 0x0000
#define UART_DLH                 0x0004

/* Interrupt Enable Register */
#define UART_IER                 0x0004

#define UART_IIR                 0x0008
#define UART_FCR                 0x0008

/* Line Control Register */
#define UART_LCR                 0x000c
#define UART_BIT8                (0x3)
#define UART_PARITY_DISABLED     (0 << 3)
#define UART_STOP_BIT1           (0 << 2)
#define UART_DLA_ENABLE          (1 << 7)
#define UART_DLA_DISABLE         (0 << 7)

#define UART_MCR                 0x0010

/* Line Status Register */
#define UART_LSR                 0x0014
#define UART_TRANSMITTER_EMPTY   BIT(6)

#define UART_MSR                 0x0018
#define UART_SCR                 0x001c
#define UART_SRBR                0x0030
#define UART_STHR                0x0064
#define UART_FAR                 0x0070
#define UART_TFR                 0x0074
#define UART_RFW                 0x0078
#define UART_USR                 0x007c
#define UART_TFL                 0x0080
#define UART_RFL                 0x0084

/* Software reset register */
#define UART_SRR                 0x0088
#define UART_RESET               BIT(0)
#define RCVR_FIFO_REST           BIT(1)
#define XMIT_FIFO_RESET          BIT(2)

#define UART_SRTS                0x008c
#define UART_SBCR                0x0090
#define UART_SDMAM               0x0094
#define UART_SFE                 0x0098
#define UART_SRT                 0x009c
#define UART_STET                0x00a0
#define UART_HTX                 0x00a4
#define UART_DMASA               0x00a8
#define UART_CPR                 0x00f4
#define UART_UCV                 0x00f8
#define UART_CTR                 0x00fc

#define UART_BASE_ADDR           UART0_BASE

uint32_t uart_addr = UART_BASE_ADDR;

__sys__ int uart_tx_char(char byte)
{
    uint32_t lsr = 0;

    /* Transfer a byte */
#if CONFIG_TRACE_ENABLE
    writel(uart_addr + UART_THR, byte);

    do {
        lsr = readl(uart_addr + UART_LSR);
    } while (!(lsr & UART_TRANSMITTER_EMPTY));
#endif

    return 0;
}

__sys__ int uart_tx_string(const char *s, uint32_t count)
{
    unsigned char r = '\r';

    while (count--) {
        if (*s == '\n')
            uart_tx_char(r);
        uart_tx_char(*s++);
    }

    return 0;
}

__sys__ int uart_init(uint32_t uart_port)
{
    uint32_t lcr = 0;
    uart_addr = UART0_BASE + (0x10000) * uart_port;
#if CONFIG_TRACE_ENABLE
    /* Set IOMUX */
//    if (uart_addr == UART0_BASE) {
//        writel(0x400b0014, 0x30001000);
//        writel(0x400b0018, 0x00030001);
//    }
//    if (uart_addr == UART1_BASE) {
//        writel(0x400b0014, 0x00770022);
//    }
    /* Clock enable, enabled by default, clock from XIN24M */

    /* Reset uart */
    writel(uart_addr + UART_SRR,
           UART_RESET | RCVR_FIFO_REST | XMIT_FIFO_RESET);

    /* Disable uart interrupt */
    writel(uart_addr + UART_IER, 0);

    /* Set 8bit, no parity, stop bit 1, enable DLA */
    lcr = UART_BIT8 | UART_STOP_BIT1 | UART_PARITY_DISABLED | UART_DLA_ENABLE;
    writel(uart_addr + UART_LCR, lcr);

    /* Set baud rate to 115200 */
    writel(uart_addr + UART_DLL, 0xD); // 26000000M:0x0e 24000000M:0x0d
    writel(uart_addr + UART_DLH, 0x0);

    /* Disable DLA */
    lcr = UART_BIT8 | UART_STOP_BIT1 | UART_PARITY_DISABLED | UART_DLA_DISABLE;
    writel(uart_addr + UART_LCR, lcr);
#endif

    return 0;
}

__sys__ void uart_set_port(uint32_t uart_port)
{
    uart_addr = UART0_BASE + (0x10000) * uart_port;
}
