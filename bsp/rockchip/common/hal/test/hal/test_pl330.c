/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */

#include "hal_bsp.h"
#include "hal_base.h"
#include "unity.h"
#include "unity_fixture.h"

#ifdef HAL_PL330_MODULE_ENABLED

#define TSIZE 64

static struct HAL_PL330_DEV *s_pl330;
static uint8_t *src;
static uint8_t *dst;

TEST_GROUP(HAL_PL330);

TEST_SETUP(HAL_PL330){
}

TEST_TEAR_DOWN(HAL_PL330){
}

static void HAL_PL330_Handler(void)
{
    HAL_PL330_IrqHandler(s_pl330);
}

static void MEMCPY_Callback(void *cparam)
{
    struct PL330_CHAN *pchan = cparam;
    uint32_t ret;

    TEST_ASSERT_EQUAL_MEMORY(src, dst, TSIZE);

    ret = HAL_PL330_Stop(pchan);
    TEST_ASSERT(ret == HAL_OK);

    ret = HAL_PL330_ReleaseChannel(pchan);
    TEST_ASSERT(ret == HAL_OK);
}

TEST(HAL_PL330, MemcpyTest){
    uint32_t ret, i;
    struct PL330_CHAN *pchan;

    for (i = 0; i < TSIZE; i++) {
        src[i] = i;
    }

    pchan = HAL_PL330_RequestChannel(s_pl330, (DMA_REQ_Type)0);
    TEST_ASSERT_NOT_NULL(pchan);

    ret = HAL_PL330_PrepDmaMemcpy(pchan, (uint32_t)&dst, (uint32_t)&src,
                                  TSIZE, MEMCPY_Callback, pchan);
    TEST_ASSERT(ret == HAL_OK);

    ret = HAL_PL330_Start(pchan);
    TEST_ASSERT(ret == HAL_OK);
}

TEST_GROUP_RUNNER(HAL_PL330){
    uint32_t ret;
    struct HAL_PL330_DEV *pl330 = &g_pl330Dev;

    ret = HAL_PL330_Init(pl330);
    TEST_ASSERT(ret == HAL_OK);

    s_pl330 = pl330;

    src = (uint8_t *)malloc(TSIZE);
    TEST_ASSERT_NOT_NULL(src);

    dst = (uint8_t *)malloc(TSIZE);
    TEST_ASSERT_NOT_NULL(dst);

    HAL_NVIC_SetIRQHandler(pl330->irq[0], (NVIC_IRQHandler) & HAL_PL330_Handler);
    HAL_NVIC_SetIRQHandler(pl330->irq[1], (NVIC_IRQHandler) & HAL_PL330_Handler);

    RUN_TEST_CASE(HAL_PL330, MemcpyTest);

    ret = HAL_PL330_DeInit(pl330);
    TEST_ASSERT(ret == HAL_OK);

    free(src);
    free(dst);
}

#endif
