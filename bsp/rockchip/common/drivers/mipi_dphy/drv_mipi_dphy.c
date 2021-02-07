/**
  * Copyright (c) 2019 Rockchip Electronic Co.,Ltd
  *
  * SPDX-License-Identifier: Apache-2.0
  ******************************************************************************
  * @file    vicap.c
  * @version V0.0.1
  * @brief   mipi-dphy-csi-rx device abstract for swallow
  *
  * Change Logs:
  * Date           Author          Notes
  * 2020-07-22     ISP Team      first implementation
  *
  ******************************************************************************
  */

#if defined(__RT_THREAD__)
#include "drv_mipi_dphy.h"
#elif defined(__RK_OS__)
#include "driver/drv_mipi_dphy.h"
#endif

#ifdef RT_USING_MIPI_DPHY

#define VIP_DEBUG 1
#if VIP_DEBUG
#include <stdio.h>
#define MIPI_DBG(...) rk_kprintf("[MIPI_DPHY]:");rk_kprintf(__VA_ARGS__)
#else
#define MIPI_DBG(...)
#endif

#define WRITE_MIPI_REG(base, addr, val) (*(unsigned int *)(addr+(base)) = val)
#define READ_MIPI_REG(base, addr)       (*(unsigned int *)(addr+(base)))

#define CSIHOST_PHY_TEST_CTRL1 0x34
#define CSIHOST_PHY_TEST_CTRL0 0x30

#define GRF_BASE_MIPI 0x40240000
#define GRF_SOC_CON2  0x00208
#define GRF_SOC_CON3  0x0020c

#define GRF_SOC_STATUS0 0x00280
#define GRF_SOC_STATUS1 0x00284

#define ISP_BASE_MIPI 0x40170000
#define LANE_NUMBER   2

#if defined(__RT_THREAD__)

static int rk_mipiphy_wr_reg(unsigned int csi_addr,
                             unsigned char addr,
                             unsigned char data
                            )
{
#if 0
    //TESTEN =1,TESTDIN=addr
    WRITE_MIPI_REG(csi_addr, CSIHOST_PHY_TEST_CTRL1, (0x00010000 | addr));
    //TESTCLK=0
    WRITE_MIPI_REG(csi_addr, CSIHOST_PHY_TEST_CTRL0, 0x00000000);
    //TESTEN =0,TESTDIN=data
    WRITE_MIPI_REG(csi_addr, CSIHOST_PHY_TEST_CTRL1, (0x00000000 | data));
    //TESTCLK=1
    WRITE_MIPI_REG(csi_addr, CSIHOST_PHY_TEST_CTRL0, 0x00000002);
#else
    WRITE_MIPI_REG(csi_addr, GRF_SOC_CON2, 0x02000200);         //TESTCLK=1
    WRITE_MIPI_REG(csi_addr, GRF_SOC_CON2, 0x00ff0000 | addr);   //TESTDIN=addr
    WRITE_MIPI_REG(csi_addr, GRF_SOC_CON2, 0x01000100);         //TESTEN =1
    WRITE_MIPI_REG(csi_addr, GRF_SOC_CON2, 0x02000000);         //TESTCLK=0
    WRITE_MIPI_REG(csi_addr, GRF_SOC_CON2, 0x01000000);         //TESTEN =0
    WRITE_MIPI_REG(csi_addr, GRF_SOC_CON2, 0x02000000);         //TESTCLK=0
    WRITE_MIPI_REG(csi_addr, GRF_SOC_CON2, 0x00ff0000 | data);   //TESTDIN=data
    WRITE_MIPI_REG(csi_addr, GRF_SOC_CON2, 0x02000200);         //TESTCLK=1
#endif

    return 0;
}

static int rk_mipiphy_rd_reg(unsigned int csi_addr,
                             unsigned char addr
                            )
{
#if 0
    uint8_t data;
    //TESTEN =1,TESTDIN=addr
    WRITE_MIPI_REG(csi_addr, CSIHOST_PHY_TEST_CTRL1, (0x00010000 | addr));
    //TESTCLK=0
    WRITE_MIPI_REG(csi_addr, CSIHOST_PHY_TEST_CTRL0, 0x00000000);
    data = (READ_MIPI_REG(csi_addr, CSIHOST_PHY_TEST_CTRL1) & 0xff00) >> 0x8;

    //TESTEN =0
    WRITE_MIPI_REG(csi_addr, CSIHOST_PHY_TEST_CTRL1, 0x00000000);
    //TESTCLK=1
    WRITE_MIPI_REG(csi_addr, CSIHOST_PHY_TEST_CTRL0, 0x00000002);
#else
    uint8_t data;
    WRITE_MIPI_REG(csi_addr, GRF_SOC_CON2, 0x01ff0100 | addr); //TESTEN =1,TESTDIN=addr
    WRITE_MIPI_REG(csi_addr, GRF_SOC_CON2, 0x02000000);     //TESTCLK=0,TESTDIN=addr
    data = READ_MIPI_REG(csi_addr, GRF_SOC_STATUS1) & 0xff;
    WRITE_MIPI_REG(csi_addr, GRF_SOC_CON2, 0x03000200);     //TESTEN =0,TESETCLK=1
    //printf("REG addr=0x%x, data=0x%x\n",addr,data);
#endif

    return data;
}

int rk_csi_phy_cfg(struct cam_csi_phy *csi_phy)
{
    WRITE_MIPI_REG(GRF_BASE_MIPI, GRF_SOC_CON2, 0x02000200); //TESTCLK=1
    WRITE_MIPI_REG(GRF_BASE_MIPI, GRF_SOC_CON2, 0x04000400); //TESTCLR=1
    WRITE_MIPI_REG(GRF_BASE_MIPI, GRF_SOC_CON2, 0x04000000); //TESTCLR=0
    WRITE_MIPI_REG(GRF_BASE_MIPI, 0x1004, 0x00004000);   //RSTZCAL=1

    WRITE_MIPI_REG(ISP_BASE_MIPI, 0x1c00, 0x00042f01);   //SHUTDOWNZ=1
    //WriteReg32(ISP_BASE+0x1c00,0x00042f01);   //RSTZ     =1

//**********************************************************************//
// mipi d-phy cofigure register between //**// lines
// read register value through base addr : 0xFFE00018
#if (LANE_NUMBER == 1)
    rk_mipiphy_wr_reg(GRF_BASE_MIPI, 0xAC, 0x00); // 1 lane
#elif (LANE_NUMBER == 2)
    rk_mipiphy_wr_reg(GRF_BASE_MIPI, 0xAC, 0x01); // 2 lane
#elif (LANE_NUMBER == 4)
    rk_mipiphy_wr_reg(GRF_BASE_MIPI, 0xAC, 0x03); // 4 lane
#endif

#if (LANE_NUMBER == 1)
//600-650M
    rk_mipiphy_wr_reg(GRF_BASE_MIPI, 0x34, 0x10);
//  MIPI_DPHY_RX_WriteReg(0x44,0x10);
#elif (LANE_NUMBER == 2)
//300-330M
    rk_mipiphy_wr_reg(GRF_BASE_MIPI, 0x34, 0x0a);
    rk_mipiphy_wr_reg(GRF_BASE_MIPI, 0x44, 0x0a);
#elif (LANE_NUMBER == 4)
//200-220M
    rk_mipiphy_wr_reg(GRF_BASE_MIPI, 0x34, 0x06);
    rk_mipiphy_wr_reg(GRF_BASE_MIPI, 0x44, 0x06);
#endif

    rk_mipiphy_rd_reg(GRF_BASE_MIPI, 0x00);                    //Normal operation
    WRITE_MIPI_REG(GRF_BASE_MIPI, GRF_SOC_CON2, 0x03000200); //TESTEN   =0,TESETCLK=1
#if (LANE_NUMBER == 1)
    WRITE_MIPI_REG(GRF_BASE_MIPI, GRF_SOC_CON3, 0x00030000); //ENABLE_0 =0,ENABLE_1=0
#elif (LANE_NUMBER == 2)
    WRITE_MIPI_REG(GRF_BASE_MIPI, GRF_SOC_CON3, 0x00030002); //ENABLE_0 =1,ENABLE_1=0
#elif (LANE_NUMBER == 4)
    WRITE_MIPI_REG(GRF_BASE_MIPI, GRF_SOC_CON3, 0x00030003); //ENABLE_0 =1,ENABLE_1=1
#endif
    WRITE_MIPI_REG(ISP_BASE_MIPI, 0x1c00, 0x00042f01);   //SHUTDOWNZ=1
    //WriteReg32(ISP_BASE+0x1c00,0x00042f01);   //RSTZ     =1

    return 0;
}

static ret_err_t rk_rtthread_mipi_dphy_control(rk_device *dev,
        dt_cmd_t cmd,
        void *args)
{
    struct rk_mipi_dphy_device *mipi;
    ret_err_t ret;
    uint32_t phy_index = *(uint32_t *)args;

    MIPI_DBG("(%s) enter \n", __FUNCTION__);

    RT_ASSERT(dev != RK_NULL);
    mipi = (struct rk_mipi_dphy_device *)dev;

    if (cmd == 0)
    {
        mipi->csi_phy[phy_index].data_en_bit = 0;
    }
    else
    {
        mipi->csi_phy[phy_index].data_en_bit = 2; /* default mipi lane num is 2 */
    }
    rk_csi_phy_cfg(&mipi->csi_phy[phy_index]);

    MIPI_DBG("(%s) exit \n", __FUNCTION__);

    return ret;
}

#if 0
static ret_err_t rk_rtthread_mipi_dphy_init(rk_device *dev)
{
    struct rk_mipi_dphy_device *mipi;

    MIPI_DBG("(%s) enter \n", __FUNCTION__);
    RT_ASSERT(dev != RK_NULL);

    mipi = (struct rk_mipi_dphy_device *)dev;
    if (mipi->ops->init)
    {
        return (mipi->ops->init(mipi));
    }

    MIPI_DBG("(%s) exit \n", __FUNCTION__);

    return RT_ENOSYS;
}

static ret_err_t rk_rtthread_mipi_dphy_open(rk_device *dev, rt_uint16_t oflag)
{
    struct rk_mipi_dphy_device *mipi;

    MIPI_DBG("(%s) enter \n", __FUNCTION__);
    RT_ASSERT(dev != RK_NULL)

    mipi = (struct rk_mipi_dphy_device *)dev;
    if (mipi->ops->open)
    {
        return (mipi->ops->open(mipi, RT_DEVICE_OFLAG_RDWR));
    }

    MIPI_DBG("(%s) exit \n", __FUNCTION__);

    return RT_ENOSYS;
}

static ret_err_t rk_rtthread_mipi_dphy_close(rk_device *dev)
{
    struct rk_mipi_dphy_device *mipi;

    VIP_DBG("(%s) enter \n", __FUNCTION__);

    RT_ASSERT(dev != RK_NULL);

    mipi = (struct rk_mipi_dphy_device *)dev;
    if (mipi->ops->close)
    {
        return mipi->ops->close(mipi);
    }

    VIP_DBG("(%s) exit \n", __FUNCTION__);

    return RT_ENOSYS;
}
#endif

const static struct rt_device_ops rk_mipi_dphy_dev_ops =
{
    RK_NULL,
    RK_NULL,
    RK_NULL,
    RK_NULL,
    RK_NULL,
    rk_rtthread_mipi_dphy_control
};

int rk_rtthread_mipi_dphy_register(void)
{
    int ret;
    rk_device *device;
    struct rk_mipi_dphy_device *mipi;

    MIPI_DBG("(%s) enter \n", __FUNCTION__);

    mipi = rt_calloc(1, sizeof(*mipi));
    RT_ASSERT(mipi != RK_NULL);

    device = &(mipi->dev);

    device->type = RT_Device_Class_Miscellaneous;
    device->rx_indicate = RK_NULL;
    device->tx_complete = RK_NULL;

#ifdef RT_USING_DEVICE_OPS
    device->ops = &rk_mipi_dphy_dev_ops;
#else
    device->init = RK_NULL;
    device->open = RK_NULL;
    device->close = RK_NULL;
    device->read = RK_NULL;
    device->write = RK_NULL;
    device->control = rk_rtthread_mipi_dphy_control;
#endif

    ret = rt_device_register(device, "mipi_dphy", RT_DEVICE_FLAG_RDWR);
    MIPI_DBG("(%s) exit \n", __FUNCTION__);

    return ret;
}
#endif

#if defined(__RT_THREAD__)
INIT_DEVICE_EXPORT(rk_rtthread_mipi_dphy_register);
#endif

#endif
