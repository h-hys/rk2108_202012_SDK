/*
 * Copyright (c) 2019 Rockchip Electronics Co. Ltd.
 * Author: Huaping Liao <huaping.liao@rock-chips.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <xtensa/core-macros.h>
#include <xtensa/tie/xt_interrupt.h>

#include "cache.h"
#include "delay.h"
#include "io.h"
#include "intc.h"
#include "mailbox.h"
#include "section.h"
#include "timer.h"
#include "typedef.h"
#include "trace.h"
#include "uart.h"
#include "pm.h"
#include "wdt.h"

#if !CONFIG_ENABLE_XIP

#define ITCM_TEST_OFFSET        0x5000
#define DTCM_TEST_OFFSET        0x1000
#if CONFIG_SOC_RK2108
#define CACHE_TEST_BASE         0x20080000
#elif CONFIG_SOC_RK2206
#define CACHE_TEST_BASE         0x20034000
#endif
#define CACHE_SIZE_STEP         1024
#define CACHE_SIZE              16 * 1024
#define VECTOR_SIZE             (2 * 1024)
/*
 * Test data need in shrare memory,
 * if test data in dtcm, will no work.
 */

char *a_vector = (char *)CACHE_TEST_BASE;
char *b_vector = (char *)CACHE_TEST_BASE + VECTOR_SIZE;

#define DEBUG_LOG(ret)  LOGD("%s:%d test: %s\n", __func__, __LINE__, ret ? "fail" : "success");
#define SLT_SUCCESS        0
#define SLT_ERROR_CACHE    0x60000001

__sys__ uint32_t dcache_invalidate_all(uint32_t *value)
{
    /* setup */
    uint32_t ret = SLT_SUCCESS;
    *value = 0x0815U;

    xthal_clear_regcached_code();
    cache_enable();
    xthal_dcache_all_writeback_inv();
    xthal_clear_regcached_code();
    /* test cached value gets lost */

    // WHEN a value is written
    *value = 0x4711U;

    // ... and the cache is invalidated
    xthal_dcache_all_invalidate();

    // ... and the cache is disabled
    cache_disable();

    // THEN the new value has been lost
    xthal_clear_regcached_code();
    if (*value != 0x0815U)
        ret = SLT_ERROR_CACHE;

    /* tear down */
    DEBUG_LOG(ret);
    return ret;
}


__sys__ uint32_t dcache_invalidate_byaddr(uint32_t *value)
{
    /* setup */
    uint32_t ret = SLT_SUCCESS;
    *value = 0x0815U;

    cache_enable();
    xthal_dcache_all_writeback_inv();

    /* test cached value is preserved */

    // WHEN a value is written
    *value = 0x4711U;

    // ... and the cache is invalidated
    xthal_dcache_region_invalidate((void *)value, sizeof(uint32_t));

    // ... and the cache is disabled
    cache_disable();

    // THEN the new value has been lost
    xthal_clear_regcached_code();
    if (*value != 0x0815U)
        ret = SLT_ERROR_CACHE;

    /* tear down */
    xthal_clear_regcached_code();
    DEBUG_LOG(ret);
    return ret;
}

__sys__ uint32_t dcache_writeback_byaddr(uint32_t *value)
{
    /* setup */
    uint32_t ret = SLT_SUCCESS;
    *value = 0x0815U;

    cache_enable();
    xthal_dcache_all_writeback_inv();

    /* test cached value is preserved */

    // WHEN a value is written
    *value = 0x4711U;

    // ... and the cache is clean
    xthal_dcache_region_writeback((void *)value, sizeof(uint32_t));

    // ... and the cache is disabled
    cache_disable();

    // THEN the new value has been lost
    xthal_clear_regcached_code();
    if (*value != 0x4711U)
        ret = SLT_ERROR_CACHE;
    /* tear down */
    xthal_clear_regcached_code();

    DEBUG_LOG(ret);
    return ret;
}

__sys__ uint32_t dcache_writeback_inv_byaddr(uint32_t *value)
{
    /* setup */
    uint32_t ret = SLT_SUCCESS;
    *value = 0x0815U;

    cache_enable();
    xthal_dcache_all_writeback_inv();

    /* test cached value is preserved */

    // WHEN a value is written
    *value = 0x4711U;

    // ... and the cache is clean
    xthal_dcache_region_writeback_inv((void *)value, sizeof(value));

    // ... and the cache is disabled
    cache_disable();

    // THEN the new value has been lost
    if (*value != 0x4711U) {
        ret = SLT_ERROR_CACHE;
        DEBUG_LOG(ret);
        return ret;
    }

    /* write to memory */
    *value = 0x0815U;

    cache_disable();
    if (*value != 0x0815U)
        ret = SLT_ERROR_CACHE;
    /* tear down */
    xthal_clear_regcached_code();

    DEBUG_LOG(ret);
    return ret;
}

__sys__ uint32_t dcache_writeback_inv_all(uint32_t *value)
{
    /* setup */
    uint32_t ret = SLT_SUCCESS;
    *value = 0x0815U;

    cache_enable();
    xthal_dcache_all_writeback_inv();

    /* test cached value is preserved */

    // WHEN a value is written
    *value = 0x4711U;

    // ... and the cache is clean
    xthal_dcache_all_writeback_inv();

    // ... and the cache is disabled
    cache_disable();

    // THEN the new value has been lost
    if (*value != 0x4711U)
        ret = SLT_ERROR_CACHE;

    /* write to memory */
    *value = 0x0815U;

    cache_enable();
    if (*value != 0x0815U)
        ret = SLT_ERROR_CACHE;
    /* tear down */
    xthal_clear_regcached_code();

    DEBUG_LOG(ret);
    return ret;
}

__sys__ uint32_t dcache_test(void)
{
    uint32_t ret = SLT_SUCCESS;

    cache_disable();

    ret = dcache_invalidate_all((uint32_t *)CACHE_TEST_BASE);
    if (ret)
        return ret;

    ret = dcache_invalidate_byaddr((uint32_t *)CACHE_TEST_BASE);
    if (ret)
        return ret;

    ret = dcache_writeback_byaddr((uint32_t *)CACHE_TEST_BASE);
    if (ret)
        return ret;

    ret = dcache_writeback_inv_byaddr((uint32_t *)CACHE_TEST_BASE);
    if (ret)
        return ret;

    ret = dcache_writeback_inv_all((uint32_t *)CACHE_TEST_BASE);
    if (ret)
        return ret;

    cache_enable();
}

/* Test memory */
__sys__ int memory_offset_test(uint32_t addr, uint32_t size, int32_t offset)
{
    int ret = 0;
    unsigned int value;
    unsigned int i;

    for (i = 0; i < size; i += 4) {
        value = readl(addr + i);
        if (value != (addr + i + offset)) {
            ret = -1;
            break;
        }
    }
    if (ret) {
        LOGD("memory_offset_test addr: %x fail\n", addr + i);
    } else {
        LOGD("memory_offset_test add: %x success\n", addr);
    }
    return ret;
}

__sys__ void tcm_sel_test()
{
    memory_offset_test(ITCM_BASE + ITCM_TEST_OFFSET, ITCM_SIZE - ITCM_TEST_OFFSET, 0x20400000 - ITCM_BASE);
    memory_offset_test(DTCM_BASE + ITCM_TEST_OFFSET, BLOCK_SIZE - ITCM_TEST_OFFSET, 0x20600000 - DTCM_BASE);
    memory_offset_test(DTCM_BASE + BLOCK_SIZE, BLOCK_SIZE, 0x20600000 - DTCM_BASE);
    memory_offset_test(DTCM_BASE + BLOCK_SIZE * 2, BLOCK_SIZE, 0x20600000 - DTCM_BASE);
}

/* Test read memory */
__sys__ int memory_read_test(uint32_t addr, uint32_t size)
{
    int ret = 0;
    unsigned int i;

    for (i = 0; i < size; i += 4)
        if ((readl(addr + i)) != (addr + i)) {
            ret = -1;
            break;
        }
    LOGD("memory_read_test : %s, addr=%x\n", ret ? "fail" : "success", addr + i);
    return ret;
}

/* Test memory */
__sys__ int memory_test(uint32_t addr, uint32_t size)
{
    int ret = 0;
    unsigned int i;

    for (i = 0; i < size; i += 4)
        writel(addr + i, addr + i);

    for (i = 0; i < size; i += 4)
        if ((readl(addr + i)) != (addr + i))
            ret = -1;

    return ret;
}

__sys__ void dcache_size_cost(uint32_t addr, uint32_t size)
{
    uint32_t i, val;
    volatile uint32_t tmp;
    clock_t start, end, cost;

    cache_enable();
    for (i = 0; i < size; i += 4)
        writel(addr + i, addr + i);
    start = clock();
    for (i = 0; i < size; i += 8) {
        tmp = addr + rand() % size;
        val = readl(ALIGN(tmp, 4));
    }
    end = clock();
    cost = end - start;
    LOGD("size = %d, cost = %d\n", size, cost);
}

__sys__ void dcache_size_test()
{
    cache_enable();
    xthal_dcache_all_invalidate();
    dcache_size_cost(CACHE_TEST_BASE, CACHE_SIZE - 2 * CACHE_SIZE_STEP);
    xthal_dcache_all_invalidate();
    dcache_size_cost(CACHE_TEST_BASE, CACHE_SIZE - CACHE_SIZE_STEP);
    xthal_dcache_all_invalidate();
    dcache_size_cost(CACHE_TEST_BASE, CACHE_SIZE);
    xthal_dcache_all_invalidate();
    dcache_size_cost(CACHE_TEST_BASE, CACHE_SIZE + CACHE_SIZE_STEP);
    xthal_dcache_all_invalidate();
    dcache_size_cost(CACHE_TEST_BASE, CACHE_SIZE + 2 * CACHE_SIZE_STEP);
    cache_disable();
}


/* Cache test */
__sys__ clock_t memcpy_test(int size_num)
{
	char *a_vector = (char *)CACHE_TEST_BASE;
	char *b_vector = (char *)CACHE_TEST_BASE + VECTOR_SIZE;

    clock_t clock_start, clock_end, clock_task;

    clock_start = clock();
    memcpy(b_vector + size_num * VECTOR_SIZE, a_vector + size_num * VECTOR_SIZE,
           VECTOR_SIZE);
    clock_end = clock();
    clock_task = clock_end - clock_start;
    return clock_task;
}

/* Share memory test */
__sys__ int shrm_test(void)
{
    int ret;
    ret = memory_test(SHRM_BASE, SHRM_SIZE);
    LOGD("shrm test: %s\n", ret ? "fail" : "success");
    return ret;
}

__sys__ int cache_shrm_test()
{
    int ret;
    clock_t no_cache, have_cache;

    /* Cache data test */
    xthal_dcache_all_writeback_inv();
    cache_disable();
    no_cache = memcpy_test(0);
    cache_enable();
    have_cache = memcpy_test(1);
    ret = have_cache < no_cache ? 0 : -1;
    LOGD("dcache test: %s\n", ret ? "fail" : "success");
}

__sys__ int dtcm_test(void)
{
    int ret;
    /* Reserved space for setcion, need use model_test map */
    ret = memory_test(DTCM_BASE + DTCM_TEST_OFFSET,
                      DTCM_SIZE - DTCM_TEST_OFFSET);
    LOGD("dtcm test: %s\n", ret ? "fail" : "success");
    return ret;
}

__sys__ int itcm_test(void)
{
    int ret;
    /* Reserved space for setcion, need use model_test map */
    ret = memory_test(ITCM_BASE + ITCM_TEST_OFFSET,
                      ITCM_SIZE - ITCM_TEST_OFFSET);
    LOGD("itcm test :%s\n", ret ? "fail" : "success");
    return ret;
}

__sys__ int mbox_receive_data(struct mbox_client *client, uint32_t cmd,
                                uint32_t data)
{
    LOGD("receive, id = %d, chan = %d, cmd = %x, data = %x\n",
            client->id, client->chan, cmd, data);
}

struct mbox_client g_mbox_client[MBOX_CHAN_MAX] =
{
    {MBOX_ID, MBOX_CHAN_0, &mbox_receive_data},
    {MBOX_ID, MBOX_CHAN_1, &mbox_receive_data},
    {MBOX_ID, MBOX_CHAN_2, &mbox_receive_data},
    {MBOX_ID, MBOX_CHAN_3, &mbox_receive_data},
};

__sys__ int mbox_test(void)
{
    intc_init();
    mbox_init(MBOX_ID);

    for (int chan = 0; chan < MBOX_CHAN_MAX; chan++)
        mbox_register_client(&g_mbox_client[chan]);

    while (1) {
        mbox_send_data(MBOX_ID, 1, DSP_CMD_READY, 0xaaaaaaaa + 1);
        mdelay(10);
        mbox_send_data(MBOX_ID, 1, DSP_CMD_CONFIG_DONE, 0xaaaaaaaa + 2);
        mdelay(10);
        mbox_send_data(MBOX_ID, 0, DSP_CMD_WORK_DONE, 0xaaaaaaaa + 3);
        mdelay(10);
        mbox_send_data(MBOX_ID, 3, DSP_CMD_TRACE, 0xaaaaaaaa + 4);
        mdelay(10);
        mbox_send_data(MBOX_ID, 2, DSP_CMD_STARTUP, 0xaaaaaaaa + 5);
        mdelay(10);
    }
    LOGD("mailbox test success\n");
}

__sys__ void uart_test(void)
{
    //uart_init();
    /* LOGD output to uart */
    LOGD("dsp test uart, func = %s, line = %d\n", __func__, __LINE__);
}

__sys__ void clock_test()
{
    int utime = 1000, mtime = 1000;
    LOGD("udelay before\n");
    udelay(utime);
    LOGD("udelay %d Us after\n", utime);

    LOGD("mdelay before\n");
    mdelay(mtime);
    LOGD("mdelay %d Ms after\n", mtime);

    LOGD("mdelay before\n");
    mdelay(2 * mtime);
    LOGD("mdelay %d Ms after\n", 2 * mtime);

    LOGD("mdelay before\n");
    mdelay(3 * mtime);
    LOGD("mdelay %d Ms after\n", 3 * mtime);
}

#define TIMEOUT (100000)
__sys__ static int timeout_handler(void *params)
{
    LOGD("timer to timeout\n");
    return 0;
}

__sys__ void timer_test()
{
    timer_init();
    timer_start(TIMEOUT, TIMER_PERIODIC, timeout_handler, 0);
    for (int i = 0; i < 10; i++) {
        udelay(TIMEOUT);
        LOGD("delay to timeout i= %d\n", i);
    }
    timer_stop();
    timer_deinit();

    intc_init();
    sys_timer_init();
    sys_timer_start(TIMEOUT, TIMER_PERIODIC, timeout_handler, 0);
    for (int i = 0; i < 10; i++) {
        udelay(TIMEOUT);
        LOGD("sys delay to timeout i= %d\n", i);
    }
    sys_timer_stop();
    sys_timer_deinit();
}

#if CONFIG_SOC_RK2108
int *test_flag = (int *)0x30230000;
int *test_num = (int *)0x30230004;
#define FLAG (0x5555aaab)
/* Test pwaitmode */
__sys__ void power_test()
{
    int ret;
    pm_get_wakeup_status();
    intc_init();
    mbox_init(MBOX_ID);

    for (int chan = 0; chan < MBOX_CHAN_MAX; chan++)
        mbox_register_client(&g_mbox_client[chan]);

    pm_pwrdown_config();
    pm_pwrdown_enable(true);
    while(1) {
        mdelay(1000);
        LOGD("sleep now\n");
        pm_sleep(SLEEP_NOR);
        LOGD("wake up now\n");
    }
}
#endif

/* */
void wdt_test_callback(uint32_t data)
{
    LOGD("wdt test callback\n");
}

__sys__ void wdt_test()
{
	intc_init();
    LOGD("enter wdt test\n");
    wdt_init(INDIRECT_SYS_RESET, wdt_test_callback);
    wdt_timeout_set(2);
    wdt_start(GLB_RST_FST_WDT);
    LOGD("end wdt test\n");
    while(1);
}

/* Test runstall */
__sys__ void run_test()
{
    while(1) {
        mdelay(3000);
        LOGD("test now\n")
    }
}

__sys__ void sleep_test()
{
    while (1) {
        mdelay(3000);
        timer_init();
        timer_start(10 * 1000 * 1000, TIMER_PERIODIC, timeout_handler, 0);
        LOGD("sleep now\n");
        pm_sleep(SLEEP_NOR);
        LOGD("wakeup now\n");
    }
}

__sys__ void pfatalerror_test()
{
    int a = XT_RSR_PS();
    int *ptr= (int *)0x11111111;
    a=a|0x10;
    XT_WSR_PS(a);
    *ptr = 0x9;
}

__sys__ void model_test()
{
    uart_test();
  //  pfatalerror_test();
  //  clock_test();
//    timer_test();
   // sleep_test();
 //   run_test();
//    wdt_test();
//    power_test();

//    cache_shrm_test();
//    dcache_test();
//    dcache_size_test();
//
    dtcm_test(); /* Need use model_test map */
    itcm_test(); /* Need use model_test map */

//#if CONFIG_SOC_RK2206
//    tcm_sel_test();
//#endif
    while(1);
   // mbox_test();
    /* If run this function, cm4 will crash */
    shrm_test();
}

#endif
