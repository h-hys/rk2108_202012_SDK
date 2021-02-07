#include <rtthread.h>

#include <littlevgl2rtt.h>
#include <lvgl/lvgl.h>
#include <dfs_posix.h>

#include "./lv_clock_main.h"

/*********************
 *  LV_CLOCK_MSG
 *********************/

struct lv_clock_setting_main_t
{
    lv_style_t main_style;
    lv_style_t page_style;

    lv_obj_t   *obj_main;
    lv_obj_t   *obj_page;
    lv_obj_t   *obj_page_text;
    lv_obj_t   *obj_btn;
    lv_obj_t   *obj_btn_text;
};
static struct lv_clock_setting_main_t mdata;

static void lv_msg_styles_init(void)
{
    /* background styles init */
    lv_style_init(&mdata.main_style);
    lv_style_set_radius(&mdata.main_style, LV_STATE_DEFAULT, LV_RADIUS_CIRCLE);
    lv_style_set_bg_color(&mdata.main_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_border_color(&mdata.main_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_border_color(&mdata.main_style, LV_STATE_FOCUSED, LV_COLOR_WHITE);
    lv_style_set_border_width(&mdata.main_style, LV_STATE_DEFAULT, 2);

    /* msg box styles init */
    lv_style_init(&mdata.page_style);
    lv_style_set_bg_color(&mdata.page_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_border_color(&mdata.page_style, LV_STATE_DEFAULT, LV_COLOR_GRAY);
    lv_style_set_border_color(&mdata.page_style, LV_STATE_FOCUSED, LV_COLOR_GRAY);
    lv_style_set_border_width(&mdata.page_style, LV_STATE_DEFAULT, 2);
}

static void event_handler(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_clock_msg_deinit();
    }
}

lv_obj_t *lv_clock_msg_init(void)
{
    lv_msg_styles_init();

    /* Background */
    mdata.obj_main = lv_obj_create(lv_scr_act(), NULL);
    lv_obj_add_style(mdata.obj_main, LV_STATE_DEFAULT, &mdata.main_style);
    lv_obj_set_size(mdata.obj_main, LV_CLOCK_DEMO_WIDTH, LV_CLOCK_DEMO_HEIGHT);
    lv_obj_set_pos(mdata.obj_main, 0, 0);

    mdata.obj_page = lv_page_create(mdata.obj_main, NULL);
    lv_obj_add_style(mdata.obj_page, LV_STATE_DEFAULT, &mdata.page_style);
    lv_obj_set_size(mdata.obj_page, 240, 120);
    lv_obj_align(mdata.obj_page, mdata.obj_main, LV_ALIGN_CENTER, 0, -30);

    /*Create a label on the page*/
    mdata.obj_page_text = lv_label_create(mdata.obj_page, NULL);
    lv_label_set_long_mode(mdata.obj_page_text, LV_LABEL_LONG_BREAK);            /*Automatically break long lines*/
    lv_obj_set_width(mdata.obj_page_text, lv_page_get_width_fit(mdata.obj_page));          /*Set the label width to max value to not show hor. scroll bars*/
    lv_label_set_text(mdata.obj_page_text, "There is no message!\n"
                      "It is only an example for message box!\n"
                      "Good luck!");

    /*Create a button on the msg*/
    mdata.obj_btn = lv_btn_create(mdata.obj_main, NULL);
    lv_obj_set_size(mdata.obj_btn, 120, 60);
    lv_obj_align(mdata.obj_btn, mdata.obj_main, LV_ALIGN_CENTER, 0, 100);
    lv_obj_set_event_cb(mdata.obj_btn, event_handler);

    mdata.obj_btn_text = lv_label_create(mdata.obj_btn, NULL);
    lv_label_set_text(mdata.obj_btn_text, "OK");

    return mdata.obj_main;
}

void lv_clock_msg_deinit(void)
{
    lv_obj_clean_style_list(mdata.obj_page, LV_STATE_DEFAULT);
    lv_obj_clean_style_list(mdata.obj_main, LV_STATE_DEFAULT);
    lv_obj_del(mdata.obj_main);
}
