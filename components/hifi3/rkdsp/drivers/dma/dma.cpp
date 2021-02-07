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
#include "dma.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "trace.h"
#include "io.h"
#include "cache.h"
#include "intc.h"

#if CONFIG_SOC_RK2206 && ENABLE_DMA

#define   DMA    ((struct DMA_REG *)DMA_BASE)

struct HAL_DWDMA_DEV g_dwdma_dev;

static void dma_memcpy_callback(void *cparam)
{
    LOGD("memcpy callback\n");
    if (cparam) {
        *(uint32_t *)cparam = 1;
    }
}

static int dma_isr(enum irq_num irq_num, void *params)
{
    int chan_id;
    if (irq_num = DMAC_CH0)
        chan_id = 0;
    else
        chan_id = irq_num - DMAC_CH1 + 1;
    rk_assert(chan_id < DMA_NUM_CHANNELS);
    HAL_DWDMA_IrqHandler((struct HAL_DWDMA_DEV *)params, chan_id);
}

int dwdma_config(void *chan, uint32_t dst, uint32_t src)
{
    struct DWDMA_CHAN *dwc = (struct DWDMA_CHAN *)chan;
    struct DMA_SLAVE_CONFIG config;

    config.direction = DMA_MEM_TO_MEM;
    config.srcAddr = src;
    config.dstAddr = dst;
    config.srcAddrWidth = DMA_SLAVE_BUSWIDTH_4_BYTES;
    config.dstAddrWidth = DMA_SLAVE_BUSWIDTH_4_BYTES;
    config.srcMaxBurst = DWDMA_MSIZE_256;
    config.dstMaxBurst = DWDMA_MSIZE_256;

    return HAL_DWDMA_Config(dwc, &config);
}

int dma_memcpy_start(void *chan, uint32_t dst, uint32_t src, uint32_t len, uint32_t *flag)
{
    uint32_t dma_dst = TCM_ADDR_TRANS(dst);
    uint32_t dma_src = TCM_ADDR_TRANS(src);

    *flag = 0;
    xthal_dcache_region_writeback((void *)dst, len);
    xthal_dcache_region_writeback((void *)src, len);
    dwdma_config(chan, dma_dst, dma_src);
    HAL_DWDMA_PrepDmaMemcpy((struct DWDMA_CHAN *)chan, dma_dst, dma_src, len, dma_memcpy_callback, (void *)flag);
    HAL_DWDMA_Start((struct DWDMA_CHAN *)chan);
}

void *dma_request()
{
    struct HAL_DWDMA_DEV *dma_dev = &g_dwdma_dev;

    struct DWDMA_CHAN *chan = HAL_DWDMA_RequestChannel(dma_dev, DMA_REQ_UART0_TX);
    rk_assert(chan);

//    chan->desc = (struct DW_DESC *)dma_malloc(NR_DESCS_PER_CHANNEL * sizeof(*(chan->desc)));
    chan->desc = (struct DW_DESC *)0x30220000;
    rk_assert(chan->desc);

    return (void *)chan;
}

int dma_release(void *chan)
{
    return HAL_DWDMA_ReleaseChannel((struct DWDMA_CHAN *)chan);
}

int dma_init()
{
    struct HAL_DWDMA_DEV *dma_dev = &g_dwdma_dev;
    LOGD("size of dev = %d\n", sizeof(struct HAL_DWDMA_DEV));
    memset(dma_dev, 0, sizeof(struct HAL_DWDMA_DEV));

    dma_dev->pReg = DMA;
    dma_dev->dataWidth = 4;
    dma_dev->irq[0] = DMAC_CH0;
    dma_dev->irq[1] = DMAC_CH1;
    dma_dev->irq[2] = DMAC_CH2;
    dma_dev->irq[3] = DMAC_CH3;
    dma_dev->irq[4] = DMAC_CH4;
    dma_dev->irq[5] = DMAC_CH5;
    dma_dev->blockSize = 0xfff;

    HAL_DWDMA_Init(dma_dev);

    irq_register_isr((enum irq_num)dma_dev->irq[0], dma_isr, (void *)dma_dev);
    irq_enable((enum irq_num)dma_dev->irq[0]);

    irq_register_isr((enum irq_num)dma_dev->irq[1], dma_isr, dma_dev);
    irq_enable((enum irq_num)dma_dev->irq[1]);
}

int dma_deinit()
{
    struct HAL_DWDMA_DEV *dma_dev = &g_dwdma_dev;
    HAL_DWDMA_DeInit(dma_dev);

    irq_disable(DMAC_CH0);
    irq_disable(DMAC_CH1);
}

#endif
