/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */
#include "hal_base.h"
#include "hal_bsp.h"
#include "unity.h"
#include "unity_fixture.h"

#ifdef HAL_HYPERPSRAM_MODULE_ENABLED
#include "test_hyperpsram.h"
#include "test_psram.h"
#include "test_hyper_cru.h"
TEST_GROUP(HAL_HYPERPSRAM);

TEST_SETUP(HAL_HYPERPSRAM){
}

TEST_TEAR_DOWN(HAL_HYPERPSRAM){
}

struct hyperbus_slt_test_list hyperbus_tests[] = {
    { "HYPERPSRAM controller test", HYPERPSRAM_CtrlTest },
    { "HYPERPSRAM cap confirm", HYPERPSRAM_CapConfirm },
    { "HYPERPSRAM memtester", PSRAM_Memtester },
    { "HYPERPSRAM march test", PSRAM_MarchCTest },
    { NULL, NULL }
};

static HAL_Status HYPERPSRAM_ModifyInit(void)
{
    g_hyperpsramDev.psramFreq = HAL_CRU_ClkGetFreq(g_hyperpsramDev.clkID) / 2;
    HAL_HYPERPSRAM_ModifyTiming(&g_hyperpsramDev);

    return HAL_OK;
}

static HAL_Status HYPERPSRAM_ReInit(void)
{
    if (HAL_HYPERPSRAM_ReInit(&g_hyperpsramDev) == HAL_OK) {
        HYPERPSRAM_ModifyInit();

        return HAL_OK;
    } else {
        return HAL_ERROR;
    }
}

static int test_early_init(void)
{
#ifdef HAL_ICACHE_MODULE_ENABLED
    HAL_ICACHE_Enable();
#endif
#ifdef HAL_DCACHE_MODULE_ENABLED
    HAL_DCACHE_Enable();
#endif
    HYPERPSRAM_FreqImprove(300);
    HYPERPSRAM_ReInit();

    return 0;
}

static int test_late_init(void)
{
#ifdef HAL_ICACHE_MODULE_ENABLED
    HAL_ICACHE_Disable();
#endif
#ifdef HAL_DCACHE_MODULE_ENABLED
    HAL_DCACHE_Disable();
#endif
    HYPERPSRAM_FreqRecover();
    HYPERPSRAM_ModifyInit();

    return 0;
}

HAL_Status HYPERPSRAM_CtrlTest(uint32_t start, uint32_t length)
{
    uint32_t i, ret = HAL_OK;
    uint32_t *test_addr = (uint32_t *)start;

    HYPERBUS->LBR = 1 << HYPERBUS_LBR_LOOPBACK_SHIFT;
    for (i = 128; i > 0; i--)
        *test_addr++ = PATTERN + i;
    for (i = 128; i > 0; i--, test_addr++) {
        if (*test_addr != PATTERN + i) {
            ret = HAL_ERROR;
            goto out;
        }
    }
out:
    HYPERBUS->LBR = 0 << HYPERBUS_LBR_LOOPBACK_SHIFT;

    return ret;
}

HAL_Status HYPERPSRAM_CapConfirm(uint32_t start, uint32_t length)
{
    uint32_t *p1 = (uint32_t *)start;
    uint32_t *test_addr = (uint32_t *)start;

    *test_addr = 0x0;
    test_addr += length / sizeof(uint32_t);
    *test_addr = PATTERN;

#ifdef HAL_DCACHE_MODULE_ENABLED
    HAL_DCACHE_CleanInvalidate();
#endif
    if (!((*p1 == 0x0) && (*test_addr == PATTERN))) {
        test_addr -= 1;
        *test_addr = PATTERN;
    #ifdef HAL_DCACHE_MODULE_ENABLED
        HAL_DCACHE_CleanInvalidate();
    #endif
        if ((*p1 == 0x0) && (*test_addr == PATTERN))
            return HAL_OK;
    }

    return HAL_ERROR;
}

TEST(HAL_HYPERPSRAM, HYPERPSRAM_Test) {
    uint32_t i, ret;
    uint32_t start = CONFIG_PSRAM_BASE0;
    uint32_t length = SIZE_8M;

    for (i = 0;; i++) {
    #ifdef HAL_DCACHE_MODULE_ENABLED
        HAL_DCACHE_CleanInvalidate();
    #endif
        if (!hyperbus_tests[i].name)
            break;
        HAL_DBG("  %s: \n", hyperbus_tests[i].name);
        ret = hyperbus_tests[i].fp(start, length);
        if (!ret) {
            HAL_DBG("    ok\n");
        } else {
            HAL_DBG("    fail %s\n", hyperbus_tests[i].name);
            HAL_DBG("test done. result fail.%lx\n", ret);

            return;
        }
    }
    HAL_DBG("test done. result pass.\n");
}

TEST_GROUP_RUNNER(HAL_HYPERPSRAM) {
    test_early_init();

    RUN_TEST_CASE(HAL_HYPERPSRAM, HYPERPSRAM_Test);

    test_late_init();
}

#endif
