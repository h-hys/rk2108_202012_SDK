/**
  * Copyright (c) 2019 Fuzhou Rockchip Electronics Co., Ltd
  *
  * SPDX-License-Identifier: Apache-2.0
  */

#ifndef __LV_CLOCK_SETTING_MAIN__
#define __LV_CLOCK_SETTING_MAIN__
#include <rtthread.h>

lv_obj_t *lv_setting_main_init(lv_coord_t x, lv_coord_t y);
void lv_setting_main_deinit(void);
void lv_setting_main_date_update(void);

#endif /*__LV_CLOCK_SETTING_MAIN__*/
