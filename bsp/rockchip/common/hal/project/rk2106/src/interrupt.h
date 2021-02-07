/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */

#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_

#include "hal_base.h"

/*
*-------------------------------------------------------------------------------
*
*                           Macro define
*
*-------------------------------------------------------------------------------
*/
#if defined(__arm__) && defined(__ARMCC_VERSION)
typedef void (*ExecFunPtr)(void);
#elif defined(__arm__) && defined(__GNUC__)
typedef void (*ExecFunPtr)(void);
#else
#error Unknown compiling tools
#endif

#define _ATTR_VECTTAB_AP_ __attribute__((section("ap_vect")))

#define NUM_PRIORITY_BITS 4
void IntDefaultHandler(void);

#endif
