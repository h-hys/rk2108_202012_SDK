/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */

#ifndef _HAL_CONF_H_
#define _HAL_CONF_H_

#define SYS_TIMER TIMER5 /* System timer designation (RK TIMER) */

/* DEG LEVEL */
#define HAL_DBG_ON      /* the master switch for hal debug log, comment out it will disable all of hal log */
#define HAL_DBG_INFO_ON /* enable hal log with info level */
#define HAL_DBG_WRN_ON  /* enable hal log with warning level */
#define HAL_DBG_ERR_ON  /* enable hal log with error level */
#define HAL_ASSERT_ON

#define HAL_CRU_MODULE_ENABLED
#define HAL_PL330_MODULE_ENABLED
#define HAL_I2C_MODULE_ENABLED
//#define HAL_I2S_MODULE_ENABLED
#define HAL_I2STDM_MODULE_ENABLED
#define HAL_PDM_MODULE_ENABLED
#define HAL_GPIO_MODULE_ENABLED
#define HAL_PINCTRL_MODULE_ENABLED
#define HAL_PL330_MODULE_ENABLED
//#define HAL_PMU_MODULE_ENABLED
#define HAL_SFC_MODULE_ENABLED
#define HAL_SNOR_MODULE_ENABLED
#define HAL_SNOR_SFC_HOST
//#define HAL_SPI_MODULE_ENABLED
#define HAL_UART_MODULE_ENABLED
//#define HAL_VAD_MODULE_ENABLED
#define HAL_SARADC_MODULE_ENABLED
#define HAL_SDIO_MODULE_ENABLED
#define HAL_SDIO_MODULE_ENABLED
#define HAL_ICACHE_MODULE_ENABLED
#define HAL_DCACHE_MODULE_ENABLED
#define HAL_TIMER_MODULE_ENABLED

#endif /* _HAL_CONF_H_ */
