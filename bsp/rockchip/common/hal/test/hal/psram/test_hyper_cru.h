/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */
#ifndef TEST_HYPER_CRU_H
#define TEST_HYPER_CRU_H

#ifdef RKMCU_RK2206

HAL_Status HYPERPSRAM_FreqImprove(uint32_t MHz);
HAL_Status HYPERPSRAM_FreqRecover(void);

#else
HAL_Status HYPERPSRAM_FreqImprove(uint32_t MHz)
{
    return HAL_OK;
}
HAL_Status HYPERPSRAM_FreqRecover(void)
{
    return HAL_OK;
}
#endif
#endif
