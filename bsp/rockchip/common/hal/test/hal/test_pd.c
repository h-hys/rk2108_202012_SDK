/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */

#include "hal_base.h"
#include "unity.h"
#include "unity_fixture.h"

#if defined(HAL_PMU_MODULE_ENABLED) && (defined(RKMCU_PISCES) || defined(RKMCU_RK2108))

HAL_UNUSED static uint32_t isrActive;

TEST_GROUP(HAL_PD);

TEST_SETUP(HAL_PD){
    isrActive = 0;
}

TEST_TEAR_DOWN(HAL_PD){
}

/* PD test case 0 */
TEST(HAL_PD, PdPowerOff){
    uint32_t ret;

    /* check config para */
    ret = HAL_PD_Off(PD_AUDIO);
    TEST_ASSERT(ret == HAL_OK);
}

/* PD test case 1 */
TEST(HAL_PD, PdPowerOn){
    uint32_t ret;

    /* check config para */
    ret = HAL_PD_On(PD_AUDIO);
    TEST_ASSERT(ret == HAL_OK);
}

TEST_GROUP_RUNNER(HAL_PD){
    RUN_TEST_CASE(HAL_PD, PdPowerOn);
    RUN_TEST_CASE(HAL_PD, PdPowerOff);
    RUN_TEST_CASE(HAL_PD, PdPowerOn);
}

#endif
