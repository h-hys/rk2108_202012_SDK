#include <rtthread.h>

#include <littlevgl2rtt.h>
#include <lvgl/lvgl.h>

#include "./lv_clock_main.h"

/*********************
 *  LV_CLOCK_DEMO0
 *********************/
lv_obj_t *lv_clock_demo0_init(lv_coord_t x, lv_coord_t y, lv_event_cb_t cb)
{
    /*Create a clock*/
    lv_obj_t *clock = lv_clock_create(lv_scr_act(), NULL);
    lv_obj_set_size(clock, LV_CLOCK_DEMO_WIDTH, LV_CLOCK_DEMO_HEIGHT);
    lv_obj_set_pos(clock, x, y);
    lv_obj_set_event_cb(clock, cb);

    /*Init the pannel style*/
    lv_clock_panel_style_t pannel;
    rt_memset(&pannel, 0, sizeof(lv_clock_panel_style_t));

    pannel.label_count = LABEL_CONT_TWELVE;
    lv_clock_set_panel_style(clock, &pannel);

    /*Init the needle style*/
    lv_clock_needle_style_t needle_style[NEEDLE_MAX_CONT];
    rt_memset(needle_style, 0, sizeof(lv_clock_needle_style_t) * NEEDLE_MAX_CONT);

    needle_style[NEEDLE_HOUR].color = LV_COLOR_BLUE;
    needle_style[NEEDLE_HOUR].width = 6;
    needle_style[NEEDLE_HOUR].length = 90;
    needle_style[NEEDLE_HOUR].centre = 8;
    needle_style[NEEDLE_HOUR].hollow_color = LV_COLOR_WHITE;
    needle_style[NEEDLE_HOUR].hollow_width = 3;
    needle_style[NEEDLE_HOUR].hollow_lpad = 20;
    needle_style[NEEDLE_HOUR].hollow_rpad = 10;

    needle_style[NEEDLE_MIN].color = LV_COLOR_ORANGE;
    needle_style[NEEDLE_MIN].width = 4;
    needle_style[NEEDLE_MIN].length = 95;
    needle_style[NEEDLE_MIN].centre = 8;
    needle_style[NEEDLE_MIN].hollow_color = LV_COLOR_WHITE;
    needle_style[NEEDLE_MIN].hollow_width = 2;
    needle_style[NEEDLE_MIN].hollow_lpad = 20;
    needle_style[NEEDLE_MIN].hollow_rpad = 10;

    needle_style[NEEDLE_SEC].color = LV_COLOR_RED;
    needle_style[NEEDLE_SEC].width = 2;
    needle_style[NEEDLE_SEC].length = 100;
    needle_style[NEEDLE_SEC].centre = 8;
    lv_clock_set_needle_style(clock, needle_style);

    /*Init the date of clock*/
    lv_clock_set_date(clock, &lv_clock.date);

    /*Init the date of time*/
    lv_clock_set_time(clock, &lv_clock.time);

    return clock;
}
