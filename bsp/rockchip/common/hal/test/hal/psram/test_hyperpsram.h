/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */
#ifndef _HYPERPSRAM_TEST_H_
#define _HYPERPSRAM_TEST_H_

#ifdef HAL_HYPERPSRAM_MODULE_ENABLED
/***************************** MACRO Definition ******************************/
#define CONFIG_PSRAM_BASE0 XIP_MAP1_BASE0
#define CONFIG_PSRAM_BASE1 XIP_MAP1_BASE1

#define PATTERN (0x5aa5f00f)
#define SIZE_8M (0x800000)

struct hyperbus_slt_test_list {
    char *name;
    HAL_Status (*fp)(uint32_t start, uint32_t length);
};

HAL_Status HYPERPSRAM_CtrlTest(uint32_t start, uint32_t length);
HAL_Status HYPERPSRAM_CapConfirm(uint32_t start, uint32_t length);

#endif

#endif
