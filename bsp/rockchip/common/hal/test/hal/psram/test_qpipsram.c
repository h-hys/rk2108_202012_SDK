/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */

#include "hal_base.h"
#include "hal_bsp.h"
#include "unity.h"
#include "unity_fixture.h"

#ifdef HAL_QPIPSRAM_MODULE_ENABLED
static struct QPI_PSRAM *psram;
#define maxest_sector 1
static uint8_t *pwrite;
static uint32_t *pread32;
static uint32_t *pwrite32;

TEST_GROUP(HAL_QPIPSRAM);

TEST_SETUP(HAL_QPIPSRAM){
}

TEST_TEAR_DOWN(HAL_QPIPSRAM){
}

static HAL_Status QPIPSRAM_TEST(uint32_t testEndLBA)
{
    uint32_t i, j;
    uint32_t testLBA = 0;
    uint32_t testSecCount = 1;
    uint32_t printFlag;
    struct HAL_FSPI_HOST *host = (struct HAL_FSPI_HOST *)psram->spi->userdata;

    pwrite32 = (uint32_t *)pwrite;

    HAL_DBG("---------Test PSRAM STRESS TEST---------\n");
    HAL_DBG("---------Test ftl write---------\n");
    testSecCount = 1;
    HAL_DBG("testEndLBA = %lx\n", testEndLBA);
    HAL_DBG("testLBA = %lx\n", testLBA);
    for (testLBA = 0; (testLBA + testSecCount) < testEndLBA;) {
        pwrite32[0] = testLBA;
        pread32 = (uint32_t *)(host->xipMemData + testLBA * 512);
        for (i = 0; i < (maxest_sector * 128); i++) {
            pread32[i] = pwrite32[i];
        }
        for (j = 0; j < testSecCount * 128; j++) {
            if (pwrite32[j] != pread32[j]) {
                HAL_DBG_HEX("w:", pwrite32, 4, testSecCount * 128);
                HAL_DBG_HEX("r:", pread32, 4, testSecCount * 128);
                HAL_DBG(
                    "check not match:row=%lx, num=%lx, write=%lx, read=%lx\n",
                    testLBA, j, (uint32_t)pwrite32[j], (uint32_t)pread32[j]);
                while (1) {
                    ;
                }
            }
        }
        printFlag = testLBA & 0x1FF;
        if (printFlag < testSecCount) {
            HAL_DBG("testLBA = %lx\n", testLBA);
        }
        testLBA += testSecCount;
        testSecCount++;
        if (testSecCount > maxest_sector) {
            testSecCount = 1;
        }
    }
    HAL_DBG("---------Test ftl check---------\n");

    testSecCount = 1;
    for (testLBA = 0; (testLBA + testSecCount) < testEndLBA;) {
        pwrite32[0] = testLBA;
        pread32 = (uint32_t *)(host->xipMemData + testLBA * 512);
        for (j = 0; j < testSecCount * 128; j++) {
            if (pwrite32[j] != pread32[j]) {
                HAL_DBG_HEX("w:", pwrite32, 4, testSecCount * 128);
                HAL_DBG_HEX("r:", pread32, 4, testSecCount * 128);
                HAL_DBG(
                    "recheck not match:row=%lx, num=%lx, write=%lx, read=%lx\n",
                    testLBA, j, (uint32_t)pread32[j], (uint32_t)pread32[j]);
                while (1) {
                    ;
                }
            }
        }
        printFlag = testLBA & 0x1FF;
        if (printFlag < testSecCount) {
            HAL_DBG("testLBA = %lx\n", testLBA);
        }
        testLBA += testSecCount;
        testSecCount++;
        if (testSecCount > maxest_sector) {
            testSecCount = 1;
        }
    }
    HAL_DBG("---------Test end---------\n");

    return HAL_OK;
}

/* PSRAM test case 0 */
TEST(HAL_QPIPSRAM, PsramStressTest){
    uint32_t ret;

    HAL_QPIPSRAM_XIPEnable(psram);
    ret = QPIPSRAM_TEST(0x1000);
    HAL_QPIPSRAM_XIPDisable(psram);
    TEST_ASSERT(ret == HAL_OK);
}

static uint8_t *AlignUp(uint8_t *ptr, int32_t align)
{
    return (uint8_t *)(((uintptr_t)ptr + align - 1) & ~(uintptr_t)(align - 1));
}

static HAL_Status SPI_Xfer(struct QPIPSRAM_HOST *spi, struct HAL_SPI_MEM_OP *op)
{
    struct HAL_FSPI_HOST *host = (struct HAL_FSPI_HOST *)spi->userdata;

    host->mode = spi->mode;
    host->cs = 0;

    return HAL_FSPI_SpiXfer(host, op);
}

static HAL_Status SPI_XipConfig(struct QPIPSRAM_HOST *spi, struct HAL_SPI_MEM_OP *op, uint32_t on)
{
    struct HAL_FSPI_HOST *host = (struct HAL_FSPI_HOST *)spi->userdata;

    host->cs = 0;
    if (op) {
        host->xmmcDev[0].type = DEV_PSRAM;
        HAL_FSPI_XmmcSetting(host, op);
    }

    return HAL_FSPI_XmmcRequest(host, on);
}

static HAL_Status QPIPSRAM_Adapt(void)
{
    struct HAL_FSPI_HOST *host;
    HAL_Status ret;

    /* Designated host to SPI PSRAM */
#ifdef FSPI1
    if (g_fspi1Dev.xmmcDev[0].type == DEV_PSRAM) {
        host = &g_fspi1Dev;
    }
#elif FSPI0
    else if (g_fspi0Dev.xmmcDev[0].type == DEV_PSRAM) {
        host = &g_fspi0Dev;
    }
#endif
    HAL_FSPI_Init(host);
    psram->spi->userdata = (void *)host;
    psram->spi->mode = HAL_SPI_MODE_3 | HAL_SPI_TX_QUAD | HAL_SPI_RX_QUAD;
    psram->spi->xfer = SPI_Xfer;
    psram->spi->xipConfig = SPI_XipConfig;

    /* Init SPI psram abstract */
    ret = HAL_QPIPSRAM_Init(psram);

    return ret;
}

/* Test code should be place in ram */
TEST_GROUP_RUNNER(HAL_QPIPSRAM){
    struct QPIPSRAM_HOST *spi;
    uint32_t ret;
    uint8_t *pwrite_t;

    /* Config test buffer */
    pwrite_t = (uint8_t *)malloc(maxest_sector * 4096 + 64);
    pwrite = AlignUp(pwrite_t, 64);
    pwrite32 = (uint32_t *)pwrite;
    HAL_DBG("pwrite %p %p\n", pwrite, pwrite32);

    for (int32_t i = 0; i < (maxest_sector * 1024); i++) {
        pwrite32[i] = i;
    }

    spi = (struct QPIPSRAM_HOST *)calloc(1, sizeof(struct QPIPSRAM_HOST));
    TEST_ASSERT_NOT_NULL(spi);
    psram = (struct QPI_PSRAM *)calloc(1, sizeof(struct QPI_PSRAM));
    TEST_ASSERT_NOT_NULL(psram);
    psram->spi = spi;

    ret = QPIPSRAM_Adapt();
    TEST_ASSERT(ret == HAL_OK);

    RUN_TEST_CASE(HAL_QPIPSRAM, PsramStressTest);

    /* PSRAM deinit */
    ret = HAL_QPIPSRAM_DeInit(psram);
    TEST_ASSERT(ret == HAL_OK);

    free(pwrite_t);
    free(psram->spi);
    free(psram);
}
#endif
