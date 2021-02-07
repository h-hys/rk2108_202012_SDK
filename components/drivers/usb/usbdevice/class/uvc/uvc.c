/**
  * Copyright (c) 2020 Rockchip Electronics Co., Ltd
  *
  * SPDX-License-Identifier: Apache-2.0
  ******************************************************************************
  * @file    uvc.c
  * @version V0.1
  * @brief   usb video class 1.1 driver
  *
  * Change Logs:
  * Date           Author          Notes
  * 2020-07-01     Frank Wang      first implementation
  *
  ******************************************************************************
  */
#include <rtthread.h>
#include <rthw.h>
#include <rtservice.h>
#include <rtdevice.h>
#include "dma.h"
#include "drivers/usb_common.h"
#include "drivers/usb_video.h"
#include "uvc.h"
#include "drv_heap.h"

/* Configuration descriptor */
ALIGN(4)
struct uvc_ctrl_intf_desc ctrl_intf_desc =
{
#ifdef RT_USB_DEVICE_COMPOSITE
    /* Interface Association Descriptor */
    {
        USB_DESC_LENGTH_IAD,
        USB_DESC_TYPE_IAD,
        0,
        0x02,
        USB_CLASS_VIDEO,
        UVC_SC_VIDEO_INTERFACE_COLLECTION,
        0x00,
        0,
    },
#endif

    /* Interface Descriptor */
    {
        USB_DESC_LENGTH_INTERFACE,
        USB_DESC_TYPE_INTERFACE,
        0,
        0,
        0x01,
        USB_CLASS_VIDEO,
        UVC_SC_VIDEOCONTROL,
        0x00,
        0,
    },

    /* VideoControl Interface Descriptor */

    /* uvc_control_header */
    {
        UVC_DT_HEADER_SIZE(1),
        USB_DT_CS_INTERFACE,
        UVC_VC_HEADER,
        cpu_to_le16(0x0100),
        cpu_to_le16(77), /* dynamic */
        cpu_to_le32(48000000),
        1, /* dynamic */
        {0}, /* dynamic */
    },

    /* uvc_extension_unit */
    {
        UVC_DT_EXTENSION_UNIT_SIZE(1, 1),
        USB_DT_CS_INTERFACE,
        UVC_VC_EXTENSION_UNIT,
        6,
        {
            0xa2, 0x9e, 0x76, 0x41, 0xde, 0x04, 0x47, 0xe3,
            0x8b, 0x2b, 0xf4, 0x34, 0x1a, 0xff, 0x00, 0x3b
        },
        4,
        1,
        {2},
        1,
        {0x0F},
        0,
    },

    /* uvc_camera_terminal */
    {
        UVC_DT_CAMERA_TERMINAL_SIZE(3),
        USB_DT_CS_INTERFACE,
        UVC_VC_INPUT_TERMINAL,
        1,
        cpu_to_le16(0x0201),
        0,
        0,
        cpu_to_le16(0),
        cpu_to_le16(0),
        cpu_to_le16(0),
        3,
        {2, 0, 0},
    },

    /* uvc_processing */
    {
        UVC_DT_PROCESSING_UNIT_SIZE(2),
        USB_DT_CS_INTERFACE,
        UVC_VC_PROCESSING_UNIT,
        2,
        1,
        cpu_to_le16(16 * 1024),
        2,
        {0x4f, 0x06},
        0,
    },

    /* uvc_output_terminal */
    {
        UVC_DT_OUTPUT_TERMINAL_SIZE,
        USB_DT_CS_INTERFACE,
        UVC_VC_OUTPUT_TERMINAL,
        3,
        cpu_to_le16(0x0101),
        0,
        2,
        0,
    },

    /* uvc_control_ep */
    {
        USB_DESC_LENGTH_ENDPOINT,
        USB_DESC_TYPE_ENDPOINT,
        USB_DYNAMIC | USB_DIR_IN,
        USB_EP_ATTR_INT,
        cpu_to_le16(16),
        8,
    },

    /* uvc_control_cs_ep */
    {
        UVC_DT_CONTROL_ENDPOINT_SIZE,
        USB_DT_CS_ENDPOINT,
        UVC_EP_INTERRUPT,
        cpu_to_le16(16),
    },
};

ALIGN(4)
struct uvc_bulk_streaming_intf_depth streaming_intf_depth =
{
    /* uvc_bulk_streaming_intf */
    {
        USB_DESC_LENGTH_INTERFACE,
        USB_DESC_TYPE_INTERFACE,
        1,
        0,
        1,
        USB_CLASS_VIDEO,
        UVC_SC_VIDEOSTREAMING,
        0x00,
        0,
    },
    /* uvc_input_header */
    {
        UVC_DT_INPUT_HEADER_SIZE(1, 1),
        USB_DT_CS_INTERFACE,
        UVC_VS_INPUT_HEADER,
        1,
        0, /* dynamic */
        0x81, /* dynamic */ // TODO: fixed
        0,
        3,
        0,
        0,
        0,
        1,
        {{27}},
    },
    /* uvc_format_yuv */
    {
        UVC_DT_FORMAT_UNCOMPRESSED_SIZE,
        USB_DT_CS_INTERFACE,
        UVC_VS_FORMAT_UNCOMPRESSED,
        2,
        4,
        {
            'Y',  'U',  'Y',  '2', 0x00, 0x00, 0x10, 0x00,
            0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71
        },
        16,
        1,
        0,
        0,
        0,
        0,
    },
    /* uvc_frame_yuv_360p */
    {
        UVC_DT_FRAME_UNCOMPRESSED_SIZE(5),
        USB_DT_CS_INTERFACE,
        UVC_VS_FRAME_UNCOMPRESSED,
        5,
        0,
        cpu_to_le16(640),
        cpu_to_le16(360),
        cpu_to_le32(27648000),
        cpu_to_le32(110592000),
        cpu_to_le32(460800),
        cpu_to_le32(333333),
        5,
        {
            cpu_to_le32(333333),
            cpu_to_le32(500000),
            cpu_to_le32(666666),
            cpu_to_le32(1000000),
            cpu_to_le32(1333333),
        }
    },
    /* uvc_frame_yuv_480p */
    {
        UVC_DT_FRAME_UNCOMPRESSED_SIZE(5),
        USB_DT_CS_INTERFACE,
        UVC_VS_FRAME_UNCOMPRESSED,
        4,
        0,
        cpu_to_le16(640),
        cpu_to_le16(480),
        cpu_to_le32(36864000),
        cpu_to_le32(147456000),
        cpu_to_le32(614400),
        cpu_to_le32(333333),
        5,
        {
            cpu_to_le32(333333),
            cpu_to_le32(500000),
            cpu_to_le32(666666),
            cpu_to_le32(1000000),
            cpu_to_le32(1333333),
        }
    },
    /* uvc_frame_yuv_480x640 */
    {
        UVC_DT_FRAME_UNCOMPRESSED_SIZE(5),
        USB_DT_CS_INTERFACE,
        UVC_VS_FRAME_UNCOMPRESSED,
        1,
        0,
        cpu_to_le16(480),
        cpu_to_le16(640),
        cpu_to_le32(36864000),
        cpu_to_le32(147456000),
        cpu_to_le32(614400),
        cpu_to_le32(333333),
        5,
        {
            cpu_to_le32(333333),
            cpu_to_le32(500000),
            cpu_to_le32(666666),
            cpu_to_le32(1000000),
            cpu_to_le32(1333333),
        }
    },
    /* uvc_frame_yuv_640x400 */
    {
        UVC_DT_FRAME_UNCOMPRESSED_SIZE(5),
        USB_DT_CS_INTERFACE,
        UVC_VS_FRAME_UNCOMPRESSED,
        6,
        0,
        cpu_to_le16(640),
        cpu_to_le16(400),
        cpu_to_le32(30720000),
        cpu_to_le32(122880000),
        cpu_to_le32(512000),
        cpu_to_le32(333333),
        5,
        {
            cpu_to_le32(333333),
            cpu_to_le32(500000),
            cpu_to_le32(666666),
            cpu_to_le32(1000000),
            cpu_to_le32(1333333),
        },
    },
    /* uvc_color_matching */
    {
        UVC_DT_COLOR_MATCHING_SIZE,
        USB_DT_CS_INTERFACE,
        UVC_VS_COLORFORMAT,
        1,
        1,
        4,
    },
    /* uvc_hs_bulk_streaming_ep */
    {
        USB_DESC_LENGTH_ENDPOINT,
        USB_DESC_TYPE_ENDPOINT,
        USB_DYNAMIC | USB_DIR_IN,
        USB_EP_ATTR_BULK,
        cpu_to_le16(512),
        0,
    },
};

ALIGN(4)
struct uvc_bulk_streaming_intf_rgb streaming_intf_rgb =
{
    /* uvc_bulk_streaming_intf */
    {
        USB_DESC_LENGTH_INTERFACE,
        USB_DESC_TYPE_INTERFACE,
        1,
        0,
        1,
        USB_CLASS_VIDEO,
        UVC_SC_VIDEOSTREAMING,
        0x00,
        0,
    },

    /* VideoStreaming Interface Descriptor */
    /* uvc_input_header_rgbs */
    {
        UVC_DT_INPUT_HEADER_SIZE(1, 1),
        USB_DT_CS_INTERFACE,
        UVC_VS_INPUT_HEADER,
        1,
        0, /* dynamic */
        0x83, /* dynamic */ // TODO: fixed
        0,
        3,
        0,
        0,
        0,
        1,
        {{4}},
    },
    /* uvc_format_mjpg_rgb */
    {
        UVC_DT_FORMAT_MJPEG_SIZE,
        USB_DT_CS_INTERFACE,
        UVC_VS_FORMAT_MJPEG,
        1,
        4,
        0,
        1,
        0,
        0,
        0,
        0,
    },
    /* uvc_frame_mjpg_1080p */
    {
        UVC_DT_FRAME_MJPEG_SIZE(5),
        USB_DT_CS_INTERFACE,
        UVC_VS_FRAME_MJPEG,
        5,
        0,
        cpu_to_le16(1920),
        cpu_to_le16(1080),
        cpu_to_le32(248832000),
        cpu_to_le32(995328000),
        cpu_to_le32(4147200),
        cpu_to_le32(333333),
        5,
        {
            cpu_to_le32(333333),
            cpu_to_le32(500000),
            cpu_to_le32(666666),
            cpu_to_le32(1000000),
            cpu_to_le32(1333333),
        },
    },
    /* uvc_frame_mjpg_1920x1440 */
    {
        UVC_DT_FRAME_MJPEG_SIZE(5),
        USB_DT_CS_INTERFACE,
        UVC_VS_FRAME_MJPEG,
        3,
        0,
        cpu_to_le16(1920),
        cpu_to_le16(1440),
        cpu_to_le32(331776000),
        cpu_to_le32(1327104000),
        cpu_to_le32(5529600),
        cpu_to_le32(333333),
        5,
        {
            cpu_to_le32(333333),
            cpu_to_le32(500000),
            cpu_to_le32(666666),
            cpu_to_le32(1000000),
            cpu_to_le32(1333333),
        }
    },
    /* uvc_frame_mjpg_640x480 */
    {
        UVC_DT_FRAME_MJPEG_SIZE(5),
        USB_DT_CS_INTERFACE,
        UVC_VS_FRAME_MJPEG,
        4,
        0,
        cpu_to_le16(640),
        cpu_to_le16(480),
        cpu_to_le32(36864000),
        cpu_to_le32(147456000),
        cpu_to_le32(614400),
        cpu_to_le32(333333),
        5,
        {
            cpu_to_le32(333333),
            cpu_to_le32(500000),
            cpu_to_le32(666666),
            cpu_to_le32(1000000),
            cpu_to_le32(1333333),
        }
    },
    /* uvc_frame_mjpg_480x640 */
    {
        UVC_DT_FRAME_MJPEG_SIZE(5),
        USB_DT_CS_INTERFACE,
        UVC_VS_FRAME_MJPEG,
        1,
        0,
        cpu_to_le16(480),
        cpu_to_le16(640),
        cpu_to_le32(36864000),
        cpu_to_le32(147456000),
        cpu_to_le32(614400),
        cpu_to_le32(333333),
        5,
        {
            cpu_to_le32(333333),
            cpu_to_le32(500000),
            cpu_to_le32(666666),
            cpu_to_le32(1000000),
            cpu_to_le32(1333333),
        }
    },
    /* uvc_color_matching */
    {
        UVC_DT_COLOR_MATCHING_SIZE,
        USB_DT_CS_INTERFACE,
        UVC_VS_COLORFORMAT,
        1,
        1,
        4,
    },
    /* uvc_hs_bulk_streaming_ep */
    {
        USB_DESC_LENGTH_ENDPOINT,
        USB_DESC_TYPE_ENDPOINT,
        USB_DYNAMIC | USB_DIR_IN,
        USB_EP_ATTR_BULK,
        cpu_to_le16(512),
        0,
    },
};

ALIGN(4)
struct uvc_bulk_streaming_intf_ir streaming_intf_ir =
{
    /* uvc_bulk_streaming_intf */
    {
        USB_DESC_LENGTH_INTERFACE,
        USB_DESC_TYPE_INTERFACE,
        1,
        0,
        1,
        USB_CLASS_VIDEO,
        UVC_SC_VIDEOSTREAMING,
        0x00,
        0,
    },
    /* uvc_input_header_ir */
    {
        UVC_DT_INPUT_HEADER_SIZE(1, 2),
        USB_DT_CS_INTERFACE,
        UVC_VS_INPUT_HEADER,
        2,
        0, /* dynamic */
        0x85, /* dynamic */ // TODO: fixed
        0,
        3,
        0,
        0,
        0,
        1,
        {{0}, {4}},
    },
    /* uvc_format_yuv_ir */
    {
        UVC_DT_FORMAT_UNCOMPRESSED_SIZE,
        USB_DT_CS_INTERFACE,
        UVC_VS_FORMAT_UNCOMPRESSED,
        2,
        4,
        {
            'Y',  'U',  'Y',  '2', 0x00, 0x00, 0x10, 0x00,
            0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71
        },
        16,
        1,
        0,
        0,
        0,
        0,
    },
    /* uvc_frame_yuv_720p */
    {
        UVC_DT_FRAME_UNCOMPRESSED_SIZE(2),
        USB_DT_CS_INTERFACE,
        UVC_VS_FRAME_UNCOMPRESSED,
        2,
        0,
        cpu_to_le16(1280),
        cpu_to_le16(720),
        cpu_to_le32(110592000),
        cpu_to_le32(147456000),
        cpu_to_le32(1843200),
        cpu_to_le32(1000000),
        2,
        {
            cpu_to_le32(1000000),
            cpu_to_le32(1333333),
        }
    },
    /* uvc_frame_yuv_480p */
    {
        UVC_DT_FRAME_UNCOMPRESSED_SIZE(5),
        USB_DT_CS_INTERFACE,
        UVC_VS_FRAME_UNCOMPRESSED,
        4,
        0,
        cpu_to_le16(640),
        cpu_to_le16(480),
        cpu_to_le32(36864000),
        cpu_to_le32(147456000),
        cpu_to_le32(614400),
        cpu_to_le32(333333),
        5,
        {
            cpu_to_le32(333333),
            cpu_to_le32(500000),
            cpu_to_le32(666666),
            cpu_to_le32(1000000),
            cpu_to_le32(1333333),
        },
    },
    /* uvc_frame_yuv_480x640 */
    {
        UVC_DT_FRAME_UNCOMPRESSED_SIZE(5),
        USB_DT_CS_INTERFACE,
        UVC_VS_FRAME_UNCOMPRESSED,
        1,
        0,
        cpu_to_le16(480),
        cpu_to_le16(640),
        cpu_to_le32(36864000),
        cpu_to_le32(147456000),
        cpu_to_le32(614400),
        cpu_to_le32(333333),
        5,
        {
            cpu_to_le32(333333),
            cpu_to_le32(500000),
            cpu_to_le32(666666),
            cpu_to_le32(1000000),
            cpu_to_le32(1333333),
        },
    },
    /* uvc_frame_yuv_1280x800 */
    {
        UVC_DT_FRAME_UNCOMPRESSED_SIZE(2),
        USB_DT_CS_INTERFACE,
        UVC_VS_FRAME_UNCOMPRESSED,
        7,
        0,
        cpu_to_le16(1280),
        cpu_to_le16(800),
        cpu_to_le32(122880000),
        cpu_to_le32(163840000),
        cpu_to_le32(2048000),
        cpu_to_le32(1000000),
        2,
        {
            cpu_to_le32(1000000),
            cpu_to_le32(1333333),
        }
    },
    /* uvc_color_matching */
    {
        UVC_DT_COLOR_MATCHING_SIZE,
        USB_DT_CS_INTERFACE,
        UVC_VS_COLORFORMAT,
        1,
        1,
        4,
    },
    /* uvc_format_mjpg */
    {
        UVC_DT_FORMAT_MJPEG_SIZE,
        USB_DT_CS_INTERFACE,
        UVC_VS_FORMAT_MJPEG,
        1,
        4,
        0,
        1,
        0,
        0,
        0,
        0,
    },
    /* uvc_frame_mjpg_720p */
    {
        UVC_DT_FRAME_MJPEG_SIZE(5),
        USB_DT_CS_INTERFACE,
        UVC_VS_FRAME_MJPEG,
        2,
        0,
        cpu_to_le16(1280),
        cpu_to_le16(720),
        cpu_to_le32(110592000),
        cpu_to_le32(442368000),
        cpu_to_le32(1843200),
        cpu_to_le32(333333),
        5,
        {
            cpu_to_le32(333333),
            cpu_to_le32(500000),
            cpu_to_le32(666666),
            cpu_to_le32(1000000),
            cpu_to_le32(1333333),
        }
    },
    /* uvc_frame_mjpg_640x480 */
    {
        UVC_DT_FRAME_MJPEG_SIZE(5),
        USB_DT_CS_INTERFACE,
        UVC_VS_FRAME_MJPEG,
        4,
        0,
        cpu_to_le16(640),
        cpu_to_le16(480),
        cpu_to_le32(36864000),
        cpu_to_le32(147456000),
        cpu_to_le32(614400),
        cpu_to_le32(333333),
        5,
        {
            cpu_to_le32(333333),
            cpu_to_le32(500000),
            cpu_to_le32(666666),
            cpu_to_le32(1000000),
            cpu_to_le32(1333333),
        }
    },
    /* uvc_frame_mjpg_480x640 */
    {
        UVC_DT_FRAME_MJPEG_SIZE(5),
        USB_DT_CS_INTERFACE,
        UVC_VS_FRAME_MJPEG,
        1,
        0,
        cpu_to_le16(480),
        cpu_to_le16(640),
        cpu_to_le32(36864000),
        cpu_to_le32(147456000),
        cpu_to_le32(614400),
        cpu_to_le32(333333),
        5,
        {
            cpu_to_le32(333333),
            cpu_to_le32(500000),
            cpu_to_le32(666666),
            cpu_to_le32(1000000),
            cpu_to_le32(1333333),
        }
    },
    /* uvc_frame_mjpg_1280x800 */
    {
        UVC_DT_FRAME_MJPEG_SIZE(5),
        USB_DT_CS_INTERFACE,
        UVC_VS_FRAME_MJPEG,
        6,
        0,
        cpu_to_le16(1280),
        cpu_to_le16(800),
        cpu_to_le32(122880000),
        cpu_to_le32(491520000),
        cpu_to_le32(2048000),
        cpu_to_le32(333333),
        5,
        {
            cpu_to_le32(333333),
            cpu_to_le32(500000),
            cpu_to_le32(666666),
            cpu_to_le32(1000000),
            cpu_to_le32(1333333),
        }
    },
    /* uvc_color_matching */
    {
        UVC_DT_COLOR_MATCHING_SIZE,
        USB_DT_CS_INTERFACE,
        UVC_VS_COLORFORMAT,
        1,
        1,
        4,
    },
    /* uvc_hs_bulk_streaming_ep */
    {
        USB_DESC_LENGTH_ENDPOINT,
        USB_DESC_TYPE_ENDPOINT,
        USB_DYNAMIC | USB_DIR_IN,
        USB_EP_ATTR_BULK,
        cpu_to_le16(512),
        0,
    },
};

/* Device descriptor */
ALIGN(4)
static struct udevice_descriptor uvc_dev_desc =
{
    USB_DESC_LENGTH_DEVICE,     //bLength;
    USB_DESC_TYPE_DEVICE,       //type;
    USB_BCD_VERSION,            //bcdUSB;
    USB_CLASS_VIDEO,            //bDeviceClass;
    0x02,                       //bDeviceSubClass;
    0x01,                       //bDeviceProtocol;
    64,                         //bMaxPacketSize0;
    _VENDOR_ID,                 //idVendor;
    _PRODUCT_ID,                //idProduct;
    USB_BCD_DEVICE,             //bcdDevice;
    USB_STRING_MANU_INDEX,      //iManufacturer;
    USB_STRING_PRODUCT_INDEX,   //iProduct;
    USB_STRING_SERIAL_INDEX,    //iSerialNumber;
    USB_DYNAMIC,                //bNumConfigurations;
};

//FS and HS needed
ALIGN(4)
static struct usb_qualifier_descriptor dev_qualifier =
{
    sizeof(dev_qualifier),          //bLength
    USB_DESC_TYPE_DEVICEQUALIFIER,  //bDescriptorType
    0x0200,                         //bcdUSB
    USB_CLASS_VIDEO,                //bDeviceClass
    0x02,                           //bDeviceSubClass
    0x01,                           //bDeviceProtocol
    64,                             //bMaxPacketSize0
    0x01,                           //bNumConfigurations
    0,
};

ALIGN(4)
const static char *uvc_ustring[] =
{
    "Language",
    "Rockchip",
    "RK625",
    "123456789",
    "Configuration",
    "UVC DEPTH",
    "Video Streaming",
    "UVC RGB",
    "Video Streaming",
    "UVC IR",
    "Video Streaming",
    USB_STRING_OS
};

static struct uvc_device *curr_uvc_dev;

static inline struct uvc_device *func_to_uvc(ufunction_t f)
{
    return (struct uvc_device *)f->user_data;
}

static rt_err_t
uvc_class_setup_notify(struct uvc_event_device *edev, ureq_t setup)
{
    struct uvc_event event;

    RT_ASSERT(edev != RT_NULL);

    event.type = UVC_EVENT_SETUP;
    rt_memcpy(&event.req, setup, sizeof(event.req));

    return uvc_event_signal(&event, edev->video_id);
}

static rt_err_t uvc_err_invoke(struct uvc_device *uvc)
{
    struct uvc_event event;

    if (!uvc)
        return RT_ERROR;

    RT_DEBUG_LOG(RT_DEBUG_USB, ("%s, id=%d\n", __func__, uvc->id));

    event.type = UVC_EVENT_EXCEPTION;
    event.content.length = 0;

    uvc_event_signal(&event, uvc->id);

    return RT_EOK;
}

static rt_err_t uvc_ep0_complete(udevice_t device, rt_size_t size)
{
    struct uvc_device *uvc = curr_uvc_dev;
    struct uvc_event event;

    if (!uvc)
        return RT_ERROR;

    RT_DEBUG_LOG(RT_DEBUG_USB, ("%s, id=%d\n", __func__, uvc->id));

    if (uvc->event_setup_out)
    {
        uvc->event_setup_out = 0;
        event.type = UVC_EVENT_DATA;
        event.content.length = (int)size;
        rt_memcpy(&event.content.data, &uvc->control_buf.data, size);

//      rt_kprintf("%02x %02x %02x %02x\n", event.content.data[0], event.content.data[1], event.content.data[2], event.content.data[3]);
//      rt_kprintf("_size=%u, size=%u\n", size, event.content.length);

        uvc_event_signal(&event, uvc->id);
        curr_uvc_dev = NULL;
    }

    dcd_ep0_send_status(device->dcd);

    return RT_EOK;
}

static void uvc_video_var_init(struct uvc_video *video)
{
    RT_ASSERT(video);

    video->fid = 0;
    video->first_stream = 1;
    video->buf_pending = 0;
    video->next_buf_to_drain = &video->buffers[0];
    video->next_buf_to_fill = &video->buffers[0];

    uvc_buffer_flush(video);
}

static rt_err_t uvc_video_unprepare(struct uvc_device *uvc)
{
    struct uvc_video *video = &uvc->video;
    rt_base_t level;
    rt_err_t ret;

    level = rt_hw_interrupt_disable();
    HAL_BUFMGR_WCHIntAllEn(video->buf_chan, video->buf_blk, 0);
    HAL_BUFMGR_WCHPpBufEn(video->buf_chan, video->buf_blk, 0);
    HAL_BUFMGR_WCHIntStsAllClr(video->buf_chan, video->buf_blk);
    rt_hw_interrupt_enable(level);

    rt_kprintf("INF: uvc(%d) close camera device...\n", uvc->id);

    ret = rk_camera_inf_close(uvc->id);
    if (ret)
    {
        rt_kprintf("ERR: camera(%d) close error, ret(%d)\n", uvc->id, ret);
        goto err;
    }

    ret = dcd_ep_disable(uvc->device->dcd, video->ep_in);
    if (ret)
    {
        rt_kprintf("ERR: uvc(%d) ep disable error, ret(%d)\n", uvc->id, ret);
        goto err;
    }

    video->enabled = 0;
    return RT_EOK;

err:
    return ret;
}

static rt_err_t uvc_video_prepare(struct uvc_device *uvc)
{
    struct uvc_video *video = &uvc->video;
    rt_base_t level;
    rt_err_t ret;

    /* close camera first */
    if (video->enabled)
    {
        ret = uvc_video_unprepare(uvc);
        if (ret)
            goto err;
    }

    uvc_video_var_init(video);

    ret = dcd_ep_enable(uvc->device->dcd, video->ep_in);
    if (ret)
    {
        rt_kprintf("ERR: uvc(%d) ep enabled error, ret(%d)\n", uvc->id, ret);
        goto err;
    }

    rt_kprintf("INF: uvc(%d) open camera device...\n", uvc->id);

    ret = rk_camera_inf_open(uvc->id);
    if (ret)
    {
        rt_kprintf("ERR: camera(%d) opened error, ret(%d)\n", uvc->id, ret);
        goto err;
    }

    ret = uvc_buffer_assign(uvc);
    if (ret)
        goto err;

    video->enabled = 1;
    return RT_EOK;

err:
    return ret;
}

static void uvc_ep_write(udevice_t device, uep_t ep, uint32_t req_len)
{
    RT_ASSERT(ep);

    RT_DEBUG_LOG(RT_DEBUG_USB, ("%s: buffer %p, size %d\n", __func__, ep->buffer, req_len));

    ep->request.buffer = ep->buffer;
    ep->request.size = req_len;
    ep->request.req_type = UIO_REQUEST_WRITE;
    rt_usbd_io_request(device, ep, &ep->request);
}

rt_size_t uvc_read_ep0(struct uvc_device *uvc, rt_size_t len)
{
    RT_DEBUG_LOG(RT_DEBUG_USB, ("%s\n", __func__));

    uvc->event_setup_out = 1;
    curr_uvc_dev = uvc;

    return rt_usbd_ep0_read(uvc->device, &uvc->control_buf.data, len,
                            uvc_ep0_complete);
}

rt_size_t uvc_write_ep0(struct uvc_device *uvc,
                        ureq_t setup, struct uvc_request_data *data)
{
    udevice_t device = uvc->device;
    uep_t ep0 = &device->dcd->ep0;
    struct uvc_event_device *edev = &uvc->event_dev;

    if (edev->req_out && data->length > 0)
    {
        edev->req_out = 0;
        uvc_read_ep0(uvc, data->length);
    }
    else if (data->length == 0)
    {
        RT_DEBUG_LOG(RT_DEBUG_USB, ("Send zero data\n"));
        data->data[0] = 0;
        ep0 = &device->dcd->ep0;
        ep0->request.size = 0;
        ep0->request.buffer = (rt_uint8_t *)&data->data;
        ep0->request.remain_size = 0;

        dcd_ep_write(device->dcd, EP0_IN_ADDR, ep0->request.buffer, 0);
    }
    else
    {
        data->length = min_t(rt_size_t, le16_to_cpu(setup->wLength), data->length);
        RT_DEBUG_LOG(RT_DEBUG_USB, ("setup IN reply, length(%d)\n", data->length));
        rt_usbd_ep0_write(device, &data->data, data->length);
    }

    return RT_EOK;
}

int uvc_send_video_data(struct uvc_device *uvc)
{
    struct uvc_video *video = &uvc->video;
    struct uvc_buffer *pbuf;
    int ret = 0;

    RT_DEBUG_LOG(RT_DEBUG_USB, ("%s\n", __func__));

    pbuf = video->next_buf_to_drain;
    if (!pbuf || pbuf->state != BUF_STATE_FULL)
    {
        if (pbuf)
            RT_DEBUG_LOG(UVC_TXD_DEBUG, ("WAR: uvc(%d) buffer(%d-%d) pending\n",
                                         uvc->id, pbuf->index, pbuf->state));
        video->buf_pending = 1; /* mark and send in buffer manager irq */
        return RT_EOK;
    }

    /* send jpeg header first for mjpg stream */
    if (pbuf->eoh && uvc->id != UVC_ID_DEPTH)
    {
        ret = uvc_buffer_pump_jpghdr(video);
        if (!ret)
        {
            rt_kprintf("ERR: uvc mjpeg header is not ready\n");
            return RT_EEMPTY;
        }

        pbuf->eoh = 0; /* clear */
        video->buf_jpghdr.state = BUF_STATE_EMPTY; /* reset */

        RT_DEBUG_LOG(UVC_TXD_DEBUG, ("INF: uvc(%d) send mjpeg header\n", uvc->id));
        goto send;
    }

    ret = uvc_buffer_pump(video);
    if (!ret)
        return RT_EEMPTY;

    RT_DEBUG_LOG(UVC_TXD_DEBUG, ("INF: uvc(%d) buffer(%d-%d) sending\n",
                                 uvc->id, pbuf->index, pbuf->state));

send:
    uvc_ep_write(uvc->device, video->ep_in, video->req_len);
    return RT_EOK;
}

int uvc_video_enable(struct uvc_device *uvc, int enable)
{
    struct uvc_video *video = &uvc->video;
    rt_err_t ret;

    if (!enable)
    {
        rt_kprintf("VIDIOC_STREAMOFF(%d)\n", uvc->id);

        if (video->enabled)
            return uvc_video_unprepare(uvc);

        return RT_EOK;
    }

    rt_kprintf("VIDIOC_STREAMON(%d)\n", uvc->id);

    ret = uvc_video_prepare(uvc);
    if (ret)
        return ret;

    return uvc_send_video_data(uvc);
}

static rt_err_t ep_in_handler(ufunction_t func, rt_size_t size)
{
    struct uvc_device *uvc = func_to_uvc(func);
    struct uvc_video *video = &uvc->video;
    struct uvc_buffer *pbuf;
    rt_base_t level;

    RT_DEBUG_LOG(RT_DEBUG_USB, ("%s: uvc_id(%d)\n", __func__, uvc->id));

    /* clear the last sent buffer */
    level = rt_hw_interrupt_disable();
    pbuf = video->next_buf_to_drain;
    if (pbuf && pbuf->state == BUF_STATE_BUSY)
    {
        /* finished to send, let clear the buffer status */
        HAL_BUFMGR_WCHIntStsClr(video->buf_chan, video->buf_blk,
                                HAL_BUFMGR_WCH_STS_FULL_BIT(pbuf->index));
        pbuf->state = BUF_STATE_EMPTY; /* reset */
        video->next_buf_to_drain = video->next_buf_to_drain->next;
        RT_DEBUG_LOG(UVC_TXD_DEBUG, ("INF: uvc(%d) buffer(%d-%d) sent\n",
                                     uvc->id, pbuf->index, pbuf->state));
    }
    rt_hw_interrupt_enable(level);

    if (pbuf && pbuf->err)
    {
        pbuf->err = 0; /* clear */
        rt_kprintf("ERR: uvc(%d) buffer(%d-%d) error sent\n",
                   uvc->id, pbuf->index, pbuf->state);
        return uvc_err_invoke(uvc);
    }

    if (pbuf && pbuf->eof && video->req_zero)
    {
        /* hook to send zero packet */
        video->req_zero = 0; /* clear */
        uvc_ep_write(uvc->device, video->ep_in, 0);
        return RT_EOK;
    }

    return uvc_send_video_data(uvc);
}

static rt_err_t interface_handler(ufunction_t func, ureq_t setup)
{
    struct uvc_device *uvc;

    RT_ASSERT(func != RT_NULL);
    RT_ASSERT(func->device != RT_NULL);
    RT_ASSERT(setup != RT_NULL);

    RT_DEBUG_LOG(UVC_SETUP_DEBUG, ("setup req: 0x%02x 0x%02x value 0x%04x index 0x%04x 0x%04x\n",
                                   setup->request_type, setup->bRequest,
                                   le16_to_cpu(setup->wValue), le16_to_cpu(setup->wIndex),
                                   le16_to_cpu(setup->wLength)));

    if ((setup->request_type & USB_TYPE_MASK) != USB_TYPE_CLASS)
    {
        rt_kprintf("ERR: invalid setup request type\n");
        return -RT_EINVAL;
    }

    /* Stall too big requests */
    if (le16_to_cpu(setup->wLength) > UVC_MAX_REQUEST_SIZE)
        return -RT_EINVAL;

    uvc = func_to_uvc(func);

    return uvc_class_setup_notify(&uvc->event_dev, setup);
}

static rt_err_t ep_ctrl_handler(ufunction_t func, rt_size_t size)
{
    RT_DEBUG_LOG(RT_DEBUG_USB, ("ep_ctrl_handler\n"));

    return RT_EOK;
}

static rt_err_t function_enable(ufunction_t func)
{
    struct uvc_device *uvc = func_to_uvc(func);
    struct uvc_event event;

    RT_DEBUG_LOG(RT_DEBUG_USB, ("%s\n", __func__));

    if (uvc->state == UVC_STATE_DISCONNECTED)
    {
        /* disable ep_ctrl endpoint */
        dcd_ep_disable(func->device->dcd, uvc->ep_ctrl);
        dcd_ep_disable(func->device->dcd, uvc->video.ep_in);

        rt_memset(&event, 0, sizeof(event));
        event.type = UVC_EVENT_CONNECT;
        uvc_event_signal(&event, uvc->event_dev.video_id);

        uvc->state = UVC_STATE_CONNECTED;
    }

    return RT_EOK;
}

static rt_err_t function_disable(ufunction_t func)
{
    struct uvc_device *uvc = func_to_uvc(func);
    struct uvc_event event;

    RT_DEBUG_LOG(RT_DEBUG_USB, ("%s\n", __func__));

    rt_memset(&event, 0, sizeof(event));
    event.type = UVC_EVENT_DISCONNECT;
    uvc_event_signal(&event, uvc->event_dev.video_id);

    uvc->state = UVC_EVENT_DISCONNECT;

    return RT_EOK;
}

static rt_err_t function_setup(ufunction_t func, ureq_t setup)
{
    RT_DEBUG_LOG(RT_DEBUG_USB, ("%s\n", __func__));

    return RT_EOK;
}

static rt_err_t
function_set_alt(ufunction_t func, rt_uint8_t intf, rt_uint8_t alt)
{
    struct uvc_device *uvc = func_to_uvc(func);
//  struct uvc_event event;

    RT_DEBUG_LOG(RT_DEBUG_USB, ("%s(%u, %u)\n", __func__, intf, alt));

    if (intf == uvc->control_intf)
    {
        RT_DEBUG_LOG(RT_DEBUG_USB, ("%s: control interface alt\n", __func__));
        return RT_EOK;
    }

    if (intf != uvc->streaming_intf)
        return -RT_EINVAL;

    switch (uvc->state)
    {
    case UVC_STATE_CONNECTED:
//      rt_memset(&event, 0, sizeof(event));
//      event.type = UVC_EVENT_STREAMON;
//      uvc_event_signal(&event, uvc->edev.video_id);

        uvc->state = UVC_STATE_STREAMING;
        break;

    case UVC_STATE_STREAMING:
//      rt_memset(&event, 0, sizeof(event));
//      event.type = UVC_EVENT_STREAMOFF;
//      uvc_event_signal(&event, uvc->edev.video_id);

        uvc->state = UVC_STATE_CONNECTED;
        break;

    default:
        return -EINVAL;
    }

    return RT_EOK;
}

static struct ufunction_ops uvc_ops =
{
    function_enable,
    function_disable,
    RT_NULL,
    function_setup,
    function_set_alt,
};

static void
uvc_descriptor_reconfig(int id, unsigned int *desc_size,
                        uvc_ctrl_desc_t ctrl_desc,
                        void *strm_desc)
{
    unsigned int strm_size;

    RT_ASSERT(id >= UVC_ID_DEPTH && id < UVC_ID_MAX);

    if (id == UVC_ID_IR)
    {
        *desc_size = sizeof(struct uvc_bulk_streaming_intf_ir);
        strm_size = *desc_size - BULK_STREAMING_STD_LENGTH;
        ((uvc_streaming_ir_t)strm_desc)->uvc_input_header_ir.wTotalLength = cpu_to_le16(strm_size);
        ctrl_desc->uvc_iad.iFunction = 9;
        ctrl_desc->uvc_control_intf.iInterface = 9;
    }
    else if (id == UVC_ID_RGB)
    {
        *desc_size = sizeof(struct uvc_bulk_streaming_intf_rgb);
        strm_size = *desc_size - BULK_STREAMING_STD_LENGTH;
        ((uvc_streaming_rgb_t)strm_desc)->uvc_input_header.wTotalLength = cpu_to_le16(strm_size);
        ctrl_desc->uvc_iad.iFunction = 7;
        ctrl_desc->uvc_control_intf.iInterface = 7;
    }
    else
    {
        *desc_size = sizeof(struct uvc_bulk_streaming_intf_depth);
        strm_size = *desc_size - BULK_STREAMING_STD_LENGTH;
        ((uvc_streaming_depth_t)strm_desc)->uvc_input_header.wTotalLength = cpu_to_le16(strm_size);
        ctrl_desc->uvc_iad.iFunction = 5;
        ctrl_desc->uvc_control_intf.iInterface = 5;
    }

    return;
}

static ufunction_t
uvc_function_create(struct uvc_device *uvc,
                    uvc_ctrl_desc_t ctrl_intf_desc,
                    void *strm_intf_desc)
{
    udevice_t device = uvc->device;
    ufunction_t func;
    uintf_t ctrl_intf, strm_intf;
    ualtsetting_t ctrl_setting, strm_setting;
    uep_desc_t ctrl_ep, strm_ep;
    uintf_desc_t intf_desc;
    unsigned int desc_size;

    RT_DEBUG_LOG(RT_DEBUG_USB, ("uvc create(id %d)\n", uvc->id));

    /* parameter check */
    RT_ASSERT(device != RT_NULL);

    /* fix uvc Configuration descriptor */
    uvc_descriptor_reconfig(uvc->id, &desc_size,
                            ctrl_intf_desc,
                            strm_intf_desc);

    intf_desc = (uintf_desc_t)strm_intf_desc;

    /* set usb device string description */
    rt_usbd_device_set_string(device, uvc_ustring);

    /* create a uvc function */
    func = rt_usbd_function_new(device, &uvc_dev_desc, &uvc_ops);
    device->dev_qualifier = &dev_qualifier;
    func->user_data = (void *)uvc;

    /* create an interface object */
    ctrl_intf = rt_usbd_interface_new(device, interface_handler);
    strm_intf = rt_usbd_interface_new(device, interface_handler);

    /* update configuration descriptor dynamically */
    ctrl_intf_desc->uvc_iad.bFirstInterface = ctrl_intf->intf_num;
    ctrl_intf_desc->uvc_control_intf.bInterfaceNumber = ctrl_intf->intf_num;
    ctrl_intf_desc->uvc_control_header.baInterfaceNr[0] = strm_intf->intf_num;
    intf_desc->bInterfaceNumber = strm_intf->intf_num;

    uvc->control_intf = ctrl_intf->intf_num;
    uvc->streaming_intf = strm_intf->intf_num;

    /* create an alternate setting object */
    ctrl_setting = rt_usbd_altsetting_new(sizeof(struct uvc_ctrl_intf_desc));
    strm_setting = rt_usbd_altsetting_new(desc_size);

    /* config desc in alternate setting */
    rt_usbd_altsetting_config_descriptor(ctrl_setting, ctrl_intf_desc,
                                         (rt_off_t) & ((uvc_ctrl_desc_t)0)->uvc_control_intf);
    rt_usbd_altsetting_config_descriptor(strm_setting, strm_intf_desc, 0);

    ctrl_ep = &((uvc_ctrl_desc_t)ctrl_setting->desc)->uvc_control_ep;

    if (uvc->id == UVC_ID_IR)
        strm_ep = &((uvc_streaming_ir_t)strm_setting->desc)->uvc_hs_bulk_streaming_ep;
    else if (uvc->id == UVC_ID_RGB)
        strm_ep = &((uvc_streaming_rgb_t)strm_setting->desc)->uvc_hs_bulk_streaming_ep;
    else
        strm_ep = &((uvc_streaming_depth_t)strm_setting->desc)->uvc_hs_bulk_streaming_ep;

    /* create ctrl/bulk in endpoint */
    uvc->ep_ctrl = rt_usbd_endpoint_new(ctrl_ep, ep_ctrl_handler);
    uvc->video.ep_in = rt_usbd_endpoint_new(strm_ep, ep_in_handler);

    /* add the ctrl/bulk in endpoint to the alternate setting */
    rt_usbd_altsetting_add_endpoint(ctrl_setting, uvc->ep_ctrl);
    rt_usbd_altsetting_add_endpoint(strm_setting, uvc->video.ep_in);

    /* add the alternate setting to the interface, then set default setting */
    rt_usbd_interface_add_altsetting(ctrl_intf, ctrl_setting);
    rt_usbd_interface_add_altsetting(strm_intf, strm_setting);

    rt_usbd_set_altsetting(ctrl_intf, 0);
    rt_usbd_set_altsetting(strm_intf, 0);

    /* add the interface to the uvc function */
    rt_usbd_function_add_interface(func, ctrl_intf);
    rt_usbd_function_add_interface(func, strm_intf);

    uvc->state = UVC_STATE_DISCONNECTED;
    return func;
}

static void
rt_usbd_function_uvc_init(struct uvc_device *uvc, udevice_t device, int id)
{
    RT_ASSERT(uvc != RT_NULL);

    uvc->id = id;
    uvc->event_dev.video_id = id;
    uvc->device = device;

    uvc_buffer_init(uvc);
    uvc_event_init(&uvc->event_dev);
}

/* UVC global structure */
static struct uvc_device g_uvc_depth;
static struct uvc_device g_uvc_ir;
static struct uvc_device g_uvc_rgb;

static ufunction_t
rt_usbd_function_create_uvc_depth(udevice_t device)
{
    RT_ASSERT(device != RT_NULL);

    rt_usbd_function_uvc_init(&g_uvc_depth, device, UVC_ID_DEPTH);

    return uvc_function_create(&g_uvc_depth, &ctrl_intf_desc, &streaming_intf_depth);
}

static ufunction_t
rt_usbd_function_create_uvc_rgb(udevice_t device)
{
    RT_ASSERT(device != RT_NULL);

    rt_usbd_function_uvc_init(&g_uvc_rgb, device, UVC_ID_RGB);

    return uvc_function_create(&g_uvc_rgb, &ctrl_intf_desc, &streaming_intf_rgb);
}

static ufunction_t
rt_usbd_function_create_uvc_ir(udevice_t device)
{
    RT_ASSERT(device != RT_NULL);

    rt_usbd_function_uvc_init(&g_uvc_ir, device, UVC_ID_IR);

    return uvc_function_create(&g_uvc_ir, &ctrl_intf_desc, &streaming_intf_ir);
}

static struct udclass uvc_class_depth =
{
    .rt_usbd_function_create = rt_usbd_function_create_uvc_depth
};

static struct udclass uvc_class_rgb =
{
    .rt_usbd_function_create = rt_usbd_function_create_uvc_rgb
};

static struct udclass uvc_class_ir =
{
    .rt_usbd_function_create = rt_usbd_function_create_uvc_ir
};

int rt_usbd_uvc_class_register(void)
{
    rt_usbd_class_register(&uvc_class_depth);
    rt_usbd_class_register(&uvc_class_rgb);
    rt_usbd_class_register(&uvc_class_ir);

    return 0;
}
INIT_PREV_EXPORT(rt_usbd_uvc_class_register);
