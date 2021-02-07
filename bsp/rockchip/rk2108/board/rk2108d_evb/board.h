/**
  * Copyright (c) 2020 Rockchip Electronics Co., Ltd
  *
  * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __BOARD_H__
#define __BOARD_H__

#include "board_base.h"

#ifdef USB_VBUS_PIN
#undef USB_VBUS_PIN
#endif
#define USB_VBUS_PIN            BANK_PIN(GPIO_BANK0, 1)

#ifdef RT_USING_TOUCH
#undef  TOUCH_IRQ_PIN
#define TOUCH_IRQ_PIN           BANK_PIN(GPIO_BANK0, 3)
#undef  TOUCH_RST_PIN
#define TOUCH_RST_PIN           BANK_PIN(GPIO_BANK1, 7)
#undef  TOUCH_I2C_DEV
#define TOUCH_I2C_DEV           "i2c0"
#undef  TOUCH_DEV_NAME
#define TOUCH_DEV_NAME          "cstxx"
#endif

#define RT_HW_LCD_GPIO_TRIGGER_PIN    BANK_PIN(GPIO_BANK0, 9)
#define RT_HW_LCD_GPIO_TRIGGER_BANK   GPIO_BANK0
#define RT_HW_LCD_GPIO_TRIGGER_GPIO   GPIO_PIN_B1

#define POWER_KEY_BANK_PIN            BANK_PIN(GPIO_BANK0, 31)
#define POWER_KEY_BANK                GPIO_BANK0
#define POWER_KEY_GPIO                GPIO0
#define POWER_KEY_PIN                 GPIO_PIN_D7

#endif
