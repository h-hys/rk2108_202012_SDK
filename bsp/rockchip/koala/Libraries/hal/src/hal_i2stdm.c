/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */

#include "hal_base.h"

#ifdef HAL_I2STDM_MODULE_ENABLED

/** @addtogroup RK_HAL_Driver
 *  @{
 */

/** @addtogroup I2STDM
 *  @{
 */

/** @defgroup I2STDM_How_To_Use How To Use
 *  @{

 The I2STDM driver can be used as follows:

 @} */

/** @defgroup I2STDM_Private_Definition Private Definition
 *  @{
 */
/********************* Private MACRO Definition ******************************/

#define I2STDM_DMA_BURST_SIZE (8) /* size * width: 8*4 = 32 bytes */

/*
 * TXCR
 * transmit operation control register
 */
#define I2STDM_TXCR_PATH_SHIFT(x) (23 + (x) * 2)
#define I2STDM_TXCR_PATH_MASK(x)  (0x3 << I2STDM_TXCR_PATH_SHIFT(x))
#define I2STDM_TXCR_PATH(x, v)    ((v) << I2STDM_TXCR_PATH_SHIFT(x))
#define I2STDM_TXCR_CSR(x)        (x << I2STDM_TXCR_TCSR_SHIFT)
#define I2STDM_TXCR_HWT           (1 << I2STDM_TXCR_HWT_SHIFT)
#define I2STDM_TXCR_SJM_R         (0 << I2STDM_TXCR_SJM_SHIFT)
#define I2STDM_TXCR_SJM_L         (1 << I2STDM_TXCR_SJM_SHIFT)
#define I2STDM_TXCR_FBM_MSB       (0 << I2STDM_TXCR_FBM_SHIFT)
#define I2STDM_TXCR_FBM_LSB       (1 << I2STDM_TXCR_FBM_SHIFT)
#define I2STDM_TXCR_IBM_NORMAL    (0 << I2STDM_TXCR_IBM_SHIFT)
#define I2STDM_TXCR_IBM_LSJM      (1 << I2STDM_TXCR_IBM_SHIFT)
#define I2STDM_TXCR_IBM_RSJM      (2 << I2STDM_TXCR_IBM_SHIFT)
#define I2STDM_TXCR_PBM_MODE(x)   ((x) << I2STDM_TXCR_PBM_SHIFT)
#define I2STDM_TXCR_TFS_I2S       (0 << I2STDM_TXCR_TFS_SHIFT)
#define I2STDM_TXCR_TFS_PCM       (1 << I2STDM_TXCR_TFS_SHIFT)
#define I2STDM_TXCR_TFS_TDM_PCM   (2 << I2STDM_TXCR_TFS_SHIFT)
#define I2STDM_TXCR_TFS_TDM_I2S   (3 << I2STDM_TXCR_TFS_SHIFT)
#define I2STDM_TXCR_VDW(x)        ((x - 1) << I2STDM_TXCR_VDW_SHIFT)

/*
 * RXCR
 * receive operation control register
 */
#define I2STDM_RXCR_PATH_SHIFT(x) (17 + (x) * 2)
#define I2STDM_RXCR_PATH_MASK(x)  (0x3 << I2STDM_RXCR_PATH_SHIFT(x))
#define I2STDM_RXCR_PATH(x, v)    ((v) << I2STDM_RXCR_PATH_SHIFT(x))
#define I2STDM_RXCR_CSR(x)        (x << I2STDM_RXCR_RCSR_SHIFT)
#define I2STDM_RXCR_HWT           (1 << I2STDM_RXCR_HWT_SHIFT)
#define I2STDM_RXCR_SJM_R         (0 << I2STDM_RXCR_SJM_SHIFT)
#define I2STDM_RXCR_SJM_L         (1 << I2STDM_RXCR_SJM_SHIFT)
#define I2STDM_RXCR_FBM_MSB       (0 << I2STDM_RXCR_FBM_SHIFT)
#define I2STDM_RXCR_FBM_LSB       (1 << I2STDM_RXCR_FBM_SHIFT)
#define I2STDM_RXCR_IBM_NORMAL    (0 << I2STDM_RXCR_IBM_SHIFT)
#define I2STDM_RXCR_IBM_LSJM      (1 << I2STDM_RXCR_IBM_SHIFT)
#define I2STDM_RXCR_IBM_RSJM      (2 << I2STDM_RXCR_IBM_SHIFT)
#define I2STDM_RXCR_PBM_MODE(x)   ((x) << I2STDM_RXCR_PBM_SHIFT)
#define I2STDM_RXCR_TFS_I2S       (0 << I2STDM_RXCR_TFS_SHIFT)
#define I2STDM_RXCR_TFS_PCM       (1 << I2STDM_RXCR_TFS_SHIFT)
#define I2STDM_RXCR_TFS_TDM_PCM   (2 << I2STDM_RXCR_TFS_SHIFT)
#define I2STDM_RXCR_TFS_TDM_I2S   (3 << I2STDM_RXCR_TFS_SHIFT)
#define I2STDM_RXCR_VDW(x)        ((x - 1) << I2STDM_RXCR_VDW_SHIFT)

/*
 * CKR
 * clock generation register
 */
#define I2STDM_CKR_TRCM(x)     (x << I2STDM_CKR_TRCM_SHIFT)
#define I2STDM_CKR_TRCM_TXRX   (0 << I2STDM_CKR_TRCM_SHIFT)
#define I2STDM_CKR_TRCM_TXONLY (1 << I2STDM_CKR_TRCM_SHIFT)
#define I2STDM_CKR_TRCM_RXONLY (2 << I2STDM_CKR_TRCM_SHIFT)
#define I2STDM_CKR_MSS_MASTER  (0 << I2STDM_CKR_MSS_SHIFT)
#define I2STDM_CKR_MSS_SLAVE   (1 << I2STDM_CKR_MSS_SHIFT)
#define I2STDM_CKR_CKP_NEG     (0 << I2STDM_CKR_CKP_SHIFT)
#define I2STDM_CKR_CKP_POS     (1 << I2STDM_CKR_CKP_SHIFT)
#define I2STDM_CKR_RLP_NORMAL  (0 << I2STDM_CKR_RLP_SHIFT)
#define I2STDM_CKR_RLP_OPPSITE (1 << I2STDM_CKR_RLP_SHIFT)
#define I2STDM_CKR_TLP_NORMAL  (0 << I2STDM_CKR_TLP_SHIFT)
#define I2STDM_CKR_TLP_OPPSITE (1 << I2STDM_CKR_TLP_SHIFT)
#define I2STDM_CKR_MDIV(x)     ((x - 1) << I2STDM_CKR_MDIV_SHIFT)
#define I2STDM_CKR_RSD(x)      ((x - 1) << I2STDM_CKR_RSD_SHIFT)
#define I2STDM_CKR_TSD(x)      ((x - 1) << I2STDM_CKR_TSD_SHIFT)

/*
 * DMACR
 * DMA control register
 */
#define I2STDM_DMACR_RDE_DISABLE (0 << I2STDM_DMACR_RDE_SHIFT)
#define I2STDM_DMACR_RDE_ENABLE  (1 << I2STDM_DMACR_RDE_SHIFT)
#define I2STDM_DMACR_RDL(x)      ((x - 1) << I2STDM_DMACR_RDL_SHIFT)
#define I2STDM_DMACR_TDE_DISABLE (0 << I2STDM_DMACR_TDE_SHIFT)
#define I2STDM_DMACR_TDE_ENABLE  (1 << I2STDM_DMACR_TDE_SHIFT)
#define I2STDM_DMACR_TDL(x)      ((x) << I2STDM_DMACR_TDL_SHIFT)

/*
 * XFER
 * Transfer start register
 */
#define I2STDM_XFER_RXS_STOP  (0 << I2STDM_XFER_RXS_SHIFT)
#define I2STDM_XFER_RXS_START (1 << I2STDM_XFER_RXS_SHIFT)
#define I2STDM_XFER_TXS_STOP  (0 << I2STDM_XFER_TXS_SHIFT)
#define I2STDM_XFER_TXS_START (1 << I2STDM_XFER_TXS_SHIFT)

/*
 * CLR
 * clear SCLK domain logic register
 */
#define I2STDM_CLR_RXC (1 << I2STDM_CLR_RXC_SHIFT)
#define I2STDM_CLR_TXC (1 << I2STDM_CLR_TXC_SHIFT)

/* channel select */
#define I2STDM_CSR_SHIFT 15
#define I2STDM_CHN_2     (0 << I2STDM_CSR_SHIFT)
#define I2STDM_CHN_4     (1 << I2STDM_CSR_SHIFT)
#define I2STDM_CHN_6     (2 << I2STDM_CSR_SHIFT)
#define I2STDM_CHN_8     (3 << I2STDM_CSR_SHIFT)

/*
 * TDM_CTRL
 * TDM ctrl register
 */
#define TDM_FSYNC_WIDTH_SEL1_SHIFT 18
#define TDM_FSYNC_WIDTH_SEL1_MSK   (0X7 << TDM_FSYNC_WIDTH_SEL1_SHIFT)
#define TDM_FSYNC_WIDTH_SEL1(x)    ((x - 1) << TDM_FSYNC_WIDTH_SEL1_SHIFT)
#define TDM_FSYNC_WIDTH_SEL0_MSK   HAL_BIT(17)
#define TDM_FSYNC_WIDTH_HALF_FRAME 0
#define TDM_FSYNC_WIDTH_ONE_FRAME  HAL_BIT(17)
#define TDM_SHIFT_CTRL_SHIFT       14
#define TDM_SHIFT_CTRL_MSK         (0x7 << TDM_SHIFT_CTRL_SHIFT)
#define TDM_SHIFT_CTRL(x)          ((x) << TDM_SHIFT_CTRL_SHIFT)
#define TDM_SLOT_BIT_WIDTH_SHIFT   9
#define TDM_SLOT_BIT_WIDTH_MSK     (0x1f << TDM_SLOT_BIT_WIDTH_SHIFT)
#define TDM_SLOT_BIT_WIDTH(x)      ((x - 1) << TDM_SLOT_BIT_WIDTH_SHIFT)
#define TDM_FRAME_WIDTH_SHIFT      0
#define TDM_FRAME_WIDTH_MSK        (0x1ff << TDM_FRAME_WIDTH_SHIFT)
#define TDM_FRAME_WIDTH(x)         ((x - 1) << TDM_FRAME_WIDTH_SHIFT)

/*
 * CLKDIV
 * Mclk div register
 */
#define I2STDM_CLKDIV_TX_MDIV(x) ((x - 1) << I2STDM_CLKDIV_TX_MDIV_SHIFT)
#define I2STDM_CLKDIV_RX_MDIV(x) ((x - 1) << I2STDM_CLKDIV_RX_MDIV_SHIFT)

/********************* Private Structure Definition **************************/

/********************* Private Variable Definition ***************************/

/********************* Private Function Definition ***************************/

static HAL_Status I2STDM_SetSampleRate(struct HAL_I2STDM_DEV *i2sTdm,
                                       eAUDIO_streamType stream,
                                       eAUDIO_sampleRate sampleRate)
{
    struct I2STDM_REG *reg = i2sTdm->pReg;
    uint32_t mclkRate, bclkRate, divBclk, divLrck;
    HAL_Status ret = HAL_OK;

    if (i2sTdm->trcmMode) {
        if (i2sTdm->trcmMode == TRCM_TXONLY) {
            mclkRate = HAL_CRU_ClkGetFreq(i2sTdm->mclkTx);
        } else {
            mclkRate = HAL_CRU_ClkGetFreq(i2sTdm->mclkRx);
        }

        bclkRate = i2sTdm->bclkFs * sampleRate;
        HAL_ASSERT(bclkRate != 0);
        divBclk = HAL_DivRoundClosest(mclkRate, bclkRate);
        divLrck = bclkRate / sampleRate;
        MODIFY_REG(reg->CLKDIV,
                   I2STDM_CLKDIV_TX_MDIV_MASK | I2STDM_CLKDIV_RX_MDIV_MASK,
                   I2STDM_CLKDIV_TX_MDIV(divBclk) | I2STDM_CLKDIV_RX_MDIV(divBclk));
        MODIFY_REG(reg->CKR,
                   I2STDM_CKR_TSD_MASK | I2STDM_CKR_RSD_MASK,
                   I2STDM_CKR_TSD(divLrck) | I2STDM_CKR_RSD(divLrck));
    } else {
        if (stream == AUDIO_STREAM_PLAYBACK) {
            mclkRate = HAL_CRU_ClkGetFreq(i2sTdm->mclkTx);
        } else {
            mclkRate = HAL_CRU_ClkGetFreq(i2sTdm->mclkRx);
        }

        bclkRate = i2sTdm->bclkFs * sampleRate;
        HAL_ASSERT(bclkRate != 0);
        divBclk = HAL_DivRoundClosest(mclkRate, bclkRate);
        divLrck = bclkRate / sampleRate;

        if (stream == AUDIO_STREAM_PLAYBACK) {
            MODIFY_REG(reg->CLKDIV,
                       I2STDM_CLKDIV_TX_MDIV_MASK,
                       I2STDM_CLKDIV_TX_MDIV(divBclk));
            MODIFY_REG(reg->CKR,
                       I2STDM_CKR_TSD_MASK,
                       I2STDM_CKR_TSD(divLrck));
        } else {
            MODIFY_REG(reg->CLKDIV,
                       I2STDM_CLKDIV_RX_MDIV_MASK,
                       I2STDM_CLKDIV_RX_MDIV(divBclk));
            MODIFY_REG(reg->CKR,
                       I2STDM_CKR_RSD_MASK,
                       I2STDM_CKR_RSD(divLrck));
        }
    }

    return ret;
}

/** @} */
/********************* Public Function Definition ****************************/
/** @defgroup I2STDM_Exported_Functions_Group1 Suspend and Resume Functions

 This section provides functions allowing to suspend and resume the module:

 ...to do or delete this row

 *  @{
 */

/**
 * @brief  i2sTdm suspend.
 * @param  i2sTdm: the handle of i2sTdm.
 * @return HAL_Status
 */
HAL_Status HAL_I2STDM_Supsend(struct HAL_I2STDM_DEV *i2sTdm)
{
    return HAL_OK;
}

/**
 * @brief  i2sTdm resume.
 * @param  i2sTdm: the handle of i2sTdm.
 * @return HAL_Status
 */
HAL_Status HAL_I2STDM_Resume(struct HAL_I2STDM_DEV *i2sTdm)
{
    return HAL_OK;
}

/** @} */

/** @defgroup I2STDM_Exported_Functions_Group2 State and Errors Functions

 This section provides functions allowing to get the status of the module:

 *  @{
 */

/** @} */

/** @defgroup I2STDM_Exported_Functions_Group3 IO Functions

 This section provides functions allowing to IO controlling:

 *  @{
 */

/** @} */

/** @defgroup I2STDM_Exported_Functions_Group4 Init and DeInit Functions

 This section provides functions allowing to init and deinit the module:

 ...to do or delete this row

 *  @{
 */

/**
 * @brief  Init i2sTdm controller.
 * @param  i2sTdm: the handle of i2sTdm.
 * @param  config: init config for i2sTdm init.
 * @return HAL_Status
 */
HAL_Status HAL_I2STDM_Init(struct HAL_I2STDM_DEV *i2sTdm, struct AUDIO_INIT_CONFIG *config)
{
    uint32_t mask = 0, val = 0;
    bool isMaster = config->master;
    bool clkInvert = config->clkInvert;
    uint16_t rxMap = config->rxMap;
    uint16_t txMap = config->txMap;
    struct I2STDM_REG *reg = i2sTdm->pReg;

    switch (config->format) {
    case AUDIO_FMT_I2S:
        MODIFY_REG(reg->TXCR, I2STDM_TXCR_TFS_MASK, I2STDM_TXCR_TFS_I2S);
        MODIFY_REG(reg->RXCR, I2STDM_RXCR_TFS_MASK, I2STDM_RXCR_TFS_I2S);
        break;

    case AUDIO_FMT_PCM:
    case AUDIO_FMT_PCM_DELAY1:
    case AUDIO_FMT_PCM_DELAY2:
    case AUDIO_FMT_PCM_DELAY3:
        MODIFY_REG(reg->TXCR,
                   I2STDM_TXCR_TFS_MASK |
                   I2STDM_TXCR_PBM_MASK,
                   I2STDM_TXCR_TFS_PCM |
                   I2STDM_TXCR_PBM_MODE(config->format - AUDIO_FMT_PCM));
        MODIFY_REG(reg->RXCR,
                   I2STDM_RXCR_TFS_MASK |
                   I2STDM_RXCR_TFS_PCM,
                   I2STDM_RXCR_TFS_PCM |
                   I2STDM_RXCR_PBM_MODE(config->format - AUDIO_FMT_PCM));
        break;

    default:
        break;
    }

    mask = I2STDM_CKR_MSS_MASK;
    val = isMaster ? I2STDM_CKR_MSS_MASTER : I2STDM_CKR_MSS_SLAVE;
    MODIFY_REG(reg->CKR, mask, val);

    mask = I2STDM_CKR_CKP_MASK;
    val = clkInvert ? I2STDM_CKR_CKP_POS : I2STDM_CKR_CKP_NEG;
    MODIFY_REG(reg->CKR, mask, val);

    HAL_ASSERT(config->trcmMode <= TRCM_RXONLY);
    i2sTdm->trcmMode = config->trcmMode;
    MODIFY_REG(reg->CKR, I2STDM_CKR_LRCK_COMMON_MASK,
               i2sTdm->trcmMode << I2STDM_CKR_LRCK_COMMON_SHIFT);

    /* channel re-mapping */
    if (txMap) {
        MODIFY_REG(reg->TXCR,
                   I2STDM_TXCR_PATH_MASK(0) |
                   I2STDM_TXCR_PATH_MASK(1) |
                   I2STDM_TXCR_PATH_MASK(2) |
                   I2STDM_TXCR_PATH_MASK(3),
                   I2STDM_TXCR_PATH(0, txMap & 0x3) |
                   I2STDM_TXCR_PATH(1, (txMap >> 4) & 0x3) |
                   I2STDM_TXCR_PATH(2, (txMap >> 8) & 0x3) |
                   I2STDM_TXCR_PATH(3, (txMap >> 12) & 0x3));
    }

    if (rxMap) {
        MODIFY_REG(reg->RXCR,
                   I2STDM_RXCR_PATH_MASK(0) |
                   I2STDM_RXCR_PATH_MASK(1) |
                   I2STDM_RXCR_PATH_MASK(2) |
                   I2STDM_RXCR_PATH_MASK(3),
                   I2STDM_RXCR_PATH(0, rxMap & 0x3) |
                   I2STDM_RXCR_PATH(1, (rxMap >> 4) & 0x3) |
                   I2STDM_RXCR_PATH(2, (rxMap >> 8) & 0x3) |
                   I2STDM_RXCR_PATH(3, (rxMap >> 12) & 0x3));
    }

    return HAL_OK;
}

/**
 * @brief  DeInit i2sTdm controller.
 * @param  i2sTdm: the handle of i2sTdm.
 * @return HAL_Status
 */
HAL_Status HAL_I2STDM_DeInit(struct HAL_I2STDM_DEV *i2sTdm)
{
    /* Do nothing. */
    return HAL_OK;
}

/** @} */

/** @defgroup I2STDM_Exported_Functions_Group5 Other Functions
 *  @{
 */

/**
 * @brief  Enable i2sTdm controller.
 * @param  i2sTdm: the handle of i2sTdm.
 * @param  stream: AUDIO_STREAM_PLAYBACK or AUDIO_STREAM_CAPTURE.
 * @return HAL_Status
 */
HAL_Status HAL_I2STDM_Enable(struct HAL_I2STDM_DEV *i2sTdm, eAUDIO_streamType stream)
{
    struct I2STDM_REG *reg = i2sTdm->pReg;

    if (stream == AUDIO_STREAM_PLAYBACK) {
        MODIFY_REG(reg->DMACR, I2STDM_DMACR_TDE_MASK, I2STDM_DMACR_TDE_ENABLE);
        MODIFY_REG(reg->XFER, I2STDM_XFER_TXS_MASK, I2STDM_XFER_TXS_START);
    } else {
        MODIFY_REG(reg->DMACR, I2STDM_DMACR_RDE_MASK, I2STDM_DMACR_RDE_ENABLE);
        MODIFY_REG(reg->XFER, I2STDM_XFER_RXS_MASK, I2STDM_XFER_RXS_START);
    }

    return HAL_OK;
}

/**
 * @brief  Disable i2sTdm controller.
 * @param  i2sTdm: the handle of i2sTdm.
 * @param  stream: AUDIO_STREAM_PLAYBACK or AUDIO_STREAM_CAPTURE.
 * @return HAL_Status
 */
HAL_Status HAL_I2STDM_Disable(struct HAL_I2STDM_DEV *i2sTdm, eAUDIO_streamType stream)
{
    struct I2STDM_REG *reg = i2sTdm->pReg;

    if (stream == AUDIO_STREAM_PLAYBACK) {
        MODIFY_REG(reg->DMACR, I2STDM_DMACR_TDE_MASK, I2STDM_DMACR_TDE_DISABLE);
        MODIFY_REG(reg->XFER, I2STDM_XFER_TXS_MASK, I2STDM_XFER_TXS_STOP);
        HAL_DelayUs(150);
        MODIFY_REG(reg->CLR, I2STDM_CLR_TXC_MASK, I2STDM_CLR_TXC);
    } else {
        MODIFY_REG(reg->DMACR, I2STDM_DMACR_RDE_MASK, I2STDM_DMACR_RDE_DISABLE);
        MODIFY_REG(reg->XFER, I2STDM_XFER_RXS_MASK, I2STDM_XFER_RXS_STOP);
        HAL_DelayUs(150);
        MODIFY_REG(reg->CLR, I2STDM_CLR_RXC_MASK, I2STDM_CLR_RXC);
    }

    return HAL_OK;
}

/**
 * @brief  Enable i2sTdm controller under trcm conditions.
 * @param  i2sTdm: the handle of i2sTdm.
 * @param  stream: AUDIO_STREAM_PLAYBACK or AUDIO_STREAM_CAPTURE.
 * @param  doXfer: whether start to handle xfer registers.
 * @return HAL_Status
 */
HAL_Status HAL_I2STDM_TxRxEnable(struct HAL_I2STDM_DEV *i2sTdm, eAUDIO_streamType stream,
                                 bool doXfer)
{
    struct I2STDM_REG *reg = i2sTdm->pReg;

    if (stream == AUDIO_STREAM_PLAYBACK) {
        MODIFY_REG(reg->DMACR, I2STDM_DMACR_TDE_MASK, I2STDM_DMACR_TDE_ENABLE);
    } else {
        MODIFY_REG(reg->DMACR, I2STDM_DMACR_RDE_MASK, I2STDM_DMACR_RDE_ENABLE);
    }

    if (doXfer) {
        MODIFY_REG(reg->XFER, I2STDM_XFER_TXS_MASK | I2STDM_XFER_RXS_MASK,
                   I2STDM_XFER_TXS_START | I2STDM_XFER_RXS_START);
    }

    return HAL_OK;
}

/**
 * @brief  Disable i2sTdm controller under trcm conditions.
 * @param  i2sTdm: the handle of i2sTdm.
 * @param  stream: AUDIO_STREAM_PLAYBACK or AUDIO_STREAM_CAPTURE.
 * @param  doXfer: whether start to handle xfer registers.
 * @return HAL_Status
 */
HAL_Status HAL_I2STDM_TxRxDisable(struct HAL_I2STDM_DEV *i2sTdm, eAUDIO_streamType stream,
                                  bool doXfer)
{
    struct I2STDM_REG *reg = i2sTdm->pReg;

    if (stream == AUDIO_STREAM_PLAYBACK) {
        MODIFY_REG(reg->DMACR, I2STDM_DMACR_TDE_MASK, I2STDM_DMACR_TDE_DISABLE);
    } else {
        MODIFY_REG(reg->DMACR, I2STDM_DMACR_RDE_MASK, I2STDM_DMACR_RDE_DISABLE);
    }

    if (doXfer) {
        MODIFY_REG(reg->XFER, I2STDM_XFER_TXS_MASK | I2STDM_XFER_RXS_MASK,
                   I2STDM_XFER_TXS_STOP | I2STDM_XFER_RXS_STOP);
        HAL_DelayUs(150);
        MODIFY_REG(reg->CLR, I2STDM_CLR_TXC_MASK | I2STDM_CLR_RXC_MASK,
                   I2STDM_CLR_TXC | I2STDM_CLR_RXC);
    }

    return HAL_OK;
}

/**
 * @brief  Config i2sTdm controller.
 * @param  i2sTdm: the handle of i2sTdm.
 * @param  stream: AUDIO_STREAM_PLAYBACK or AUDIO_STREAM_CAPTURE.
 * @param  params: audio params.
 * @return HAL_Status
 */
HAL_Status HAL_I2STDM_Config(struct HAL_I2STDM_DEV *i2sTdm, eAUDIO_streamType stream,
                             struct AUDIO_PARAMS *params)
{
    struct I2STDM_REG *reg = i2sTdm->pReg;
    uint32_t val = 0;
    HAL_Status ret = HAL_OK;
    bool isMaster;

    isMaster = (READ_BIT(reg->CKR, I2STDM_CKR_MSS_MASK) == I2STDM_CKR_MSS_MASTER);
    if (isMaster) {
        I2STDM_SetSampleRate(i2sTdm, stream, params->sampleRate);
    }

    switch (params->channels) {
    case 8:
        val |= I2STDM_CHN_8;
        break;
    case 6:
        val |= I2STDM_CHN_6;
        break;
    case 4:
        val |= I2STDM_CHN_4;
        break;
    case 2:
        val |= I2STDM_CHN_2;
        break;
    default:

        return HAL_INVAL;
    }

    if (stream == AUDIO_STREAM_CAPTURE) {
        val |= I2STDM_RXCR_VDW(params->sampleBits);
        MODIFY_REG(reg->RXCR,
                   I2STDM_RXCR_VDW_MASK | I2STDM_RXCR_RCSR_MASK,
                   val);
    } else {
        val |= I2STDM_TXCR_VDW(params->sampleBits);
        MODIFY_REG(reg->TXCR,
                   I2STDM_TXCR_VDW_MASK | I2STDM_TXCR_TCSR_MASK,
                   val);
    }

    MODIFY_REG(reg->DMACR, I2STDM_DMACR_TDL_MASK, I2STDM_DMACR_TDL(I2STDM_DMA_BURST_SIZE));
    MODIFY_REG(reg->DMACR, I2STDM_DMACR_RDL_MASK, I2STDM_DMACR_RDL(I2STDM_DMA_BURST_SIZE));

    return ret;
}

/** @} */

/** @} */

/** @} */

#endif /* HAL_I2STDM_MODULE_ENABLED */
