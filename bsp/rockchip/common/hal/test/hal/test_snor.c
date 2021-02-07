/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */

#include "hal_bsp.h"
#include "hal_base.h"
#include "unity.h"
#include "unity_fixture.h"

#ifdef HAL_SNOR_MODULE_ENABLED

struct SPI_NOR nor_buf;
struct SNOR_HOST nor_spi_buf;
struct SPI_NOR *nor;
#define maxest_sector 4
static uint8_t *pwrite;
static uint8_t *pread;
static uint32_t *pread32;
static uint32_t *pwrite32;
#define FLASH_SKIP_LBA 0x200 /* About 1M space skip */

static uint8_t *AlignUp(uint8_t *ptr, int32_t align)
{
    return (uint8_t *)(((uintptr_t)ptr + align - 1) & ~(uintptr_t)(align - 1));
}

static HAL_Status SNOR_SINGLE_TEST(void)
{
    uint32_t testLba = FLASH_SKIP_LBA;

    pwrite32[0] = testLba;
    HAL_SNOR_Erase(nor, testLba << 9, ERASE_SECTOR);
    HAL_SNOR_ProgData(nor, testLba << 9, pwrite32, 0x1000);
    memset(pread, 0, 256);
    memset(pread32, 0, 0x1000);
    HAL_DBG("%lx\n", (uint32_t)pread32);
    for (int i = 0; i < 1024; i++) {
#ifdef HAL_FSPI_DMA_ENABLED
        HAL_DCACHE_InvalidateByRange((uint32_t)pread32, 0x1000);
#endif
        HAL_SNOR_ReadData(nor, testLba << 9, pread32, 0x1000);
    }

    for (int32_t i = 0; i < (0x1000 / 4); i++) {
        if (pwrite32[i] != pread32[i]) {
            HAL_DBG_HEX("w", pwrite32, 4, 0x400);
            HAL_DBG_HEX("r", pread32, 4, 0x400);
            HAL_DBG("check not match:row=%lx, num=%lx, write=%lx, read=%lx %lx %lx %lx\n",
                    testLba, i, pwrite32[i], pread32[i], pread32[i + 1], pread32[i + 2], pread32[i - 1]);
            HAL_DBG("SNOR Single test fail\n");
            while (1) {
                ;
            }
        }
    }
    HAL_DBG("SNOR Single test success\n");

    return HAL_OK;
}

static HAL_Status SNOR_STRESS_RANDOM_TEST(uint32_t testEndLBA)
{
    int32_t ret, j;
    uint32_t testCount, testLBA;
    int32_t testSecCount = 1;

    HAL_DBG("---------%s %lx---------\n", __func__, testEndLBA);
    HAL_DBG("---------%s---------\n", __func__);
    for (testCount = 0; testCount < testEndLBA;) {
        testLBA = (uint32_t)rand() % testEndLBA;
        if (testLBA < FLASH_SKIP_LBA) {
            continue;
        }
        pwrite32[0] = testLBA;
        ret = HAL_SNOR_OverWrite(nor, testLBA, testSecCount, pwrite32);
        if (ret != testSecCount) {
            return HAL_ERROR;
        }
        pread32[0] = -1;
        #ifdef HAL_FSPI_DMA_ENABLED
        HAL_DCACHE_InvalidateByRange((uint32_t)pread32, 0x1000);
        #endif
        ret = HAL_SNOR_Read(nor, testLBA, testSecCount, pread32);
        if (ret != testSecCount) {
            return HAL_ERROR;
        }
        for (j = 0; j < testSecCount * (int32_t)nor->sectorSize / 4; j++) {
            if (pwrite32[j] != pread32[j]) {
                HAL_DBG_HEX("w:", pwrite32, 4, 16);
                HAL_DBG_HEX("r:", pread32, 4, 16);
                HAL_DBG(
                    "check not match:row=%lx, num=%lx, write=%lx, read=%lx %lx %lx %lx\n",
                    testLBA, j, pwrite32[j], pread32[j], pread32[j + 1], pread32[j + 2], pread32[j - 1]);
                while (1) {
                    ;
                }
            }
        }
        HAL_DBG("testCount= %lx testLBA= %lx\n", testCount, testLBA);
        testCount += testSecCount;
    }
    HAL_DBG("---------%s SUCCESS---------\n", __func__);

    return HAL_OK;
}

#ifdef HAL_FSPI_XIP_ENABLE
static HAL_Status SNOR_XIP_RANDOM_TEST(uint32_t testEndLBA)
{
    int32_t j, ret;
    uint32_t testLBA = 0;
    uint32_t testCount, testSecCount = 1;
    struct HAL_FSPI_HOST *host = (struct HAL_FSPI_HOST *)nor->spi->userdata;

    HAL_DBG("---------%s Begin to set pattern---------\n", __func__);
    for (testLBA = FLASH_SKIP_LBA; testLBA < testEndLBA;) {
        pwrite32[0] = testLBA;
        ret = HAL_SNOR_OverWrite(nor, testLBA, testSecCount, pwrite32);
        if (ret != testSecCount) {
            return HAL_ERROR;
        }
        pread32[0] = -1;
        ret = HAL_SNOR_Read(nor, testLBA, testSecCount, pread32);
        if (ret != testSecCount) {
            return HAL_ERROR;
        }
        for (j = 0; j < testSecCount * (int32_t)nor->sectorSize / 4; j++) {
            if (pwrite32[j] != pread32[j]) {
                HAL_DBG_HEX("w:", pwrite32, 4, 16);
                HAL_DBG_HEX("r:", pread32, 4, 16);
                HAL_DBG(
                    "check not match:row=%lx, num=%lx, write=%lx, read=%lx %lx %lx %lx\n",
                    testLBA, j, pwrite32[j], pread32[j], pread32[j + 1], pread32[j + 2], pread32[j - 1]);
                while (1) {
                    ;
                }
            }
        }
        HAL_DBG("testLBA = %lx\n", testLBA);
        testLBA += testSecCount;
    }
    HAL_DBG("---------%s Begin to test---------\n", __func__);
    HAL_SNOR_XIPEnable(nor);
    testSecCount = 1;
    for (testCount = 0; testCount < (testEndLBA - FLASH_SKIP_LBA);) {
        testLBA = (uint32_t)rand() % testEndLBA;
        if (testLBA < FLASH_SKIP_LBA) {
            continue;
        }
        pwrite32[0] = testLBA;
        pread32 = (uint32_t *)(host->xipMemData + testLBA * nor->sectorSize);
        for (j = 0; j < testSecCount * nor->sectorSize / 4; j++) {
            if (pwrite32[j] != pread32[j]) {
                HAL_DBG_HEX("w:", pwrite32, 4, testSecCount * nor->sectorSize / 4);
                HAL_DBG_HEX("r:", pread32, 4, testSecCount * nor->sectorSize / 4);
                HAL_DBG(
                    "recheck not match:row=%lx, num=%lx, write=%lx, read=%lx\n",
                    testLBA, j, pwrite32[j], pread32[j]);
                while (1) {
                    ;
                }
            }
        }
        HAL_DBG("testCount= %lx testLBA = %lx\n", testCount, testLBA);
        testCount += testSecCount;
    }
    HAL_DBG("---------%s SUCCESS---------\n", __func__);
    HAL_SNOR_XIPDisable(nor);

    return HAL_OK;
}
#endif

/*************************** SNOR TEST ****************************/
TEST_GROUP(HAL_SNOR);

TEST_SETUP(HAL_SNOR){
    pwrite32 = (uint32_t *)pwrite;
    pread32 = (uint32_t *)pread;

    /* Write pattern */
    for (int32_t i = 0; i < (maxest_sector * (int32_t)nor->sectorSize / 4); i++) {
        pwrite32[i] = i;
    }
}

TEST_TEAR_DOWN(HAL_SNOR){
}

/* SNOR test case 0 */
TEST(HAL_SNOR, SnorStressRandomTest){
    int32_t ret, testEndLBA;

    ret = SNOR_SINGLE_TEST();
    TEST_ASSERT(ret == HAL_OK);
    testEndLBA = HAL_SNOR_GetCapacity(nor) / nor->sectorSize;
    TEST_ASSERT(testEndLBA > 0);
    ret = SNOR_STRESS_RANDOM_TEST(testEndLBA);
    TEST_ASSERT(ret == HAL_OK);
}

/* SNOR test case 1 */
#ifdef HAL_FSPI_XIP_ENABLE
TEST(HAL_SNOR, SnorXIPRandomTest){
    int32_t ret, testEndLBA;

    testEndLBA = HAL_SNOR_GetCapacity(nor) / nor->sectorSize;
    TEST_ASSERT(testEndLBA > 0);
    ret = SNOR_XIP_RANDOM_TEST(testEndLBA);
    HAL_SNOR_XIPDisable(nor);
    TEST_ASSERT(ret == HAL_OK);
}
#endif

/*************************** SNOR FSPI HOST SETTING****************************/
#if defined(HAL_SNOR_FSPI_HOST)
static HAL_Status FSPI_IRQHandler(void)
{
    struct HAL_FSPI_HOST *host = (struct HAL_FSPI_HOST *)nor->spi->userdata;

    HAL_FSPI_IRQHelper(host);

    return HAL_OK;
}

static HAL_Status SPI_Xfer(struct SNOR_HOST *spi, struct HAL_SPI_MEM_OP *op)
{
    struct HAL_FSPI_HOST *host = (struct HAL_FSPI_HOST *)spi->userdata;

    host->mode = spi->mode;
    host->cs = 0;

    return HAL_FSPI_SpiXfer(host, op);
}

static HAL_Status SPI_XipConfig(struct SNOR_HOST *spi, struct HAL_SPI_MEM_OP *op, uint32_t on)
{
    struct HAL_FSPI_HOST *host = (struct HAL_FSPI_HOST *)spi->userdata;

    host->cs = 0;
    if (op) {
        HAL_FSPI_XmmcSetting(host, op);
    }

    return HAL_FSPI_XmmcRequest(host, on);
}

static HAL_Status SNOR_Adapt(void)
{
    struct HAL_FSPI_HOST *host;
    HAL_Status ret;

    /* Designated host to SNOR */
    host = &g_fspi0Dev;
    host->xmmcDev[0].type = DEV_NOR;
    HAL_FSPI_Init(host);
    nor->spi->userdata = (void *)host;
    nor->spi->mode = HAL_SPI_MODE_3;
    nor->spi->xfer = SPI_Xfer;
#ifdef HAL_NVIC_MODULE_ENABLED
    HAL_NVIC_ConfigExtIRQ(FSPI0_IRQn, (NVIC_IRQHandler) & FSPI_IRQHandler, NVIC_PERIPH_PRIO_DEFAULT, NVIC_PERIPH_SUB_PRIO_DEFAULT);
#endif
#ifdef HAL_FSPI_TUNING_ENABLED
    uint8_t idByte[5];
    uint32_t i, j;

    nor->spi->mode = HAL_SPI_MODE_0;
    HAL_SNOR_Init(nor);
    for (i = 0; i <= HAL_FSPI_MAX_DELAY_LINE_CELLS; i += 2) {
        HAL_FSPI_SetDelayLines(host, (uint8_t)i);
        HAL_SNOR_ReadID(nor, idByte);
        if (HAL_SNOR_IsFlashSupported(idByte)) {
            break;
        }
    }
    for (j = HAL_FSPI_MAX_DELAY_LINE_CELLS; j > i; j -= 2) {
        HAL_FSPI_SetDelayLines(host, (uint8_t)j);
        HAL_SNOR_ReadID(nor, idByte);
        if (HAL_SNOR_IsFlashSupported(idByte)) {
            break;
        }
    }
    HAL_FSPI_SetDelayLines(host, (uint8_t)((i + j) / 2));
    HAL_SNOR_ReadID(nor, idByte);
    if (!HAL_SNOR_IsFlashSupported(idByte)) {
        nor->spi->mode = HAL_SPI_MODE_3;
    }
#endif

    nor->spi->mode |= (HAL_SPI_TX_QUAD | HAL_SPI_RX_QUAD);
#ifdef HAL_FSPI_XIP_ENABLE
    nor->spi->mode |= HAL_SPI_XIP;
    nor->spi->xipConfig = SPI_XipConfig;
#endif

    /* Init spi nor abstract */
    ret = HAL_SNOR_Init(nor);

    return ret;
}
#endif

uint8_t buffer_temp1[maxest_sector * 4096 + 64];
uint8_t buffer_temp2[maxest_sector * 4096 + 64];

/* Test code should be place in ram */
TEST_GROUP_RUNNER(HAL_SNOR){
    struct SNOR_HOST *spi;
    uint32_t ret;
    uint8_t *pwrite_t, *pread_t;

    /* Config test buffer */
    pwrite_t = (uint8_t *)buffer_temp1;
    pread_t = (uint8_t *)buffer_temp2;
    TEST_ASSERT_NOT_NULL(pwrite_t);
    TEST_ASSERT_NOT_NULL(pread_t);
    pwrite = AlignUp(pwrite_t, 64);
    pread = AlignUp(pread_t, 64);
    HAL_DBG("pwrite %p pread %p\n", pwrite, pread);

    for (int32_t i = 0; i < (maxest_sector * 1024); i++) {
        pwrite32[i] = i;
    }

    spi = &nor_spi_buf;
    memset(spi, 0, sizeof(struct SNOR_HOST));
    TEST_ASSERT_NOT_NULL(spi);
    nor = &nor_buf;
    memset(spi, 0, sizeof(struct SPI_NOR));
    TEST_ASSERT_NOT_NULL(nor);
    nor->spi = spi;
#if defined(HAL_SNOR_FSPI_HOST)
    ret = SNOR_Adapt();

    TEST_ASSERT(ret == HAL_OK);
#endif

    RUN_TEST_CASE(HAL_SNOR, SnorStressRandomTest);
#ifdef HAL_FSPI_XIP_ENABLE
    RUN_TEST_CASE(HAL_SNOR, SnorXIPRandomTest);
#endif

    /* SNOR deinit */
    ret = HAL_SNOR_DeInit(nor);
    TEST_ASSERT(ret == HAL_OK);

    free(pwrite_t);
    free(pread_t);
    free(nor->spi);
    free(nor);
}

#endif
