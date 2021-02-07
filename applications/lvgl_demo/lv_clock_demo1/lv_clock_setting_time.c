#include <rtthread.h>
#include "display.h"

#include <littlevgl2rtt.h>
#include <lvgl/lvgl.h>
#include <dfs_posix.h>

#include "./lv_clock_main.h"

/*********************
 *  LV_CLOCK_SETTING_TIME
 *********************/

struct lv_clock_setting_time_t
{
    lv_style_t main_style;
    lv_clock_time_t time;

    lv_obj_t   *obj_main;
    lv_obj_t   *obj_hour;
    lv_obj_t   *obj_min;
    lv_obj_t   *obj_cur;
    lv_obj_t   *obj_btn;
    lv_obj_t   *obj_btn_text;
};
static struct lv_clock_setting_time_t mdata;

static const char *hour_str = "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n"
                              "10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n"
                              "20\n21\n22\n23";
static const char *min_str =  "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n"
                              "10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n"
                              "20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n"
                              "30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n"
                              "40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n"
                              "50\n51\n52\n53\n54\n55\n56\n57\n58\n59";

static void event_handler(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        char buf[8];
        lv_roller_get_selected_str(mdata.obj_hour, buf, sizeof(buf));
        mdata.time.hour = lv_clock_str2num(buf, 2);

        lv_roller_get_selected_str(mdata.obj_min, buf, sizeof(buf));
        mdata.time.min = lv_clock_str2num(buf, 2);

        rt_memcpy(&lv_clock.time, &mdata.time, sizeof(lv_clock_time_t));

        lv_setting_time_deinit();
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
}

lv_obj_t *lv_setting_time_init(void)
{
    lv_setting_styles_init();

    rt_memcpy(&mdata.time, &lv_clock.time, sizeof(lv_clock_time_t));

    /* Background */
    mdata.obj_main = lv_obj_create(lv_scr_act(), NULL);
    lv_obj_add_style(mdata.obj_main, LV_STATE_DEFAULT, &mdata.main_style);
    lv_obj_set_size(mdata.obj_main, LV_CLOCK_DEMO_WIDTH, LV_CLOCK_DEMO_HEIGHT);
    lv_obj_set_pos(mdata.obj_main, 0, 0);

    mdata.obj_hour = lv_roller_create(mdata.obj_main, NULL);
    lv_roller_set_options(mdata.obj_hour, hour_str, LV_ROLLER_MODE_INIFINITE);
    lv_roller_set_visible_row_count(mdata.obj_hour, 2);
    lv_obj_align(mdata.obj_hour, mdata.obj_main, LV_ALIGN_CENTER, -50, -10);
    lv_roller_set_selected(mdata.obj_hour, mdata.time.hour - lv_clock_str2num(hour_str, 2), LV_ANIM_OFF);

    mdata.obj_min = lv_roller_create(mdata.obj_main, NULL);
    lv_roller_set_options(mdata.obj_min, min_str, LV_ROLLER_MODE_INIFINITE);
    lv_roller_set_visible_row_count(mdata.obj_min, 2);
    lv_obj_align(mdata.obj_min, mdata.obj_main, LV_ALIGN_CENTER, 50, -10);
    lv_roller_set_selected(mdata.obj_min, mdata.time.min - lv_clock_str2num(min_str, 2), LV_ANIM_OFF);

    /*Create a button */
    mdata.obj_btn = lv_btn_create(mdata.obj_main, NULL);
    lv_obj_set_size(mdata.obj_btn, 120, 60);
    lv_obj_align(mdata.obj_btn, mdata.obj_main, LV_ALIGN_CENTER, 0, 100);
    lv_obj_set_event_cb(mdata.obj_btn, event_handler);

    mdata.obj_btn_text = lv_label_create(mdata.obj_btn, NULL);
    lv_label_set_text(mdata.obj_btn_text, "OK");

    return mdata.obj_main;
    return mdata.obj_main;
}

void lv_setting_time_deinit(void)
{
    lv_obj_clean_style_list(mdata.obj_main, LV_STATE_DEFAULT);
    lv_obj_del(mdata.obj_main);
}
