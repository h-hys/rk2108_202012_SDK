/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */

#include "hal_conf.h"

/** @addtogroup RK_HAL_Driver
 *  @{
 */

/** @addtogroup PINCTRL
 *  @{
 */

#ifndef __HAL_PINCTRL_H__
#define __HAL_PINCTRL_H__

#include "hal_def.h"

/***************************** MACRO Definition ******************************/
/** @defgroup PINCTRL_Exported_Definition_Group1 Basic Definition
 *  @{
 */

typedef enum {
    PINCTRL_IOMUX_FUNC0,
    PINCTRL_IOMUX_FUNC1,
    PINCTRL_IOMUX_FUNC2,
    PINCTRL_IOMUX_FUNC3,
    PINCTRL_IOMUX_FUNC4,
    PINCTRL_IOMUX_FUNC5,
    PINCTRL_IOMUX_FUNC6,
    PINCTRL_IOMUX_FUNC7
} ePINCTRL_iomuxFunc;

typedef enum {
    PINCTRL_PULL_OD,
    PINCTRL_PULL_UP,
    PINCTRL_PULL_DOWN,
    PINCTRL_PULL_KEEP
} ePINCTRL_pullMode;

typedef enum {
    PINCTRL_DRIVE_LEVEL0,
    PINCTRL_DRIVE_LEVEL1,
    PINCTRL_DRIVE_LEVEL2,
    PINCTRL_DRIVE_LEVEL3,
    PINCTRL_DRIVE_LEVEL4,
    PINCTRL_DRIVE_LEVEL5,
    PINCTRL_DRIVE_LEVEL6,
    PINCTRL_DRIVE_LEVEL7
} ePINCTRL_driveLevel;

typedef enum {
    PINCTRL_SLEWRATE_SLOW,
    PINCTRL_SLEWRATE_FAST
} ePINCTRL_slewRate;

typedef enum {
    PINCTRL_SCHMITT_DIS,
    PINCTRL_SCHMITT_EN
} ePINCTRL_schmitt;

#define FLAG_MUX  HAL_BIT(31)
#define FLAG_PUL  HAL_BIT(30)
#define FLAG_DRV  HAL_BIT(29)
#define FLAG_SRT  HAL_BIT(28)
#define FLAG_SMT  HAL_BIT(27)
#define SHIFT_MUX (0)
#define SHIFT_PUL (4)
#define SHIFT_DRV (8)
#define SHIFT_SRT (12)
#define SHIFT_SMT (14)
#define MASK_MUX  (0xFU << SHIFT_MUX)
#define MASK_PUL  (0xFU << SHIFT_PUL)
#define MASK_DRV  (0xFU << SHIFT_DRV)
#define MASK_SRT  (0x3U << SHIFT_SRT)
#define MASK_SMT  (0x3U << SHIFT_SMT)

/** @brief  PIN Configuration Mode
 *  Elements values convention: gggg g000 0000 0000 ttrr dddd pppp xxxx
 *      - ggggg  : Flag to set Mux/Pull/Drive/Slewrate/Schmitt
 *      - tt  : Schmitt value
 *      - rr  : Slewrate value
 *      - dddd  : Drive value
 *      - pppp  : Pull value
 *      - xxxx  : Mux mode value
 */
typedef enum {
    PIN_CONFIG_MUX_FUNC0   = (0x0 << SHIFT_MUX | FLAG_MUX),
    PIN_CONFIG_MUX_FUNC1   = (0x1 << SHIFT_MUX | FLAG_MUX),
    PIN_CONFIG_MUX_FUNC2   = (0x2 << SHIFT_MUX | FLAG_MUX),
    PIN_CONFIG_MUX_FUNC3   = (0x3 << SHIFT_MUX | FLAG_MUX),
    PIN_CONFIG_MUX_FUNC4   = (0x4 << SHIFT_MUX | FLAG_MUX),
    PIN_CONFIG_MUX_FUNC5   = (0x5 << SHIFT_MUX | FLAG_MUX),
    PIN_CONFIG_MUX_FUNC6   = (0x6 << SHIFT_MUX | FLAG_MUX),
    PIN_CONFIG_MUX_FUNC7   = (0x7 << SHIFT_MUX | FLAG_MUX),
    PIN_CONFIG_MUX_FUNC8   = (0x8 << SHIFT_MUX | FLAG_MUX),
    PIN_CONFIG_MUX_FUNC9   = (0x9 << SHIFT_MUX | FLAG_MUX),
    PIN_CONFIG_MUX_FUNC10  = (0xa << SHIFT_MUX | FLAG_MUX),
    PIN_CONFIG_MUX_FUNC11  = (0xb << SHIFT_MUX | FLAG_MUX),
    PIN_CONFIG_MUX_FUNC12  = (0xc << SHIFT_MUX | FLAG_MUX),
    PIN_CONFIG_MUX_FUNC13  = (0xd << SHIFT_MUX | FLAG_MUX),
    PIN_CONFIG_MUX_FUNC14  = (0xe << SHIFT_MUX | FLAG_MUX),
    PIN_CONFIG_MUX_FUNC15  = (0xf << SHIFT_MUX | FLAG_MUX),
    PIN_CONFIG_MUX_DEFAULT = PIN_CONFIG_MUX_FUNC0,

    PIN_CONFIG_PUL_NORMAL  = (0x0 << SHIFT_PUL | FLAG_PUL),
    PIN_CONFIG_PUL_UP      = (0x1 << SHIFT_PUL | FLAG_PUL),
    PIN_CONFIG_PUL_DOWN    = (0x2 << SHIFT_PUL | FLAG_PUL),
    PIN_CONFIG_PUL_KEEP    = (0x3 << SHIFT_PUL | FLAG_PUL),
    PIN_CONFIG_PUL_DEFAULT = PIN_CONFIG_PUL_NORMAL,

    PIN_CONFIG_DRV_LEVEL0        = (0x0 << SHIFT_DRV | FLAG_DRV),
    PIN_CONFIG_DRV_LEVEL1        = (0x1 << SHIFT_DRV | FLAG_DRV),
    PIN_CONFIG_DRV_LEVEL2        = (0x2 << SHIFT_DRV | FLAG_DRV),
    PIN_CONFIG_DRV_LEVEL3        = (0x3 << SHIFT_DRV | FLAG_DRV),
    PIN_CONFIG_DRV_LEVEL4        = (0x4 << SHIFT_DRV | FLAG_DRV),
    PIN_CONFIG_DRV_LEVEL5        = (0x5 << SHIFT_DRV | FLAG_DRV),
    PIN_CONFIG_DRV_LEVEL6        = (0x6 << SHIFT_DRV | FLAG_DRV),
    PIN_CONFIG_DRV_LEVEL7        = (0x7 << SHIFT_DRV | FLAG_DRV),
    PIN_CONFIG_DRV_LEVEL_DEFAULT = PIN_CONFIG_DRV_LEVEL2,

    PIN_CONFIG_SRT_SLOW    = (0x0 << SHIFT_SRT | FLAG_SRT),
    PIN_CONFIG_SRT_FAST    = (0x1 << SHIFT_SRT | FLAG_SRT),
    PIN_CONFIG_SRT_DEFAULT = PIN_CONFIG_SRT_SLOW,

    PIN_CONFIG_SMT_DISABLE = (0x0 << SHIFT_SMT | FLAG_SMT),
    PIN_CONFIG_SMT_ENABLE  = (0x1 << SHIFT_SMT | FLAG_SMT),
    PIN_CONFIG_SMT_DEFAULT = PIN_CONFIG_SMT_DISABLE,

    PIN_CONFIG_MAX = 0xFFFFFFFFU,
} ePINCTRL_configParam;

typedef enum {
    GRF_MUX_INFO = 0,
    GRF_PUL_INFO,
    GRF_DRV_INFO,
    GRF_SRT_INFO,
    GRF_SMT_INFO,
    GRF_INFO_NUM
} ePIN_GRF_INFO_ID;

#define PIN_BANK_CFG_FLAGS(chn, cnt, reg,                                                       \
                           offset0, bpp0, ppr0,                                                 \
                           offset1, bpp1, ppr1,                                                 \
                           offset2, bpp2, ppr2,                                                 \
                           offset3, bpp3, ppr3,                                                 \
                           offset4, bpp4, ppr4)                                                 \
    {                                                                                           \
        .channel = chn,                                                                         \
        .pinCount = cnt,                                                                        \
        .grfBase = reg,                                                                         \
        .GRFInfo[GRF_MUX_INFO] = { .offset = offset0, .bitsPerPin = bpp0, .pinsPerReg = ppr0 }, \
        .GRFInfo[GRF_PUL_INFO] = { .offset = offset1, .bitsPerPin = bpp1, .pinsPerReg = ppr1 }, \
        .GRFInfo[GRF_DRV_INFO] = { .offset = offset2, .bitsPerPin = bpp2, .pinsPerReg = ppr2 }, \
        .GRFInfo[GRF_SRT_INFO] = { .offset = offset3, .bitsPerPin = bpp3, .pinsPerReg = ppr3 }, \
        .GRFInfo[GRF_SMT_INFO] = { .offset = offset4, .bitsPerPin = bpp4, .pinsPerReg = ppr4 }, \
    }

/** @defgroup PINCTRL_GPIO_PINS Pins Definition
 *  @{
 */

#define GPIO_PIN_A0 (0x00000001U)  /*!< Pin 0 selected    */
#define GPIO_PIN_A1 (0x00000002U)  /*!< Pin 1 selected    */
#define GPIO_PIN_A2 (0x00000004U)  /*!< Pin 2 selected    */
#define GPIO_PIN_A3 (0x00000008U)  /*!< Pin 3 selected    */
#define GPIO_PIN_A4 (0x00000010U)  /*!< Pin 4 selected    */
#define GPIO_PIN_A5 (0x00000020U)  /*!< Pin 5 selected    */
#define GPIO_PIN_A6 (0x00000040U)  /*!< Pin 6 selected    */
#define GPIO_PIN_A7 (0x00000080U)  /*!< Pin 7 selected    */
#define GPIO_PIN_B0 (0x00000100U)  /*!< Pin 8 selected    */
#define GPIO_PIN_B1 (0x00000200U)  /*!< Pin 9 selected    */
#define GPIO_PIN_B2 (0x00000400U)  /*!< Pin 10 selected   */
#define GPIO_PIN_B3 (0x00000800U)  /*!< Pin 11 selected   */
#define GPIO_PIN_B4 (0x00001000U)  /*!< Pin 12 selected   */
#define GPIO_PIN_B5 (0x00002000U)  /*!< Pin 13 selected   */
#define GPIO_PIN_B6 (0x00004000U)  /*!< Pin 14 selected   */
#define GPIO_PIN_B7 (0x00008000U)  /*!< Pin 15 selected   */
#define GPIO_PIN_C0 (0x00010000U)  /*!< Pin 16 selected   */
#define GPIO_PIN_C1 (0x00020000U)  /*!< Pin 17 selected   */
#define GPIO_PIN_C2 (0x00040000U)  /*!< Pin 18 selected   */
#define GPIO_PIN_C3 (0x00080000U)  /*!< Pin 19 selected   */
#define GPIO_PIN_C4 (0x00100000U)  /*!< Pin 20 selected   */
#define GPIO_PIN_C5 (0x00200000U)  /*!< Pin 21 selected   */
#define GPIO_PIN_C6 (0x00400000U)  /*!< Pin 22 selected   */
#define GPIO_PIN_C7 (0x00800000U)  /*!< Pin 23 selected   */
#define GPIO_PIN_D0 (0x01000000U)  /*!< Pin 24 selected   */
#define GPIO_PIN_D1 (0x02000000U)  /*!< Pin 25 selected   */
#define GPIO_PIN_D2 (0x04000000U)  /*!< Pin 26 selected   */
#define GPIO_PIN_D3 (0x08000000U)  /*!< Pin 27 selected   */
#define GPIO_PIN_D4 (0x10000000U)  /*!< Pin 28 selected   */
#define GPIO_PIN_D5 (0x20000000U)  /*!< Pin 29 selected   */
#define GPIO_PIN_D6 (0x40000000U)  /*!< Pin 30 selected   */
#define GPIO_PIN_D7 (0x80000000U)  /*!< Pin 31 selected   */

#define GPIO_PIN_ALL (0xFFFFFFFFU)  /*!< All pins selected */

/** @} */

#define ROUTE_VAL(v, s, m) (((v) << (s)) | (m) << ((s) + 16))

/***************************** Structure Definition **************************/

struct PINCTRL_GRF_INFO {
    uint16_t offset;
    uint8_t bitsPerPin;
    uint8_t pinsPerReg;
};

struct PINCTRL_MUX_RECAL_DATA {
    uint32_t reg;
    uint8_t bank;
    uint8_t pin;
    uint8_t bit;
    uint8_t mask;
};

struct PINCTRL_MUX_ROUTE_DATA {
    uint32_t routeReg;
    uint32_t routeVal;
    uint32_t pin;
    uint8_t bank;
    uint8_t func;
};

struct PINCTRL_BANK_INFO {
    struct PINCTRL_GRF_INFO GRFInfo[GRF_INFO_NUM];
    uint32_t grfBase;
    uint8_t pinCount;
    uint8_t channel;
};

struct HAL_PINCTRL_DEV {
    const struct PINCTRL_BANK_INFO *banks;
    const struct PINCTRL_MUX_RECAL_DATA *muxRecalData;
    const struct PINCTRL_MUX_ROUTE_DATA *muxRouteData;
    uint8_t banksNum;
    uint8_t muxRecalDataNum;
    uint8_t muxRouteDataNum;
};

/** @brief  Rockchip pinctrl device struct define
 * Define a struct for pinctrl, including banks info, bank number,
 * and grf info about iomux offset, iomux bit info, drive/pull/
 * slewrate/schmitt offset and bit info.
 */
extern const struct HAL_PINCTRL_DEV g_pinDev;

/** @} */

/***************************** Function Declare ******************************/
/** @defgroup PINCTRL_Public_Function_Declare Public Function Declare
 *  @{
 */

HAL_Status HAL_PINCTRL_Suspend(void);
HAL_Status HAL_PINCTRL_Resume(void);

HAL_Status HAL_PINCTRL_Init(void);
HAL_Status HAL_PINCTRL_DeInit(void);

HAL_Status HAL_PINCTRL_SetParam(eGPIO_bankId bank, uint32_t mPins, ePINCTRL_configParam param);
HAL_Status HAL_PINCTRL_SetIOMUX(eGPIO_bankId bank, uint32_t mPins, ePINCTRL_configParam param);

/** @} */

#endif /* __HAL_PINCTRL_H__ */

/** @} */

/** @} */
