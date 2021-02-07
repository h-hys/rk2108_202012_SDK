/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */

#include "hal_base.h"

#if defined(HAL_DCACHE_MODULE_ENABLED)

#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(HAL_DCACHE);

TEST_SETUP(HAL_DCACHE){
    HAL_DCACHE_Disable();
}

TEST_TEAR_DOWN(HAL_DCACHE){
    HAL_DCACHE_Disable();
    HAL_DCACHE_Enable();
}

/*-----------------------------------------------------------------------------
 *      Test implementation
 * Note: it must be compiled with -O0, otherwise the variable will be instead
 * with constant.
 *----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 *      Test cases
 *----------------------------------------------------------------------------*/

/*=======0=========1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1====*/
TEST(HAL_DCACHE, TC_DCache_InvalidateAll){
    /* setup */
    uint32_t value = 0x0815U;

    HAL_DCACHE_Enable();
    HAL_DCACHE_CleanInvalidate();

    /* test cached value gets lost */

    // WHEN a value is written
    value = 0x4711U;

    // ... and the cache is invalidated
    HAL_DCACHE_Invalidate();

    // ... and the cache is disabled
    HAL_DCACHE_Disable();

    // THEN the new value has been lost
    TEST_ASSERT(value == 0x0815U);

    /* tear down */
    __ISB();
}

/*=======0=========1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1====*/
TEST(HAL_DCACHE, TC_DCache_InvalidateByRange){
    /* setup */
    uint32_t value = 0x0815U;

    HAL_DCACHE_Enable();
    HAL_DCACHE_CleanInvalidate();

    /* test cached value is preserved */

    // WHEN a value is written
    value = 0x4711U;

    // ... and the cache is invalidated
    HAL_DCACHE_InvalidateByRange((uint32_t)&value, sizeof(value));

    // ... and the cache is disabled
    HAL_DCACHE_Disable();

    // THEN the new value has been lost
    TEST_ASSERT(value == 0x0815U);

    /* tear down */
    __ISB();
}

/*=======0=========1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1====*/
TEST(HAL_DCACHE, TC_DCache_CleanByRange){
    /* setup */
    uint32_t value = 0x0815U;

    HAL_DCACHE_Enable();
    HAL_DCACHE_CleanInvalidate();

    /* test cached value is preserved */

    // WHEN a value is written
    value = 0x4711U;

    // ... and the cache is clean
    HAL_DCACHE_CleanByRange((uint32_t)&value, sizeof(value));

    // ... and the cache is disabled
    HAL_DCACHE_Disable();

    // THEN the new value has been lost
    TEST_ASSERT(value == 0x4711U);

    /* tear down */
    __ISB();
}

TEST(HAL_DCACHE, TC_DCache_CleanInvalidateByRange){
    /* setup */
    uint32_t value = 0x0815U;

    HAL_DCACHE_Enable();
    HAL_DCACHE_CleanInvalidate();

    /* test cached value is preserved */

    // WHEN a value is written
    value = 0x4711U;

    // ... and the cache is clean
    HAL_DCACHE_CleanInvalidateByRange((uint32_t)&value, sizeof(value));

    // ... and the cache is disabled
    HAL_DCACHE_Disable();

    // THEN the new value has been lost
    TEST_ASSERT(value == 0x4711U);

    /* write to memory */
    value = 0x0815U;

    HAL_DCACHE_Enable();
    TEST_ASSERT(value == 0x0815U);

    /* tear down */
    __ISB();
}

TEST(HAL_DCACHE, TC_DCache_CleanInvalidate){
    /* setup */
    uint32_t value = 0x0815U;

    HAL_DCACHE_Enable();
    HAL_DCACHE_CleanInvalidate();

    /* test cached value is preserved */

    // WHEN a value is written
    value = 0x4711U;

    // ... and the cache is clean
    HAL_DCACHE_CleanInvalidate();

    // ... and the cache is disabled
    HAL_DCACHE_Disable();

    // THEN the new value has been lost
    TEST_ASSERT(value == 0x4711U);

    /* write to memory */
    value = 0x0815U;

    HAL_DCACHE_Enable();
    TEST_ASSERT(value == 0x0815U);

    /* tear down */
    __ISB();
}

TEST_GROUP_RUNNER(HAL_DCACHE){
    RUN_TEST_CASE(HAL_DCACHE, TC_DCache_InvalidateAll);
    RUN_TEST_CASE(HAL_DCACHE, TC_DCache_InvalidateByRange);
    RUN_TEST_CASE(HAL_DCACHE, TC_DCache_CleanByRange);
    RUN_TEST_CASE(HAL_DCACHE, TC_DCache_CleanInvalidateByRange);
    RUN_TEST_CASE(HAL_DCACHE, TC_DCache_CleanInvalidate);
}

#endif
