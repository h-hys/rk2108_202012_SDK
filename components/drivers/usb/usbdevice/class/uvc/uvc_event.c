/**
  * Copyright (c) 2020 Rockchip Electronics Co., Ltd
  *
  * SPDX-License-Identifier: Apache-2.0
  ******************************************************************************
  * @file    uvc_event.c
  * @version V0.1
  * @brief   usb video class request process file
  *
  * Change Logs:
  * Date           Author          Notes
  * 2020-07-01     Frank Wang      first implementation
  *
  ******************************************************************************
  */
#include <rtthread.h>
#include <rtservice.h>
#include <rtdevice.h>
#include "drivers/usb_common.h"
#include "drivers/usb_video.h"
#include "uvc.h"
#include <hal_base.h>

#define PAYLOAD_SIZE (512 * 1024)

#define EL2HLT      51  /* Level 2 halted */
#define EXT_QUERY_CMD 0x82

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(ar)     (sizeof(ar)/sizeof(ar[0]))
#endif

#ifndef typeof
#define typeof    __typeof__
#endif

#define CLEAR(x)    rt_memset (&(x), 0, sizeof (x))

#define clamp(val, min, max) ({ \
    typeof(val) __val = (val); \
    typeof(min) __min = (min); \
    typeof(max) __max = (max); \
    (void) (&__val == &__min); \
    (void) (&__val == &__max); \
    __val = __val < __min ? __min: __val; \
    __val > __max ? __max: __val; })

/*
 * The UVC webcam gadget kernel driver (g_webcam.ko) supports changing
 * the Brightness attribute of the Processing Unit (PU). by default. If
 * the underlying video capture device supports changing the Brightness
 * attribute of the image being acquired (like the Virtual Video, VIVI
 * driver), then we should route this UVC request to the respective
 * video capture device.
 *
 * Incase, there is no actual video capture device associated with the
 * UVC gadget and we wish to use this application as the final
 * destination of the UVC specific requests then we should return
 * pre-cooked (static) responses to GET_CUR(BRIGHTNESS) and
 * SET_CUR(BRIGHTNESS) commands to keep command verifier test tools like
 * UVC class specific test suite of USBCV, happy.
 *
 * Note that the values taken below are in sync with the VIVI driver and
 * must be changed for your specific video capture device. These values
 * also work well in case there in no actual video capture device.
 */
#define PU_BRIGHTNESS_MIN_VAL       0
#define PU_BRIGHTNESS_MAX_VAL       255
#define PU_BRIGHTNESS_STEP_SIZE     1
#define PU_BRIGHTNESS_DEFAULT_VAL   127

#define PU_CONTRAST_MIN_VAL         0
#define PU_CONTRAST_MAX_VAL         65535
#define PU_CONTRAST_STEP_SIZE       1
#define PU_CONTRAST_DEFAULT_VAL     127

#define PU_HUE_MIN_VAL              -32768
#define PU_HUE_MAX_VAL              32767
#define PU_HUE_STEP_SIZE            1
#define PU_HUE_DEFAULT_VAL          0

#define PU_SATURATION_MIN_VAL       0
#define PU_SATURATION_MAX_VAL       65535
#define PU_SATURATION_STEP_SIZE     1
#define PU_SATURATION_DEFAULT_VAL   0

#define PU_SHARPNESS_MIN_VAL        0
#define PU_SHARPNESS_MAX_VAL        255
#define PU_SHARPNESS_STEP_SIZE      1
#define PU_SHARPNESS_DEFAULT_VAL    127

#define PU_GAMMA_MIN_VAL            0
#define PU_GAMMA_MAX_VAL            255
#define PU_GAMMA_STEP_SIZE          1
#define PU_GAMMA_DEFAULT_VAL        127

#define PU_WHITE_BALANCE_TEMPERATURE_MIN_VAL        0
#define PU_WHITE_BALANCE_TEMPERATURE_MAX_VAL        255
#define PU_WHITE_BALANCE_TEMPERATURE_STEP_SIZE      1
#define PU_WHITE_BALANCE_TEMPERATURE_DEFAULT_VAL    127

#define PU_GAIN_MIN_VAL             0
#define PU_GAIN_MAX_VAL             255
#define PU_GAIN_STEP_SIZE           1
#define PU_GAIN_DEFAULT_VAL         0

#define PU_HUE_AUTO_MIN_VAL         0
#define PU_HUE_AUTO_MAX_VAL         255
#define PU_HUE_AUTO_STEP_SIZE       1
#define PU_HUE_AUTO_DEFAULT_VAL     127

#define HWID_TBL_NUM                3

static const struct uvc_frame_info uvc_frames_yuyv[] =
{
    {  480, 640, { 333333, 500000, 666666, 1000000, 1333333, 0 }, },
    { 1280, 720, { 1000000, 1333333, 0 }, },
    { 1280, 900, { 1000000, 1333333, 0 }, },
    {  640, 480, { 333333, 500000, 666666, 1000000, 1333333, 0 }, },
    {  640, 360, { 333333, 500000, 666666, 1000000, 1333333, 0 }, },
    {  640, 400, { 333333, 500000, 666666, 1000000, 1333333, 0 }, },
    { 1280, 800, { 1000000, 1333333, 0 }, },
    { 0, 0, { 0, }, },
};

static const struct uvc_frame_info uvc_frames_mjpeg[] =
{
    { 480, 640, { 333333, 500000, 666666, 1000000, 1333333, 0 }, },
    { 1280, 720, { 333333, 500000, 666666, 1000000, 1333333, 0 }, },
    { 1920, 1440, { 333333, 500000, 666666, 1000000, 1333333, 0 }, },
    { 640, 480, { 333333, 500000, 666666, 1000000, 1333333, 0 }, },
    { 1920, 1080, { 333333, 500000, 666666, 1000000, 1333333, 0 }, },
    { 1280, 800, { 333333, 500000, 666666, 1000000, 1333333, 0 }, },
    { 0, 0, { 0, }, },
};

static const struct uvc_format_info uvc_formats[] =
{
    { V4L2_PIX_FMT_MJPEG, uvc_frames_mjpeg },
    { V4L2_PIX_FMT_YUYV, uvc_frames_yuyv },
};

static inline struct uvc_device *class_to_uvc(struct uvc_event_device *dev)
{
    return rt_container_of(dev, struct uvc_device, event_dev);
}

/* ---------------------------------------------------------------------------
 * UVC Request processing
 */

static void
uvc_fill_streaming_control(struct uvc_event_device *dev,
                           struct uvc_streaming_control *ctrl,
                           int iframe, int iformat)
{
    const struct uvc_format_info *format;
    const struct uvc_frame_info *frame;
    unsigned int nframes;

    if (iformat < 0)
        iformat = ARRAY_SIZE(uvc_formats) + iformat;
    if (iformat < 0 || iformat >= (int)ARRAY_SIZE(uvc_formats))
        return;
    format = &uvc_formats[iformat];

    nframes = 0;
    while (format->frames[nframes].width != 0)
        ++nframes;

    if (iframe < 0)
        iframe = nframes + iframe;
    if (iframe < 0 || iframe >= (int)nframes)
        return;
    frame = &format->frames[iframe];

    rt_memset(ctrl, 0, sizeof(*ctrl));

    ctrl->bmHint = 1;
    ctrl->bFormatIndex = iformat + 1;
    ctrl->bFrameIndex = iframe + 1;
    ctrl->dwFrameInterval = frame->intervals[0];
    switch (format->fcc)
    {
    case V4L2_PIX_FMT_YUYV:
        ctrl->dwMaxVideoFrameSize = frame->width * frame->height * 2;
        break;
    case V4L2_PIX_FMT_MJPEG:
        ctrl->dwMaxVideoFrameSize = frame->width * frame->height * 3 / 2;
        break;
    }

    /* TODO: the UVC maxpayload transfer size should be filled
     * by the driver.
     */
    ctrl->dwMaxPayloadTransferSize = PAYLOAD_SIZE;//ctrl->dwMaxVideoFrameSize;

    ctrl->bmFramingInfo = 3;
    ctrl->bPreferedVersion = 1;
    ctrl->bMaxVersion = 1;
}

static void
uvc_events_process_standard(struct uvc_event_device *dev,
                            ureq_t ctrl,
                            struct uvc_request_data *resp)
{
    RT_DEBUG_LOG(RT_DEBUG_USB, ("standard request\n"));
    (void)dev;
    (void)ctrl;
    (void)resp;
}

static void
uvc_events_process_control(struct uvc_event_device *dev, uint8_t req,
                           uint8_t cs, uint8_t entity_id,
                           uint8_t len, struct uvc_request_data *resp)
{
    RT_DEBUG_LOG(UVC_SETUP_DEBUG, ("%s: video_id %d req 0x%02x cs %d entity_id %d len %d\n",
                                   __func__, dev->video_id, req, cs, entity_id, len));

    dev->cs = cs;
    dev->entity_id = entity_id;

    switch (entity_id)
    {
    case 0:
        switch (cs)
        {
        case UVC_VC_REQUEST_ERROR_CODE_CONTROL:
            /* Send the request error code last prepared. */
            resp->data[0] = dev->request_error_code.data[0];
            resp->length = dev->request_error_code.length;
            break;

        default:
            /*
             * If we were not supposed to handle this
             * 'cs', prepare an error code response.
             */
            dev->request_error_code.data[0] = 0x06;
            dev->request_error_code.length = 1;
            break;
        }
        break;

    /* Camera terminal unit 'UVC_VC_INPUT_TERMINAL'. */
    case 1:
        switch (cs)
        {
        /*
         * We support only 'UVC_CT_AE_MODE_CONTROL' for CAMERA
         * terminal, as our bmControls[0] = 2 for CT. Also we
         * support only auto exposure.
         */
        case UVC_CT_AE_MODE_CONTROL:
            switch (req)
            {
            case UVC_SET_CUR:
                /* Incase of auto exposure, attempts to
                 * programmatically set the auto-adjusted
                 * controls are ignored.
                 */
                resp->data[0] = 0x01;
                resp->length = 1;
                /*
                 * For every successfully handled control
                 * request set the request error code to no
                 * error.
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                dev->req_out = 1;
                break;

            case UVC_GET_INFO:
                /*
                 * TODO: We support Set and Get requests, but
                 * don't support async updates on an video
                 * status (interrupt) endpoint as of
                 * now.
                 */
                resp->data[0] = 0x03;
                resp->length = 1;
                /*
                 * For every successfully handled control
                 * request set the request error code to no
                 * error.
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_CUR:
            case UVC_GET_DEF:
            case UVC_GET_RES:
                /* Auto Mode Ã¢?? auto Exposure Time, auto Iris. */
                resp->data[0] = 0x02;
                resp->length = 1;
                /*
                 * For every successfully handled control
                 * request set the request error code to no
                 * error.
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                /*
                 * We don't support this control, so STALL the
                 * control ep.
                 */
                resp->length = -EL2HLT;
                /*
                 * For every unsupported control request
                 * set the request error code to appropriate
                 * value.
                 */
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;
        case UVC_CT_EXPOSURE_TIME_ABSOLUTE_CONTROL:
            switch (req)
            {
            case UVC_GET_INFO:
            case UVC_GET_MIN:
            case UVC_GET_MAX:
            case UVC_GET_CUR:
            case UVC_GET_DEF:
            case UVC_GET_RES:
                resp->data[0] = 100;
                resp->length = len;

                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                /*
                 * We don't support this control, so STALL the
                 * control ep.
                 */
                resp->length = -EL2HLT;
                /*
                 * For every unsupported control request
                 * set the request error code to appropriate
                 * value.
                 */
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
            }
            break;
        case UVC_CT_IRIS_ABSOLUTE_CONTROL:
            switch (req)
            {
            case UVC_GET_INFO:
            case UVC_GET_CUR:
            case UVC_GET_MIN:
            case UVC_GET_MAX:
            case UVC_GET_DEF:
            case UVC_GET_RES:
                resp->data[0] = 10;
                resp->length = len;

                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                /*
                 * We don't support this control, so STALL the
                 * control ep.
                 */
                resp->length = -EL2HLT;
                /*
                 * For every unsupported control request
                 * set the request error code to appropriate
                 * value.
                 */
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
            }
            break;

        default:
            /*
             * We don't support this control, so STALL the control
             * ep.
             */
            resp->length = -EL2HLT;
            /*
             * If we were not supposed to handle this
             * 'cs', prepare a Request Error Code response.
             */
            dev->request_error_code.data[0] = 0x06;
            dev->request_error_code.length = 1;
            break;
        }
        break;

    /* processing unit 'UVC_VC_PROCESSING_UNIT' */
    case 2:
        switch (cs)
        {
        case UVC_PU_BRIGHTNESS_CONTROL:
            switch (req)
            {
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                /*
                 * For every successfully handled control
                 * request set the request error code to no
                 * error
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                rt_kprintf("INF: set brightness\n");
                dev->req_out = 1;
                break;
            case UVC_GET_MIN:
                resp->data[0] = PU_BRIGHTNESS_MIN_VAL;
                resp->length = 2;
                /*
                 * For every successfully handled control
                 * request set the request error code to no
                 * error
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MAX:
                resp->data[0] = PU_BRIGHTNESS_MAX_VAL;
                resp->length = 2;
                /*
                 * For every successfully handled control
                 * request set the request error code to no
                 * error
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_CUR:
                resp->length = 2;
                rt_memcpy(&resp->data[0], &dev->brightness_val,
                          resp->length);
                /*
                 * For every successfully handled control
                 * request set the request error code to no
                 * error
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_INFO:
                /*
                 * We support Set and Get requests and don't
                 * support async updates on an interrupt endpt
                 */
                resp->data[0] = 0x03;
                resp->length = 1;
                /*
                 * For every successfully handled control
                 * request, set the request error code to no
                 * error.
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_DEF:
                resp->data[0] = PU_BRIGHTNESS_DEFAULT_VAL;
                resp->length = 2;
                /*
                 * For every successfully handled control
                 * request, set the request error code to no
                 * error.
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_RES:
                resp->data[0] = PU_BRIGHTNESS_STEP_SIZE;
                resp->length = 2;
                /*
                 * For every successfully handled control
                 * request, set the request error code to no
                 * error.
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                /*
                 * We don't support this control, so STALL the
                 * default control ep.
                 */
                resp->length = -EL2HLT;
                /*
                 * For every unsupported control request
                 * set the request error code to appropriate
                 * code.
                 */
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;
        case UVC_PU_CONTRAST_CONTROL:
            switch (req)
            {
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                dev->req_out = 1;
                break;
            case UVC_GET_MIN:
                resp->data[0] = PU_CONTRAST_MIN_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MAX:
                resp->data[0] = PU_CONTRAST_MAX_VAL % 256;
                resp->data[1] = PU_CONTRAST_MAX_VAL / 256;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_CUR:
                resp->length = 2;
                rt_memcpy(&resp->data[0], &dev->contrast_val,
                          resp->length);
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_INFO:
                resp->data[0] = 0x03;
                resp->length = 1;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_DEF:
                resp->data[0] = PU_CONTRAST_DEFAULT_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_RES:
                resp->data[0] = PU_CONTRAST_STEP_SIZE;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                resp->length = -EL2HLT;
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;
        case UVC_PU_HUE_CONTROL:
            switch (req)
            {
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                dev->req_out = 1;
                break;
            case UVC_GET_MIN:
                resp->data[0] = PU_HUE_MIN_VAL % 256;
                resp->data[1] = PU_HUE_MIN_VAL / 256;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MAX:
                resp->data[0] = PU_HUE_MAX_VAL % 256;
                resp->data[1] = PU_HUE_MAX_VAL / 256;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_CUR:
                resp->length = 2;
//                if (hue_get_cb)
//                    dev->hue_val = hue_get_cb(hue_get_device);
                rt_memcpy(&resp->data[0], &dev->hue_val,
                          resp->length);
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_INFO:
                resp->data[0] = 0x03;
                resp->length = 1;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_DEF:
                resp->data[0] = PU_HUE_DEFAULT_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_RES:
                resp->data[0] = PU_HUE_STEP_SIZE;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                resp->length = -EL2HLT;
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;
        case UVC_PU_SATURATION_CONTROL:
            switch (req)
            {
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                dev->req_out = 1;
                break;
            case UVC_GET_MIN:
                resp->data[0] = PU_SATURATION_MIN_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MAX:
                resp->data[0] = PU_SATURATION_MAX_VAL % 256;
                resp->data[1] = PU_SATURATION_MAX_VAL / 256;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_CUR:
                resp->length = 2;
                rt_memcpy(&resp->data[0], &dev->saturation_val,
                          resp->length);
                rt_memset(&dev->saturation_val, 0, sizeof(dev->saturation_val));
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_INFO:
                resp->data[0] = 0x03;
                resp->length = 1;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_DEF:
                resp->data[0] = PU_SATURATION_DEFAULT_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_RES:
                resp->data[0] = PU_SATURATION_STEP_SIZE;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                resp->length = -EL2HLT;
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;
        case UVC_PU_SHARPNESS_CONTROL:
            switch (req)
            {
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                dev->req_out = 1;
                break;
            case UVC_GET_MIN:
                resp->data[0] = PU_SHARPNESS_MIN_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MAX:
                resp->data[0] = PU_SHARPNESS_MAX_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_CUR:
                resp->length = 2;
                rt_memcpy(&resp->data[0], &dev->sharpness_val,
                          resp->length);
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_INFO:
                resp->data[0] = 0x03;
                resp->length = 1;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_DEF:
                resp->data[0] = PU_SHARPNESS_DEFAULT_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_RES:
                resp->data[0] = PU_SHARPNESS_STEP_SIZE;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                resp->length = -EL2HLT;
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;
        case UVC_PU_GAMMA_CONTROL:
            switch (req)
            {
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                dev->req_out = 1;
                break;
            case UVC_GET_MIN:
                resp->data[0] = PU_GAMMA_MIN_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MAX:
                resp->data[0] = PU_GAMMA_MAX_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_CUR:
                resp->length = 2;
                rt_memcpy(&resp->data[0], &dev->gamma_val,
                          resp->length);
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_INFO:
                resp->data[0] = 0x03;
                resp->length = 1;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_DEF:
                resp->data[0] = PU_GAMMA_DEFAULT_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_RES:
                resp->data[0] = PU_GAMMA_STEP_SIZE;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                resp->length = -EL2HLT;
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;
        case UVC_PU_WHITE_BALANCE_TEMPERATURE_CONTROL:
            switch (req)
            {
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                dev->req_out = 1;
                break;
            case UVC_GET_MIN:
                resp->data[0] = PU_WHITE_BALANCE_TEMPERATURE_MIN_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MAX:
                resp->data[0] = PU_WHITE_BALANCE_TEMPERATURE_MAX_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_CUR:
                resp->length = 2;
                rt_memcpy(&resp->data[0], &dev->white_balance_temperature_val,
                          resp->length);
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_INFO:
                resp->data[0] = 0x03;
                resp->length = 1;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_DEF:
                resp->data[0] = PU_WHITE_BALANCE_TEMPERATURE_DEFAULT_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_RES:
                resp->data[0] = PU_WHITE_BALANCE_TEMPERATURE_STEP_SIZE;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                resp->length = -EL2HLT;
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;
        case UVC_PU_GAIN_CONTROL:
            switch (req)
            {
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                dev->req_out = 1;
                break;
            case UVC_GET_MIN:
                resp->data[0] = PU_GAIN_MIN_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MAX:
                resp->data[0] = PU_GAIN_MAX_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_CUR:
                resp->length = 2;
                rt_memcpy(&resp->data[0], &dev->gain_val,
                          resp->length);
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_INFO:
                resp->data[0] = 0x03;
                resp->length = 1;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_DEF:
                resp->data[0] = PU_GAIN_DEFAULT_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_RES:
                resp->data[0] = PU_GAIN_STEP_SIZE;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                resp->length = -EL2HLT;
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;
        case UVC_PU_HUE_AUTO_CONTROL:
            switch (req)
            {
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                dev->req_out = 1;
                break;
            case UVC_GET_MIN:
                resp->data[0] = PU_HUE_AUTO_MIN_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MAX:
                resp->data[0] = PU_HUE_AUTO_MAX_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_CUR:
                resp->length = 2;
                rt_memcpy(&resp->data[0], &dev->hue_auto_val,
                          resp->length);
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_INFO:
                resp->data[0] = 0x03;
                resp->length = 1;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_DEF:
                resp->data[0] = PU_HUE_AUTO_DEFAULT_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_RES:
                resp->data[0] = PU_HUE_AUTO_STEP_SIZE;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                resp->length = -EL2HLT;
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;
        case UVC_PU_POWER_LINE_FREQUENCY_CONTROL:
            switch (req)
            {
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                dev->req_out = 1;
                break;
            case UVC_GET_CUR:
                resp->length = 1;
                rt_memcpy(&resp->data[0], &dev->power_line_frequency_val,
                          resp->length);
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_INFO:
                resp->data[0] = 0x03;
                resp->length = 1;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_DEF:
                resp->data[0] = 1;
                resp->length = 1;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
// TODO: FIXME: need to keep inline with linux flow
//              resp->length = -EL2HLT;
                resp->length = 1;
                resp->data[0] = 0x07;
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;
        default:
            /*
             * We don't support this control, so STALL the control
             * ep.
             */
            resp->length = -EL2HLT;
            /*
             * If we were not supposed to handle this
             * 'cs', prepare a Request Error Code response.
             */
            dev->request_error_code.data[0] = 0x06;
            dev->request_error_code.length = 1;
            break;
        }

        break;

    case 6:
        switch (cs)
        {
        case 1:
            switch (req)
            {
            case UVC_GET_LEN:
                resp->data[0] = 0x4;
                resp->length = len;
                /*
                 * For every successfully handled control
                 * request set the request error code to no
                 * error
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                /*
                 * For every successfully handled control
                 * request set the request error code to no
                 * error
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                dev->req_out = 1;
                break;
            case UVC_GET_MIN:
                resp->data[0] = 0;
                resp->length = 4;
                /*
                 * For every successfully handled control
                 * request set the request error code to no
                 * error
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MAX:
                resp->data[0] = 0xFF;
                resp->data[1] = 0xFF;
                resp->data[2] = 0xFF;
                resp->data[3] = 0xFF;
                resp->length = 4;
                /*
                 * For every successfully handled control
                 * request set the request error code to no
                 * error
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_CUR:
                resp->length = len < sizeof(dev->ext1) ? len : sizeof(dev->ext1);
                rt_memcpy(resp->data, dev->ext1, resp->length);
                /*
                 * For every successfully handled control
                 * request set the request error code to no
                 * error
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_INFO:
                /*
                 * We support Set and Get requests and don't
                 * support async updates on an interrupt endpt
                 */
                resp->data[0] = 0x03;
                resp->length = 1;
                /*
                 * For every successfully handled control
                 * request, set the request error code to no
                 * error.
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_DEF:
                resp->data[0] = 0;
                resp->length = 4;
                /*
                 * For every successfully handled control
                 * request, set the request error code to no
                 * error.
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_RES:
                resp->data[0] = 1;
                resp->length = 4;
                /*
                 * For every successfully handled control
                 * request, set the request error code to no
                 * error.
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                /*
                 * We don't support this control, so STALL the
                 * default control ep.
                 */
                resp->length = -EL2HLT;
                /*
                 * For every unsupported control request
                 * set the request error code to appropriate
                 * code.
                 */
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;

        case 2:
            switch (req)
            {
            case UVC_GET_LEN:
                resp->data[0] = 0x10;
                resp->data[1] = 0x00;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                dev->req_out = 1;
                break;
            case UVC_GET_MIN:
                resp->data[0] = 0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MAX:
                resp->data[0] = 0xFF;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_CUR:
                resp->length = len;
                if (sizeof(dev->ex_ctrl) >= resp->length)
                    rt_memcpy(resp->data, dev->ex_ctrl, resp->length);
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_INFO:
                resp->data[0] = 0x03;
                resp->length = 1;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_DEF:
                resp->data[0] = 0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_RES:
                resp->data[0] = 1;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                resp->length = -EL2HLT;
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;

        case 3:
            switch (req)
            {
            case UVC_GET_LEN:
                if (dev->ex_length > dev->ex_index)
                    resp->data[0] = min(dev->ex_length - dev->ex_index, 60);
                else
                    resp->data[0] = 2;
                resp->data[1] = 0;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                dev->req_out = 1;
                break;
            case UVC_GET_MIN:
                resp->data[0] = 0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MAX:
                resp->data[0] = 0xFF;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_CUR:
                resp->length = len;
                if (dev->ex_ctrl[0] == EXT_QUERY_CMD)
                {
                    if (resp->length == 4)
                    {
                        resp->data[0] = EXT_QUERY_CMD;
                        resp->data[1] = dev->ex_result;
                        rt_memcpy(&resp->data[2], &dev->get_checksum, 2);
                        dev->ex_result = 0;
                    }
                    else
                    {
                        rt_kprintf("ERR: %d uvc iq tool get data error.\n", __LINE__);
                    }
                }
                else
                {
                    rt_kprintf("ERR: %d uvc iq tool get data error.\n", __LINE__);
                }
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_INFO:
                resp->data[0] = 0x03;
                resp->length = 1;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_DEF:
                resp->data[0] = 0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_RES:
                resp->data[0] = 1;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                resp->length = -EL2HLT;
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;

        case 4:
            switch (req)
            {
            case UVC_GET_LEN:
                rt_memset(resp->data, 0, sizeof(resp->data));
                resp->data[0] = sizeof(resp->data);
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_SET_CUR:
                rt_memset(resp->data, 0, sizeof(resp->data));
                resp->data[0] = 0x0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                dev->req_out = 1;
                break;
            case UVC_GET_MIN:
                rt_memset(resp->data, 0, sizeof(resp->data));
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MAX:
                rt_memset(resp->data, 0xFF, sizeof(resp->data));
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_CUR:
                resp->length = len < sizeof(dev->ext4) ? len : sizeof(dev->ext4);
                rt_memcpy(resp->data, dev->ext4, resp->length);
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_INFO:
                resp->data[0] = 0x03;
                resp->length = 1;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_DEF:
                rt_memset(resp->data, 0, sizeof(resp->data));
                resp->data[0] = 0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_RES:
                rt_memset(resp->data, 0, sizeof(resp->data));
                resp->data[0] = 1;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                resp->length = -EL2HLT;
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;

        default:
            /*
             * We don't support this control, so STALL the control
             * ep.
             */
            resp->length = -EL2HLT;
            /*
             * If we were not supposed to handle this
             * 'cs', prepare a Request Error Code response.
             */
            dev->request_error_code.data[0] = 0x06;
            dev->request_error_code.length = 1;
            break;
        }
        break;

    default:
        /*
         * If we were not supposed to handle this
         * 'cs', prepare a Request Error Code response.
         */
        dev->request_error_code.data[0] = 0x06;
        dev->request_error_code.length = 1;
        break;

    }

    if (resp->length == -EL2HLT)
    {
        rt_kprintf("WAR: unsupported, req=%02x, cs=%d, entity_id=%d, len=%d\n",
                   req, cs, entity_id, len);
        resp->length = 0;
    }
}

static void
uvc_events_process_streaming(struct uvc_event_device *dev, uint8_t req,
                             uint8_t cs, struct uvc_request_data *resp)
{
    struct uvc_streaming_control *ctrl;

    RT_DEBUG_LOG(UVC_SETUP_DEBUG, ("%s: req 0x%02x cs 0x%02x\n", __func__, req, cs));

    if (cs != UVC_VS_PROBE_CONTROL && cs != UVC_VS_COMMIT_CONTROL)
        return;

    ctrl = (struct uvc_streaming_control *)&resp->data;
    resp->length = sizeof(*ctrl);

    switch (req)
    {
    case UVC_SET_CUR:
        RT_DEBUG_LOG(UVC_SETUP_DEBUG, ("uvc set cur (%d %d)\n", dev->video_id, cs));
        dev->control = cs;
        resp->length = 26;
        dev->req_out = 1;
        break;

    case UVC_GET_CUR:
        RT_DEBUG_LOG(UVC_SETUP_DEBUG, ("uvc get cur(%d %d)\n", dev->video_id, cs));
        if (cs == UVC_VS_PROBE_CONTROL)
            rt_memcpy(ctrl, &dev->probe, sizeof * ctrl);
        else
            rt_memcpy(ctrl, &dev->commit, sizeof * ctrl);
#if 0
        rt_kprintf("bmHint: %u\n", ctrl->bmHint);
        rt_kprintf("bFormatIndex: %u\n", ctrl->bFormatIndex);
        rt_kprintf("bFrameIndex: %u\n", ctrl->bFrameIndex);
        rt_kprintf("dwFrameInterval: %u\n", ctrl->dwFrameInterval);
        rt_kprintf("wKeyFrameRate: %u\n", ctrl->wKeyFrameRate);
        rt_kprintf("wPFrameRate: %u\n", ctrl->wPFrameRate);
        rt_kprintf("wCompQuality: %u\n", ctrl->wCompQuality);
        rt_kprintf("wCompWindowSize: %u\n", ctrl->wCompWindowSize);
        rt_kprintf("wDelay: %u\n", ctrl->wDelay);
        rt_kprintf("dwMaxVideoFrameSize: %u\n", ctrl->dwMaxVideoFrameSize);
        rt_kprintf("dwMaxPayloadTransferSize: %u\n", ctrl->dwMaxPayloadTransferSize);
        rt_kprintf("dwClockFrequency: %u\n", ctrl->dwClockFrequency);
        rt_kprintf("bmFramingInfo: %u\n", ctrl->bmFramingInfo);
        rt_kprintf("bPreferedVersion: %u\n", ctrl->bPreferedVersion);
        rt_kprintf("bMinVersion: %u\n", ctrl->bMinVersion);
        rt_kprintf("bMaxVersion: %u\n", ctrl->bMaxVersion);
#endif
        break;

    case UVC_GET_MIN:
    case UVC_GET_MAX:
    case UVC_GET_DEF:
        RT_DEBUG_LOG(UVC_SETUP_DEBUG, ("%s: video %d req 0x%02x\n", __func__, dev->video_id, req));
        uvc_fill_streaming_control(dev, ctrl, req == UVC_GET_MAX ? -1 : 0,
                                   req == UVC_GET_MAX ? -1 : 0);
        break;

    case UVC_GET_RES:
        rt_memset(ctrl, 0, sizeof(*ctrl));
        break;

    case UVC_GET_LEN:
        resp->data[0] = 0x00;
        resp->data[1] = 0x22;
        resp->length = 2;
        break;

    case UVC_GET_INFO:
        resp->data[0] = 0x03;
        resp->length = 1;
        break;
    }
}

static void
uvc_events_process_class(struct uvc_event_device *dev,
                         ureq_t ctrl, struct uvc_request_data *resp)
{
    if ((ctrl->request_type & USB_RECIP_MASK) != USB_RECIP_INTERFACE)
        return;

    switch ((ctrl->wIndex & 0xff) % 2)
    {
    case UVC_INTF_CONTROL:
        RT_DEBUG_LOG(RT_DEBUG_USB, ("uvc intf control\n"));
        uvc_events_process_control(dev, ctrl->bRequest,
                                   ctrl->wValue >> 8,
                                   ctrl->wIndex >> 8,
                                   ctrl->wLength, resp);
        break;

    case UVC_INTF_STREAMING:
        RT_DEBUG_LOG(RT_DEBUG_USB, ("uvc intf streaming\n"));
        uvc_events_process_streaming(dev, ctrl->bRequest,
                                     ctrl->wValue >> 8, resp);
        break;

    default:
        break;
    }
}

static void
uvc_events_process_setup(struct uvc_event_device *dev, ureq_t ctrl,
                         struct uvc_request_data *resp)
{
    dev->control = 0;

    switch (ctrl->request_type & USB_TYPE_MASK)
    {
    case USB_TYPE_STANDARD:
        uvc_events_process_standard(dev, ctrl, resp);
        break;

    case USB_TYPE_CLASS:
        uvc_events_process_class(dev, ctrl, resp);
        break;

    default:
        break;
    }
}

static int
uvc_events_process_control_data(struct uvc_event_device *dev,
                                uint8_t cs, uint8_t entity_id,
                                struct uvc_request_data *data)
{

    unsigned int *val = (unsigned int *)data->data;

    RT_DEBUG_LOG(UVC_SETUP_DEBUG, ("%s: data=0x%08x length=%d current_cs=%u\n",
                                   __func__, *val, data->length, dev->cs));

    switch (entity_id)
    {
    /* Processing unit 'UVC_VC_PROCESSING_UNIT'. */
    case 2:
        switch (cs)
        {
        case UVC_PU_BRIGHTNESS_CONTROL:
            rt_kprintf("INF: UVC_PU_BRIGHTNESS_CONTROL receive\n");
            if (sizeof(dev->brightness_val) >= data->length)
            {
                rt_memcpy(&dev->brightness_val, data->data, data->length);
                //video_record_set_brightness(*val);
            }
            break;
        case UVC_PU_CONTRAST_CONTROL:
            rt_kprintf("INF: UVC_PU_CONTRAST_CONTROL receive\n");
            if (sizeof(dev->contrast_val) >= data->length)
            {
                rt_memcpy(&dev->contrast_val, data->data, data->length);
//                if (video_record_set_time_cb)
//                    video_record_set_time_cb(dev->contrast_val, 1);
                rt_kprintf("INF: UVC_PU_CONTRAST_CONTROL: 0x%02x 0x%02x\n",
                           data->data[0], data->data[1]);
                //video_record_set_contrast(*val);
            }
            break;
        case UVC_PU_HUE_CONTROL:
            rt_kprintf("INF: UVC_PU_HUE_CONTROL receive\n");
            if (sizeof(dev->hue_val) >= data->length)
            {
                rt_memcpy(&dev->hue_val, data->data, data->length);
                rt_kprintf("INF: UVC_PU_HUE_CONTROL: 0x%02x 0x%02x\n",
                           data->data[0], data->data[1]);
//                if (hue_set_cb)
//                    hue_set_cb(dev->hue_val, hue_set_device);
//                video_record_set_hue(*val);
            }
            break;
        case UVC_PU_SATURATION_CONTROL:
            if (sizeof(dev->saturation_val) >= data->length)
            {
                //rt_memcpy(&dev->saturation_val, data->data, data->length);
//                saturation_communicate(dev, data);
                //video_record_set_saturation(*val);
            }
            break;
        case UVC_PU_SHARPNESS_CONTROL:
            if (sizeof(dev->sharpness_val) >= data->length)
                rt_memcpy(&dev->sharpness_val, data->data, data->length);
            break;
        case UVC_PU_GAMMA_CONTROL:
            if (sizeof(dev->gamma_val) >= data->length)
                rt_memcpy(&dev->gamma_val, data->data, data->length);
            break;
        case UVC_PU_WHITE_BALANCE_TEMPERATURE_CONTROL:
            /* 0:auto, 1:Daylight 2:fluocrescence 3:cloudysky 4:tungsten */
            if (sizeof(dev->white_balance_temperature_val) >= data->length)
            {
                rt_memcpy(&dev->white_balance_temperature_val, data->data, data->length);
                //api_set_white_balance(*val / 51);
            }
            break;
        case UVC_PU_GAIN_CONTROL:
            if (sizeof(dev->gain_val) >= data->length)
                rt_memcpy(&dev->gain_val, data->data, data->length);
//            if (video_record_cif_set_gain_cb)
//                video_record_cif_set_gain_cb(dev->gain_val);
            break;
        case UVC_PU_HUE_AUTO_CONTROL:
            if (sizeof(dev->hue_auto_val) >= data->length)
                rt_memcpy(&dev->hue_auto_val, data->data, data->length);
            break;
        case UVC_PU_POWER_LINE_FREQUENCY_CONTROL:
            if (sizeof(dev->power_line_frequency_val) >= data->length)
            {
                rt_memcpy(&dev->power_line_frequency_val, data->data, data->length);
                //video_record_set_power_line_frequency(*val);
            }
            break;
        default:
            break;
        }

        break;

    case 6:
        switch (cs)
        {
        case 1:
            if (sizeof(dev->ext1) >= data->length)
            {
//              const char conf[] = "web_camera_rgb,mass_storage";
                rt_memset(dev->ext1, 0, sizeof(dev->ext1));
                rt_memcpy(dev->ext1, data->data, data->length);
                rt_memcpy(&dev->ext1_value, dev->ext1, sizeof(dev->ext1_value));
                rt_kprintf("INF: extern ctrl(1) set cur: 0x%02x\n", dev->ext1[0]);
                if (dev->ext1[0] == 0xF8 && dev->ext1[1] == 0xFF && dev->ext1[2] == 0xFF)
                {
                    rt_kprintf("set iq/focus ...\n");
                    // TODO: need to implement?
                }
                else
                {
                    rt_kprintf("INF: extern ctrl(1) set cur: 0x%08x\n", dev->ext1_value);

                    switch (dev->ext1_value)
                    {
                    case 0xFFFFFFFF:
                        rt_kprintf("reboot loader\n");
                        break;
                    case 0xFFFFFFFE:
                        rt_kprintf("reboot\n");
                        break;
                    case 0xFFFFFFFC:
                        rt_kprintf("toggle to msc\n");
                        break;
                    case 0xFFFFFFFB:
                        rt_kprintf("nonsupport for calibration write\n");
                        break;
                    case 0xFFFFFFFA:
                        rt_kprintf("toggle to scan code mode\n");
                        break;
                    case 0xFFFFFFF9:
                        rt_kprintf("toggle to scan face mode\n");
                        break;
                    case 0xFFFFFFF8:
                        rt_kprintf("toggle to fixed focus mode\n");
                        break;
                    case 0xFFFFFFF7:
                        rt_kprintf("toggle to nomal mode\n");
                        break;
                    case 0xFFFFFFF6:
                        rt_kprintf("image flips 180 degrees\n");
                        break;
                    case 0xFFFFFFF5:
                        rt_kprintf("rgb convert gray\n");
                        break;
                    case 0xFFFFFFF4:
                        rt_kprintf("gray convert rgb\n");
                        break;
                    case 0xFFFFFFF3:
                        rt_kprintf("open video streaming\n");
                        break;
                    case 0xFFFFFFF2:
                        rt_kprintf("close video streaming\n");
                        break;
                    case 0xFFFFFFF1:
                        rt_kprintf("close video and reset uvc\n");
                        break;
                    case 0xFFFFFFF0:
                        rt_kprintf("close video, reset uvc and suspend\n");
                        break;
                    case 0xFFFFFFEF:
                        rt_kprintf("toggle to continue output mode\n");
                        break;
                    case 0xFFFFFFEE:
                        rt_kprintf("only speckle output\n");
                        break;
                    case 0xFFFFFFED:
                        rt_kprintf("only IR output\n");
                        break;
                    case 0xFFFFFFEC:
                        rt_kprintf("speckle and IR output by turn\n");
                        break;
                    case 0xFFFFFFEB:
                        rt_kprintf("toggle to adb\n");
                        break;
                    case 0xFFFFFFEA:
                        rt_kprintf("disable isp crop\n");
                        break;
                    case 0xFFFFFFE9:
                        rt_kprintf("enable isp crop\n");
                        break;
                    default:
                        rt_kprintf("nonsupport extern ctrl(1) command: 0x%08x\n", dev->ext1_value);
                        break;
                    }
                }
            }
            break;
#if 0
        case 2:
            if (sizeof(dev->ex_ctrl) >= data->length)
            {
                rt_memcpy(dev->ex_ctrl, data->data, data->length);
                rt_memcpy(&dev->ex_length, &dev->ex_ctrl[1], 2);
                rt_memcpy(&dev->ex_checksum, &dev->ex_ctrl[3], 2);
                dev->ex_index = 0;
                if (dev->ex_ctrl[0] != EXT_QUERY_CMD)
                    dev->ex_result = 0;
                rt_memset(dev->ex_data, 0, sizeof(dev->ex_data));
                switch (dev->ex_ctrl[0])
                {
                case 0xc5:
                    rt_kprintf("%s: video_record_get_flt_parameter ...\n", __func__);
                    // TODO: need to implement?

//                        if (video_record_get_flt_parameter_cb)
//                            video_record_get_flt_parameter_cb(dev->ex_ctrl[5], dev->ex_ctrl[6]);
                    break;
                default:
                    break;
                }
                if (dev->ex_ctrl[0] != EXT_QUERY_CMD /* && uvc_iq_tool_get_data_cb */)
                {
                    rt_kprintf("%s: uvc_iq_tool_get_data ...\n", __func__);
                    // TODO: need to implement?

//                    uvc_iq_tool_get_data_cb(dev->ex_ctrl, dev->ex_data, dev->ex_length);
                    dev->get_checksum = 0;
                    for (int i = 0; i < dev->ex_length; i++)
                        dev->get_checksum += dev->ex_data[i];
                }
            }
            break;

        case 3:
            if (dev->ex_index + data->length < MAX_UVC_REQUEST_DATA_LENGTH)
            {
                rt_memcpy(dev->ex_data + dev->ex_index, data->data, data->length);
                dev->ex_index += data->length;
            }
            else
            {
                rt_kprintf("ex data received error occur!\n");
                dev->ex_result = -1;
            }
            if (/* uvc_iq_tool_set_data_cb && */dev->ex_index == dev->ex_length)
            {
                if (dev->ex_length <= 60)
                {
                    rt_kprintf("%s: uvc_iq_tool_set_data ...\n", __func__);
                    // TODO: need to implement?

//                    uvc_iq_tool_set_data_cb(dev->ex_data, dev->ex_length);
                    dev->ex_result = 1;
                }
                else
                {
                    unsigned short sum = 0;
                    for (int i = 0; i < dev->ex_length; i++)
                        sum += dev->ex_data[i];
                    if (sum == dev->ex_checksum)
                    {
                        rt_kprintf("%s: uvc_iq_tool_set_data ...\n", __func__);
                        // TODO: need to implement?

//                        uvc_iq_tool_set_data_cb(dev->ex_data, dev->ex_length);
                        dev->ex_result = 1;
                    }
                    else
                    {
                        rt_kprintf("ex data checksum error!\n");
                        dev->ex_result = -1;
                    }
                }
            }
            break;
#endif
        case 4:
            if (sizeof(dev->ext4) >= data->length)
            {
                rt_memset(dev->ext4, 0, sizeof(dev->ext4));
                rt_memcpy(dev->ext4, data->data, data->length);
                rt_memcpy(&dev->ext4_value, dev->ext4, sizeof(dev->ext4_value));
                rt_kprintf("INF: extern ctrl(4) set cur: 0x%08x\n", dev->ext4_value);
                switch (dev->ext4_value)
                {
                case 0x00000000:
                    rt_kprintf("get release version\n");
//                    uvc_get_release_version(dev);
                    break;
                case 0x00000001:
                    rt_kprintf("get sn\n");
//                    uvc_get_sn_code(dev);
                    break;
                case 0x00000002:
                    rt_kprintf("get the valid range for depth\n");
//                    uvc_get_calib_pos(dev);
                    break;
                case 0x00000003:
                    rt_kprintf("get pcba sn\n");
//                    rt_memset(dev->ext4, 0, sizeof(dev->ext4));
//                    vendor_storage_read(sizeof(dev->ext4), dev->ext4, VENDOR_SN_ID);
                    break;
                case 0x00000004:
                    rt_kprintf("get pcba result\n");
//                    rt_memset(dev->ext4, 0, sizeof(dev->ext4));
//                    vendor_storage_read(sizeof(dev->ext4), dev->ext4, VENDOR_PCBA_RESULT_ID);
                    break;
                default:
                    rt_kprintf("WAR: nonsupport extern ctrl(4) command: 0x%08x\n", dev->ext4_value);
                    break;
                }
            }
            break;

        default:
            break;
        }
        break;

    default:
        break;
    }

    return 0;
}

static int
uvc_event_handle_streamon(struct uvc_event_device *dev)
{
    return uvc_video_enable(class_to_uvc(dev), 1);
}

static int
uvc_events_process_data(struct uvc_event_device *dev, struct uvc_request_data *data)
{
    struct uvc_device *uvc = class_to_uvc(dev);
    struct uvc_streaming_control *target;
    struct uvc_streaming_control *ctrl;
    const struct uvc_format_info *format;
    const struct uvc_frame_info *frame;
    const unsigned int *interval;
    unsigned int iformat, iframe;
    unsigned int nframes;
    int ret = 0;

    switch (dev->control)
    {
    case UVC_VS_PROBE_CONTROL:
        RT_DEBUG_LOG(UVC_SETUP_DEBUG, ("setting probe control, length = %d\n", data->length));
        target = &dev->probe;
        break;

    case UVC_VS_COMMIT_CONTROL:
        RT_DEBUG_LOG(UVC_SETUP_DEBUG, ("setting commit control, length = %d\n", data->length));
        target = &dev->commit;
        break;

    default:
        RT_DEBUG_LOG(UVC_SETUP_DEBUG, ("process control data, length = %d\n", data->length));
        ret = uvc_events_process_control_data(dev,
                                              dev->cs,
                                              dev->entity_id, data);
        if (ret < 0)
            goto err;

        return 0;
    }

    ctrl = (struct uvc_streaming_control *)&data->data;
    iformat = clamp((unsigned int)ctrl->bFormatIndex, 1U,
                    (unsigned int)ARRAY_SIZE(uvc_formats));
    format = &uvc_formats[iformat - 1];

    nframes = 0;
    while (format->frames[nframes].width != 0)
        ++nframes;

    iframe = clamp((unsigned int)ctrl->bFrameIndex, 1U, nframes);
    frame = &format->frames[iframe - 1];
    interval = frame->intervals;

    while (interval[0] < ctrl->dwFrameInterval && interval[1])
        ++interval;

    target->bFormatIndex = iformat;
    target->bFrameIndex = iframe;

    switch (format->fcc)
    {
    case V4L2_PIX_FMT_YUYV:
        target->dwMaxVideoFrameSize = frame->width * frame->height * 2;
        break;
    case V4L2_PIX_FMT_MJPEG:
        if (dev->imgsize == 0)
            rt_kprintf("WAR: MJPEG requested and no image loaded.\n");
        target->dwMaxVideoFrameSize = dev->imgsize;
        break;
    }

    target->dwFrameInterval = *interval;
    if (dev->control == UVC_VS_COMMIT_CONTROL)
    {
        if (uvc->video.enabled)
            return 0;

        dev->fcc = format->fcc;
        dev->width = frame->width;
        dev->height = frame->height;

#ifndef RT_USB_DEVICE_UVC_BUF_TEST
        /*
         * As per the new commit command received from the UVC host
         * change the current format selection.
         */
        rt_kprintf("INF: uvc(%d) set format width %d height %d\n",
                   uvc->id, dev->width, dev->height);
        ret = rk_camera_inf_set_width_height(uvc->id, dev->width, dev->height);
        if (ret)
        {
            rt_kprintf("ERR: uvc set format error(%d)\n", ret);
            goto err;
        }
#endif
        ret = uvc_event_handle_streamon(dev);
        if (ret)
        {
            rt_kprintf("ERR: uvc streamon error(%d)\n", ret);
            goto err;
        }
    }

    return 0;

err:
    return ret;
}

static void
uvc_events_process(struct uvc_event_device *dev, uvc_event_t event)
{
    struct uvc_device *uvc = class_to_uvc(dev);
    struct uvc_request_data resp;
    rt_err_t ret;

    rt_memset(&resp, 0, sizeof(resp));
    resp.length = -EL2HLT;

    switch (event->type)
    {
    case UVC_EVENT_CONNECT:
        return;

    case UVC_EVENT_DISCONNECT:
        rt_kprintf("INF: Possible UVC shutdown requested from Host\n");
        uvc_video_enable(uvc, 0);
        return;

    case UVC_EVENT_SETUP:
        uvc_events_process_setup(dev, &event->req, &resp);
        break;

    case UVC_EVENT_DATA:
        ret = uvc_events_process_data(dev, &event->content);
        if (ret < 0)
            break;
        return;

    case UVC_EVENT_EXCEPTION:
        uvc_video_enable(uvc, 0);
        uvc_video_enable(uvc, 1);
        return;

    default:
        rt_kprintf("WAR: unknown uvc event type %d\n", event->type);
        break;
    }

    /* Send uvc response */
    uvc_write_ep0(uvc, &event->req, &resp);
}

static void
uvc_event_dev_init(struct uvc_event_device *udev)
{
    /* Set parameters as default */
    udev->width = 640;
    udev->height = 480;
    udev->imgsize = udev->width * udev->height * 1.5;
    udev->fcc = V4L2_PIX_FMT_MJPEG;
    udev->hue_val = PU_HUE_DEFAULT_VAL;

    uvc_fill_streaming_control(udev, &udev->probe, 0, 0);
    uvc_fill_streaming_control(udev, &udev->commit, 0, 0);
}

static struct rt_messagequeue uvc_mq[UVC_ID_MAX];

static void uvc_thread_entry(void *parameter)
{
    struct uvc_event_device *dev = (struct uvc_event_device *)parameter;
    int id = dev->video_id;

    uvc_event_dev_init(dev);

    while (1)
    {
        struct uvc_event event;

        /* receive message */
        if (rt_mq_recv(&uvc_mq[id], &event, sizeof(struct uvc_event),
                       RT_WAITING_FOREVER) != RT_EOK)
            continue;

        RT_DEBUG_LOG(RT_DEBUG_USB, ("uvc rx event type %d\n", event.type));

//      rt_kprintf("%s: %02x %02x %02x %02x\n", __func__, event.content.data[0], event.content.data[1], event.content.data[2], event.content.data[3]);
//      rt_kprintf("%s: size=%d\n", __func__, event.content.length);

        uvc_events_process(dev, &event);
    }
}

rt_err_t uvc_event_signal(struct uvc_event *event, int id)
{
    RT_ASSERT(event != RT_NULL);

    /* send message to usb message queue */
//    RT_DEBUG_LOG(RT_DEBUG_USB, ("uvc tx event: id %d type %d\n", id, event->type));
//    rt_kprintf("mq->event_size=%d, size=%d\n", uvc_mq[id].event_size, sizeof(struct uvc_event));
    return rt_mq_send(&uvc_mq[id], (void *)event, sizeof(struct uvc_event));
}

ALIGN(RT_ALIGN_SIZE)
static rt_uint8_t uvc_thread_stack[UVC_ID_MAX][4096];
static struct rt_thread uvc_thread[UVC_ID_MAX];

#define UVC_MQ_MSG_SZ  128
#define UVC_MQ_MAX_MSG 4

static rt_uint8_t
uvc_mq_pool[UVC_ID_MAX][(UVC_MQ_MSG_SZ + sizeof(void *)) * UVC_MQ_MAX_MSG];

rt_err_t uvc_event_init(struct uvc_event_device *dev)
{
    char name[16];
    int id = dev->video_id;

    RT_ASSERT(id >= UVC_ID_DEPTH && id < UVC_ID_MAX);

    if (id == UVC_ID_IR)
        rt_snprintf(name, 16, "uvc_%s", "ir");
    else if (id == UVC_ID_RGB)
        rt_snprintf(name, 16, "uvc_%s", "rgb");
    else
        rt_snprintf(name, 16, "uvc_%s", "depth");

    /* create an uvc message queue */
    rt_mq_init(&uvc_mq[id],
               name,
               uvc_mq_pool[id], UVC_MQ_MSG_SZ,
               sizeof(uvc_mq_pool[0]),
               RT_IPC_FLAG_FIFO);

    /* init usb event thread */
    rt_thread_init(&uvc_thread[id],
                   name,
                   uvc_thread_entry, (void *)dev,
                   uvc_thread_stack[id], 4096,
                   (RT_USBD_THREAD_PRIO - 1), 20);
    /* rt_thread_init should always be OK, so start the thread without further
     * checking. */
    return rt_thread_startup(&uvc_thread[id]);
}
