#include <rtthread.h>
#include "display.h"

#include <littlevgl2rtt.h>
#include <lvgl/lvgl.h>
#include <dfs_posix.h>

#include "./lv_clock_main.h"

/*********************
 *  LV_CLOCK_SETTING_DATE
 *********************/

struct lv_clock_setting_date_t
{
    lv_style_t main_style;
    lv_clock_date_t date;

    lv_obj_t   *obj_main;
    lv_obj_t   *obj_year;
    lv_obj_t   *obj_month;
    lv_obj_t   *obj_day;
    lv_obj_t   *obj_btn;
    lv_obj_t   *obj_btn_text;
};
static struct lv_clock_setting_date_t mdata;
static const char *year_str =   "2010\n2011\n2012\n2013\n2014\n2015\n2016\n2017\n2018\n2019\n"
                                "2020\n2021\n2022\n2023\n2024\n2025\n2026\n2027\n2028\n2029\n2030";
static const char *month_str =  "01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n12";
static const char *day_str =    "01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n"
                                "11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n"
                                "21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31";

static void event_handler(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        char buf[8];
        lv_roller_get_selected_str(mdata.obj_year, buf, sizeof(buf));
        mdata.date.year = lv_clock_str2num(buf, 4);

        lv_roller_get_selected_str(mdata.obj_month, buf, sizeof(buf));
        mdata.date.month = lv_clock_str2num(buf, 2);

        lv_roller_get_selected_str(mdata.obj_day, buf, sizeof(buf));
        mdata.date.day = lv_clock_str2num(buf, 2);

        mdata.date.weekdays = get_day_of_week(mdata.date.year, mdata.date.month, mdata.date.day);

        rt_memcpy(&lv_clock.date, &mdata.date, sizeof(lv_clock_date_t));

        lv_setting_date_deinit();
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

lv_obj_t *lv_setting_date_init(void)
{
    lv_setting_styles_init();

    rt_memcpy(&mdata.date, &lv_clock.date, sizeof(lv_clock_date_t));

    /* Background */
    mdata.obj_main = lv_obj_create(lv_scr_act(), NULL);
    lv_obj_add_style(mdata.obj_main, LV_STATE_DEFAULT, &mdata.main_style);
    lv_obj_set_size(mdata.obj_main, LV_CLOCK_DEMO_WIDTH, LV_CLOCK_DEMO_HEIGHT);
    lv_obj_set_pos(mdata.obj_main, 0, 0);

    mdata.obj_year = lv_roller_create(mdata.obj_main, NULL);
    lv_roller_set_options(mdata.obj_year, year_str, LV_ROLLER_MODE_INIFINITE);
    lv_roller_set_visible_row_count(mdata.obj_year, 2);
    lv_obj_align(mdata.obj_year, mdata.obj_main, LV_ALIGN_CENTER, -60, -10);
    lv_roller_set_selected(mdata.obj_year, mdata.date.year - lv_clock_str2num(year_str, 4), LV_ANIM_OFF);

    mdata.obj_month = lv_roller_create(mdata.obj_main, NULL);
    lv_roller_set_options(mdata.obj_month, month_str, LV_ROLLER_MODE_INIFINITE);
    lv_roller_set_visible_row_count(mdata.obj_month, 2);
    lv_obj_align(mdata.obj_month, mdata.obj_main, LV_ALIGN_CENTER, 17, -10);
    lv_roller_set_selected(mdata.obj_month, mdata.date.month - lv_clock_str2num(month_str, 2), LV_ANIM_OFF);

    mdata.obj_day = lv_roller_create(mdata.obj_main, NULL);
    lv_roller_set_options(mdata.obj_day, day_str, LV_ROLLER_MODE_INIFINITE);
    lv_roller_set_visible_row_count(mdata.obj_day, 2);
    lv_obj_align(mdata.obj_day, mdata.obj_main, LV_ALIGN_CENTER, 80, -10);
    lv_roller_set_selected(mdata.obj_day, mdata.date.day - lv_clock_str2num(day_str, 2), LV_ANIM_OFF);

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

void lv_setting_date_deinit(void)
{
    lv_obj_clean_style_list(mdata.obj_main, LV_STATE_DEFAULT);
    lv_obj_del(mdata.obj_main);
}
