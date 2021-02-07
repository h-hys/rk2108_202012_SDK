/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */

#include "interrupt.h"

extern int Reset_Handler(void);
extern uint32_t Image$$AP_MAIN_STACK$$ZI$$Limit;

_ATTR_VECTTAB_AP_
ExecFunPtr exceptions_table[NUM_INTERRUPTS] = {
    (ExecFunPtr)(&Image$$AP_MAIN_STACK$$ZI$$Limit),
    (ExecFunPtr)Reset_Handler,
};

void IntDefaultHandler(void)
{
    while (1) {
        ;
    }
}
