#include <rtthread.h>

#include <littlevgl2rtt.h>
#include <lvgl/lvgl.h>

#include "drv_heap.h"
#include "drv_display.h"
#include "display.h"

#if defined(RT_USING_TOUCH_DRIVERS)
#include "touch.h"
#include "touchpanel.h"
#endif

#include "lv_app_main.h"

/*
 **************************************************************************************************
 *
 * Macro define
 *
 **************************************************************************************************
 */

/*
 *  lvgl config parm as below:
 *
 *  LV_COLOR_DEPTH      16
 *  LV_HOR_RES          320
 *  LV_VER_RES          320
 */

#define LVGL_APP_MAIN_DEBUG 0

/* display win layers */
#define LVGL_DIAPLAY_WIN    0

#define LVGL_REGION_X       0
#define LVGL_REGION_Y       0
#define LVGL_FB_W           LV_HOR_RES
#define LVGL_FB_H           LV_VER_RES

/* Event define */
#define EVENT_LV_DISP_REFRESH       (0x01UL << 0)
#define EVENT_LV_TASK_HANDLER       (0x01UL << 1)
#define EVENT_REFR_DONE             (0x01UL << 2)

#define LV_TASK_HANDLER_TICKS       (RT_TICK_PER_SECOND / 100)   //20ms

/*
 **************************************************************************************************
 *
 * Declaration
 *
 **************************************************************************************************
 */

/*
 **************************************************************************************************
 *
 * Global static struct & data define
 *
 **************************************************************************************************
 */
struct lv_display_data_t
{
    rt_display_data_t disp;
    rt_event_t  event;
    rt_timer_t  lv_timer;
    rt_uint32_t cmd;

    rt_uint8_t *fb;
    rt_uint32_t fblen;
};

static struct lv_display_data_t *g_disp_data = RT_NULL;

/*
 **************************************************************************************************
 *
 * lvgl GUI sub functions: Win layer0.
 *
 **************************************************************************************************
 */

/**
 * hook function for lvgl set graphic info.
 */
rt_err_t lv_set_graphic_info(struct rt_device_graphic_info *info)
{
    struct display_state *state = (struct display_state *)g_disp_data->disp->device->user_data;
    struct rt_device_graphic_info *graphic_info = &state->graphic_info;

    graphic_info->bits_per_pixel = LV_COLOR_DEPTH;
    graphic_info->width          = LVGL_FB_W;
    graphic_info->height         = LVGL_FB_H;
    graphic_info->framebuffer    = g_disp_data->fb;

    memcpy(info, graphic_info, sizeof(struct rt_device_graphic_info));

    return RT_EOK;
}

#if defined(RT_USING_TOUCH_DRIVERS)
/**
 * lvgl touch callback.
 */
static struct rt_touchpanel_block lv_touch_block;

static rt_err_t lv_touch_cb(struct rt_touch_data *point, rt_uint8_t num)
{
    struct rt_touch_data *p = &point[0];
    struct rt_touchpanel_block *b = &lv_touch_block;

    if (RT_EOK != rt_touchpoint_is_valid(p, b))
    {
        return RT_ERROR;
    }

    if (b->event == RT_TOUCH_EVENT_DOWN)
    {
        littlevgl2rtt_send_input_event(p->x_coordinate - b->x, p->y_coordinate - b->y, LITTLEVGL2RTT_INPUT_DOWN);
    }
    else if (b->event == RT_TOUCH_EVENT_MOVE)
    {
        littlevgl2rtt_send_input_event(p->x_coordinate - b->x, p->y_coordinate - b->y, LITTLEVGL2RTT_INPUT_MOVE);
    }
    else if (b->event == RT_TOUCH_EVENT_UP)
    {
        littlevgl2rtt_send_input_event(p->x_coordinate - b->x, p->y_coordinate - b->y, LITTLEVGL2RTT_INPUT_UP);
    }

    return RT_EOK;
}

static void lv_touch_block_init(struct rt_touchpanel_block *block)
{
    struct rt_device_graphic_info *info = &g_disp_data->disp->info;

    rt_memset(block, 0, sizeof(struct rt_touchpanel_block));

    block->x = LVGL_REGION_X + ((info->width  - LVGL_FB_W) / 2);
    block->y = LVGL_REGION_Y + ((info->height - LVGL_FB_H) / 2);
    block->w = LVGL_FB_W;
    block->h = LVGL_FB_H;
    block->name = "lvgl";
    block->callback = lv_touch_cb;
}

#endif

/**
 * app clock display refresh request: request send data to LCD pannel.
 */
static rt_err_t lv_refr_done(void)
{
    return (rt_event_send(g_disp_data->event, EVENT_REFR_DONE));
}

static rt_err_t lv_refr_request(struct rt_display_mq_t *disp_mq)
{
    rt_err_t ret;

    //wait refresh done
    rt_uint32_t event;
    ret = rt_event_recv(g_disp_data->event, EVENT_REFR_DONE,
                        RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR,
                        RT_WAITING_FOREVER, &event);
    RT_ASSERT(ret == RT_EOK);

    //request refresh display data to Pannel
    disp_mq->disp_finish = lv_refr_done;
    ret = rt_mq_send(g_disp_data->disp->disp_mq, disp_mq, sizeof(struct rt_display_mq_t));
    RT_ASSERT(ret == RT_EOK);

    return RT_EOK;
}

/**
 * home region refresh.
 */
static void lv_lcd_flush(void)
{
    struct lv_display_data_t *p_data = g_disp_data;
    struct rt_display_mq_t disp_mq;
    struct rt_display_config *wincfg = &disp_mq.win[0];
    struct rt_device_graphic_info *info = &p_data->disp->info;

    rt_memset(&disp_mq, 0, sizeof(struct rt_display_mq_t));
    disp_mq.win[0].zpos = WIN_TOP_LAYER;
    disp_mq.cfgsta |= (0x01 << 0);

#if (LV_COLOR_DEPTH == 24)
    wincfg->format = RTGRAPHIC_PIXEL_FORMAT_RGB888;
    wincfg->lut    = RT_NULL;
    wincfg->lutsize = 0;
#elif (LV_COLOR_DEPTH == 16)
    wincfg->format = RTGRAPHIC_PIXEL_FORMAT_RGB565;
    wincfg->lut    = RT_NULL;
    wincfg->lutsize = 0;
#else //elif (LV_COLOR_DEPTH == 8)
    wincfg->format = RTGRAPHIC_PIXEL_FORMAT_RGB332;
    wincfg->lut    = bpp_lut;
    wincfg->lutsize = sizeof(bpp_lut) / sizeof(bpp_lut[0]);
#endif
    wincfg->winId  = LVGL_DIAPLAY_WIN;
    wincfg->fb    = p_data->fb;
    wincfg->fblen = p_data->fblen;
    wincfg->w     = LVGL_FB_W;
    wincfg->h     = LVGL_FB_H;
    wincfg->x     = LVGL_REGION_X + ((info->width  - LVGL_FB_W) / 2);
    wincfg->y     = LVGL_REGION_Y + ((info->height - LVGL_FB_H) / 2);
    wincfg->ylast = wincfg->y;

    RT_ASSERT((wincfg->w % 4) == 0);
    RT_ASSERT((wincfg->y % 2) == 0);
    RT_ASSERT((wincfg->h % 2) == 0);

#if LVGL_APP_MAIN_DEBUG
    rt_tick_t ticks = rt_tick_get();
#endif

    lv_refr_request(&disp_mq);

#if LVGL_APP_MAIN_DEBUG
    ticks = rt_tick_get() - ticks;
    if (ticks)
    {
        rt_kprintf("lcd flush ticks: %d\n", ticks);
    }
#endif
}

/**
 * Display clock demo lv_timer callback.
 */
static void lv_task_timer(void *parameter)
{
    rt_event_send(g_disp_data->event, EVENT_LV_TASK_HANDLER);
}

/**
 * clock demo thread
 */

static void lv_main_thread(void *p)
{
    rt_err_t ret;
    uint32_t event;
    struct lv_display_data_t *p_data;

    g_disp_data = p_data = (struct lv_display_data_t *)rt_malloc(sizeof(struct lv_display_data_t));
    RT_ASSERT(p_data != RT_NULL);
    rt_memset((void *)p_data, 0, sizeof(struct lv_display_data_t));

    p_data->fblen = ((LVGL_FB_W * LVGL_FB_H * LV_COLOR_DEPTH / 8 + 3) / 4) * 4;
    p_data->fb     = (rt_uint8_t *)rt_malloc_large(p_data->fblen);
    RT_ASSERT(p_data->fb != RT_NULL);
    rt_memset((void *)p_data->fb, 0, p_data->fblen);

    p_data->disp = rt_display_get_disp();
    RT_ASSERT(p_data->disp != RT_NULL);

    ret = rt_display_screen_clear();
    RT_ASSERT(ret == RT_EOK);

    p_data->event = rt_event_create("lv_event", RT_IPC_FLAG_FIFO);
    RT_ASSERT(p_data->event != RT_NULL);

    rt_event_send(g_disp_data->event, EVENT_REFR_DONE);

    /* init littlevGL */
    ret = littlevgl2rtt_init("lcd");
    RT_ASSERT(ret == RT_EOK);

    rtlvgl_fb_monitor_cb_register(lv_lcd_flush);

#if defined(RT_USING_TOUCH_DRIVERS)
    lv_touch_block_init(&lv_touch_block);
    rt_touchpanel_block_register(&lv_touch_block);
#endif

    /* init lvgl demo */
    lv_app_init();

    /* init lv_timer */
    p_data->lv_timer = rt_timer_create("lv_timer",
                                       lv_task_timer, (void *)p_data,
                                       LV_TASK_HANDLER_TICKS, RT_TIMER_FLAG_PERIODIC);
    RT_ASSERT(p_data->lv_timer != RT_NULL);
    rt_timer_start(p_data->lv_timer);

    while (1)
    {
        ret = rt_event_recv(p_data->event, EVENT_LV_TASK_HANDLER,
                            RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR,
                            RT_WAITING_FOREVER, &event);
        if (ret != RT_EOK)
        {
            /* Reserved... */
        }

        if (event & EVENT_LV_TASK_HANDLER)
        {
#if LVGL_APP_MAIN_DEBUG
            rt_tick_t ticks = rt_tick_get();
#endif

            lv_task_handler();

#if LVGL_APP_MAIN_DEBUG
            ticks = rt_tick_get() - ticks;
            if (ticks)
            {
                rt_kprintf("lv draw ticks: %d\n", ticks);
            }
#endif
        }
    }

    rt_timer_stop(p_data->lv_timer);
    ret = rt_timer_delete(p_data->lv_timer);
    RT_ASSERT(ret == RT_EOK);

#if defined(RT_USING_TOUCH_DRIVERS)
    rt_touchpanel_block_unregister(&lv_touch_block);
#endif

    rtlvgl_fb_monitor_cb_unregister(lv_lcd_flush);
    littlevgl2rtt_deinit();

    rt_event_delete(p_data->event);

    rt_free_large((void *)p_data->fb);

    rt_free(p_data);
}

/**
 * clock demo init
 */
int lv_app_main_init(void)
{
    rt_thread_t thread;

    thread = rt_thread_create("lvclock", lv_main_thread, RT_NULL, 2048, 5, 10);
    RT_ASSERT(thread != RT_NULL);

    rt_thread_startup(thread);

    return RT_EOK;
}
INIT_APP_EXPORT(lv_app_main_init);
