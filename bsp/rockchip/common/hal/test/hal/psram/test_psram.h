/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */
#ifndef _PSRAMM_TEST_H_
#define _PSRAMM_TEST_H_

#include "hal_def.h"

#if defined(HAL_HYPERPSRAM_MODULE_ENABLED) || defined(HAL_QPIPSRAM_MODULE_ENABLED)

/* psram test return code define */
#define PSRAM_MEMTESTER_ERR (0x1 << 2)

struct psram_test {
    char *name;
    int (*fp)(uint32_t *buf1, uint32_t *buf2, uint32_t count);
};

HAL_Status PSRAM_Memtester(uint32_t start, uint32_t length);
HAL_Status PSRAM_MarchCTest(uint32_t start, uint32_t length);

#endif

#endif
