/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2018-2020 Rockchip Electronics Co., Ltd.
 */

#include "hal_bsp.h"
#include "hal_base.h"
#include "unity_runner.h"

/********************* Private MACRO Definition ******************************/

/********************* Private Structure Definition **************************/

/********************* Private Variable Definition ***************************/

/********************* Private Function Definition ***************************/

/********************* Public Function Definition ****************************/

static struct UART_REG *pUart = UART1;

#ifdef __GNUC__
int _write(int fd, char *ptr, int len)
{
    int i = 0;

    /*
     * write "len" of char from "ptr" to file id "fd"
     * Return number of char written.
     *
    * Only work for STDOUT, STDIN, and STDERR
     */
    if (fd > 2) {
        return -1;
    }

    while (*ptr && (i < len)) {
        if (*ptr == '\n') {
            HAL_UART_SerialOutChar(pUart, '\r');
        }
        HAL_UART_SerialOutChar(pUart, *ptr);

        i++;
        ptr++;
    }

    return i;
}
#else
int fputc(int ch, FILE *f)
{
    if (ch == '\n') {
        HAL_UART_SerialOutChar(pUart, '\r');
    }

    HAL_UART_SerialOutChar(pUart, (char)ch);
}
#endif

void UART_IRQHandler(void)
{
    HAL_UART_HandleIrq(pUart);
}

int main(void)
{
    struct HAL_UART_CONFIG hal_uart_config = {
        .baudRate = UART_BR_115200,
        .dataBit = UART_DATA_8B,
        .stopBit = UART_ONE_STOPBIT,
        .parity = UART_PARITY_DISABLE,
    };

    /* HAL BASE Init */
    HAL_NVIC_SetIRQHandler(SysTick_IRQn, HAL_SYSTICK_IRQHandler);
    HAL_Init();

    /* BSP Init */
    BSP_Init();

    /* UART Init */
    HAL_NVIC_SetIRQHandler(UART1_IRQn, UART_IRQHandler);
    HAL_NVIC_EnableIRQ(UART1_IRQn);

    HAL_UART_Init(&g_uart1Dev, &hal_uart_config);

    /* Unity Test  */
    test_main();

    while (1) {
        ;
    }

    return 0;
}

int Main(void)
{
    main();

    return 0;
}
