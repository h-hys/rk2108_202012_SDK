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

#include "mailbox.h"

#include <string.h>

#include "error.h"
#include "intc.h"
#include "io.h"
#include "section.h"
#include "trace.h"

/* ARM to DSP registers */
#define MAILBOX_A2B_INTEN               0x00
#define MAILBOX_A2B_STATUS              0x04
#define MAILBOX_A2B_CMD(x)              (0x08 + (x) * 8)
#define MAILBOX_A2B_DAT(x)              (0x0c + (x) * 8)

/* DSP to ARM registers */
#define MAILBOX_B2A_INTEN               0x28
#define MAILBOX_B2A_STATUS              0x2C
#define MAILBOX_B2A_CMD(x)              (0x30 + (x) * 8)
#define MAILBOX_B2A_DAT(x)              (0x34 + (x) * 8)

#define MAILBOX_ATOMIC_LOCK(x)          (0x100 + (x) * 8)

/* A2B: 0 - 2k */
#define A2B_BUF(size, idx)              ((idx) * (size))
/* B2A: 2k - 4k */
#define B2A_BUF(size, idx)              (((idx) + 4) * (size))

#define MAILBOX_ATOMIC_LOCK_MASK        0x01
#define MAILBOX_A2B_ATOMIC_LOCK         MAILBOX_ATOMIC_LOCK(0)
#define MAILBOX_B2A_ATOMIC_LOCK         MAILBOX_ATOMIC_LOCK(1)

struct mbox {
    struct mbox_client *client[MBOX_CHAN_MAX];
};

static __sys_data__ struct mbox g_mbox[MBOX_ID_MAX];

#if 0
static inline void mbox_atomic_lock(uint32_t atomic_lock)
{
    while (readl(DSP_MBOX_BASE + atomic_lock) &
            MAILBOX_ATOMIC_LOCK_MASK);
}

static inline void mbox_atomic_unlock(uint32_t atomic_lock)
{
    writel(DSP_MBOX_BASE + atomic_lock, MAILBOX_ATOMIC_LOCK_MASK);
}
#endif

__sys__ uint32_t mbox_get_base_byid(enum mbox_id id)
{
    switch (id) {
#if CONFIG_SOC_RK2108
    case MBOX_ID_0:
        return DSP_MBOX0_BASE;
#endif
    case MBOX_ID_1:
        return DSP_MBOX1_BASE;
#if CONFIG_SOC_RK2108
    case MBOX_ID_2:
        return DSP_MBOX2_BASE;
#endif
    default:
        return DSP_MBOX0_BASE;
    }
}

__sys__ uint32_t mbox_get_base_byirq(enum irq_num irq_num)
{
    switch (irq_num) {
#if CONFIG_SOC_RK2108
    case IRQ_MBOX0_BB:
        return DSP_MBOX0_BASE;
    case IRQ_MBOX1_BB:
        return DSP_MBOX1_BASE;
    case IRQ_MBOX2_BB:
        return DSP_MBOX2_BASE;
#elif CONFIG_SOC_RK2206
    case A2B1_IRQ0:
    case A2B1_IRQ1:
    case A2B1_IRQ2:
    case A2B1_IRQ3:
    return DSP_MBOX1_BASE;
#endif
    default:
        return 0;
    }
}

/* mbox_send_data */
__sys__ int mbox_send_data(enum mbox_id mbox_id, uint32_t chann_id,
        uint32_t cmd, uint32_t data)
{
    /* TODO flush DSP cache if needed */

    //mbox_atomic_lock(MAILBOX_B2A_ATOMIC_LOCK);
    /* Write command and data to ARM */
    uint32_t mbox_base = mbox_get_base_byid(mbox_id);
    writel(mbox_base + MAILBOX_B2A_CMD(chann_id), cmd);
    writel(mbox_base + MAILBOX_B2A_DAT(chann_id), data);

    return 0;
}

/* mbox_irq - mbox irq handler */
__sys__ int mbox_irq_handler(enum irq_num irq_num, void *params)
{
    int idx;
    uint32_t status;
    struct mbox_client *client;
    uint32_t mbox_base = mbox_get_base_byirq(irq_num);

    status = readl(mbox_base + MAILBOX_A2B_STATUS);
    for (idx = 0; idx < MBOX_CHAN_MAX; idx++) {
        if (status & (1 << idx)) {
            uint32_t cmd, data;

            /* Receive data */
            cmd = readl(mbox_base + MAILBOX_A2B_CMD(idx));
            data = readl(mbox_base + MAILBOX_A2B_DAT(idx));
#if CONFIG_SOC_RK2108
            client = g_mbox[(irq_num - IRQ_MBOX0_BB) / 2].client[idx];
#elif CONFIG_SOC_RK2206
            client = g_mbox[0].client[idx];
#endif
            if (client && client->receive_data)
                client->receive_data(client, cmd, data);

            //LOGD("dsp chan = %d, cmd = %x, data = %x\n", idx, cmd, data);
            /* Clear mailbox interrupt */
            writel(mbox_base + MAILBOX_A2B_STATUS, 1 << idx);
        }
    }
    //mbox_atomic_unlock(MAILBOX_A2B_ATOMIC_LOCK);
}

__sys__ int mbox_register_client(struct mbox_client *client)
{
    if (client->chan >= MBOX_CHAN_MAX)
        return -EFAULT;

    g_mbox[client->id].client[client->chan] = client;

    return SUCCESS;
}

/* mbox_init - mailbox driver initialize */
__sys__ int mbox_init(enum mbox_id mbox_id)
{
    int i = 0;
    enum irq_num irq_num;
    uint32_t mbox_base = mbox_get_base_byid(mbox_id);

    for (i = 0; i < MBOX_CHAN_MAX; i++)
        g_mbox[mbox_id].client[i] = NULL;

    /* Clear pending interrupts */
    writel(mbox_base + MAILBOX_A2B_STATUS, 0xf);
    /* Enable A2B interrupt */
    writel(mbox_base + MAILBOX_A2B_INTEN, 0xf);

    /* Register irq handler */
#if CONFIG_SOC_RK2108
    irq_num = (enum irq_num )(IRQ_MBOX0_BB + 2 * mbox_id);
    irq_register_isr(irq_num, mbox_irq_handler, NULL);
    irq_enable(irq_num);

#elif CONFIG_SOC_RK2206
    irq_register_isr(A2B1_IRQ0, mbox_irq_handler, NULL);
    irq_enable(A2B1_IRQ0);
    irq_register_isr(A2B1_IRQ1, mbox_irq_handler, NULL);
    irq_enable(A2B1_IRQ1);
    irq_register_isr(A2B1_IRQ2, mbox_irq_handler, NULL);
    irq_enable(A2B1_IRQ2);
    irq_register_isr(A2B1_IRQ3, mbox_irq_handler, NULL);
    irq_enable(A2B1_IRQ3);
#endif
    return 0;
}
