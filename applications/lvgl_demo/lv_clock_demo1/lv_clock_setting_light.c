#include <rtthread.h>
#include "display.h"

#include <littlevgl2rtt.h>
#include <lvgl/lvgl.h>
#include <dfs_posix.h>

#include "./lv_clock_main.h"

/*********************
 *  LV_CLOCK_SETTING_LIGHT
 *********************/

struct lv_clock_setting_light_t
{
    lv_style_t main_style;
    lv_style_t slider_label_style;

    lv_obj_t   *obj_main;
    lv_obj_t   *slider;
    lv_obj_t   *slider_label;
    lv_obj_t   *obj_btn;
    lv_obj_t   *obj_btn_text;
};
static struct lv_clock_setting_light_t mdata;

static void slider_event_cb(lv_obj_t *slider, lv_event_t event)
{
    if (event == LV_EVENT_VALUE_CHANGED)
    {
        static char buf[5]; /* max 3 bytes for number plus 1 null terminating byte */
        snprintf(buf, 5, "%u", lv_slider_get_value(slider));
        lv_label_set_text(mdata.slider_label, buf);
        rt_display_backlight_set(lv_slider_get_value(slider));
    }
}

static void event_handler(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_setting_light_deinit();
    }
}

static void lv_setting_styles_init(void)
{
    /* background styles init */
    lv_style_init(&mdata.main_style);
    lv_style_set_radius(&mdata.main_style, LV_STATE_DEFAULT, LV_RADIUS_CIRCLE);
    lv_style_set_bg_color(&mdata.main_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_border_color(&mdata.main_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_border_color(&mdata.main_style, LV_STATE_FOCUSED, LV_COLOR_WHITE);
    lv_style_set_border_width(&mdata.main_style, LV_STATE_DEFAULT, 2);

    /* date label styles init */
    lv_style_init(&mdata.slider_label_style);
    lv_style_set_text_font(&mdata.slider_label_style, LV_STATE_DEFAULT, &lv_font_montserrat_36);
}

lv_obj_t *lv_setting_light_init(void)
{
    lv_setting_styles_init();

    /* Background */
    mdata.obj_main = lv_obj_create(lv_scr_act(), NULL);
    lv_obj_add_style(mdata.obj_main, LV_STATE_DEFAULT, &mdata.main_style);
    lv_obj_set_size(mdata.obj_main, LV_CLOCK_DEMO_WIDTH, LV_CLOCK_DEMO_HEIGHT);
    lv_obj_set_pos(mdata.obj_main, 0, 0);

    mdata.slider = lv_slider_create(mdata.obj_main, NULL);
    lv_obj_set_size(mdata.slider, 240, 40);
    lv_obj_align(mdata.slider, mdata.obj_main, LV_ALIGN_CENTER, 0, 0);
    lv_slider_set_range(mdata.slider, 0, 100);
    lv_slider_set_value(mdata.slider, rt_display_backlight_get(), LV_ANIM_OFF);
    lv_obj_set_event_cb(mdata.slider, slider_event_cb);

    /* Create a label top the slider */
    char buf[4];
    mdata.slider_label = lv_label_create(mdata.obj_main, NULL);
    lv_obj_add_style(mdata.slider_label, LV_STATE_DEFAULT, &mdata.slider_label_style);
    snprintf(buf, 4, "%u", lv_slider_get_value(mdata.slider));
    lv_label_set_text(mdata.slider_label, buf);
    lv_obj_set_auto_realign(mdata.slider_label, true);
    lv_obj_align(mdata.slider_label, mdata.slider, LV_ALIGN_OUT_TOP_MID, 0, -30);

    /*Create a button */
    mdata.obj_btn = lv_btn_create(mdata.obj_main, NULL);
    lv_obj_set_size(mdata.obj_btn, 120, 60);
    lv_obj_align(mdata.obj_btn, mdata.obj_main, LV_ALIGN_CENTER, 0, 100);
    lv_obj_set_event_cb(mdata.obj_btn, event_handler);

    mdata.obj_btn_text = lv_label_create(mdata.obj_btn, NULL);
    lv_label_set_text(mdata.obj_btn_text, "OK");

    return mdata.obj_main;
}

void lv_setting_light_deinit(void)
{
    lv_obj_clean_style_list(mdata.slider_label, LV_STATE_DEFAULT);
    lv_obj_clean_style_list(mdata.obj_main, LV_STATE_DEFAULT);
    lv_obj_del(mdata.obj_main);
}
