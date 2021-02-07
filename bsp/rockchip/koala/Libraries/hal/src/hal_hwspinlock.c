/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */

#include "hal_base.h"

#ifdef HAL_HWSPINLOCK_MODULE_ENABLED

/** @addtogroup RK_HAL_Driver
 *  @{
 */

/** @addtogroup HWSpinlock
 *  @{
 */

/** @defgroup HWSpinlock_Private_Definition Private Definition
 *  @{
 */
/********************* Private MACRO Definition ******************************/

#ifndef HWSPINLOCK
#define HWSPINLOCK GRF->HW_SPINLOCK
#endif

#define HWSPINLOCK_STATUS_MASK (0xFU << 0U)
#define IS_VALID_LOCKID(n)     ((uint32_t)(n) < 64U)

/********************* Private Variable Definition ***************************/

/*
 * HAL_HWSPINLOCK_OWNER_ID macro *MUST* be defined at hal_conf.h
 * if HAL_HWSPINLOCK_MODULE_ENABLED is selected.
 */
static const uint8_t g_OwnerID = HAL_HWSPINLOCK_OWNER_ID;

/** @} */
/********************* Public Function Definition ****************************/

/** @defgroup HWSpinlock_Exported_Functions_Group1 TryLock and Unlock Functions

This section provides functions allowing to Trylock and Unlock HWSpinlock:

*  @{
*/

/**
 * @brief  HWSpinlock Try to Lock API.
 * @param  LockID: The Lock ID which try to lock.
 * @return The lock status, 1 means locked and 0 is not.
 */
HAL_Check HAL_HWSpinlock_TryLock(uint32_t LockID)
{
    HAL_ASSERT(IS_VALID_LOCKID(LockID));

    WRITE_REG(HWSPINLOCK[LockID], g_OwnerID);

    /*
     * Get only first 4 bits and compare to HWSPINLOCK_OWNER_ID,
     * if equal, we attempt to acquire the lock, otherwise,
     * someone else has it.
     */
    return (g_OwnerID == (HWSPINLOCK_STATUS_MASK &
                          READ_REG(HWSPINLOCK[LockID])));
}

/**
 * @brief  HWSpinlock Unlock API
 * @param  LockID: The Lock ID which try to unlock.
 */
void HAL_HWSpinlock_Unlock(uint32_t LockID)
{
    HAL_ASSERT(IS_VALID_LOCKID(LockID));

    /* Release the lock by writing 0 to it */
    WRITE_REG(HWSPINLOCK[LockID], 0);
}

/**
 * @brief  HWSpinlock Get Owner API
 * @param  LockID: The Lock ID which get owner.
 * @return The current owner of the LockID.
 */
uint32_t HAL_HWSpinlock_GetOwner(uint32_t LockID)
{
    HAL_ASSERT(IS_VALID_LOCKID(LockID));

    return (HWSPINLOCK_STATUS_MASK & READ_REG(HWSPINLOCK[LockID]));
}

/** @} */

/** @} */

/** @} */

#endif /* HAL_HWSPINLOCK_MODULE_ENABLED */
