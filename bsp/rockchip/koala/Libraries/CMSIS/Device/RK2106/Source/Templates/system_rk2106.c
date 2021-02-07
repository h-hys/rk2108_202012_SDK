/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */

#include "hal_base.h"

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
#define  XTAL            (24000000UL)     /* Oscillator frequency */

#define  SYSTEM_CLOCK    (XTAL * 4U)


/*----------------------------------------------------------------------------
  Externals
 *----------------------------------------------------------------------------*/
#if defined (__VTOR_PRESENT) && (__VTOR_PRESENT == 1U)
  extern uint32_t __Vectors;
#endif

/*----------------------------------------------------------------------------
  System Core Clock Variable
 *----------------------------------------------------------------------------*/
uint32_t SystemCoreClock = SYSTEM_CLOCK;  /* System Core Clock Frequency */


/*----------------------------------------------------------------------------
  System Core Clock update function
 *----------------------------------------------------------------------------*/
void SystemCoreClockUpdate (void)
{
  SystemCoreClock = SYSTEM_CLOCK;
}

/*----------------------------------------------------------------------------
  System initialization function
 *----------------------------------------------------------------------------*/
void SystemInit (void)
{
#if defined (__VTOR_PRESENT) && (__VTOR_PRESENT == 1U)
  SCB->VTOR = (uint32_t) &__Vectors;
#endif
  SystemCoreClock = SYSTEM_CLOCK;
}

/*----------------------------------------------------------------------------
  System reset function
 *----------------------------------------------------------------------------*/
void SystemReset(eRESET_MODE mode)
{
  /* mask cpu interrupt */
  __disable_fault_irq();
  __disable_irq();

  if (REST_MASKROM == mode)
  {
      /* maskrom */
      PMU->SYS_REG[3] = VAL_MASK_WE(0xFFFF, 0x18BF);
  }
  else if (REST_LOADER == mode)
  {
      /* loader */
      PMU->SYS_REG[3] = VAL_MASK_WE(0xFFFF, 0x18AF);
  }
  else
  {
      /* reset */
  }

  /* Vectortable --> maskrom address 0x0000 */
  SCB->VTOR = 0x00000000;

  /* Remap, address 0x0 --> maskrom */
  GRF->GRF_INTER_CON0 = VAL_MASK_WE(0x01 << 8, 0x00 << 8);

  /* Software reset */
  NVIC_SystemReset();
}
