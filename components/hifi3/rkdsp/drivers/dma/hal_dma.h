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

#ifndef __HAL_DMA_H__
#define __HAL_DMA_H__

#include <stdint.h>

#define NR_DESCS_PER_CHANNEL 8

/* Bitfields in CTL_LO */
#define DWC_CTLL_INT_EN       (1 << 0)    /* irqs enabled? */
#define DWC_CTLL_DST_WIDTH(n) ((n)<<1)    /* bytes per element */
#define DWC_CTLL_SRC_WIDTH(n) ((n)<<4)
#define DWC_CTLL_DST_INC      (0<<7)        /* DAR update/not */
#define DWC_CTLL_DST_DEC      (1<<7)
#define DWC_CTLL_DST_FIX      (2<<7)
#define DWC_CTLL_SRC_INC      (0<<7)        /* SAR update/not */
#define DWC_CTLL_SRC_DEC      (1<<9)
#define DWC_CTLL_SRC_FIX      (2<<9)
#define DWC_CTLL_DST_MSIZE(n) ((n)<<11)    /* burst, #elements */
#define DWC_CTLL_SRC_MSIZE(n) ((n)<<14)
#define DWC_CTLL_S_GATH_EN    (1 << 17)    /* src gather, !FIX */
#define DWC_CTLL_D_SCAT_EN    (1 << 18)    /* dst scatter, !FIX */
#define DWC_CTLL_FC(n)        ((n) << 20)
#define DWC_CTLL_FC_M2M       (0 << 20)    /* mem-to-mem */
#define DWC_CTLL_FC_M2P       (1 << 20)    /* mem-to-periph */
#define DWC_CTLL_FC_P2M       (2 << 20)    /* periph-to-mem */
#define DWC_CTLL_FC_P2P       (3 << 20)    /* periph-to-periph */
/* plus 4 transfer types for peripheral-as-flow-controller */
#define DWC_CTLL_DMS(n)   ((n)<<23)    /* dst master select */
#define DWC_CTLL_SMS(n)   ((n)<<25)    /* src master select */
#define DWC_CTLL_LLP_D_EN (1 << 27)    /* dest block chain */
#define DWC_CTLL_LLP_S_EN (1 << 28)    /* src block chain */

/* Bitfields in CTL_HI */
#define DWC_CTLH_DONE          0x00001000
#define DWC_CTLH_BLOCK_TS_MASK 0x00000fff

/* Bitfields in CFG_LO */
#define DWC_CFGL_CH_PRIOR_MASK  (0x7 << 5)    /* priority mask */
#define DWC_CFGL_CH_PRIOR(x)    ((x) << 5)    /* priority */
#define DWC_CFGL_CH_SUSP        (1 << 8)    /* pause xfer */
#define DWC_CFGL_FIFO_EMPTY     (1 << 9)    /* pause xfer */
#define DWC_CFGL_HS_DST         (1 << 10)    /* handshake w/dst */
#define DWC_CFGL_HS_SRC         (1 << 11)    /* handshake w/src */
#define DWC_CFGL_LOCK_CH_XFER   (0 << 12)    /* scope of LOCK_CH */
#define DWC_CFGL_LOCK_CH_BLOCK  (1 << 12)
#define DWC_CFGL_LOCK_CH_XACT   (2 << 12)
#define DWC_CFGL_LOCK_BUS_XFER  (0 << 14)    /* scope of LOCK_BUS */
#define DWC_CFGL_LOCK_BUS_BLOCK (1 << 14)
#define DWC_CFGL_LOCK_BUS_XACT  (2 << 14)
#define DWC_CFGL_LOCK_CH        (1 << 15)    /* channel lockout */
#define DWC_CFGL_LOCK_BUS       (1 << 16)    /* busmaster lockout */
#define DWC_CFGL_HS_DST_POL     (1 << 18)    /* dst handshake active low */
#define DWC_CFGL_HS_SRC_POL     (1 << 19)    /* src handshake active low */
#define DWC_CFGL_MAX_BURST(x)   ((x) << 20)
#define DWC_CFGL_RELOAD_SAR     (1 << 30)
#define DWC_CFGL_RELOAD_DAR     (1 << 31)

/* Bitfields in CFG_HI */
#define DWC_CFGH_FCMODE     (1 << 0)
#define DWC_CFGH_FIFO_MODE  (1 << 1)
#define DWC_CFGH_PROTCTL(x) ((x) << 2)
#define DWC_CFGH_DS_UPD_EN  (1 << 5)
#define DWC_CFGH_SS_UPD_EN  (1 << 6)
#define DWC_CFGH_SRC_PER(x) ((x) << 7)
#define DWC_CFGH_DST_PER(x) ((x) << 11)

/* Bitfields in SGR */
#define DWC_SGR_SGI(x) ((x) << 0)
#define DWC_SGR_SGC(x) ((x) << 20)

/* Bitfields in DSR */
#define DWC_DSR_DSI(x) ((x) << 0)
#define DWC_DSR_DSC(x) ((x) << 20)

/* Bitfields in CFG */
#define DW_CFG_DMA_EN (1 << 0)

typedef void (*DMA_Callback)(void *cparam);

typedef enum {
    DMA_REQ_UART0_TX = 0,
    DMA_REQ_UART0_RX = 1,
    DMA_REQ_UART1_TX = 2,
    DMA_REQ_UART1_RX = 3,
    DMA_REQ_SPI0_TX = 4,
    DMA_REQ_SPI0_RX = 5,
    DMA_REQ_SPI1_TX = 6,
    DMA_REQ_SPI1_RX = 7,
    DMA_REQ_PWM = 8,
    DMA_REQ_AUDIOPWM = 9,
    DMA_REQ_I2S0_TX = 10,
    DMA_REQ_I2S0_RX = 11,
    DMA_REQ_I2S1_TX = 12,
    DMA_REQ_I2S1_RX = 13,
    DMA_REQ_PDM = 14,
    DMA_REQ_VOP = 15,
} DMA_REQ_Type;

/* bursts size */
typedef enum {
    DWDMA_MSIZE_1,
    DWDMA_MSIZE_4,
    DWDMA_MSIZE_8,
    DWDMA_MSIZE_16,
    DWDMA_MSIZE_32,
    DWDMA_MSIZE_64,
    DWDMA_MSIZE_128,
    DWDMA_MSIZE_256,
} eDWDMA_MSIZE;

struct DMA_IRQ_REGS {
    volatile uint32_t TFR;                                /* Address Offset: 0x0000 */
    uint32_t RESERVED0004;                       /* Address Offset: 0x0004 */
    volatile uint32_t BLOCK;                              /* Address Offset: 0x0008 */
    uint32_t RESERVED000C;                       /* Address Offset: 0x000C */
    volatile uint32_t SRCTRAN;                            /* Address Offset: 0x0010 */
    uint32_t RESERVED0014;                       /* Address Offset: 0x0014 */
    volatile uint32_t DSTTRAN;                            /* Address Offset: 0x0018 */
    uint32_t RESERVED001C;                       /* Address Offset: 0x001C */
    volatile uint32_t ERR;                                /* Address Offset: 0x0020 */
    uint32_t RESERVED0024;                       /* Address Offset: 0x0024 */
};

/**
 * LLI == Linked List Item; a.k.a. DMA block descriptor
 */
struct DW_LLI {
    uint32_t sar; /**< values that are not changed by hardware */
    uint32_t dar; /**< values that are not changed by hardware */
    uint32_t llp; /**< chain to next lli */
    uint32_t ctllo;
    uint32_t ctlhi;

    uint32_t sstat; /**< values that may get written back. */
    uint32_t dstat; /**< values that may get written back. */
};

/**
 * struct DW_DESC - dma transfer desc
 */
struct DW_DESC {
    /* FIRST values the hardware uses, must be in the first place. */
    struct DW_LLI lli;

    uint32_t len;
    uint32_t totalLen;
};

typedef enum {
    DMA_MEM_TO_MEM, /**< Async/Memcpy mode */
    DMA_MEM_TO_DEV, /**< Slave mode & From Memory to Device */
    DMA_DEV_TO_MEM, /**< Slave mode & From Device to Memory */
    DMA_DEV_TO_DEV, /**< Slave mode & From Device to Device */
    DMA_TRANS_NONE,
} eDMA_TRANSFER_DIRECTION;

/**
 * enum DMA_SLAVE_BUSWIDTH - defines bus width of the DMA slave
 * device, source or target buses
 */
typedef enum {
    DMA_SLAVE_BUSWIDTH_UNDEFINED = 0,
    DMA_SLAVE_BUSWIDTH_1_BYTE    = 1,
    DMA_SLAVE_BUSWIDTH_2_BYTES   = 2,
    DMA_SLAVE_BUSWIDTH_3_BYTES   = 3,
    DMA_SLAVE_BUSWIDTH_4_BYTES   = 4,
    DMA_SLAVE_BUSWIDTH_8_BYTES   = 8,
    DMA_SLAVE_BUSWIDTH_16_BYTES  = 16,
    DMA_SLAVE_BUSWIDTH_32_BYTES  = 32,
    DMA_SLAVE_BUSWIDTH_64_BYTES  = 64,
} eDMA_SLAVE_BUSWIDTH;

struct DMA_SLAVE_CONFIG {
    eDMA_TRANSFER_DIRECTION direction; /**< Transfer direction. */
    eDMA_SLAVE_BUSWIDTH srcAddrWidth; /**< The width in bytes of the source,
                                        *  Legal values: 1, 2, 4, 8.
                                        */
    eDMA_SLAVE_BUSWIDTH dstAddrWidth; /**< The same as srcAddrWidth. */
    uint32_t srcAddr; /**< The source physical address. */
    uint32_t dstAddr; /**< The destination physical address. */
    uint16_t srcMaxBurst; /**< The maximum number of words (note: words, as in
                            *  units of the srcAddrWidth member, not bytes) that
                            *  can be sent in one burst to the device, Typically
                            *  something like half the FIFO depth on I/O peri so
                            *  you don't overflow it.
                            */
    uint16_t dstMaxBurst; /**< The same as srcMaxBurst for destination. */
};

/**
 * struct DWDMA_CHAN - dw dma channel.
 */
struct DWDMA_CHAN {
    struct HAL_DWDMA_DEV *dw;
    struct DMA_CHAN_REGS *creg;
    struct DMA_SLAVE_CONFIG config;
    struct DW_DESC *desc;
    eDMA_TRANSFER_DIRECTION direction;

    uint8_t mask;
    uint8_t srcMaster;
    uint8_t dstMaster;
    uint8_t periId;

    bool cyclic;

    DMA_Callback callback;
    void *cparam;
};

/* DMA Register Structure Define */
#define DMA_NUM_CHANNELS     6

struct DMA_CHAN_REGS {
    volatile uint32_t SAR;                                /* Address Offset: 0x0000 */
    uint32_t RESERVED0004;                       /* Address Offset: 0x0004 */
    volatile uint32_t DAR;                                /* Address Offset: 0x0008 */
    uint32_t RESERVED000C;                       /* Address Offset: 0x000C */
    volatile uint32_t LLP;                                /* Address Offset: 0x0010 */
    uint32_t RESERVED0014;                       /* Address Offset: 0x0014 */
    volatile uint32_t CTL_LO;                             /* Address Offset: 0x0018 */
    volatile uint32_t CTL_HI;                             /* Address Offset: 0x001C */
    volatile uint32_t SSTAT;                              /* Address Offset: 0x0020 */
    uint32_t RESERVED0024;                       /* Address Offset: 0x0024 */
    volatile uint32_t DSTAT;                              /* Address Offset: 0x0028 */
    uint32_t RESERVED002C;                       /* Address Offset: 0x002C */
    volatile uint32_t SSTATAR;                            /* Address Offset: 0x0030 */
    uint32_t RESERVED0034;                       /* Address Offset: 0x0034 */
    volatile uint32_t DSTATAR;                            /* Address Offset: 0x0038 */
    uint32_t RESERVED003C;                       /* Address Offset: 0x003C */
    volatile uint32_t CFG_LO;                             /* Address Offset: 0x0040 */
    volatile uint32_t CFG_HI;                             /* Address Offset: 0x0044 */
    volatile uint32_t SGR;                                /* Address Offset: 0x0048 */
    uint32_t RESERVED004C;                       /* Address Offset: 0x004C */
    volatile uint32_t DSR;                                /* Address Offset: 0x0050 */
    uint32_t RESERVED0054;                       /* Address Offset: 0x0054 */
};

struct DMA_REG {
    struct DMA_CHAN_REGS CHAN[DMA_NUM_CHANNELS];      /* Address Offset: 0x0000 */
    uint32_t RESERVED0108[44];                   /* Address Offset: 0x0108 */
    struct DMA_IRQ_REGS RAW;                          /* Address Offset: 0x02C0 */
    struct DMA_IRQ_REGS STATUS;                       /* Address Offset: 0x02E8 */
    struct DMA_IRQ_REGS MASK;                         /* Address Offset: 0x0310 */
    struct DMA_IRQ_REGS CLEAR;                        /* Address Offset: 0x0338 */
    volatile  uint32_t STATUSINT;                          /* Address Offset: 0x0360 */
    uint32_t RESERVED0364[13];                   /* Address Offset: 0x0364 */
    volatile uint32_t DMACFGREG;                          /* Address Offset: 0x0398 */
    uint32_t RESERVED039C;                       /* Address Offset: 0x039C */
    volatile uint32_t CHENREG;                            /* Address Offset: 0x03A0 */
};

/**
 * struct HAL_DWDMA_DEV - dw dma hal dev.
 */
struct HAL_DWDMA_DEV {
    struct DMA_REG *pReg;
    struct DWDMA_CHAN chan[DMA_NUM_CHANNELS];
    uint8_t irq[DMA_NUM_CHANNELS];
    uint8_t allChanMask;
    uint8_t used;
    /* hardware configuration */
    uint8_t dataWidth;
    uint32_t blockSize;

    void *priv;
};

#ifdef __cplusplus
extern "C" {
#endif

int HAL_DWDMA_Init(struct HAL_DWDMA_DEV *dw);
int HAL_DWDMA_DeInit(struct HAL_DWDMA_DEV *dw);
int HAL_DWDMA_Start(struct DWDMA_CHAN *dwc);
int HAL_DWDMA_Stop(struct DWDMA_CHAN *dwc);
struct DWDMA_CHAN *HAL_DWDMA_RequestChannel(struct HAL_DWDMA_DEV *dw, DMA_REQ_Type id);
int HAL_DWDMA_ReleaseChannel(struct DWDMA_CHAN *dwc);
int HAL_DWDMA_PrepDmaMemcpy(struct DWDMA_CHAN *dwc, uint32_t dst,
                                   uint32_t src, uint32_t len,
                                   DMA_Callback callback, void *cparam);
int HAL_DWDMA_PrepDmaSingle(struct DWDMA_CHAN *dwc, uint32_t dmaAddr,
                                   uint32_t len,
                                   eDMA_TRANSFER_DIRECTION direction,
                                   DMA_Callback callback, void *cparam);
int HAL_DWDMA_PrepDmaCyclic(struct DWDMA_CHAN *dwc, uint32_t dmaAddr,
                                   uint32_t len, uint32_t periodLen,
                                   eDMA_TRANSFER_DIRECTION direction,
                                   DMA_Callback callback, void *cparam);
int HAL_DWDMA_IrqHandler(struct HAL_DWDMA_DEV *dw, uint32_t chanId);
int HAL_DWDMA_Config(struct DWDMA_CHAN *dwc, struct DMA_SLAVE_CONFIG *config);

#ifdef __cplusplus
}
#endif

#endif // __HAL_DMA_H__
