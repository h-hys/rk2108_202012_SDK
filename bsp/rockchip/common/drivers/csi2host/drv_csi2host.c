/**
  * Copyright (c) 2019 Rockchip Electronic Co.,Ltd
  *
  * SPDX-License-Identifier: Apache-2.0
  ******************************************************************************
  * @file    drv_csi2host.c
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
#include "drv_csi2host.h"
#elif defined(__RK_OS__)
#include "driver/drv_csi2host.h"
#endif

#ifdef RT_USING_CSI2HOST

#define CSI2HOST_DEBUG 1
#if CSI2HOST_DEBUG
#include <stdio.h>
#define CSI2HOST_DBG(...) rt_kprintf("[CSI2HOST]:");rt_kprintf(__VA_ARGS__)
#else
#define CSI2HOST_DBG(...)
#endif

typedef volatile unsigned int       REG32;

#define      CSI2_HOST_VERSION_OS                 0x000
#define      CSI2_HOST_N_LANES_QST_OS             0x004
#define      CSI2_HOST_PHY_SHUTDOWNZ_OS           0x008
#define      CSI2_HOST_DPHY_RSTZ_OS               0x00C
#define      CSI2_HOST_CSI2_RESETN_OS             0x010
#define      CSI2_HOST_PHY_STATE_OS               0x014
#define      CSI2_HOST_DATA_IDS_1_OS              0x018
#define      CSI2_HOST_DATA_IDS_2_OS              0x01C
#define      CSI2_HOST_ERR1_OS                    0x020
#define      CSI2_HOST_ERR2_OS                    0x024
#define      CSI2_HOST_MASK1_OS                   0x028
#define      CSI2_HOST_MASK2_OS                   0x02C
#define      CSI2_HOST_PHY_TEST_CTRL0_OS          0x030
#define      CSI2_HOST_PHY_TEST_CTRL1_OS          0x034
#define      CSI2_HOST_CONTROL_OS                 0x040

#define WriteReg32(addr, data)              (*(REG32 *)(addr) = data)
#define ReadReg32(addr)                     (*(REG32 *)(addr))
#define WriteReg32(addr, data)              (*(REG32 *)(addr) = data)
#define SetRegBits32(addr, databit)         WriteReg32(addr, ReadReg32(addr)|(databit))
#define ClrRegBits32(addr, databit)         WriteReg32(addr, ReadReg32(addr)&~(databit))
#define SetRegBit32(addr,bit)               WriteReg32(addr,(ReadReg32(addr)|(1<<bit)))
#define ClrRegBit32(addr,bit)               WriteReg32(addr,(ReadReg32(addr)&(~(1<<bit))))
#define GetRegBit32(addr,bit)               (ReadReg32(addr)&(1<<bit))
#define MaskRegBits32(addr, y, z)           WriteReg32(addr, (ReadReg32(addr)&~(y))|(z))

#define GRF_SOC_CON4                         0x00210

struct rk_csi2host_device csi2host_instance;

///////////////////////////////////////////////////////////////////////////
static void MIPI_DPHY1_RX_WriteReg(uint8_t addr, uint8_t data)
{
    SetRegBit32(CSI2HOST_BASE + CSI2_HOST_PHY_TEST_CTRL0_OS, 1); //TESTCLK=1
    WriteReg32(CSI2HOST_BASE + CSI2_HOST_PHY_TEST_CTRL1_OS, 0x10000 | addr); //TESTDIN=addr
    //TESTEN =1
    ClrRegBit32(CSI2HOST_BASE + CSI2_HOST_PHY_TEST_CTRL0_OS, 1); //TESTCLK=0
    WriteReg32(CSI2HOST_BASE + CSI2_HOST_PHY_TEST_CTRL1_OS, 0x00000); //TESTEN =0
    ClrRegBit32(CSI2HOST_BASE + CSI2_HOST_PHY_TEST_CTRL0_OS, 1); //TESTCLK=0

    WriteReg32(CSI2HOST_BASE + CSI2_HOST_PHY_TEST_CTRL1_OS, 0x10000 | data); //TESTDIN=data                                                                          //TESTCLK=1
}

///////////////////////////////////////////////////////////////////////////
static uint8_t MIPI_DPHY1_RX_ReadReg(uint8_t addr)
{
    uint8_t data;
    WriteReg32(CSI2HOST_BASE + CSI2_HOST_PHY_TEST_CTRL1_OS, 0x10000 | addr); //TESTEN =1,TESTDIN=addr
    ClrRegBit32(CSI2HOST_BASE + CSI2_HOST_PHY_TEST_CTRL0_OS, 1); //TESTCLK=0,TESTDIN=addr
    data = ReadReg32((CSI2HOST_BASE + CSI2_HOST_PHY_TEST_CTRL1_OS) >> 8) & 0xff;
    WriteReg32(CSI2HOST_BASE + CSI2_HOST_PHY_TEST_CTRL1_OS, 0x00000);
    SetRegBit32(CSI2HOST_BASE + CSI2_HOST_PHY_TEST_CTRL0_OS, 1); //TESTEN =0,TESETCLK=1
    //printf("REG addr=0x%x, data=0x%x\n",addr,data);

    return data;
}


rt_err_t rk_rtthread_csi2host_control(rt_device_t dev,
                                      int cmd,
                                      void *args)
{
    int lane_num = *(int *)args;
    WriteReg32(CSI2HOST_BASE + CSI2_HOST_DPHY_RSTZ_OS, 0x00); //RSTZ     =0
    WriteReg32(CSI2HOST_BASE + CSI2_HOST_PHY_SHUTDOWNZ_OS, 0x00); //SHUTDOWNZ=0

    SetRegBit32(CSI2HOST_BASE + CSI2_HOST_PHY_TEST_CTRL0_OS, 1); //TESTCLK=1
    SetRegBit32(CSI2HOST_BASE + CSI2_HOST_PHY_TEST_CTRL0_OS, 0); //TESTCLR=1
    ClrRegBit32(CSI2HOST_BASE + CSI2_HOST_PHY_TEST_CTRL0_OS, 1); //TESTCLR=0
    WriteReg32(CRU_BASE + 0x1008, 0x00004000); //RSTZCAL=1

    WriteReg32(CSI2HOST_BASE + CSI2_HOST_PHY_SHUTDOWNZ_OS, 0x01); //SHUTDOWNZ=1
    WriteReg32(CSI2HOST_BASE + CSI2_HOST_DPHY_RSTZ_OS, 0x01); //RSTZ     =1

//**********************************************************************//
// mipi d-phy cofigure register between //**// lines
// read register value through base addr : 0xFFE00018
    if (lane_num == 1)
    {
        MIPI_DPHY1_RX_WriteReg(0xAC, 0x0); // 1 lane
        //600-650M
        MIPI_DPHY1_RX_WriteReg(0x34, 0x10);
        //MIPI_DPHY1_RX_WriteReg(0x44,0x10);
    }
    else if (lane_num == 2)
    {
        MIPI_DPHY1_RX_WriteReg(0xAC, 0x1); // 2 lane
        //300-330M
        MIPI_DPHY1_RX_WriteReg(0x34, 0x0a);
        MIPI_DPHY1_RX_WriteReg(0x44, 0x0a);
    }
    else if (lane_num == 4)
    {
        MIPI_DPHY1_RX_WriteReg(0xAC, 0x03); // 4 lane
        //200-220M
        MIPI_DPHY1_RX_WriteReg(0x34, 0x06);
        MIPI_DPHY1_RX_WriteReg(0x44, 0x06);
    }

    MIPI_DPHY1_RX_ReadReg(0x00);                    //Normal operation
    WriteReg32(CSI2HOST_BASE + CSI2_HOST_PHY_TEST_CTRL1_OS, 0x00000);
    SetRegBit32(CSI2HOST_BASE + CSI2_HOST_PHY_TEST_CTRL0_OS, 1); //TESTEN   =0,TESETCLK=1
    if (lane_num == 1)
        GRF->SOC_CON4 = 0x03200020; //ENABLE_0 =0,ENABLE_1=0
    else if (lane_num == 2)
        GRF->SOC_CON4 = 0x03200120; //ENABLE_0 =1,ENABLE_1=0
    else if (lane_num == 4)
        GRF->SOC_CON4 = 0x03200320; //ENABLE_0 =1,ENABLE_1=1

    WriteReg32(CSI2HOST_BASE + CSI2_HOST_PHY_SHUTDOWNZ_OS, 0x01); //SHUTDOWNZ=1
    WriteReg32(CSI2HOST_BASE + CSI2_HOST_DPHY_RSTZ_OS, 0x01); //RSTZ     =1

    WriteReg32(CSI2HOST_BASE + CSI2_HOST_N_LANES_QST_OS, 0x0);
    WriteReg32(CSI2HOST_BASE + CSI2_HOST_CSI2_RESETN_OS, 0x1);
    return 0;
}

const static struct rt_device_ops rk_csi2host_dev_ops =
{
    RT_NULL,
    RT_NULL,
    RT_NULL,
    RT_NULL,
    RT_NULL,
    rk_rtthread_csi2host_control
};

int rk_rtthread_csi2host_register(void)
{
    int ret;
    rt_device_t device;
    struct rk_csi2host_device *csi2host = &csi2host_instance;

    CSI2HOST_DBG("(%s) enter \n", __FUNCTION__);

    device = &(csi2host->dev);

    device->type        = RT_Device_Class_Miscellaneous;
    device->rx_indicate = RT_NULL;
    device->tx_complete = RT_NULL;

    /* hardware reg addr */
#ifdef RT_USING_DEVICE_OPS
    device->ops         = &rk_csi2host_dev_ops;
#else
    device->init        = RT_NULL;
    device->open        = RT_NULL;
    device->close       = RT_NULL;
    device->read        = RT_NULL;
    device->write       = RT_NULL;
    device->control     = rk_rtthread_csi2host_control;
#endif

    ret = rt_device_register(device, "csi2host", RT_DEVICE_FLAG_RDWR);
    CSI2HOST_DBG("(%s) exit \n", __FUNCTION__);
    return ret;

}

#if defined(__RT_THREAD__)
INIT_DEVICE_EXPORT(rk_rtthread_csi2host_register);
#endif

#endif
