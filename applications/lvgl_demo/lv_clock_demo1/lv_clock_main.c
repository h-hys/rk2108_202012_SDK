#include <rtthread.h>
#include <math.h>

#include <littlevgl2rtt.h>
#include <lvgl/lvgl.h>
#include <dfs_posix.h>
#include "drv_heap.h"

#include "./lv_clock_main.h"
#include "auto_version.h"

/*********************
 *      DEFINES
 *********************/

#define LV_CLOCK_MOVE_TIMER_TICKS   (RT_TICK_PER_SECOND * 200 / 1000)
#define LV_CLOCK_MOVE_STEP          80

#define LV_CLOCK_ANIM_TIME          50
#define LV_CLOCK_ANIM_STEP          80

/**********************
 *  GLOBAL VARIABLES
 **********************/
const char *week_days[] =
{
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
};
const uint8_t month_days[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct lv_clock_demo_t lv_clock;

/**********************
 *  STATIC VARIABLES
 **********************/
struct lv_clock_list_t
{
    rt_list_t list;
    lv_obj_t  *clock;
};

struct lv_clock_main_t
{
    rt_timer_t   tick_timer;
    lv_anim_t     anim;

    rt_list_t    *clk_head;
    struct lv_clock_list_t clock_list[16];
    lv_obj_t     *obj_setting;

    uint8_t       mov_bidir;
    uint8_t       mov_dir;
};
static struct lv_clock_main_t mdata;

/**********************
 * GLOBAL FUNCTIONS
 **********************/
void lv_clock_img_file_load(lv_img_dsc_t *img_dsc, const char *file)
{
    lv_res_t res;

    lv_img_header_t info;
    res = lv_img_decoder_get_info(file, &info);
    RT_ASSERT(res == LV_RES_OK);

    uint8_t px_size = lv_img_cf_get_px_size(info.cf);
    RT_ASSERT(px_size == LV_COLOR_DEPTH);

    //rt_kprintf("%s: %d, %d, %d, %d\n", file, info.w, info.h, px_size, info.w * info.h * px_size / 8);
    uint8_t *img_buf;
    if (RT_PSRAM_MALLOC_THRRESH > info.w * info.h * px_size / 8)
    {
        img_buf = rt_malloc(info.w * info.h * px_size / 8);
    }
    else
    {
        img_buf = rt_malloc_psram(info.w * info.h * px_size / 8);
        //img_buf = rt_malloc_dtcm(info.w * info.h * px_size / 8);
    }
    RT_ASSERT(img_buf != RT_NULL);
    rt_memset((void *)img_buf, 0, info.w * info.h * px_size / 8);

    lv_img_decoder_dsc_t dsc;
    res = lv_img_decoder_open(&dsc, file, LV_COLOR_WHITE);
    RT_ASSERT(res == LV_RES_OK);

    res = lv_img_decoder_read_line(&dsc, 0, 0, info.w * info.h, img_buf);
    //RT_ASSERT(res == LV_RES_OK);

    lv_img_decoder_close(&dsc);

    img_dsc->header.cf = info.cf;
    img_dsc->header.always_zero = info.always_zero;
    img_dsc->header.w = info.w;
    img_dsc->header.h = info.h;
    img_dsc->data_size = info.w * info.h * px_size / 8;
    img_dsc->data = img_buf;
}

void lv_clock_img_file_unload(lv_img_dsc_t *img_dsc)
{
    //rt_free_psram((void *)img_dsc->data);
    rt_memheap_free((void *)img_dsc->data);
}

uint32_t lv_clock_str2num(const char *str, uint8_t len)
{
    uint32_t num = 0;

    for (uint8_t i = 0; i < len; i++)
    {
        num += (str[i] - '0') * pow(10, (len - i - 1));
    }

    return num;
}

uint8_t get_day_of_week(uint16_t year, uint8_t month, uint8_t day)
{
    uint32_t a = month < 3 ? 1 : 0;
    uint32_t b = year - a;

    uint32_t day_of_week = (day + (31 * (month - 2 + 12 * a) / 12) + b + (b / 4) - (b / 100) + (b / 400)) % 7;

    return day_of_week;
}

/*********************
 *  STATIC FUNCTIONS
 *********************/

static void lv_clock_init_variable(void)
{
    const char *str = FIRMWARE_AUTO_VERSION;

    /*Init the date of clock*/
    lv_clock.date.year     = lv_clock_str2num(&str[0], 4);
    lv_clock.date.month    = lv_clock_str2num(&str[5], 2);
    lv_clock.date.day      = lv_clock_str2num(&str[8], 2);
    lv_clock.date.weekdays = get_day_of_week(lv_clock.date.year, lv_clock.date.month, lv_clock.date.day);

    /*Init the date of time*/
    lv_clock.time.hour = lv_clock_str2num(&str[11], 2);
    lv_clock.time.min  = lv_clock_str2num(&str[14], 2);
    lv_clock.time.sec  = lv_clock_str2num(&str[17], 2);

}

static void lv_clock_timer_tick(void *parameter)
{
    lv_clock_date_t *date = &lv_clock.date;
    lv_clock_time_t *time = &lv_clock.time;

    if (++time->sec >= 60)
    {
        time->sec = 0;
        if (++time->min >= 60)
        {
            time->min = 0;
            if (++time->hour >= 24)
            {
                time->hour = 0;
                if (++date->weekdays >= 7)
                {
                    date->weekdays = 0;
                }

                if (++date->day > month_days[date->month - 1])
                {
                    date->day = 1;
                    if (++date->month > 12)
                    {
                        date->month = 1;
                        if (++date->year > 3000)
                        {
                            date->year = 1900;
                        }
                    }
                }

            }
        }
    }

    /* Refresh current clock if current clock is visible*/
    if (0 != lv_obj_get_y(mdata.obj_setting))
    {
        struct lv_clock_list_t *lclock = rt_list_entry(mdata.clk_head, struct lv_clock_list_t, list);
        lv_obj_invalidate(lclock->clock);
    }
}

static void lv_clock_init_start(void)
{
    mdata.tick_timer = rt_timer_create("clkt",
                                       lv_clock_timer_tick, (void *)(&mdata),
                                       RT_TICK_PER_SECOND, RT_TIMER_FLAG_PERIODIC);
    RT_ASSERT(mdata.tick_timer != RT_NULL);

    rt_timer_start(mdata.tick_timer);
}

/*********************
 *  LV_CLOCK_MAIN_CB
 *********************/
static void anim_start_cb(lv_anim_t *a)
{
    if (mdata.mov_bidir == LV_CLOCK_MOVE_LEFTRGHT)
    {
        struct lv_clock_list_t *lclock = rt_list_entry(mdata.clk_head, struct lv_clock_list_t, list);
        rt_list_t *pos = mdata.clk_head;
        do
        {
            lclock = rt_list_entry(pos, struct lv_clock_list_t, list);
            lv_obj_set_x(lclock->clock, lv_obj_get_x(lclock->clock) + a->end);
            pos = pos->next;
        }
        while (pos != mdata.clk_head);
    }
    else if (mdata.mov_bidir == LV_CLOCK_MOVE_UPDOWN)
    {
        lv_coord_t set_y = lv_obj_get_y(mdata.obj_setting) + a->end;
        if (set_y > 0) set_y = 0;
        if (set_y < -LV_CLOCK_DEMO_HEIGHT) set_y = -LV_CLOCK_DEMO_HEIGHT;
        lv_obj_set_y(mdata.obj_setting, set_y);
    }
}

static void anim_exe_cb(void *var, lv_anim_value_t value)
{
    // do nothing....
}

static void anim_ready_cb(lv_anim_t *a)
{
    if (mdata.mov_bidir == LV_CLOCK_MOVE_LEFTRGHT)
    {
        struct lv_clock_list_t *lclock = rt_list_entry(mdata.clk_head, struct lv_clock_list_t, list);

        if (mdata.mov_dir == LV_CLOCK_MOVE_LEFT)
        {
            mdata.clk_head = mdata.clk_head->next;
        }
        else
        {
            mdata.clk_head = mdata.clk_head->prev;
        }

        uint16_t x_pos = -1;
        rt_list_t *pos = mdata.clk_head->prev;
        do
        {
            lclock = rt_list_entry(pos, struct lv_clock_list_t, list);
            lv_obj_set_x(lclock->clock, (x_pos++) * LV_CLOCK_DEMO_WIDTH);
            pos = pos->next;
        }
        while (pos->next != mdata.clk_head);
    }
    else if (mdata.mov_bidir == LV_CLOCK_MOVE_UPDOWN)
    {
        if (mdata.mov_dir == LV_CLOCK_MOVE_UP)
        {
            lv_obj_set_y(mdata.obj_setting, -1 * LV_CLOCK_DEMO_WIDTH);
        }
        else
        {
            lv_obj_set_y(mdata.obj_setting, 0);
        }
    }

    lv_anim_del(&mdata, NULL);
}

static lv_point_t p_prev;
static void event_handler(lv_obj_t *clock, lv_event_t event)
{
    if (event == LV_EVENT_PRESSED)
    {
        mdata.mov_bidir = LV_CLOCK_MOVE_NULL;
        mdata.mov_dir = LV_CLOCK_MOVE_NULL;
        lv_indev_get_point(lv_indev_get_act(), &p_prev);
    }
    else if (event == LV_EVENT_PRESSING)
    {
        lv_point_t p;
        lv_indev_get_point(lv_indev_get_act(), &p);

        /* Check Y or X dir move */
        if (mdata.mov_bidir == LV_CLOCK_MOVE_NULL)
        {
            if ((ABS(p.x - p_prev.x) > 20) || (ABS(p.y - p_prev.y) > 20))
            {
                if (ABS(p.x - p_prev.x) < ABS(p.y - p_prev.y))
                {
                    mdata.mov_bidir = LV_CLOCK_MOVE_UPDOWN;
                    mdata.mov_dir = LV_CLOCK_MOVE_DOWN;
                    if (p.y < p_prev.y)
                    {
                        mdata.mov_dir = LV_CLOCK_MOVE_UP;
                    }
                }
                else
                {
                    mdata.mov_bidir = LV_CLOCK_MOVE_LEFTRGHT;
                    mdata.mov_dir = LV_CLOCK_MOVE_RIGHT;
                    if (p.x < p_prev.x)
                    {
                        mdata.mov_dir = LV_CLOCK_MOVE_LEFT;
                    }
                }
            }
        }
        else
        {
            if (mdata.mov_bidir == LV_CLOCK_MOVE_LEFTRGHT)
            {
                if (ABS(p.x - p_prev.x) > 10)
                {
                    struct lv_clock_list_t *lclock;
                    rt_list_t *pos = mdata.clk_head;
                    do
                    {
                        lclock = rt_list_entry(pos, struct lv_clock_list_t, list);
                        lv_obj_set_x(lclock->clock, lv_obj_get_x(lclock->clock) + (p.x - p_prev.x));
                        pos = pos->next;
                    }
                    while (pos != mdata.clk_head);

                    mdata.mov_dir = LV_CLOCK_MOVE_RIGHT;
                    if (p.x < p_prev.x)
                    {
                        mdata.mov_dir = LV_CLOCK_MOVE_LEFT;
                    }

                    p_prev.x = p.x;
                    p_prev.y = p.y;
                }
            }
            else if (mdata.mov_bidir == LV_CLOCK_MOVE_UPDOWN)
            {
                if (ABS(p.y - p_prev.y) > 10)
                {
                    lv_obj_set_y(mdata.obj_setting, lv_obj_get_y(mdata.obj_setting) + (p.y - p_prev.y));

                    mdata.mov_dir = LV_CLOCK_MOVE_DOWN;
                    if (p.y < p_prev.y)
                    {
                        mdata.mov_dir = LV_CLOCK_MOVE_UP;
                    }

                    p_prev.x = p.x;
                    p_prev.y = p.y;
                }
            }
        }
    }
    else if ((event == LV_EVENT_RELEASED) || (event == LV_EVENT_PRESS_LOST))
    {
        lv_coord_t end_val = 0;
        uint16_t  loop_cnt = 0;

        if (mdata.mov_bidir == LV_CLOCK_MOVE_LEFTRGHT)
        {
            end_val = LV_CLOCK_ANIM_STEP;
            if (mdata.mov_dir == LV_CLOCK_MOVE_LEFT)
            {
                end_val = -LV_CLOCK_ANIM_STEP;
            }
            struct lv_clock_list_t *lclock = rt_list_entry(mdata.clk_head, struct lv_clock_list_t, list);
            loop_cnt = (LV_CLOCK_DEMO_WIDTH + (LV_CLOCK_ANIM_STEP - 1) - ABS(lv_obj_get_x(lclock->clock))) / LV_CLOCK_ANIM_STEP;
        }
        else if (mdata.mov_bidir == LV_CLOCK_MOVE_UPDOWN)
        {
            end_val = LV_CLOCK_ANIM_STEP;
            loop_cnt = (ABS(lv_obj_get_y(mdata.obj_setting)) + (LV_CLOCK_ANIM_STEP - 1)) / LV_CLOCK_ANIM_STEP;
            if (mdata.mov_dir == LV_CLOCK_MOVE_UP)
            {
                end_val = -LV_CLOCK_ANIM_STEP;
                loop_cnt = (LV_CLOCK_DEMO_HEIGHT - ABS(lv_obj_get_y(mdata.obj_setting)) + (LV_CLOCK_ANIM_STEP - 1)) / LV_CLOCK_ANIM_STEP;
            }
        }

        if (mdata.mov_bidir != LV_CLOCK_MOVE_NULL)
        {
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
 *  LV_CLOCK_MAIN
 *********************/
void lv_app_init(void)
{
    lv_clock_init_variable();

    mdata.clk_head = &mdata.clock_list[0].list;

    mdata.clock_list[0].clock = lv_clock_demo0_init(0 * LV_CLOCK_DEMO_WIDTH, 0, event_handler);
    rt_list_init(&mdata.clock_list[0].list);

    mdata.clock_list[1].clock = lv_clock_demo1_init(1 * LV_CLOCK_DEMO_WIDTH, 0, event_handler);
    rt_list_insert_after(&mdata.clock_list[0].list, &mdata.clock_list[1].list);

    mdata.clock_list[2].clock = lv_clock_demo2_init(2 * LV_CLOCK_DEMO_WIDTH, 0, event_handler);
    rt_list_insert_after(&mdata.clock_list[1].list, &mdata.clock_list[2].list);

    mdata.clock_list[3].clock = lv_clock_demo3_init(3 * LV_CLOCK_DEMO_WIDTH, 0, event_handler);
    rt_list_insert_after(&mdata.clock_list[2].list, &mdata.clock_list[3].list);

    mdata.obj_setting = lv_setting_main_init(0, -1 * LV_CLOCK_DEMO_HEIGHT);

    lv_clock_init_start();
}
