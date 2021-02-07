/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */

#ifndef __SOC_H
#define __SOC_H
#ifdef __cplusplus
  extern "C" {
#endif

/* IO definitions (access restrictions to peripheral registers) */
#ifdef __cplusplus
  #define   __I     volatile             /*!< brief Defines 'read only' permissions */
#else
  #define   __I     volatile const       /*!< brief Defines 'read only' permissions */
#endif
#define     __O     volatile             /*!< brief Defines 'write only' permissions */
#define     __IO    volatile             /*!< brief Defines 'read / write' permissions */

/* ================================================================================ */
/* ================                    DMA REQ                      =============== */
/* ================================================================================ */
typedef enum {
    DMA_REQ_UART2_RX = 4,
    DMA_REQ_UART2_TX = 5,
} DMA_REQ_Type;

/* ================================================================================ */
/* ================                       IRQ                      ================ */
/* ================================================================================ */
typedef enum
{
/******  Platform Exceptions Numbers ***************************************************/
  TIMER0_IRQn            = 141,      /*!< TIMER0 Interrupt            */
  TIMER1_IRQn            = 142,      /*!< TIMER1 Interrupt            */
  TIMER2_IRQn            = 143,      /*!< TIMER2 Interrupt            */
  TIMER3_IRQn            = 144,      /*!< TIMER3 Interrupt            */
  TIMER4_IRQn            = 145,      /*!< TIMER4 Interrupt            */
  TIMER5_IRQn            = 146,      /*!< TIMER5 Interrupt            */
  NUM_INTERRUPTS         = 283,
} IRQn_Type;

/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */
#ifndef __ASSEMBLY__
#include "cmsis_compiler.h"               /* CMSIS compiler specific defines */
#include "system_rk3568.h"
#endif /* __ASSEMBLY__ */
#include "rk3568.h"

/****************************************************************************************/
/*                                                                                      */
/*                               Register Bitmap Section                                */
/*                                                                                      */
/****************************************************************************************/
/******************************************CRU*******************************************/
#ifndef __ASSEMBLY__
typedef enum CLOCK_Name {
    CLK_INVALID = 0U,
} eCLOCK_Name;
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __SOC_H */
