/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */

#include "soc.h"
#include "hal_conf.h"
#include "hal_def.h"

HAL_SECTION_SRAM_DATA uint32_t SystemCoreClock = 24000000;

/*----------------------------------------------------------------------------
  Externals
 *----------------------------------------------------------------------------*/
#if defined(__VTOR_PRESENT) && (__VTOR_PRESENT == 1U)
extern uint32_t __Vectors[];
extern const uint32_t __vector_remap__[];
#endif

/*----------------------------------------------------------------------------
  System Core Clock update function
 *----------------------------------------------------------------------------*/
void SystemCoreClockUpdate(void)
{
}

/*----------------------------------------------------------------------------
  System initialization function
 *----------------------------------------------------------------------------*/
void SystemInit(void)
{
#if defined(HAL_ICACHE_MODULE_ENABLED) || defined(HAL_DCACHE_MODULE_ENABLED)
        uint32_t status;
#endif

#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
    SCB->CPACR |= ((3UL << 10 * 2) | (3UL << 11 * 2));  /* set CP10 and CP11 Full Access */
#endif

#if defined(__VTOR_PRESENT) && (__VTOR_PRESENT == 1U)
#ifdef __vector_remap__
    uint32_t *ramVector = (uint32_t *)(__vector_remap__);

    for (uint32_t i = 0; i < 16; i++) {
        ramVector[i] = __Vectors[i];
    }
    SCB->VTOR = (uint32_t)ramVector;
#else
    SCB->VTOR = (uint32_t)__Vectors;
#endif
#endif

#if defined(HAL_ICACHE_MODULE_ENABLED)
    /* config icache: mpu disable, stb disable, write through, hot buffer enable */
    ICACHE->CACHE_CTRL |= (ICACHE_CACHE_CTRL_CACHE_EN_MASK | ICACHE_CACHE_CTRL_CACHE_WT_EN_MASK |
                           ICACHE_CACHE_CTRL_CACHE_MPU_MODE_MASK);
    ICACHE->CACHE_CTRL &= (~ICACHE_CACHE_CTRL_CACHE_STB_EN_MASK);

    do {
        status =
            ICACHE->CACHE_STATUS & ICACHE_CACHE_STATUS_CACHE_INIT_FINISH_MASK;
    } while (status == 0);

    ICACHE->CACHE_CTRL &= ~ICACHE_CACHE_CTRL_CACHE_BYPASS_MASK;
#endif

#if defined(HAL_DCACHE_MODULE_ENABLED)
    /* stb enable, stb_entry=7, stb_timeout enable, write back */
    DCACHE->CACHE_CTRL |= DCACHE_CACHE_CTRL_CACHE_EN_MASK |
                          (7U << DCACHE_CACHE_CTRL_CACHE_ENTRY_THRESH_SHIFT) |
                          DCACHE_CACHE_CTRL_STB_TIMEOUT_EN_MASK |
                          DCACHE_CACHE_CTRL_CACHE_MPU_MODE_MASK;
    DCACHE->STB_TIMEOUT_CTRL = 1;

    do {
        status =
            DCACHE->CACHE_STATUS & DCACHE_CACHE_STATUS_CACHE_INIT_FINISH_MASK;
    } while (status == 0);

    DCACHE->CACHE_CTRL &= ~DCACHE_CACHE_CTRL_CACHE_BYPASS_MASK;

    /* enable dap cache access for jtag protocol. don't modify the uncache data
     * by jtag, the data will be inconsistent. */
    GRF->MCU_CON0 |= GRF_MCU_CON0_M4_DAP_DCACHE_MASK;
#endif
}
