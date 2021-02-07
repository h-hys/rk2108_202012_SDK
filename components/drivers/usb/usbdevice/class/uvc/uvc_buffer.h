/**
  * Copyright (c) 2020 Rockchip Electronics Co., Ltd
  *
  * SPDX-License-Identifier: Apache-2.0
  ******************************************************************************
  * @file    uvc_buffer.h
  * @version V0.1
  * @brief   usb buffer process header
  *
  * Change Logs:
  * Date           Author          Notes
  * 2020-07-01     Frank Wang      first implementation
  *
  ******************************************************************************
  */
#ifndef __UVC_BUFFER_H__
#define __UVC_BUFFER_H__

#include <rtdevice.h>
#include "drivers/usb_video.h"
#include "hal_base.h"

#define UVC_BUFFER_NUM    4
#define UVC_HEADER_SIZE   0x04 /* 4 Byte */
#define UVC_HEADER_RESERVED_SIZE    0x80 /* 128 Byte */
#define UVC_BUFFER_OFFSET    (UVC_HEADER_RESERVED_SIZE - UVC_HEADER_SIZE)
#define UBUFFER_SIZE    0x1F80 /* 8064 Byte */
#define UBUFFER_PAYLOAD_SIZE (UBUFFER_SIZE - UVC_HEADER_SIZE)

#define UBUFFER_JPG_HEADER_SIZE 0x0400 /* 1024 Byte */

/* buffer manager related define */
enum buf_mgr_wch
{
    BUF_MGR_WCH0 = 0,
    BUF_MGR_WCH1,
    BUF_MGR_WCH2,
    BUF_MGR_WCH3,
    BUF_MGR_WCH_CNT
};

enum buf_mgr_blk
{
    BUF_MGR_BLK0 = 0,
    BUF_MGR_BLK1,
    BUF_MGR_BLK_CNT
};

enum buf_mgr_irq
{
    BUF_MGR_WCH_IRQ_DEPTH = BUFFER_MANAGER_CH3_IRQn,
    BUF_MGR_WCH_IRQ_RGB   = BUFFER_MANAGER_CH4_IRQn,
    BUF_MGR_WCH_IRQ_IR    = BUFFER_MANAGER_CH2_IRQn,
};

enum uvc_buffer_state
{
    BUF_STATE_EMPTY = 0,
    BUF_STATE_FULL,
    BUF_STATE_BUSY
};

struct uvc_buffer
{
    uint8_t *data;
    uint8_t  eoh;
    uint8_t  eof;
    uint8_t  err;
    uint32_t index;
    uint32_t length;
    enum uvc_buffer_state state;
    struct uvc_buffer *next;

    /* Some other properties defined in HW */
};
typedef struct uvc_buffer *uvc_buffer_t;

#endif /* __UVC_BUFFER_H__ */
