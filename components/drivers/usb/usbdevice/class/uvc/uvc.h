/**
  * Copyright (c) 2020 Rockchip Electronics Co., Ltd
  *
  * SPDX-License-Identifier: Apache-2.0
  ******************************************************************************
  * @file    uvc.h
  * @version V0.1
  * @brief   usb audio class 1.0 driver
  *
  * Change Logs:
  * Date           Author          Notes
  * 2020-07-01     Frank Wang      first implementation
  *
  ******************************************************************************
  */
#ifndef __UVC_H__
#define __UVC_H__

#include <rtdevice.h>
#include "drivers/usb_video.h"
#include "uvc_buffer.h"
#include "uvc_event.h"

#if RT_DEBUG_USB
#define UVC_SETUP_DEBUG 1
#define UVC_TXD_DEBUG   1
#define UVC_BUF_DEBUG   1
#else
#define UVC_SETUP_DEBUG 0
#define UVC_TXD_DEBUG   0
#define UVC_BUF_DEBUG   0
#endif

#ifndef min
#define min(x,y) (x<y?x:y)
#endif
#ifndef max
#define max(x,y) (x<y?y:x)
#endif
#define min_t(t, x,y) ((t)x<(t)y?(t)x:(t)y)

#define UVC_MAX_REQUEST_SIZE            64

/* ------------------------------------------------------------------------
 * Structures
 */

struct uvc_video
{
    uep_t ep_in;
    uint8_t enabled;

    /* Requests and Buffers */
    struct uvc_buffer buf_jpghdr;
    struct uvc_buffer buffers[UVC_BUFFER_NUM];
    struct uvc_buffer *next_buf_to_fill;
    struct uvc_buffer *next_buf_to_drain;
    uint8_t  first_stream;
    uint8_t  buf_pending;
    uint8_t  req_zero;
    uint32_t buf_chan;
    uint32_t buf_blk;
    uint32_t buf_irq;
    uint32_t buf_size;
    uint32_t req_len;
    uint32_t fid;

    /* Frame parameters */
    uint8_t bpp;
    uint32_t fcc;
    uint32_t width;
    uint32_t height;
    uint32_t imagesize;
};

enum uvc_id
{
    UVC_ID_DEPTH = 0,
    UVC_ID_RGB,
    UVC_ID_IR,
    UVC_ID_MAX
};

enum uvc_state
{
    UVC_STATE_DISCONNECTED,
    UVC_STATE_CONNECTED,
    UVC_STATE_STREAMING,
};

struct uvc_device
{
    /* uvc device specific */
    udevice_t device;
    struct uvc_video video;
    struct uvc_event_device event_dev;
    int id;
    enum uvc_state state;

    /* usb core specific */
    uep_t ep_ctrl;
    ufunction_ops_t func;
    uint8_t control_intf;
    uint8_t streaming_intf;

    /* uvc events */
    uint8_t event_setup_out;
    struct uvc_request_data control_buf;
};

DECLARE_UVC_HEADER_DESCRIPTOR(1);
DECLARE_UVC_EXTENSION_UNIT_DESCRIPTOR(1, 1);
DECLARE_UVC_INPUT_HEADER_DESCRIPTOR(1, 1);
DECLARE_UVC_FRAME_UNCOMPRESSED(2);
DECLARE_UVC_FRAME_UNCOMPRESSED(5);
DECLARE_UVC_INPUT_HEADER_DESCRIPTOR(1, 2);
DECLARE_UVC_FRAME_MJPEG(5);

struct uvc_fs_control_cls
{
    struct UVC_HEADER_DESCRIPTOR(1) uvc_control_header;
    struct UVC_EXTENSION_UNIT_DESCRIPTOR(1, 1) uvc_extension_unit;
    struct uvc_camera_terminal_descriptor uvc_camera_terminal;
    struct uvc_processing_unit_descriptor uvc_processing;
    struct uvc_output_terminal_descriptor uvc_output_terminal;
};

/* Descriptors layout
 *
 * uvc_iad
 * uvc_control_intf
 * Class-specific UVC control descriptors
 * uvc_control_ep
 * uvc_control_cs_ep
 * uvc_streaming_intf
 * Class-specific UVC streaming descriptors
 * uvc_{fs|hs}_streaming
 */
struct uvc_ctrl_intf_desc
{
#ifdef RT_USB_DEVICE_COMPOSITE
    struct uiad_descriptor uvc_iad;
#endif
    struct uinterface_descriptor uvc_control_intf;

    /* uvc_fs_control_cls */
    struct UVC_HEADER_DESCRIPTOR(1) uvc_control_header;
    struct UVC_EXTENSION_UNIT_DESCRIPTOR(1, 1) uvc_extension_unit;
    struct uvc_camera_terminal_descriptor uvc_camera_terminal;
    struct uvc_processing_unit_descriptor uvc_processing;
    struct uvc_output_terminal_descriptor uvc_output_terminal;

    /* uvc_control_ep */
    struct uendpoint_descriptor uvc_control_ep;
    struct uvc_control_endpoint_descriptor uvc_control_cs_ep;
} __attribute__((__packed__));
typedef struct uvc_ctrl_intf_desc *uvc_ctrl_desc_t;

struct uvc_bulk_streaming_intf_depth
{
    /* uvc_streaming_intf */
    struct uinterface_descriptor uvc_bulk_streaming_intf;

    /* uvc_streaming_cls */
    struct UVC_INPUT_HEADER_DESCRIPTOR(1, 1) uvc_input_header;
    struct uvc_format_uncompressed uvc_format_yuv;
    struct UVC_FRAME_UNCOMPRESSED(5) uvc_frame_yuv_360p;
    struct UVC_FRAME_UNCOMPRESSED(5) uvc_frame_yuv_480p;
    struct UVC_FRAME_UNCOMPRESSED(5) uvc_frame_yuv_480x640;
    struct UVC_FRAME_UNCOMPRESSED(5) uvc_frame_yuv_640x400;
    struct uvc_color_matching_descriptor uvc_color_matching;

    /* uvc_hs_bulk_streaming_ep */
    struct uendpoint_descriptor uvc_hs_bulk_streaming_ep;
} __attribute__((__packed__));
typedef struct uvc_bulk_streaming_intf_depth *uvc_streaming_depth_t;

struct uvc_bulk_streaming_intf_rgb
{
    /* uvc_streaming_intf */
    struct uinterface_descriptor uvc_bulk_streaming_intf;

    /* uvc_streaming_cls */
    struct UVC_INPUT_HEADER_DESCRIPTOR(1, 1) uvc_input_header;
    struct uvc_format_mjpeg uvc_format_mjpg_rgb;
    struct UVC_FRAME_MJPEG(5) uvc_frame_mjpg_1080p;
    struct UVC_FRAME_MJPEG(5) uvc_frame_mjpg_1920x1440;
    struct UVC_FRAME_MJPEG(5) uvc_frame_mjpg_640x480;
    struct UVC_FRAME_MJPEG(5) uvc_frame_mjpg_480x640;
    struct uvc_color_matching_descriptor uvc_color_matching;

    /* uvc_hs_bulk_streaming_ep */
    struct uendpoint_descriptor uvc_hs_bulk_streaming_ep;
} __attribute__((__packed__));
typedef struct uvc_bulk_streaming_intf_rgb *uvc_streaming_rgb_t;

struct uvc_bulk_streaming_intf_ir
{
    /* uvc_streaming_intf */
    struct uinterface_descriptor uvc_bulk_streaming_intf;

    /* uvc_streaming_cls */
    struct UVC_INPUT_HEADER_DESCRIPTOR(1, 2) uvc_input_header_ir;
    struct uvc_format_uncompressed uvc_format_yuv_ir;
    struct UVC_FRAME_UNCOMPRESSED(2) uvc_frame_yuv_720p;
    struct UVC_FRAME_UNCOMPRESSED(5) uvc_frame_yuv_480p;
    struct UVC_FRAME_UNCOMPRESSED(5) uvc_frame_yuv_480x640;
    struct UVC_FRAME_UNCOMPRESSED(2) uvc_frame_yuv_1280x800;
    struct uvc_color_matching_descriptor uvc_color_matching_yuv;

    struct uvc_format_mjpeg uvc_format_mjpg;
    struct UVC_FRAME_MJPEG(5) uvc_frame_mjpg_720p;
    struct UVC_FRAME_MJPEG(5) uvc_frame_mjpg_640x480;
    struct UVC_FRAME_MJPEG(5) uvc_frame_mjpg_480x640;
    struct UVC_FRAME_MJPEG(5) uvc_frame_mjpg_1280x800;
    struct uvc_color_matching_descriptor uvc_color_matching_mjpg;

    /* uvc_hs_bulk_streaming_ep */
    struct uendpoint_descriptor uvc_hs_bulk_streaming_ep;
} __attribute__((__packed__));
typedef struct uvc_bulk_streaming_intf_ir *uvc_streaming_ir_t;

#define BULK_STREAMING_STD_LENGTH \
    ( USB_DESC_LENGTH_INTERFACE + USB_DESC_LENGTH_ENDPOINT)

uint32_t uvc_buffer_pump_jpghdr(struct uvc_video *video);
uint32_t uvc_buffer_pump(struct uvc_video *video);
void uvc_buffer_flush(struct uvc_video *video);
rt_err_t uvc_buffer_assign(struct uvc_device *uvc);
rt_err_t uvc_buffer_init(struct uvc_device *uvc);
int uvc_send_video_data(struct uvc_device *uvc);
int uvc_video_enable(struct uvc_device *uvc, int enable);
rt_size_t uvc_write_ep0(struct uvc_device *uvc,
                        ureq_t setup, struct uvc_request_data *data);
rt_size_t uvc_read_ep0(struct uvc_device *uvc, rt_size_t len);

#if defined(RT_USING_CAMERA) || defined(CONFIG_DRIVER_CAMERA)
#include "camera_inf.h"
#else
static inline rt_err_t rk_camera_inf_open(int id)
{
    return RT_EOK;
}

static inline rt_err_t rk_camera_inf_close(int id)
{
    return RT_EOK;
}

static inline uint8_t *
rk_camera_inf_get_enc_head_addr(int sensor_id)
{
    return NULL;
}

static inline  uint32_t
rk_camera_inf_get_enc_length(int sensor_id)
{
    return 0;
}
#endif /* RT_USING_CAMERA */

#endif /* __UVC_H__ */
