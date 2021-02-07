/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */

#include "hal_base.h"
#include "unity.h"
#include "unity_fixture.h"

#ifdef HAL_TIMER_MODULE_ENABLED

#ifndef PLL_INPUT_OSC_RATE
#define PLL_INPUT_OSC_RATE (24 * 1000 * 1000)
#endif

struct TIMER_REG *timerDev;
static uint32_t isrActive, timeOut;

static uint64_t TIMER_GetReloadNum(struct TIMER_REG *pReg)
{
    uint64_t loadCount = 0;

    loadCount = (((uint64_t)pReg->LOAD_COUNT[1]) << 32);
    loadCount |= (pReg->LOAD_COUNT[0] & 0xffffffff);

    return loadCount;
}

static HAL_Status TIMER_SetReloadNum(struct TIMER_REG *pReg, uint64_t currentVal)
{
    pReg->LOAD_COUNT[0] = (currentVal & 0xffffffff);
    pReg->LOAD_COUNT[1] = ((currentVal >> 32) & 0xffffffff);

    return HAL_OK;
}

static HAL_Status HAL_TIMER_Handler(void)
{
    if (HAL_TIMER_ClrInt(timerDev)) {
        timeOut++;
    }
    isrActive++;

    return HAL_OK;
}

TEST_GROUP(HAL_TIMER);

TEST_SETUP(HAL_TIMER){
}

TEST_TEAR_DOWN(HAL_TIMER){
    HAL_TIMER_DeInit(timerDev);
}

/* TIMER test case 0 */
TEST(HAL_TIMER, TimerInit){
    uint64_t ret, ret1;

    /* check config para */
    ret = HAL_TIMER_Init(timerDev, TIMER_FREE_RUNNING);
    TEST_ASSERT(ret == HAL_OK);
    ret = HAL_TIMER_Init(timerDev, TIMER_USER_DEFINED);
    TEST_ASSERT(ret == HAL_OK);

    /* test timer TIMER_FREE_RUNNING mode */
    HAL_DBG("test free running mode %d\n", __LINE__);
    HAL_DBG("test interrupt mask mode %d\n", __LINE__);
    HAL_TIMER_Init(timerDev, TIMER_FREE_RUNNING);
    HAL_TIMER_SetCount(timerDev, (uint64_t)PLL_INPUT_OSC_RATE / 1000); /* Ms count */
    HAL_TIMER_Start(timerDev);
    HAL_DelayMs(1000);
    ret = HAL_TIMER_GetCount(timerDev);
    if (!ret) {
        ret = HAL_TIMER_GetCount(timerDev); /* Avoiding Small Probability Events */
    }
    TEST_ASSERT(ret > 0);
    HAL_TIMER_Stop(timerDev);

    /* test timer TIMER_USER_DEFINED mode */
    HAL_DBG("test user defined mode %d\n", __LINE__);
    HAL_TIMER_Init(timerDev, TIMER_USER_DEFINED);
    HAL_TIMER_SetCount(timerDev, (uint64_t)PLL_INPUT_OSC_RATE / 1000); /* Ms count */
    HAL_TIMER_Start(timerDev);
    HAL_DelayMs(1000);
    ret = HAL_TIMER_GetCount(timerDev);
    TEST_ASSERT((ret == 0) || (ret == (uint64_t)PLL_INPUT_OSC_RATE / 1000));
    HAL_TIMER_Stop(timerDev);

    HAL_DBG("test set current value %d\n", __LINE__);
    ret = 0x5a5a5a5aa5a5a5a5;
    TIMER_SetReloadNum(timerDev, ret);
    ret1 = TIMER_GetReloadNum(timerDev);
    TEST_ASSERT(ret == ret1);
}

/* TIMER test case 1 */
TEST(HAL_TIMER, TimerSetCount){
    uint64_t loadCount = 0;

    /* test timer setcount */
    HAL_TIMER_Init(timerDev, TIMER_FREE_RUNNING);
    HAL_TIMER_SetCount(timerDev, (uint64_t)PLL_INPUT_OSC_RATE / 1000); /* Ms count */
    loadCount = TIMER_GetReloadNum(timerDev);
    TEST_ASSERT(loadCount == (uint64_t)PLL_INPUT_OSC_RATE / 1000);
    HAL_TIMER_Stop(timerDev);
}

/* TIMER test case 2 */
TEST(HAL_TIMER, TimerStartStop){
    uint32_t ret;

    /* test timerDev stop in normalc mode */
    HAL_TIMER_Init(timerDev, TIMER_FREE_RUNNING);
    HAL_TIMER_SetCount(timerDev, (uint64_t)PLL_INPUT_OSC_RATE / 1000); /* Ms count */
    HAL_TIMER_Start(timerDev);
    ret = HAL_TIMER_GetCount(timerDev);
    TEST_ASSERT(ret != HAL_TIMER_GetCount(timerDev)); /* test start*/
    HAL_TIMER_Stop(timerDev);
    ret = HAL_TIMER_GetCount(timerDev);
    TEST_ASSERT(ret == HAL_TIMER_GetCount(timerDev)); /* test stop*/

    /* test timerDev stop in IT mode */
    HAL_DBG("test interrupt unmask %d\n", __LINE__);
    isrActive = 0;
    timeOut = 0;
    HAL_TIMER_Init(timerDev, TIMER_FREE_RUNNING);
    HAL_TIMER_SetCount(timerDev, HAL_DivU64((uint64_t)PLL_INPUT_OSC_RATE, 1000)); /* Ms count */
    HAL_TIMER_Start_IT(timerDev);
    HAL_DelayMs(1000);
    ret = HAL_TIMER_GetCount(timerDev);
    TEST_ASSERT(ret != HAL_TIMER_GetCount(timerDev)); /* test start*/
    HAL_TIMER_Stop_IT(timerDev);
    ret = HAL_TIMER_GetCount(timerDev);
    TEST_ASSERT(ret == HAL_TIMER_GetCount(timerDev)); /* test stop*/
    HAL_DBG("TimerStartStop test %d isrActive %lu timeOut %lu\n", __LINE__, isrActive, timeOut);
    TEST_ASSERT(isrActive >= 1000 && isrActive <= 1005);
}

static void TIMER_TestLoop(int32_t num, struct TIMER_REG *t, IRQn_Type irq)
{
    timerDev = t;
    HAL_DBG("%s TIMER%ld\n", __func__, num);
#ifdef HAL_NVIC_MODULE_ENABLED
    HAL_NVIC_ConfigExtIRQ(irq, (NVIC_IRQHandler) & HAL_TIMER_Handler,
                          NVIC_PERIPH_PRIO_DEFAULT, NVIC_PERIPH_SUB_PRIO_DEFAULT);
#endif
    RUN_TEST_CASE(HAL_TIMER, TimerInit);
    RUN_TEST_CASE(HAL_TIMER, TimerSetCount);
    RUN_TEST_CASE(HAL_TIMER, TimerStartStop);
}

TEST_GROUP_RUNNER(HAL_TIMER){
    /* Choose test TIMER */
    TIMER_TestLoop(0, TIMER0, TIMER0_IRQn);
//    TIMER_TestLoop(1, TIMER1, TIMER1_IRQn);
//    TIMER_TestLoop(2, TIMER2, TIMER2_IRQn);
//    TIMER_TestLoop(3, TIMER3, TIMER3_IRQn);
//    TIMER_TestLoop(4, TIMER4, TIMER4_IRQn);
//    TIMER_TestLoop(5, TIMER5, TIMER5_IRQn);
//    TIMER_TestLoop(6, TIMER6, TIMER6_IRQn);
}

#endif
