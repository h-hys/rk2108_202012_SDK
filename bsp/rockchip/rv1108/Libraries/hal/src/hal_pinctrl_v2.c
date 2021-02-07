/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */

#include "hal_base.h"

#if defined(HAL_PINCTRL_MODULE_ENABLED) && defined(SOC_RV1126)

/** @addtogroup RK_HAL_Driver
 *  @{
 */

/** @addtogroup PINCTRL
 *  @{
 */

/** @defgroup PINCTRL_How_To_Use How To Use
 *  @{

 The pinctrl setting registers actually is bus grf registers, which include
 iomux, drive strength, pull mode, slew rate and schmitt trigger.

 The pinctrl driver provides APIs:
   - HAL_PINCTRL_SetPinIOMUX to set pin iomux
   - HAL_PINCTRL_SetPinParam to set pin iomux/drive/pull/slewrate/schmitt/ie

Example:
     HAL_PINCTRL_SetIOMUX(GPIO_BANK0,
                          GPIO_PIN_A0 | // I2S_IN_SCLK
                          GPIO_PIN_A1 | // I2S_IN_LRCK
                          GPIO_PIN_A2 | // I2S_IN_SDI0
                          GPIO_PIN_A3,  // I2S_IN_SDI1
                          PIN_CONFIG_MUX_FUNC2);

     HAL_PINCTRL_SetParam(GPIO_BANK0,
                          GPIO_PIN_A0 | // I2S_IN_SCLK
                          GPIO_PIN_A1 | // I2S_IN_LRCK
                          GPIO_PIN_A2 | // I2S_IN_SDI0
                          GPIO_PIN_A3,  // I2S_IN_SDI1
                          PIN_CONFIG_MUX_FUNC2 |
                          PIN_CONFIG_PUL_DOWN |
                          PIN_CONFIG_DRV_LEVEL2 |
                          PIN_CONFIG_SRT_FAST |
                          PIN_CONFIG_SMT_ENABLE);
 @} */

/** @defgroup PINCTRL_Private_Definition Private Definition
 *  @{
 */
/********************* Private MACRO Definition ******************************/

#ifdef GRF_IOMUX_W
#define IOMUX_WIDTH GRF_IOMUX_W
#else
#define IOMUX_WIDTH (4)
#endif

#ifdef GRF_DS_W
#define DS_WIDTH GRF_DS_W
#else
#define DS_WIDTH (4)
#endif

#ifdef GRF_P_W
#define PULL_WIDTH GRF_P_W
#else
#define PULL_WIDTH (2)
#endif

#define _TO_MASK(w)         ((1U << (w)) - 1U)
#define _TO_OFFSET(p, w)    ((p) * (w))
#define RK_GEN_VAL(p, v, w) ((_TO_MASK(w) << (_TO_OFFSET(p, w) + 16)) | (((v) & _TO_MASK(w)) << _TO_OFFSET(p, w)))

#define IOMUX_H(__B, __P) (GRF->GPIO##__B##__P##_IOMUX_H)
#define IOMUX_L(__B, __P) (GRF->GPIO##__B##__P##_IOMUX_L)
#define DS_H(__B, __P)    (GRF->GPIO##__B##__P##_DS_H)
#define DS_L(__B, __P)    (GRF->GPIO##__B##__P##_DS_L)
#define P_H(__B, __P)     (GRF->GPIO##__B##__P##_P_H)
#define P_L(__B, __P)     (GRF->GPIO##__B##__P##_P_L)
#define P(__B, __P)       (GRF->GPIO##__B##__P##_P)

#define _PINCTRL_WRITE(REG, DATA) \
{                                 \
    HAL_DBG("0x%lx\n", REG);      \
    REG = DATA;                   \
    HAL_DBG("0x%lx\n", REG);      \
}

#define SET_IOMUX_H(_B, _P, p, v, w) _PINCTRL_WRITE(IOMUX_H(_B, _P), RK_GEN_VAL(p, v, w))
#define SET_IOMUX_L(_B, _P, p, v, w) _PINCTRL_WRITE(IOMUX_L(_B, _P), RK_GEN_VAL(p, v, w))
#define SET_DS_H(_B, _P, p, v, w)    _PINCTRL_WRITE(DS_H(_B, _P), RK_GEN_VAL(p, v, w))
#define SET_DS_L(_B, _P, p, v, w)    _PINCTRL_WRITE(DS_L(_B, _P), RK_GEN_VAL(p, v, w))
#define SET_P_H(_B, _P, p, v, w)     _PINCTRL_WRITE(P_H(_B, _P), RK_GEN_VAL(p, v, w))
#define SET_P_L(_B, _P, p, v, w)     _PINCTRL_WRITE(P_L(_B, _P), RK_GEN_VAL(p, v, w))
#define SET_P_(_B, _P, p, v, w)      _PINCTRL_WRITE(P(_B, _P), RK_GEN_VAL(p, v, w))

#define RK_SET_IOMUX_H(B, P, p, v) SET_IOMUX_H(B, P, p % (16 / IOMUX_WIDTH), v, IOMUX_WIDTH)
#define RK_SET_IOMUX_L(B, P, p, v) SET_IOMUX_L(B, P, p % (16 / IOMUX_WIDTH), v, IOMUX_WIDTH)
#define RK_SET_DS_H(B, P, p, v)    SET_DS_H(B, P, p % (16 / DS_WIDTH), v, DS_WIDTH)
#define RK_SET_DS_L(B, P, p, v)    SET_DS_L(B, P, p % (16 / DS_WIDTH), v, DS_WIDTH)
#define RK_SET_P_H(B, P, p, v)     SET_P_H(B, P, p % (16 / PULL_WIDTH), v, PULL_WIDTH)
#define RK_SET_P_L(B, P, p, v)     SET_P_L(B, P, p % (16 / PULL_WIDTH), v, PULL_WIDTH)
#define RK_SET_P(B, P, p, v)       SET_P_(B, P, p % (16 / PULL_WIDTH), v, PULL_WIDTH)

#define SET_IOMUX(_GPIO, _PORT, pin, val)       \
{                                               \
    if ((pin % 8) > 3) {                        \
        RK_SET_IOMUX_H(_GPIO, _PORT, pin, val); \
    }else{                                      \
        RK_SET_IOMUX_L(_GPIO, _PORT, pin, val); \
    }                                           \
}

#define SET_DS(_GPIO, _PORT, pin, val)       \
{                                            \
    if ((pin % 8) > 3) {                     \
        RK_SET_DS_H(_GPIO, _PORT, pin, val); \
    } else {                                 \
        RK_SET_DS_H(_GPIO, _PORT, pin, val); \
    }                                        \
}

#define SET_P(_GPIO, _PORT, pin, val)     \
{                                         \
        RK_SET_P(_GPIO, _PORT, pin, val); \
}

#define PINCTRL_SET_IOMUX(bank, pin, val) \
{                                         \
    if (pin < 8) {                        \
        SET_IOMUX(bank, A, pin, val);     \
    } else if (pin < 16) {                \
        SET_IOMUX(bank, B, pin, val);     \
    } else if (pin < 24) {                \
        SET_IOMUX(bank, C, pin, val);     \
    } else {                              \
        SET_IOMUX(bank, D, pin, val);     \
    }                                     \
}

#define PINCTRL_SET_DS(bank, pin, val) \
{                                      \
    if (pin < 8) {                     \
        SET_DS(bank, A, pin, val);     \
    } else if (pin < 16) {             \
        SET_DS(bank, B, pin, val);     \
    } else if (pin < 24) {             \
        SET_DS(bank, C, pin, val);     \
    } else {                           \
        SET_DS(bank, D, pin, val);     \
    }                                  \
}

#define PINCTRL_SET_P(bank, pin, val) \
{                                     \
    if (pin < 8) {                    \
        SET_P(bank, A, pin, val);     \
    } else if (pin < 16) {            \
        SET_P(bank, B, pin, val);     \
    } else if (pin < 24) {            \
        SET_P(bank, C, pin, val);     \
    } else {                          \
        SET_P(bank, D, pin, val);     \
    }                                 \
}

/********************* Private Variable Definition ***************************/

/********************* Private Function Definition ***************************/

/**
 * @brief  Private function to set iomux for one pin.
 * @param  bank: pin bank channel.
 * @param  pin: pin index, 0~31.
 * @param  param: value to write.
 * @return HAL_Status.
 */
static HAL_Status PINCTRL_SetIOMUX(eGPIO_bankId bank, uint8_t pin, uint32_t data)
{
    HAL_DBG("func: %-20s: GPIO%d-%d set %lx (%08lx)\n", __func__, bank, pin, data, RK_GEN_VAL(pin % (16 / IOMUX_WIDTH), data, IOMUX_WIDTH));

    switch (bank) {
#ifdef GPIO0
    case 0:
        PINCTRL_SET_IOMUX(0, pin, data);
        break;
#endif
#ifdef GPIO1
    case 1:
    #ifdef RKMCU_RK2108
        if (pin < 8) {
            SET_IOMUX(1, A, pin, data);
        } else if (pin < 16) {
            SET_IOMUX(1, B, pin, data);
        } else if (pin < 24) {
            SET_IOMUX(1, C, pin, data);
        } else {
            RK_SET_IOMUX_L(1, D, pin, data);
        }
    #else
        PINCTRL_SET_IOMUX(1, pin, data);
    #endif
        break;
#endif
#ifdef GPIO2
    case 2:
        PINCTRL_SET_IOMUX(2, pin, data);
        break;
#endif
#ifdef GPIO3
    case 3:
        PINCTRL_SET_IOMUX(3, pin, data);
        break;
#endif
#ifdef GPIO4
    case 4:
    #ifdef SOC_RV1126
        RK_SET_IOMUX_L(4, A, pin, data);
    #else
        PINCTRL_SET_IOMUX(4, pin, data);
    #endif
        break;
#endif
    default:
        HAL_DBG("unknown gpio%d\n", bank);
        break;
    }

    return HAL_OK;
}

/**
 * @brief  Private function to set drive strength for one pin.
 * @param  bank: pin bank channel.
 * @param  pin: pin index, 0~31.
 * @param  param: value to write.
 * @return HAL_Status.
 */
static HAL_Status PINCTRL_SetDS(eGPIO_bankId bank, uint8_t pin, uint32_t data)
{
#ifndef RKMCU_RK2108
    HAL_DBG("func: %-20s: GPIO%d-%d set %lx (%08lx)\n", __func__, bank, pin, data, RK_GEN_VAL(pin % (16 / DS_WIDTH), data, DS_WIDTH));

    switch (bank) {
#ifdef GPIO0
    case 0:
        PINCTRL_SET_DS(0, pin, data);
        break;
#endif
#ifdef GPIO1
    case 1:
        PINCTRL_SET_DS(1, pin, data);
        break;
#endif
#ifdef GPIO2
    case 2:
        PINCTRL_SET_DS(2, pin, data);
        break;
#endif
#ifdef GPIO3
    case 3:
        PINCTRL_SET_DS(3, pin, data);
        break;
#endif
#ifdef GPIO4
    case 4:
    #ifdef SOC_RV1126
        RK_SET_DS_L(4, A, pin, data);
    #else
        PINCTRL_SET_DS(4, pin, data);
    #endif
        break;
#endif
    default:
        HAL_DBG("unknown gpio%d\n", bank);
        break;
    }
#endif

    return HAL_OK;
}

#ifdef SOC_RV1126
static void PINCTRL_SetP_RV1126(uint8_t pin, uint32_t data)
{
    if (pin < 8) {
        RK_SET_P(0, A, pin, data);
    } else if (pin < 16) {
        RK_SET_P(0, B, pin, data);
    } else if (pin < 19) {
        RK_SET_P_L(0, C, pin, data);
    } else if (pin < 24) {
        RK_SET_P_H(0, C, pin, data);
    } else {
        RK_SET_P(0, D, pin, data);
    }
}
#endif

/**
 * @brief  Private function to set pupd for one pin.
 * @param  bank: pin bank channel.
 * @param  pin: pin index, 0~31.
 * @param  param: value to write.
 * @return HAL_Status.
 */
static HAL_Status PINCTRL_SetPUPD(eGPIO_bankId bank, uint8_t pin, uint32_t data)
{
    HAL_DBG("func: %-20s: GPIO%d-%d set %lx (%08lx)\n", __func__, bank, pin, data, RK_GEN_VAL(pin % (16 / PULL_WIDTH), data, PULL_WIDTH));

    switch (bank) {
#ifdef GPIO0
    case 0:
    #ifdef SOC_RV1126
        PINCTRL_SetP_RV1126(pin, data);
    #else
        PINCTRL_SET_P(0, pin, data);
    #endif
        break;
#endif
#ifdef GPIO1
    case 1:
        PINCTRL_SET_P(1, pin, data);
        break;
#endif
#ifdef GPIO2
    case 2:
        PINCTRL_SET_P(2, pin, data);
        break;
#endif
#ifdef GPIO3
    case 3:
        PINCTRL_SET_P(3, pin, data);
        break;
#endif
#ifdef GPIO4
    case 4:
    #ifdef SOC_RV1126
        RK_SET_P(4, A, pin, data);
    #else
        PINCTRL_SET_P(4, pin, data);
    #endif
        break;
#endif
    default:
        HAL_DBG("unknown gpio%d\n", bank);
        break;
    }

    return HAL_OK;
}

/**
 * @brief  Private function to configure one pin.
 * @param  bank: pin bank channel defined in @ref eGPIO_bankId.
 * @param  pin: pin index, 0~31.
 * @param  param: multi params defined in @ref ePINCTRL_configParam,
 * @return HAL_Status.
 */
static HAL_Status PINCTRL_SetPinParam(eGPIO_bankId bank, uint8_t pin, uint32_t param)
{
    HAL_Status rc = HAL_OK;

    if (param & FLAG_MUX) {
        rc |= PINCTRL_SetIOMUX(bank, pin, (uint8_t)((param & MASK_MUX) >> SHIFT_MUX));
    }

    if (param & FLAG_PUL) {
        rc |= PINCTRL_SetPUPD(bank, pin, (uint8_t)((param & MASK_PUL) >> SHIFT_PUL));
    }

    if (param & FLAG_DRV) {
        rc |= PINCTRL_SetDS(bank, pin, (uint8_t)((param & MASK_DRV) >> SHIFT_DRV));
    }

    return rc;
}
/** @} */

/********************* Public Function Definition ****************************/

/** @defgroup PINCTRL_Exported_Functions_Group1 Suspend and Resume Functions

 This section provides functions allowing to suspend and resume the module:

 *  @{
 */

/** @} */

/** @defgroup PINCTRL_Exported_Functions_Group2 Init and DeInit Functions

 This section provides functions allowing to init and deinit the module:

 *  @{
 */
HAL_Status HAL_PINCTRL_Init(void)
{
#ifdef RKMCU_PISCES
    HAL_PINCTRL_SetIOMUX(GPIO_BANK0, GPIO_PIN_ALL & ~(
                             GPIO_PIN_C7 | // UART0_RX
                             GPIO_PIN_D0 | // UART0_TX
                             GPIO_PIN_D5 | // MIPI_SWITCH_CTRL
                             GPIO_PIN_D6), // AUD_BY_CTRL
                         PIN_CONFIG_MUX_FUNC0);
    HAL_PINCTRL_SetIOMUX(GPIO_BANK1, GPIO_PIN_ALL & ~(
                             GPIO_PIN_A0 | // LCD_IN_RESET_N
                             GPIO_PIN_A1 | // LCD_IN_TE
                             GPIO_PIN_A2 | // LCD_OUT_RESETN
                             GPIO_PIN_A3 | // LCD_OUT_TE
                             GPIO_PIN_A5 | // BOOT_DEV_SEL
                             GPIO_PIN_A6 | // M4_DSP_JTAG_SEL
                             GPIO_PIN_B2), // CLK_IN_SEL
                         PIN_CONFIG_MUX_FUNC0);

    HAL_PINCTRL_SetParam(GPIO_BANK0, GPIO_PIN_ALL & ~(
                             GPIO_PIN_D5 | // MIPI_SWITCH_CTRL
                             GPIO_PIN_D6), // AUD_BY_CTRL
                         PIN_CONFIG_PUL_NORMAL);
    HAL_PINCTRL_SetParam(GPIO_BANK1, GPIO_PIN_ALL & ~(
                             GPIO_PIN_A5 | // BOOT_DEV_SEL
                             GPIO_PIN_A6 | // M4_DSP_JTAG_SEL
                             GPIO_PIN_B2), // CLK_IN_SEL
                         PIN_CONFIG_PUL_NORMAL);
#endif

    return HAL_OK;
}

HAL_Status HAL_PINCTRL_DeInit(void)
{
    return HAL_OK;
}
/** @} */

/** @defgroup PINCTRL_Exported_Functions_Group3 State and Errors Functions

 This section provides functions allowing to get the status of the module:

 *  @{
 */

/**
 * @brief  Public function to configure for multi pins.
 * @param  bank: pin bank channel defined in eGPIO_bankId.
 * @param  mPins: multi pins defined in PINCTRL_GPIO_PINS.
 * @param  param: multi params defined in ePINCTRL_configParam,
 * @return HAL_Status.
 */
HAL_Status HAL_PINCTRL_SetParam(eGPIO_bankId bank, uint32_t mPins, ePINCTRL_configParam param)
{
    uint8_t pin;
    HAL_Status rc;

    HAL_ASSERT(bank < GPIO_BANK_NUM);

    if (!(param & (FLAG_MUX | FLAG_PUL | FLAG_DRV | FLAG_SRT | FLAG_SMT))) {
        return HAL_OK;
    }

    for (pin = 0; pin < 32; pin++) {
        if (mPins & (1 << pin)) {
            rc = PINCTRL_SetPinParam(bank, pin, param);
            if (rc) {
                return rc;
            }
        }
    }

    return HAL_OK;
}

/**
 * @brief  Public function to set iomux for multi pins.
 * @param  bank: pin bank channel defined in eGPIO_bankId.
 * @param  mPins: multi pins defined in PINCTRL_GPIO_PINS.
 * @param  param: multi params defined in ePINCTRL_configParam,
 * @return HAL_Status.
 */
HAL_Status HAL_PINCTRL_SetIOMUX(eGPIO_bankId bank, uint32_t mPins, ePINCTRL_configParam param)
{
    return HAL_PINCTRL_SetParam(bank, mPins, param);
}

/** @} */

/** @} */

/** @} */

#endif /* HAL_PINCTRL_V2_MODULE_ENABLED */
