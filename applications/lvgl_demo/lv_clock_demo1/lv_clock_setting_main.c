#include <rtthread.h>

#include <littlevgl2rtt.h>
#include <lvgl/lvgl.h>
#include <dfs_posix.h>

#include "./lv_clock_main.h"

/*********************
 *      DEFINES
 *********************/

#define LV_CLOCK_MOVE_TIMER_TICKS   (RT_TICK_PER_SECOND * 200 / 1000)
#define LV_CLOCK_MOVE_STEP          80

#define LV_CLOCK_ANIM_TIME          50
#define LV_CLOCK_ANIM_STEP          80

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

struct lv_clock_setting_main_t
{
    lv_style_t main_style;
    lv_style_t date_label_style;

    lv_obj_t   *obj_main;
    lv_obj_t   *obj_msg;
    lv_obj_t   *obj_setting;
    lv_obj_t   *obj_date;
    lv_obj_t   *obj_week;

    lv_point_t  p_prev;
    lv_anim_t   anim;
    uint8_t     mov_dir;

    lv_img_dsc_t msg_dsc;
    lv_img_dsc_t setting_dsc;
};
static struct lv_clock_setting_main_t mdata;

/*********************
 *  BTN EVENT_CB FUNCTIONS
 *********************/
static void msg_event_handler(lv_obj_t *src, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_clock_msg_init();
    }
}

static void setting_event_handler(lv_obj_t *src, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_setting_menu_init();
    }
}

/*********************
 *  MOVE EVENT_CB FUNCTIONS
 *********************/
static void anim_start_cb(lv_anim_t *a)
{
    lv_coord_t set_y = lv_obj_get_y(mdata.obj_main) + a->end;

    if (set_y > 0) set_y = 0;
    if (set_y < -LV_CLOCK_DEMO_HEIGHT) set_y = -LV_CLOCK_DEMO_HEIGHT;
    lv_obj_set_y(mdata.obj_main, set_y);
}

static void anim_exe_cb(void *var, lv_anim_value_t value)
{
    // do nothing....
}

static void anim_ready_cb(lv_anim_t *a)
{
    if (mdata.mov_dir == LV_CLOCK_MOVE_UP)
    {
        lv_obj_set_y(mdata.obj_main, -1 * LV_CLOCK_DEMO_WIDTH);
    }
    else
    {
        lv_obj_set_y(mdata.obj_main, 0);
    }

    /* Enable btn callback */
    lv_obj_set_event_cb(mdata.obj_msg, msg_event_handler);
    lv_obj_set_event_cb(mdata.obj_setting, setting_event_handler);

    lv_anim_del(&mdata, NULL);
}

static void move_event_handler(lv_obj_t *src, lv_event_t event)
{
    if (event == LV_EVENT_PRESSED)
    {
        mdata.mov_dir = LV_CLOCK_MOVE_NULL;
        lv_indev_get_point(lv_indev_get_act(), &mdata.p_prev);
    }
    else if (event == LV_EVENT_PRESSING)
    {
        lv_point_t p;
        lv_indev_get_point(lv_indev_get_act(), &p);

        lv_coord_t new_y = lv_obj_get_y(src) + (p.y - mdata.p_prev.y);
        if ((ABS(p.y - mdata.p_prev.y) > 10) && (new_y < 0))
        {
            lv_obj_set_y(src, new_y);

            mdata.mov_dir = LV_CLOCK_MOVE_DOWN;
            if (p.y < mdata.p_prev.y)
            {
                mdata.mov_dir = LV_CLOCK_MOVE_UP;
            }

            mdata.p_prev.x = p.x;
            mdata.p_prev.y = p.y;

            /* Disable btn callback */
            lv_obj_set_event_cb(mdata.obj_msg, NULL);
            lv_obj_set_event_cb(mdata.obj_setting, NULL);
        }
    }
    else if ((event == LV_EVENT_RELEASED) || (event == LV_EVENT_PRESS_LOST))
    {
        if (mdata.mov_dir != LV_CLOCK_MOVE_NULL)
        {
            lv_coord_t end_val = 0;
            uint16_t  loop_cnt = 0;

            end_val  = LV_CLOCK_ANIM_STEP;
            loop_cnt = (ABS(lv_obj_get_y(src)) + (LV_CLOCK_ANIM_STEP - 1)) / LV_CLOCK_ANIM_STEP;
            if (mdata.mov_dir == LV_CLOCK_MOVE_UP)
            {
                end_val = -LV_CLOCK_ANIM_STEP;
                loop_cnt = (LV_CLOCK_DEMO_HEIGHT - ABS(lv_obj_get_y(src)) + (LV_CLOCK_ANIM_STEP - 1)) / LV_CLOCK_ANIM_STEP;
            }

            lv_anim_init(&mdata.anim);
            lv_anim_set_var(&mdata.anim, &mdata);
            lv_anim_set_start_cb(&mdata.anim, anim_start_cb);
            lv_anim_set_exec_cb(&mdata.anim, (lv_anim_exec_xcb_t)anim_exe_cb);
            lv_anim_set_ready_cb(&mdata.anim, anim_ready_cb);
            lv_anim_set_values(&mdata.anim, 0, end_val);
            lv_anim_set_time(&mdata.anim, LV_CLOCK_ANIM_TIME);
            lv_anim_set_repeat_count(&mdata.anim, loop_cnt - 1);
            lv_anim_start(&mdata.anim);
        }
    }
}

/*********************
 *  MAIN FUNCTIONS
 *********************/
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
    lv_style_init(&mdata.date_label_style);
    lv_style_set_bg_opa(&mdata.date_label_style, LV_STATE_DEFAULT, LV_OPA_80);
    lv_style_set_bg_color(&mdata.date_label_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_text_color(&mdata.date_label_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_border_color(&mdata.date_label_style, LV_STATE_DEFAULT, LV_COLOR_GRAY);
    lv_style_set_border_color(&mdata.date_label_style, LV_STATE_FOCUSED, LV_COLOR_GRAY);
    lv_style_set_border_width(&mdata.date_label_style, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_top(&mdata.date_label_style, LV_STATE_DEFAULT, 4);
    lv_style_set_pad_bottom(&mdata.date_label_style, LV_STATE_DEFAULT, 4);
    lv_style_set_pad_left(&mdata.date_label_style, LV_STATE_DEFAULT, 4);
    lv_style_set_pad_right(&mdata.date_label_style, LV_STATE_DEFAULT, 4);
}

void lv_setting_main_date_update(void)
{
    /* Date info */
    char str[16];
    snprintf(str, 16, "%04d-%02d-%02d", lv_clock.date.year, lv_clock.date.month, lv_clock.date.day);
    lv_label_set_text(mdata.obj_date, str);
    lv_label_set_text(mdata.obj_week, week_days[lv_clock.date.weekdays]);
    lv_obj_invalidate(mdata.obj_main);
}

lv_obj_t *lv_setting_main_init(lv_coord_t x, lv_coord_t y)
{
    /* Styles init */
    lv_setting_styles_init();

    /* Image soruce load */
#if (LV_COLOR_DEPTH == 8)
    lv_clock_img_file_load(&mdata.msg_dsc, "L:/color8/setting/msg_ico.bin");
    lv_clock_img_file_load(&mdata.setting_dsc, "L:/color8/setting/setting_ico.bin");
#elif (LV_COLOR_DEPTH == 16)
    lv_clock_img_file_load(&mdata.msg_dsc, "L:/color16/setting/msg_ico.bin");
    lv_clock_img_file_load(&mdata.setting_dsc, "L:/color16/setting/setting_ico.bin");
#endif

    /* Background */
    mdata.obj_main = lv_obj_create(lv_scr_act(), NULL);
    lv_obj_add_style(mdata.obj_main, LV_STATE_DEFAULT, &mdata.main_style);
    lv_obj_set_size(mdata.obj_main, LV_CLOCK_DEMO_WIDTH, LV_CLOCK_DEMO_HEIGHT);
    lv_obj_set_pos(mdata.obj_main, x, y);
    lv_obj_set_event_cb(mdata.obj_main, move_event_handler);

    /* Message btn */
    mdata.obj_msg = lv_imgbtn_create(mdata.obj_main, NULL);
    lv_imgbtn_set_src(mdata.obj_msg, LV_BTN_STATE_RELEASED, &mdata.msg_dsc);
    lv_imgbtn_set_src(mdata.obj_msg, LV_BTN_STATE_PRESSED, &mdata.msg_dsc);
    lv_imgbtn_set_src(mdata.obj_msg, LV_BTN_STATE_CHECKED_RELEASED, &mdata.msg_dsc);
    lv_imgbtn_set_src(mdata.obj_msg, LV_BTN_STATE_CHECKED_PRESSED, &mdata.msg_dsc);

    lv_obj_set_pos(mdata.obj_msg, LV_CLOCK_DEMO_WIDTH / 2 - mdata.msg_dsc.header.w - 20, LV_CLOCK_DEMO_HEIGHT / 4 - mdata.msg_dsc.header.h / 2 + 15);
    lv_obj_set_event_cb(mdata.obj_msg, msg_event_handler);

    lv_obj_t *label = lv_label_create(mdata.obj_main, NULL);
    lv_obj_set_pos(label, LV_CLOCK_DEMO_WIDTH / 2 - mdata.msg_dsc.header.w - 35, LV_CLOCK_DEMO_HEIGHT / 4 + mdata.msg_dsc.header.h / 2 + 25);
    lv_label_set_text(label, "Message");

    /* Setting btn */
    mdata.obj_setting = lv_imgbtn_create(mdata.obj_main, NULL);
    lv_imgbtn_set_src(mdata.obj_setting, LV_BTN_STATE_RELEASED, &mdata.setting_dsc);
    lv_imgbtn_set_src(mdata.obj_setting, LV_BTN_STATE_PRESSED, &mdata.setting_dsc);
    lv_imgbtn_set_src(mdata.obj_setting, LV_BTN_STATE_CHECKED_RELEASED, &mdata.setting_dsc);
    lv_imgbtn_set_src(mdata.obj_setting, LV_BTN_STATE_CHECKED_PRESSED, &mdata.setting_dsc);

    lv_obj_set_pos(mdata.obj_setting, LV_CLOCK_DEMO_WIDTH / 2 + 20, LV_CLOCK_DEMO_HEIGHT / 4 - mdata.setting_dsc.header.h / 2 + 15);
    lv_obj_set_event_cb(mdata.obj_setting, setting_event_handler);

    label = lv_label_create(mdata.obj_main, NULL);
    lv_obj_set_pos(label, LV_CLOCK_DEMO_WIDTH / 2 + 20, LV_CLOCK_DEMO_HEIGHT / 4 + mdata.setting_dsc.header.h / 2 + 25);
    lv_label_set_text(label, "Setting");

    /* Date info */
    char str[16];
    mdata.obj_date = lv_label_create(mdata.obj_main, NULL);
    lv_obj_add_style(mdata.obj_date, LV_STATE_DEFAULT, &mdata.date_label_style);
    snprintf(str, 16, "%04d-%02d-%02d", lv_clock.date.year, lv_clock.date.month, lv_clock.date.day);
    lv_label_set_text(mdata.obj_date, str);
    lv_obj_align(mdata.obj_date, mdata.obj_main, LV_ALIGN_CENTER, 0, LV_CLOCK_DEMO_HEIGHT / 4 - 10);

    mdata.obj_week = lv_label_create(mdata.obj_main, NULL);
    lv_label_set_text(mdata.obj_week, week_days[lv_clock.date.weekdays]);
    lv_obj_align(mdata.obj_week, mdata.obj_main, LV_ALIGN_CENTER, 0, LV_CLOCK_DEMO_HEIGHT / 4 + 30);

    return mdata.obj_main;
}

void lv_setting_main_deinit(void)
{
    lv_obj_clean_style_list(mdata.obj_date, LV_STATE_DEFAULT);
    lv_obj_clean_style_list(mdata.obj_main, LV_STATE_DEFAULT);
    lv_obj_del(mdata.obj_main);

    lv_clock_img_file_unload(&mdata.msg_dsc);
    lv_clock_img_file_unload(&mdata.setting_dsc);
}
