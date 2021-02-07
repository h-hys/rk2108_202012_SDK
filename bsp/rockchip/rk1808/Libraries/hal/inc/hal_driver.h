/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2018-2020 Rockchip Electronics Co., Ltd.
 */

#ifndef _HAL_DRIVER_H_
#define _HAL_DRIVER_H_

#include "hal_pm.h"

#ifdef HAL_ACDCDIG_MODULE_ENABLED
#include "hal_acdcdig.h"
#endif

#ifdef HAL_AUDIOPWM_MODULE_ENABLED
#include "hal_audiopwm.h"
#endif

#include "hal_cache.h"

#ifdef HAL_BUFFER_MANAGE_MODULE_ENABLED
#include "hal_buffer_manage.h"
#endif

#ifdef HAL_CRU_MODULE_ENABLED
#include "hal_cru.h"
#endif

#ifdef HAL_CRYPTO_MODULE_ENABLED
#include "hal_crypto.h"
#endif

#ifdef HAL_DSI_MODULE_ENABLED
#include "hal_display.h"
#include "hal_dsi.h"
#endif

#ifdef HAL_DEMO_MODULE_ENABLED
#include "hal_demo.h"
#endif

#ifdef HAL_DSP_MODULE_ENABLED
#include "hal_dsp.h"
#endif

#include "hal_dma.h"

#ifdef HAL_DWDMA_MODULE_ENABLED
#include "hal_dwdma.h"
#endif

#ifdef HAL_EFUSE_MODULE_ENABLED
#include "hal_efuse.h"
#endif

#ifdef HAL_GPIO_MODULE_ENABLED
#include "hal_gpio.h"
#endif

#ifdef HAL_PINCTRL_MODULE_ENABLED
#include "hal_pinctrl.h"
#endif

#if defined(HAL_HCD_MODULE_ENABLED) || defined(HAL_PCD_MODULE_ENABLED)
#include "hal_usb_core.h"
#include "hal_usb_phy.h"
#endif

#ifdef HAL_HCD_MODULE_ENABLED
#include "hal_hcd.h"
#endif

#ifdef HAL_HWSPINLOCK_MODULE_ENABLED
#include "hal_hwspinlock.h"
#if !defined(HAL_HWSPINLOCK_OWNER_ID) || (HAL_HWSPINLOCK_OWNER_ID <= 0)
#error "HAL_HWSPINLOCK_OWNER_ID must be defined in hal_conf.h file"
#endif
#endif

#ifdef HAL_HYPERPSRAM_MODULE_ENABLED
#include "hal_hyperpsram.h"
#endif

#ifdef HAL_I2C_MODULE_ENABLED
#include "hal_i2c.h"
#endif

#ifdef HAL_I2S_MODULE_ENABLED
#include "hal_i2s.h"
#endif

#ifdef HAL_I2STDM_MODULE_ENABLED
#include "hal_i2stdm.h"
#endif

#ifdef HAL_INTC_MODULE_ENABLED
#include "hal_intc.h"
#endif

#ifdef HAL_MBOX_MODULE_ENABLED
#include "hal_mbox.h"
#endif

#ifdef HAL_NVIC_MODULE_ENABLED
#include "hal_nvic.h"
#endif

#ifdef HAL_PCD_MODULE_ENABLED
#include "hal_pcd.h"
#endif

#ifdef HAL_PDM_MODULE_ENABLED
#include "hal_pdm.h"
#endif

#ifdef HAL_PL330_MODULE_ENABLED
#include "hal_pl330.h"
#endif

#ifdef HAL_PMU_MODULE_ENABLED
#include "hal_pd.h"
#endif

#ifdef HAL_PVTM_MODULE_ENABLED
#include "hal_pvtm.h"
#endif

#ifdef HAL_PWM_MODULE_ENABLED
#include "hal_pwm.h"
#endif

#include "hal_pwr.h"

#ifdef HAL_SDIO_MODULE_ENABLED
#include "hal_sdio.h"
#endif

#ifdef HAL_SNOR_MODULE_ENABLED
#include "hal_spi_mem.h"
#include "hal_snor.h"
#endif

#ifdef HAL_SFC_MODULE_ENABLED
#include "hal_sfc.h"
#endif

#ifdef HAL_SPINAND_MODULE_ENABLED
#include "hal_spi_mem.h"
#include "hal_spinand.h"
#endif

#ifdef HAL_SYSTICK_MODULE_ENABLED
#include "hal_systick.h"
#endif

#ifdef HAL_FSPI_MODULE_ENABLED
#include "hal_spi_mem.h"
#include "hal_fspi.h"
#endif

#ifdef HAL_QPIPSRAM_MODULE_ENABLED
#include "hal_spi_mem.h"
#include "hal_qpipsram.h"
#endif

#ifdef HAL_TOUCHKEY_MODULE_ENABLED
#include "hal_touchkey.h"
#endif

#ifdef HAL_TSADC_MODULE_ENABLED
#include "hal_tsadc.h"
#endif

#ifdef HAL_SARADC_MODULE_ENABLED
#include "hal_saradc.h"
#endif

#ifdef HAL_KEYCTRL_MODULE_ENABLED
#include "hal_keyctrl.h"
#endif

#ifdef HAL_SPI_MODULE_ENABLED
#include "hal_spi.h"
#endif

#ifdef HAL_SPI2APB_MODULE_ENABLED
#include "hal_spi2apb.h"
#endif

#ifdef HAL_TIMER_MODULE_ENABLED
#include "hal_timer.h"
#endif

#ifdef HAL_UART_MODULE_ENABLED
#include "hal_uart.h"
#endif

#ifdef HAL_VAD_MODULE_ENABLED
#include "hal_vad.h"
#endif

#ifdef HAL_VICAP_MODULE_ENABLED
#include "hal_vicap.h"
#endif

#ifdef HAL_VOP_MODULE_ENABLED
#include "hal_display.h"
#include "hal_vop.h"
#endif

#ifdef HAL_WDT_MODULE_ENABLED
#include "hal_wdt.h"
#endif

#endif
