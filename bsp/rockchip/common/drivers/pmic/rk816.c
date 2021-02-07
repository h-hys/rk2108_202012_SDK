/**
  * Copyright (c) 2019 Fuzhou Rockchip Electronics Co., Ltd
  *
  * SPDX-License-Identifier: Apache-2.0
  ******************************************************************************
  * @file    rk816.c
  * @version V0.1
  * @brief   rk816 interface
  *
  * Change Logs:
  * Date           Author          Notes
  * 2019-12-26     Joseph Chen     first implementation
  *
  ******************************************************************************
  */

#include <rtdevice.h>
#include <rtthread.h>

#ifdef RT_USING_PMIC_RK816
#include "drv_pmic.h"
#include "rk816.h"

/*
 * bat charge current:
 *               10mR:    [2000, 2400, 2800, 3200, 3600, 4000, 4500, 4800]
 *               20mR:    [1000, 1200, 1400, 1600, 1800, 2000, 2250, 2400]
 *               40mR:    [500,   600,  700,  800,  900, 1000, 1125, 1200]
 *              100mR:    [200,   240,  280,  320,  360,  400,  450,  480]
 *
 * bat charge voltage:    [4050, 4100, 4150, 4200, 4250, 4300, 4350]
 *
 * src input current:     [450, 80, 850, 1000, 1250, 1500, 1750, 2000]
 *
 * finish charge current:
 *               10mR:    [300, 400, 600, 800]
 *               20mR:    [150, 200, 300, 400]
 *               40mR:    [75,  100, 150, 200]
 *              100mR:    [30,   40,  60,  80]
 *
 *
 * NOTE:
 *
 * 1. Developer should [never update] the following array definition, they
 *    are the values of 20mR of sample resistor.
 *
 * 2. Developer pass the value showing on the above to rt_device_control()
 *    from user space.
 *
 *  Example: set 200ma charge current on board with 100mR sample resistor:
 *
 *  void foo(void)
 *  {
 *      rt_uint32_t charge_current= 200;
 *      ......
 *      ret = rt_device_control(device, RT_DEVICE_CTRL_CHAGER_BATCUR_SET, &charge_current);
 *      ......
 *  }
 *
 */
const rt_int16_t bat_vol_level[7] =
{
    4050, 4100, 4150, 4200, 4250, 4300, 4350
};

const rt_int16_t bat_cur_level[8] =
{
    1000, 1200, 1400, 1600, 1800, 2000, 2250, 2400
};

const rt_int16_t fns_cur_level[4] =
{
    150, 200, 300, 400,
};

const rt_int16_t src_cur_level[8] =
{
    450, 80, 850, 1000, 1250, 1500, 1750, 2000
};

static const struct reg_data init_reg[] =
{
    { BAT_CTRL_REG, BAT_DIS_ILIM_MASK, BAT_DIS_ILIM_DIS, },
};

static int rt_rk816_init(void)
{
    struct pwr_i2c_desc *i2c;
    rt_int32_t val;
    int i, ret;

    i2c = pmic_get_i2c_desc();
    if (i2c == RT_NULL)
        return -RT_EINVAL;

    for (i = 0; i < ARRAY_SIZE(init_reg); i++)
    {
        val = pmic_read(i2c->bus, i2c->addr, init_reg[i].reg);
        if (val < 0)
        {
            rt_kprintf("failed to read reg: 0x%x\n", init_reg[i].reg);
            return val;
        }

        val &= ~init_reg[i].mask;
        val |= init_reg[i].val;
        ret = pmic_write(i2c->bus, i2c->addr, init_reg[i].reg, val);
        if (ret < 0)
        {
            rt_kprintf("failed to write reg: 0x%x\n", init_reg[i].reg);
            return ret;
        }
    }

    return RT_EOK;
}

INIT_DEVICE_EXPORT(rt_rk816_init);

#endif
