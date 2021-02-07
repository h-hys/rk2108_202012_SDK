/**
  * Copyright (c) 2019 Rockchip Electronic Co.,Ltd
  *
  * SPDX-License-Identifier: Apache-2.0
  ******************************************************************************
  * @file    camera.h
  * @version V0.0.1
  * @brief   camera device abstract for rk2108
  *
  * Change Logs:
  * Date           Author          Notes
  * 2019-03-29     ISP Team      first implementation
  *
  ******************************************************************************
  */
#ifndef __CAMERA_H__
#define __CAMERA_H__

#if defined(__RT_THREAD__)
#include "adapter.h"
#include "drv_clock.h"
#include "camera_mediabus.h"

#elif defined(__RK_OS__)
#include "driver/adapter.h"
#include "driver/camera_mediabus.h"
#endif

#if defined(RT_USING_CAMERA) || defined(CONFIG_DRIVER_CAMERA)
#define CAMERA_MODULE_COMPILED
#else
#undef CAMERA_MODULE_COMPILED
#endif

#ifdef CAMERA_MODULE_COMPILED

/* Exported macro ------------------------------------------------------------*/
#define RK_CAMERA_DEVICE_NAME_SIZE                  (12)
#define RK_CAMERA_I2C_NAME_SIZE                     (12)

#define RK_DEVICE_CTRL_DEVICE_INIT                  (0)
#define RK_DEVICE_CTRL_CAMERA_STREAM_ON             (1)
#define RK_DEVICE_CTRL_CAMERA_STREAM_OFF            (2)
#define RK_DEVICE_CTRL_CAMERA_GET_FORMAT            (3)

/* Exported types ------------------------------------------------------------*/
struct rk_camera_info
{
    struct rk_camera_mbus_framefmt mbus_fmt;
    struct rk_camera_mbus_config mbus_config;
};

struct rk_camera_ops;
struct rk_camera_device
{
    rk_device parent;
    char name[RK_CAMERA_DEVICE_NAME_SIZE];
    struct rk_camera_info info;
    const struct rk_camera_ops *ops;
    char i2c_name[RK_CAMERA_I2C_NAME_SIZE];
    rk_i2c_bus_device *i2c_bus;
#if defined(__RK_OS__)
    uint8_t class_id;
    uint8_t object_id;
#endif
};

struct rk_camera_ops
{
    ret_err_t (*init)(struct rk_camera_device *dev);
    ret_err_t (*open)(struct rk_camera_device *dev, uint16_t oflag);
    ret_err_t (*close)(struct rk_camera_device *dev);
    ret_err_t (*control)(struct rk_camera_device *dev, dt_cmd_t cmd, void *arg);
    ret_err_t (*rx_indicate)(struct rk_camera_device *dev, ret_size_t size);
};

#if defined(__RK_OS__)
HDC rk_rkos_camera_create(uint8_t dev_id, void *arg);
ret_err_t rk_rkos_camera_delete(uint8_t dev_id, void *arg);
#endif

ret_err_t rk_camera_register(struct rk_camera_device *camera,
                             const char *name,
                             void *data);

#endif

#endif
