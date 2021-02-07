/*
 * Copyright (c) 2019 Rockchip Electronics Co. Ltd.
 * Author: Huaping Liao <huaping.liao@rock-chips.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "hal_dma.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "trace.h"
#include "io.h"
#include "cache.h"

#if CONFIG_SOC_RK2206 && ENABLE_DMA

#define HAL_MIN(x, y)     ((x) < (y) ? (x) : (y))

#define DW_CHAN_SET_BIT(reg, mask) \
        WRITE_REG(reg, ((mask) << 8) | (mask))
#define DW_CHAN_CLEAR_BIT(reg, mask) \
        WRITE_REG(reg, ((mask) << 8) | 0)

bool HAL_DMA_IsSlaveDirection(eDMA_TRANSFER_DIRECTION direction)
{
    return (direction == DMA_MEM_TO_DEV) || (direction == DMA_DEV_TO_MEM);
}

#define DWC_DEFAULT_CTLLO(_dwc) ({                                \
            struct DMA_SLAVE_CONFIG *_config = &_dwc->config;         \
            bool _islave = HAL_DMA_IsSlaveDirection(_dwc->direction); \
            uint8_t _smSize = _islave ? _config->srcMaxBurst :        \
                DWDMA_MSIZE_256;                                      \
            uint8_t _dmSize = _islave ? _config->dstMaxBurst :        \
                DWDMA_MSIZE_256;                                      \
                                                                      \
            (DWC_CTLL_DST_MSIZE(_dmSize)                              \
             | DWC_CTLL_SRC_MSIZE(_smSize)                            \
             | DWC_CTLL_LLP_D_EN                                      \
             | DWC_CTLL_LLP_S_EN                                      \
             | DWC_CTLL_DMS(_dwc->dstMaster)                          \
             | DWC_CTLL_SMS(_dwc->srcMaster));                        \
        })
    
    /********************* Private Structure Definition **************************/
    
    /********************* Private Variable Definition ***************************/
    
    /********************* Private Function Definition ***************************/
    
void DWC_DumpRegs(struct DWDMA_CHAN *dwc)
{
    LOGD("SAR: 0x%08lx DAR: 0x%08lx LLP: 0x%08lx CTL: 0x%08lx:%08lx\n",
            READ_REG(dwc->creg->SAR), READ_REG(dwc->creg->DAR),
            READ_REG(dwc->creg->LLP), READ_REG(dwc->creg->CTL_HI),
            READ_REG(dwc->creg->CTL_LO));
}

/**
 * Fix config's burst len to bit.
 */
void DW_ConvertBurst(uint16_t *maxburst)
{
    uint32_t val;

    switch (*maxburst) {
    case 1:
        val = 0;
        break;
    case 4:
        val = 1;
        break;
    case 8:
        val = 2;
        break;
    case 16:
        val = 3;
        break;
    case 32:
        val = 4;
        break;
    case 64:
        val = 5;
        break;
    case 128:
        val = 6;
        break;
    case 256:
        val = 7;
        break;
    default:
        val = 0;
        break;
    }

    *maxburst = val;
}

uint32_t DW_FFS(uint32_t word)
{
    int num = 0;

    rk_assert(word);
    if ((word & 0xffff) == 0) {
        num += 16;
        word >>= 16;
    }
    if ((word & 0xff) == 0) {
        num += 8;
        word >>= 8;
    }
    if ((word & 0xf) == 0) {
        num += 4;
        word >>= 4;
    }
    if ((word & 0x3) == 0) {
        num += 2;
        word >>= 2;
    }
    if ((word & 0x1) == 0)
        num += 1;

    return num;
}

static void DWDMA_off(struct HAL_DWDMA_DEV *dw)
{
    struct DMA_REG *reg = dw->pReg;

    WRITE_REG(reg->DMACFGREG, 0);

    DW_CHAN_CLEAR_BIT(reg->MASK.TFR, dw->allChanMask);
    DW_CHAN_CLEAR_BIT(reg->MASK.BLOCK, dw->allChanMask);
    DW_CHAN_CLEAR_BIT(reg->MASK.SRCTRAN, dw->allChanMask);
    DW_CHAN_CLEAR_BIT(reg->MASK.DSTTRAN, dw->allChanMask);
    DW_CHAN_CLEAR_BIT(reg->MASK.ERR, dw->allChanMask);

    while (READ_REG(reg->DMACFGREG) & DW_CFG_DMA_EN)
        ;
}

static void DWDMA_on(struct HAL_DWDMA_DEV *dw)
{
    struct DMA_REG *reg = dw->pReg;

    WRITE_REG(reg->DMACFGREG, DW_CFG_DMA_EN);
}

static void DWC_initialize(struct DWDMA_CHAN *dwc)
{
    struct HAL_DWDMA_DEV *dw = dwc->dw;
    uint32_t cfghi = DWC_CFGH_FIFO_MODE;
    uint32_t cfglo = 0;

    switch (dwc->direction) {
    case DMA_MEM_TO_DEV:
        cfghi |= DWC_CFGH_DST_PER(dwc->periId);
        break;
    case DMA_DEV_TO_MEM:
        cfghi |= DWC_CFGH_SRC_PER(dwc->periId);
        break;
    default:
        break;
    }

    WRITE_REG(dwc->creg->CFG_LO, cfglo);
    WRITE_REG(dwc->creg->CFG_HI, cfghi);

    /* Enable interrupts */
    DW_CHAN_SET_BIT(dw->pReg->MASK.TFR, dwc->mask);
    DW_CHAN_SET_BIT(dw->pReg->MASK.ERR, dwc->mask);
    if (dwc->cyclic)
        DW_CHAN_SET_BIT(dw->pReg->MASK.BLOCK, dwc->mask);
}

static void DWC_deinitialize(struct DWDMA_CHAN *dwc)
{
    struct HAL_DWDMA_DEV *dw = dwc->dw;

    /* Disable interrupts */
    DW_CHAN_CLEAR_BIT(dw->pReg->MASK.TFR, dwc->mask);
    DW_CHAN_CLEAR_BIT(dw->pReg->MASK.ERR, dwc->mask);
    if (dwc->cyclic)
        DW_CHAN_CLEAR_BIT(dw->pReg->MASK.BLOCK, dwc->mask);

    /* Clear interrupts. */
    WRITE_REG(dw->pReg->CLEAR.TFR, dwc->mask);
    WRITE_REG(dw->pReg->CLEAR.SRCTRAN, dwc->mask);
    WRITE_REG(dw->pReg->CLEAR.DSTTRAN, dwc->mask);
    WRITE_REG(dw->pReg->CLEAR.ERR, dwc->mask);
    if (dwc->cyclic)
        WRITE_REG(dw->pReg->CLEAR.BLOCK, dwc->mask);
}

static void DWC_HandleCyclic(struct HAL_DWDMA_DEV *dw, struct DWDMA_CHAN *dwc,
                             uint32_t statusBlock, uint32_t statusErr, uint32_t statusXfer)
{
    if (statusBlock & dwc->mask) {
        WRITE_REG(dw->pReg->CLEAR.BLOCK, dwc->mask);
        if (dwc->callback)
            dwc->callback(dwc->cparam);
    }

    /* TODO: execption handler */
    rk_assert(!statusErr && !statusXfer);

    DW_CHAN_SET_BIT(dw->pReg->MASK.BLOCK, dwc->mask);
}

static void DWC_HandleError(struct HAL_DWDMA_DEV *dw, struct DWDMA_CHAN *dwc)
{
    LOGD("%s: %d\n", __func__, __LINE__);

    /* TODO: error handler */
    DWC_DumpRegs(dwc);
    WRITE_REG(dw->pReg->CLEAR.ERR, dwc->mask);
}

static void DWC_HandleXfer(struct HAL_DWDMA_DEV *dw, struct DWDMA_CHAN *dwc)
{
    LOGD("%s: %d\n", __func__, __LINE__);

    WRITE_REG(dw->pReg->CLEAR.TFR, dwc->mask);

    if (dwc->callback)
        dwc->callback(dwc->cparam);
    //HAL_DWDMA_Stop(dwc);
}

/********************* Public Function Definition ****************************/

/** @defgroup DWDMA_Exported_Functions_Group2 State and Errors Functions

 This section provides functions allowing to get the status of the module:

 *  @{
 */

/** @} */

/** @defgroup DWDMA_Exported_Functions_Group4 Init and DeInit Functions

 This section provides functions allowing to init and deinit the module:

 *  @{
 */

/**
 * @brief Initializes a specific dw dma.
 *
 * @param dw: the handle of dw dma.
 *
 * @return
 *        - 0 on success.
 *        - HAL_ERROR on fail.
 */
int HAL_DWDMA_Init(struct HAL_DWDMA_DEV *dw)
{
    int i;
    struct DMA_REG *reg = dw->pReg;
    struct DWDMA_CHAN *dwc;

    rk_assert(dw);

    /* Calculate all channel mask before DMA setup */
    dw->allChanMask = (1 << DMA_NUM_CHANNELS) - 1;
    /* Force dma off, just in case */
    DWDMA_off(dw);

    for (i = 0; i < DMA_NUM_CHANNELS; i++) {
        dwc = &dw->chan[i];

        dwc->dw = dw;
        dwc->creg = &(dw->pReg->CHAN[i]);
        dwc->mask = 1 << i;
        /* clear bit */
        DW_CHAN_CLEAR_BIT(reg->CHENREG, dwc->mask);

        dwc->direction = DMA_TRANS_NONE;
    }

    /* Clear all interrupts on all channels. */
    WRITE_REG(reg->CLEAR.TFR, dw->allChanMask);
    WRITE_REG(reg->CLEAR.BLOCK, dw->allChanMask);
    WRITE_REG(reg->CLEAR.SRCTRAN, dw->allChanMask);
    WRITE_REG(reg->CLEAR.DSTTRAN, dw->allChanMask);
    WRITE_REG(reg->CLEAR.ERR, dw->allChanMask);

    return 0;
}

/**
 * @brief DeInitializes a specific dw dma.
 *
 * @param dw: the handle of dw dma.
 *
 * @return
 *        - 0 on success.
 *        - HAL_ERROR on fail.
 */
int HAL_DWDMA_DeInit(struct HAL_DWDMA_DEV *dw)
{
    rk_assert(dw);

    DWDMA_off(dw);

    DW_CHAN_CLEAR_BIT(dw->pReg->CHENREG, dw->allChanMask);

    return 0;
}

/** @} */

/** @defgroup DWDMA_Exported_Functions_Group3 IO Functions

 This section provides functions allowing to IO controlling:

 *  @{
 */

/**
 * @brief Start to run the dma chan.
 *
 * @param dwc: the handle of dma chan.
 *
 * @return
 *        - 0 on success
 *        - HAL_BUSY if chan is busy
 *        - HAL_ERROR on other failures
 */
int HAL_DWDMA_Start(struct DWDMA_CHAN *dwc)
{
    struct HAL_DWDMA_DEV *dw;
    struct DMA_REG *reg;

    rk_assert(dwc);

    dw = dwc->dw;
    reg = dw->pReg;

    if (READ_REG(reg->CHENREG) & dwc->mask) {
        LOGD("%s: chan is not idle\n", __func__);
        DWC_DumpRegs(dwc);

        return -1;
    }
    writel(0x41050200, 0x1000000);
    DWC_initialize(dwc);

    WRITE_REG(dwc->creg->LLP, TCM_ADDR_TRANS((uint32_t)&dwc->desc[0]));

    WRITE_REG(dwc->creg->CTL_LO,
              DWC_CTLL_LLP_D_EN | DWC_CTLL_LLP_S_EN);
    WRITE_REG(dwc->creg->CTL_HI, 0);
    DW_CHAN_SET_BIT(dw->pReg->CHENREG, dwc->mask);

    return 0;
}

/**
 * @brief Stop the dma chan.
 *
 * @param dwc: the handle of dma chan.
 *
 * @return
 *        - 0 on success
 *        - HAL_BUSY if dma is busy
 *        - HAL_ERROR on other failures
 */
int HAL_DWDMA_Stop(struct DWDMA_CHAN *dwc)
{
    struct HAL_DWDMA_DEV *dw;

    rk_assert(dwc);

    dw = dwc->dw;

    DW_CHAN_CLEAR_BIT(dw->pReg->CHENREG, dwc->mask);
    while (READ_REG(dw->pReg->CHENREG) & dwc->mask)
        ;

    DWC_deinitialize(dwc);

    return 0;
}

/**
 * @brief dw dma IrqHandler
 *
 * @param dw: the handle of dw dma.
 * @param chanId: the chan num.
 *
 * @return
 *        - 0 on success.
 *        - HAL_ERROR on fail.
 */
int HAL_DWDMA_IrqHandler(struct HAL_DWDMA_DEV *dw, uint32_t chanId)
{
    struct DWDMA_CHAN *dwc = &dw->chan[chanId];
    uint32_t statusBlock;
    uint32_t statusXfer;
    uint32_t statusErr;

    DW_CHAN_CLEAR_BIT(dw->pReg->MASK.TFR, dwc->mask);
    DW_CHAN_CLEAR_BIT(dw->pReg->MASK.BLOCK, dwc->mask);
    DW_CHAN_CLEAR_BIT(dw->pReg->MASK.ERR, dwc->mask);

    statusBlock = READ_REG(dw->pReg->RAW.BLOCK);
    statusXfer = READ_REG(dw->pReg->RAW.TFR);
    statusErr = READ_REG(dw->pReg->RAW.ERR);

    if (dwc->cyclic)
        DWC_HandleCyclic(dw, dwc, statusBlock, statusXfer, statusXfer);
    else if (statusErr & dwc->mask)
        DWC_HandleError(dw, dwc);
   // else if (statusXfer & dwc->mask)
    DWC_HandleXfer(dw, dwc);

    /* Re-enable interrupts */
    DW_CHAN_SET_BIT(dw->pReg->MASK.TFR, dwc->mask);
    DW_CHAN_SET_BIT(dw->pReg->MASK.ERR, dwc->mask);

    return 0;
}

/**
 * @brief Request a dma channel
 *
 * @param dw: the handle of dw dma.
 * @param id: the peri id.
 *
 * @return a idle dma channel.
 * @note must hold lock.
 */
struct DWDMA_CHAN *HAL_DWDMA_RequestChannel(struct HAL_DWDMA_DEV *dw, DMA_REQ_Type id)
{
    struct DWDMA_CHAN *dwc = NULL;
    int i;

    rk_assert(dw);

    if (!dw->used)
        DWDMA_on(dw);

    for (i = 0; i < DMA_NUM_CHANNELS; i++) {
        dwc = &dw->chan[i];

        if (dw->used & dwc->mask)
            continue;

        dwc->periId = id;
        dw->used |= dwc->mask;
        break;
    }

    if (i >= DMA_NUM_CHANNELS || !dwc)
        return NULL;

    return dwc;
}

/**
 * @brief Release a dma channel
 *
 * @param dwc: the handle of dma chan.
 *
 * @return
 *        - 0 on success.
 *        - HAL_ERROR on fail.
 * @note must hold lock.
 */
int HAL_DWDMA_ReleaseChannel(struct DWDMA_CHAN *dwc)
{
    struct HAL_DWDMA_DEV *dw;

    rk_assert(dwc);

    dw = dwc->dw;

    dwc->periId = 0xff;

    dwc->srcMaster = 0;
    dwc->dstMaster = 0;

    dwc->cyclic = false;

    /* Disable interrupts */
    DW_CHAN_CLEAR_BIT(dw->pReg->MASK.TFR, dwc->mask);
    DW_CHAN_CLEAR_BIT(dw->pReg->MASK.BLOCK, dwc->mask);
    DW_CHAN_CLEAR_BIT(dw->pReg->MASK.ERR, dwc->mask);

    dw->used &= ~dwc->mask;
    if (!dw->used)
        DWDMA_off(dw);

    return 0;
}

/**
 * @brief Config a dma channel
 *
 * @param dwc: the handle of dma chan.
 * @param config: the peri req config.
 *
 * @return
 *        - 0 on success.
 *        - HAL_ERROR on fail.
 */
int HAL_DWDMA_Config(struct DWDMA_CHAN *dwc, struct DMA_SLAVE_CONFIG *config)
{
    memcpy(&dwc->config, config, sizeof(*config));
    dwc->direction = config->direction;

    DW_ConvertBurst(&dwc->config.srcMaxBurst);
    DW_ConvertBurst(&dwc->config.dstMaxBurst);

    return 0;
}

/**
 * @brief Prepare a cyclic dma transfer for the channel
 *
 * @param dwc: the handle of dma chan.
 * @param dmaAddr: the memory addr.
 * @param len: data len.
 * @param periodLen: periodic len.
 * @param direction: transfer direction.
 * @param callback: callback function.
 * @param cparam: callback param.
 *
 * @return
 *        - 0 on success.
 *        - HAL_ERROR on fail.
 */
int HAL_DWDMA_PrepDmaCyclic(struct DWDMA_CHAN *dwc, uint32_t dmaAddr,
                                   uint32_t len, uint32_t periodLen,
                                   eDMA_TRANSFER_DIRECTION direction,
                                   DMA_Callback callback, void *cparam)
{
    struct HAL_DWDMA_DEV *dw;
    struct DMA_SLAVE_CONFIG *config;
    struct DW_DESC *desc, *last = NULL;
    uint32_t regWidth;
    uint32_t periods;
    uint32_t i;

    rk_assert(dwc);

    dw = dwc->dw;
    config = &dwc->config;

    rk_assert(HAL_DMA_IsSlaveDirection(direction));

    dwc->direction = direction;

    if (direction == DMA_MEM_TO_DEV)
        regWidth = DW_FFS(config->dstAddrWidth);
    else
        regWidth = DW_FFS(config->srcAddrWidth);

    periods = len / periodLen;

    /* Check for too big/unaligned periods and unaligned DMA buffer. */
    rk_assert(periodLen <= (dw->blockSize << regWidth));
    rk_assert(!(periodLen & ((1 << regWidth) - 1)));
    rk_assert(!(dmaAddr & ((1 << regWidth) - 1)));

    for (i = 0; i < periods; i++) {
        desc = &dwc->desc[i];

        rk_assert(desc);

        switch (direction) {
        case DMA_MEM_TO_DEV:
            desc->lli.dar = config->dstAddr;
            desc->lli.sar = dmaAddr + (periodLen * i);
            desc->lli.ctllo = (DWC_DEFAULT_CTLLO(dwc)
                               | DWC_CTLL_DST_WIDTH(regWidth)
                               | DWC_CTLL_SRC_WIDTH(regWidth)
                               | DWC_CTLL_DST_FIX
                               | DWC_CTLL_SRC_INC
                               | DWC_CTLL_INT_EN
                               | DWC_CTLL_FC_M2P);

            break;
        case DMA_DEV_TO_MEM:
            desc->lli.dar = dmaAddr + (periodLen * i);
            desc->lli.sar = config->srcAddr;
            desc->lli.ctllo = (DWC_DEFAULT_CTLLO(dwc)
                               | DWC_CTLL_SRC_WIDTH(regWidth)
                               | DWC_CTLL_DST_WIDTH(regWidth)
                               | DWC_CTLL_DST_INC
                               | DWC_CTLL_SRC_FIX
                               | DWC_CTLL_INT_EN
                               | DWC_CTLL_FC_P2M);

            break;
        default:
            break;
        }

        desc->lli.ctlhi = (periodLen >> regWidth);
        if (last)
            last->lli.llp = (uint32_t)desc;

        last = desc;
    }

    /* cyclic */
    last->lli.llp = (uint32_t)&dwc->desc[0];
    dwc->cyclic = true;
    dwc->callback = callback;
    dwc->cparam = cparam;

    xthal_dcache_region_writeback((void *)dwc->desc,
                            NR_DESCS_PER_CHANNEL * sizeof(*(dwc->desc)));

    return 0;
}

/**
 * @brief Prepare a single dma transfer for the channel
 *
 * @param dwc: the handle of dma chan.
 * @param dmaAddr: the memory addr.
 * @param len: data len.
 * @param direction: transfer direction.
 * @param callback: callback function.
 * @param cparam: callback param.
 *
 * @return
 *        - 0 on success.
 *        - HAL_ERROR on fail.
 */
int HAL_DWDMA_PrepDmaSingle(struct DWDMA_CHAN *dwc, uint32_t dmaAddr,
                                   uint32_t len,
                                   eDMA_TRANSFER_DIRECTION direction,
                                   DMA_Callback callback, void *cparam)
{
    struct HAL_DWDMA_DEV *dw;
    struct DMA_SLAVE_CONFIG *config;
    struct DW_DESC *desc, *last = NULL;
    uint32_t regWidth;
    uint32_t xferCount;
    uint32_t offset;
    uint32_t src, dst;
    uint32_t ctllo;
    uint32_t i = 0;

    rk_assert(dwc);

    dw = dwc->dw;
    config = &dwc->config;

    rk_assert(HAL_DMA_IsSlaveDirection(direction));

    dwc->direction = direction;

    if (direction == DMA_MEM_TO_DEV) {
        regWidth = DW_FFS(config->dstAddrWidth);
        src = dmaAddr;
        dst = config->dstAddr;
        ctllo = (DWC_DEFAULT_CTLLO(dwc)
                 | DWC_CTLL_SRC_WIDTH(regWidth)
                 | DWC_CTLL_DST_WIDTH(regWidth)
                 | DWC_CTLL_DST_FIX
                 | DWC_CTLL_SRC_INC
                 | DWC_CTLL_FC_M2P);
    } else {
        regWidth = DW_FFS(config->srcAddrWidth);
        src = config->srcAddr;
        dst = dmaAddr;
        ctllo = (DWC_DEFAULT_CTLLO(dwc)
                 | DWC_CTLL_SRC_WIDTH(regWidth)
                 | DWC_CTLL_DST_WIDTH(regWidth)
                 | DWC_CTLL_DST_INC
                 | DWC_CTLL_SRC_FIX
                 | DWC_CTLL_FC_P2M);
    }

    for (offset = 0; offset < len; offset += xferCount << regWidth) {
        xferCount = HAL_MIN((len - offset) >> regWidth, dw->blockSize);

        desc = &dwc->desc[i];

        desc->lli.sar = (ctllo & DWC_CTLL_SRC_FIX) ? src : src + offset;
        desc->lli.dar = (ctllo & DWC_CTLL_DST_FIX) ? dst : dst + offset;
        desc->lli.ctllo = ctllo;
        desc->lli.ctlhi = xferCount;
        desc->len = xferCount << regWidth;

        if (last)
            last->lli.llp = (uint32_t)desc;

        last = desc;

        i++;
    }

    last->lli.ctllo |= DWC_CTLL_INT_EN;
    last->lli.llp = 0;
    dwc->desc[0].totalLen = len;

    dwc->callback = callback;
    dwc->cparam = cparam;

    xthal_dcache_region_writeback((void *)dwc->desc,
                            NR_DESCS_PER_CHANNEL * sizeof(*(dwc->desc)));

    return 0;
}

/**
 * @brief Prepare a dma memcpy
 *
 * @param dwc: the handle of dma chan.
 * @param dst: the memory dst addr.
 * @param src: the memory src addr.
 * @param len: data len.
 * @param callback: callback function.
 * @param cparam: callback param.
 *
 * @return
 *        - 0 on success.
 *        - HAL_ERROR on fail.
 */
int get_result(struct DWDMA_CHAN *_dwc)
{
    struct DMA_SLAVE_CONFIG *_config = &_dwc->config;
    bool _islave = HAL_DMA_IsSlaveDirection(_dwc->direction);
    uint8_t _smSize = _islave ? _config->srcMaxBurst :
        DWDMA_MSIZE_256;
    uint8_t _dmSize = _islave ? _config->dstMaxBurst :
        DWDMA_MSIZE_256;

    return (DWC_CTLL_DST_MSIZE(_dmSize)
     | DWC_CTLL_SRC_MSIZE(_smSize)
     | DWC_CTLL_LLP_D_EN
     | DWC_CTLL_LLP_S_EN
     | DWC_CTLL_DMS(_dwc->dstMaster)
     | DWC_CTLL_SMS(_dwc->srcMaster));
}

int HAL_DWDMA_PrepDmaMemcpy(struct DWDMA_CHAN *dwc, uint32_t dst,
                                   uint32_t src, uint32_t len,
                                   DMA_Callback callback, void *cparam)
{
    struct HAL_DWDMA_DEV *dw;
    struct DW_DESC *desc, *last = NULL;
    uint32_t xferCount;
    uint32_t offset;
    uint32_t srcWidth;
    uint32_t dstWidth;
    uint32_t dataWidth;
    uint32_t ctllo;
    int i = 0;

    rk_assert(dwc);
    rk_assert(len);

    dw = dwc->dw;

    dwc->direction = DMA_MEM_TO_MEM;

    dataWidth = dw->dataWidth;

    srcWidth = dstWidth = DW_FFS(dataWidth | src | dst | len);

    ctllo = get_result(dwc);
    ctllo       |= DWC_CTLL_DST_WIDTH(dstWidth)
            | DWC_CTLL_SRC_WIDTH(srcWidth)
            | DWC_CTLL_DST_INC
            | DWC_CTLL_SRC_INC
            | DWC_CTLL_FC_M2M;

    for (offset = 0; offset < len; offset += xferCount << srcWidth) {
        xferCount = HAL_MIN((len - offset) >> srcWidth, dw->blockSize);

        desc = &dwc->desc[i];

        desc->lli.sar = src + offset;
        desc->lli.dar = dst + offset;
        desc->lli.ctllo = ctllo;
        desc->lli.ctlhi = xferCount;
        desc->len = xferCount << srcWidth;

        if (last)
            last->lli.llp = (uint32_t)desc;

        last = desc;

        i++;
    }

    last->lli.ctllo |= DWC_CTLL_INT_EN;
    last->lli.llp = 0;
    dwc->desc[0].totalLen = len;

    dwc->callback = callback;
    dwc->cparam = cparam;

    LOGD("addr = %x, size = %d\n", dwc->desc, NR_DESCS_PER_CHANNEL * sizeof(*(dwc->desc)));
    xthal_dcache_region_writeback((void *)dwc->desc,
                            NR_DESCS_PER_CHANNEL * sizeof(*(dwc->desc)));

    return 0;
}

#endif
