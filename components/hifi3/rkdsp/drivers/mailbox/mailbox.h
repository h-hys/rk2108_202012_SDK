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

#ifndef __MAILBOX_H__
#define __MAILBOX_H__

#include <stdint.h>

#define DSP_CMD_ARM2DSP    0x01
#define DSP_CMD_DSP2ARM    0x02

#define DSP_CMD_DEFINE(chan, dir, id) ((chan & 0xff) << 16 | (dir & 0xff) << 8 | (id & 0xff))

#define DSP_CMD_WORK          DSP_CMD_DEFINE(MBOX_CHAN_0, DSP_CMD_ARM2DSP, 0x01)
#define DSP_CMD_WORK_DONE     DSP_CMD_DEFINE(MBOX_CHAN_0, DSP_CMD_DSP2ARM, 0x01)

#define DSP_CMD_READY         DSP_CMD_DEFINE(MBOX_CHAN_1, DSP_CMD_DSP2ARM, 0x01)
#define DSP_CMD_CONFIG        DSP_CMD_DEFINE(MBOX_CHAN_1, DSP_CMD_ARM2DSP, 0x02)
#define DSP_CMD_CONFIG_DONE   DSP_CMD_DEFINE(MBOX_CHAN_1, DSP_CMD_DSP2ARM, 0x02)
#define DSP_CMD_SUSPEND       DSP_CMD_DEFINE(MBOX_CHAN_1, DSP_CMD_ARM2DSP, 0x03)
#define DSP_CMD_SHUTDOWN      DSP_CMD_DEFINE(MBOX_CHAN_1, DSP_CMD_ARM2DSP, 0x04)
#define DSP_CMD_SEND_VENDOR_KEY \
                              DSP_CMD_DEFINE(MBOX_CHAN_1, DSP_CMD_ARM2DSP, 0x08)
#define DSP_CMD_ASSERT        DSP_CMD_DEFINE(MBOX_CHAN_1, DSP_CMD_DSP2ARM, 0x09)

#define DSP_CMD_STARTUP       DSP_CMD_DEFINE(MBOX_CHAN_2, DSP_CMD_DSP2ARM, 0x01)
#define DSP_CMD_PRE_FILE_INFO DSP_CMD_DEFINE(MBOX_CHAN_2, DSP_CMD_ARM2DSP, 0x02)
#define DSP_CMD_PRE_FILE_DONE DSP_CMD_DEFINE(MBOX_CHAN_2, DSP_CMD_DSP2ARM, 0x03)

#define DSP_CMD_TRACE         DSP_CMD_DEFINE(MBOX_CHAN_3, DSP_CMD_DSP2ARM, 0x01)
#define DSP_CMD_TRACE_DONE    DSP_CMD_DEFINE(MBOX_CHAN_3, DSP_CMD_ARM2DSP, 0x01)
#define DSP_CMD_TRACE_CONFIG        DSP_CMD_DEFINE(MBOX_CHAN_3, DSP_CMD_ARM2DSP, 0x02)
#define DSP_CMD_TRACE_CONFIG_DONE   DSP_CMD_DEFINE(MBOX_CHAN_3, DSP_CMD_DSP2ARM, 0x02)

enum mbox_chan {
    MBOX_CHAN_0 = 0,
    MBOX_CHAN_1 = 1,
    MBOX_CHAN_2 = 2,
    MBOX_CHAN_3 = 3,
    MBOX_CHAN_MAX = 4,
};

#if CONFIG_SOC_RK2108
enum mbox_id {
    MBOX_ID_0 = 0,
    MBOX_ID_1 = 1,
    MBOX_ID_2 = 2,
    MBOX_ID_MAX,
};
#elif CONFIG_SOC_RK2206
enum mbox_id {
    MBOX_ID_1 = 0,
    MBOX_ID_MAX,
};
#endif

struct mbox_client {
    enum mbox_id id;
    enum mbox_chan chan;

    /*
     * callback in mbox irq, do things as less as
     * possible in this callback function
     */
    int (*receive_data)(struct mbox_client *client, uint32_t cmd,
            uint32_t data);
};

#if CONFIG_SOC_RK2108
#define MBOX_ID     MBOX_ID_0
#elif CONFIG_SOC_RK2206
#define MBOX_ID     MBOX_ID_1
#else
#define MBOX_ID     MBOX_ID_0
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern int mbox_register_client(struct mbox_client *client);
extern int mbox_send_data(enum mbox_id mbox_id, uint32_t chann_id, uint32_t cmd,
        uint32_t data);
extern int mbox_init(enum mbox_id mbox_id);
extern int mail_box_test(void);

#ifdef __cplusplus
}
#endif

#endif
