#include <rtthread.h>

#include <littlevgl2rtt.h>
#include <lvgl/lvgl.h>

#include "./lv_clock_main.h"

/*********************
 *  LV_CLOCK_DEMO2
 *********************/

static lv_img_dsc_t lv_clock2_panel_bkg;
static lv_img_dsc_t lv_clock2_panel_centre;
static lv_img_dsc_t lv_clock2_needle_hour;
static lv_img_dsc_t lv_clock2_needle_min;
static lv_img_dsc_t lv_clock2_needle_sec;

lv_obj_t *lv_clock_demo2_init(lv_coord_t x, lv_coord_t y, lv_event_cb_t cb)
{
    /*Create a clock*/
    lv_obj_t *clock = lv_clock_create(lv_scr_act(), NULL);
    lv_obj_set_size(clock, LV_CLOCK_DEMO_WIDTH, LV_CLOCK_DEMO_HEIGHT);
    lv_obj_set_pos(clock, x, y);
    lv_obj_set_event_cb(clock, cb);

    /*Init the pannel style*/
    lv_clock_panel_style_t panel_style;
    rt_memset(&panel_style, 0, sizeof(lv_clock_panel_style_t));

    panel_style.label_count = LABEL_CONT_NULL;
    panel_style.bk_img      = &lv_clock2_panel_bkg;
    panel_style.centre_img  = &lv_clock2_panel_centre;
    lv_clock_set_panel_style(clock, &panel_style);
#if (LV_COLOR_DEPTH == 8)
    lv_clock_img_file_load(&lv_clock2_panel_bkg, "L:/color8/demo2/clock_bkg.bin");
    lv_clock_img_file_load(&lv_clock2_panel_centre, "L:/color8/demo2/clock_centre.bin");
#elif (LV_COLOR_DEPTH == 16)
    lv_clock_img_file_load(&lv_clock2_panel_bkg, "L:/color16/demo2/clock_bkg.bin");
    lv_clock_img_file_load(&lv_clock2_panel_centre, "L:/color16/demo2/clock_centre.bin");
#endif

    /*Init the needle style*/
    lv_clock_needle_style_t needle_style[NEEDLE_MAX_CONT];
    rt_memset(needle_style, 0, sizeof(lv_clock_needle_style_t) * NEEDLE_MAX_CONT);

    needle_style[NEEDLE_HOUR].img = &lv_clock2_needle_hour;
    needle_style[NEEDLE_HOUR].centre = 12;
    needle_style[NEEDLE_MIN].img  = &lv_clock2_needle_min;
    needle_style[NEEDLE_MIN].centre = 12;
    needle_style[NEEDLE_SEC].img  = &lv_clock2_needle_sec;
    lv_clock_set_needle_style(clock, needle_style);
    needle_style[NEEDLE_SEC].centre = 12;
#if (LV_COLOR_DEPTH == 8)
    lv_clock_img_file_load(&lv_clock2_needle_hour, "L:/color8/demo2/clock_hour.bin");
    lv_clock_img_file_load(&lv_clock2_needle_min, "L:/color8/demo2/clock_min.bin");
    lv_clock_img_file_load(&lv_clock2_needle_sec, "L:/color8/demo2/clock_sec.bin");
#elif (LV_COLOR_DEPTH == 16)
    lv_clock_img_file_load(&lv_clock2_needle_hour, "L:/color16/demo2/clock_hour.bin");
    lv_clock_img_file_load(&lv_clock2_needle_min, "L:/color16/demo2/clock_min.bin");
    lv_clock_img_file_load(&lv_clock2_needle_sec, "L:/color16/demo2/clock_sec.bin");
#endif

    /*Init the date of clock*/
    lv_clock_set_date(clock, &lv_clock.date);

    /*Init the date of time*/
    lv_clock_set_time(clock, &lv_clock.time);

    return clock;
}
