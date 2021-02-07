/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */

#include "hal_base.h"
#include "unity.h"
#include "unity_fixture.h"

#if defined(HAL_CRU_MODULE_ENABLED) && (defined(RKMCU_PISCES) || defined(RKMCU_RK2108))

HAL_UNUSED static uint32_t isrActive;

TEST_GROUP(HAL_CRU);

TEST_SETUP(HAL_CRU){
    isrActive = 0;
}

TEST_TEAR_DOWN(HAL_CRU){
}

/* CRU test case 0 */
TEST(HAL_CRU, ClkRate){
    uint32_t ret, oldRate, newRate;

    /* set pll freq */
    oldRate = HAL_CRU_ClkGetFreq(PLL_GPLL);
    ret = HAL_CRU_ClkSetFreq(PLL_GPLL, 1008000000);
    TEST_ASSERT(ret == HAL_OK);
    newRate = HAL_CRU_ClkGetFreq(PLL_GPLL);
    TEST_ASSERT(newRate == 1008000000);
    ret = HAL_CRU_ClkSetFreq(PLL_GPLL, oldRate);
    TEST_ASSERT(ret == HAL_OK);

    /* set i2s frac freq */
    oldRate = HAL_CRU_ClkGetFreq(I2S_MCLKOUT);
    ret = HAL_CRU_ClkSetFreq(I2S_MCLKOUT, 11289600);
    TEST_ASSERT(ret == HAL_OK);
    newRate = HAL_CRU_ClkGetFreq(I2S_MCLKOUT);
    TEST_ASSERT(newRate == 11289600);

    /* set aclk dsp freq */
    oldRate = HAL_CRU_ClkGetFreq(ACLK_DSP);
    ret = HAL_CRU_ClkSetFreq(ACLK_DSP, 200000000);
    TEST_ASSERT(ret == HAL_OK);
    newRate = HAL_CRU_ClkGetFreq(ACLK_DSP);
    TEST_ASSERT(newRate == 200000000);
}

/* CRU test case 1 */
TEST(HAL_CRU, ClkGate){
    uint32_t ret;

    ret = HAL_CRU_ClkDisable(PCLK_I2C0_GATE);
    ret = HAL_CRU_ClkIsEnabled(PCLK_I2C0_GATE);
    TEST_ASSERT(ret == HAL_FALSE);
    ret = HAL_CRU_ClkEnable(PCLK_I2C0_GATE);
    ret = HAL_CRU_ClkIsEnabled(PCLK_I2C0_GATE);
    TEST_ASSERT(ret == HAL_TRUE);
}

/* CRU test case 2 */
TEST(HAL_CRU, ClkReset){
    uint32_t ret;

    ret = HAL_CRU_ClkResetAssert(SRST_I2C0);
    ret = HAL_CRU_ClkIsReset(SRST_I2C0);
    TEST_ASSERT(ret == HAL_TRUE);
    ret = HAL_CRU_ClkResetDeassert(SRST_I2C0);
    ret = HAL_CRU_ClkIsReset(SRST_I2C0);
    TEST_ASSERT(ret == HAL_FALSE);
}

TEST_GROUP_RUNNER(HAL_CRU){
    RUN_TEST_CASE(HAL_CRU, ClkRate);
    RUN_TEST_CASE(HAL_CRU, ClkGate);
    RUN_TEST_CASE(HAL_CRU, ClkReset);
}

#endif
