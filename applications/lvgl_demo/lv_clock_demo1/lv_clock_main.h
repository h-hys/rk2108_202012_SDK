/**
  * Copyright (c) 2019 Fuzhou Rockchip Electronics Co., Ltd
  *
  * SPDX-License-Identifier: Apache-2.0
  */

#ifndef __LV_CLOCK_MAIN__
#define __LV_CLOCK_MAIN__
#include <rtthread.h>

/*********************
 *      DEFINES
 *********************/
#define LV_CLOCK_DEMO_WIDTH     320
#define LV_CLOCK_DEMO_HEIGHT    320

#undef  MIN
#define MIN(X, Y)           ((X)<(Y)?(X):(Y))
#undef  MAX
#define MAX(X, Y)           ((X)>(Y)?(X):(Y))
#undef  ABS
#define ABS(X)              (((X) < 0) ? (-(X)) : (X))

/**********************
 *      TYPEDEFS
 **********************/

/*Lv clock move dir*/
enum
{
    LV_CLOCK_MOVE_NULL = 0,
    LV_CLOCK_MOVE_UP,
    LV_CLOCK_MOVE_DOWN,
    LV_CLOCK_MOVE_UPDOWN,
    LV_CLOCK_MOVE_LEFT,
    LV_CLOCK_MOVE_RIGHT,
    LV_CLOCK_MOVE_LEFTRGHT,
};

struct lv_clock_demo_t
{
    lv_clock_date_t date;
    lv_clock_time_t time;
};

/**********************
 * GLOBAL PROTOTYPES
 **********************/

extern const char *week_days[];

extern const uint8_t month_days[];

extern struct lv_clock_demo_t lv_clock;

void lv_clock_img_file_load(lv_img_dsc_t *img_dsc, const char *file);

void lv_clock_img_file_unload(lv_img_dsc_t *img_dsc);

uint32_t lv_clock_str2num(const char *str, uint8_t len);

uint8_t get_day_of_week(uint16_t year, uint8_t month, uint8_t day);

/**********************
 * SUB INCLUDE
 **********************/
#include "lv_clock_demo0.h"
#include "lv_clock_demo1.h"
#include "lv_clock_demo2.h"
#include "lv_clock_demo3.h"
#include "lv_clock_msg.h"
#include "lv_clock_setting_main.h"
#include "lv_clock_setting_menu.h"
#include "lv_clock_setting_time.h"
#include "lv_clock_setting_date.h"
#include "lv_clock_setting_light.h"
#include "lv_clock_setting_volume.h"
#include "lv_clock_setting_version.h"
#include "lv_clock_setting_help.h"

#endif /*__LV_CLOCK_MAIN__*/
