#include <rtthread.h>

#include <littlevgl2rtt.h>
#include <lvgl/lvgl.h>
#include <dfs_posix.h>

#include "./lv_clock_main.h"

/*********************
 *  LV_CLOCK_SETTING_MENU
 *********************/

struct lv_clock_setting_menu_t
{
    lv_style_t main_style;
    lv_style_t list_btn_style;

    lv_obj_t   *obj_main;
    lv_obj_t   *list_btn[5];
};
static struct lv_clock_setting_menu_t mdata;

static void time_handler(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_setting_time_init();
    }
}

static void date_cb(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_setting_date_init();
    }
}

static void light_cb(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_setting_light_init();
    }
}

static void volume_cb(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_setting_volume_init();
    }
}

static void version_cb(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_setting_version_init();
    }
}

static void help_cb(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_setting_help_init();
    }
}

static void exit_cb(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_setting_menu_deinit();
        lv_setting_main_date_update();
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
    lv_style_init(&mdata.list_btn_style);
    lv_style_set_bg_opa(&mdata.list_btn_style, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_bg_color(&mdata.list_btn_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_text_color(&mdata.list_btn_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_text_font(&mdata.list_btn_style, LV_STATE_DEFAULT, &lv_font_montserrat_36);
    lv_style_set_pad_left(&mdata.list_btn_style, LV_STATE_DEFAULT, 80);
    lv_style_set_pad_right(&mdata.list_btn_style, LV_STATE_DEFAULT, 20);
}

lv_obj_t *lv_setting_menu_init(void)
{
    lv_setting_styles_init();

    /*Create a list*/
    mdata.obj_main = lv_list_create(lv_scr_act(), NULL);
    lv_obj_add_style(mdata.obj_main, LV_STATE_DEFAULT, &mdata.main_style);
    lv_obj_set_size(mdata.obj_main, LV_CLOCK_DEMO_WIDTH, LV_CLOCK_DEMO_HEIGHT);
    lv_obj_set_pos(mdata.obj_main, 0, 0);
    lv_list_set_scrollbar_mode(mdata.obj_main, LV_SCROLLBAR_MODE_OFF);

    /*Add buttons to the list*/
    mdata.list_btn[0] = lv_list_add_btn(mdata.obj_main, LV_SYMBOL_SETTINGS, "Time");
    lv_obj_add_style(mdata.list_btn[0], LV_STATE_DEFAULT, &mdata.list_btn_style);
    lv_obj_set_event_cb(mdata.list_btn[0], time_handler);

    mdata.list_btn[1] = lv_list_add_btn(mdata.obj_main, LV_SYMBOL_SETTINGS, "Date");
    lv_obj_add_style(mdata.list_btn[1], LV_STATE_DEFAULT, &mdata.list_btn_style);
    lv_obj_set_event_cb(mdata.list_btn[1], date_cb);

    mdata.list_btn[2] = lv_list_add_btn(mdata.obj_main, LV_SYMBOL_SETTINGS, "Light");
    lv_obj_add_style(mdata.list_btn[2], LV_STATE_DEFAULT, &mdata.list_btn_style);
    lv_obj_set_event_cb(mdata.list_btn[2], light_cb);

    mdata.list_btn[3] = lv_list_add_btn(mdata.obj_main, LV_SYMBOL_SETTINGS, "Volume");
    lv_obj_add_style(mdata.list_btn[3], LV_STATE_DEFAULT, &mdata.list_btn_style);
    lv_obj_set_event_cb(mdata.list_btn[3], volume_cb);

    mdata.list_btn[3] = lv_list_add_btn(mdata.obj_main, LV_SYMBOL_SETTINGS, "Version");
    lv_obj_add_style(mdata.list_btn[3], LV_STATE_DEFAULT, &mdata.list_btn_style);
    lv_obj_set_event_cb(mdata.list_btn[3], version_cb);

    mdata.list_btn[3] = lv_list_add_btn(mdata.obj_main, LV_SYMBOL_SETTINGS, "Help");
    lv_obj_add_style(mdata.list_btn[3], LV_STATE_DEFAULT, &mdata.list_btn_style);
    lv_obj_set_event_cb(mdata.list_btn[3], help_cb);

    mdata.list_btn[4] = lv_list_add_btn(mdata.obj_main, LV_SYMBOL_HOME, "Exit");
    lv_obj_add_style(mdata.list_btn[4], LV_STATE_DEFAULT, &mdata.list_btn_style);
    lv_obj_set_event_cb(mdata.list_btn[4], exit_cb);


    return mdata.obj_main;
}

void lv_setting_menu_deinit(void)
{
    for (uint8_t i = 0; i < 5; i++)
    {
        lv_obj_clean_style_list(mdata.list_btn[i], LV_STATE_DEFAULT);
    }
    lv_obj_clean_style_list(mdata.obj_main, LV_STATE_DEFAULT);
    lv_obj_del(mdata.obj_main);
}
