/*
 * Copyright (c) 2020 Rockchip Electronics Co. Ltd.
 * Author: Chris Zhong <zyw@rock-chips.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "iomap.h"
#include "typedef.h"
#include "delay.h"
#include "trace.h"

#define __O     volatile             /*!< \brief Defines 'write only' permissions */
#define __IO    volatile             /*!< \brief Defines 'read / write' permissions */
#define __I     volatile const       /*!< \brief Defines 'read only' permissions */

#define SFC_BUSY BIT(0)

/* FSPI Register Structure Define */
struct FSPI_REG
{
    __IO uint32_t CTRL0;                /* Address Offset: 0x0000 */
    __IO uint32_t IMR;              /* Address Offset: 0x0004 */
    __O  uint32_t ICLR;             /* Address Offset: 0x0008 */
    __IO uint32_t FTLR;             /* Address Offset: 0x000C */
    __IO uint32_t RCVR;             /* Address Offset: 0x0010 */
    __IO uint32_t AX0;              /* Address Offset: 0x0014 */
    __IO uint32_t ABIT0;                /* Address Offset: 0x0018 */
    __IO uint32_t ISR;              /* Address Offset: 0x001C */
    __IO uint32_t FSR;              /* Address Offset: 0x0020 */
    __I  uint32_t SR;               /* Address Offset: 0x0024 */
    __I  uint32_t RISR;             /* Address Offset: 0x0028 */
    __I  uint32_t VER;              /* Address Offset: 0x002C */
    __IO uint32_t QOP;              /* Address Offset: 0x0030 */
    __IO uint32_t EXT_CTRL;             /* Address Offset: 0x0034 */
    __IO uint32_t POLL_CTRL;                /* Address Offset: 0x0038 */
    __IO uint32_t DLL_CTRL0;                /* Address Offset: 0x003C */
    __IO uint32_t HRDYMASK;             /* Address Offset: 0x0040 */
    __IO uint32_t EXT_AX;               /* Address Offset: 0x0044 */
    __IO uint32_t SCLK_INATM_CNT;           /* Address Offset: 0x0048 */
    __IO uint32_t AUTO_RF_CNT;          /* Address Offset: 0x004C */
    __O  uint32_t XMMC_WCMD0;           /* Address Offset: 0x0050 */
    __O  uint32_t XMMC_RCMD0;           /* Address Offset: 0x0054 */
    __IO uint32_t XMMC_CTRL;                /* Address Offset: 0x0058 */
    __IO uint32_t MODE;             /* Address Offset: 0x005C */
    __IO uint32_t DEVRGN;               /* Address Offset: 0x0060 */
    __IO uint32_t DEVSIZE0;             /* Address Offset: 0x0064 */
    __IO uint32_t TME0;             /* Address Offset: 0x0068 */
    __IO uint32_t POLLDLY_CTRL;         /* Address Offset: 0x006C */
    uint32_t RESERVED0070[4];            /* Address Offset: 0x0070 */
    __O  uint32_t DMATR;                /* Address Offset: 0x0080 */
    __IO uint32_t DMAADDR;              /* Address Offset: 0x0084 */
    uint32_t RESERVED0088[2];            /* Address Offset: 0x0088 */
    __I  uint32_t POLL_DATA;                /* Address Offset: 0x0090 */
    __IO uint32_t XMMCSR;               /* Address Offset: 0x0094 */
    uint32_t RESERVED0098[26];           /* Address Offset: 0x0098 */
    __O  uint32_t CMD;              /* Address Offset: 0x0100 */
    __O  uint32_t ADDR;             /* Address Offset: 0x0104 */
    __IO uint32_t DATA;             /* Address Offset: 0x0108 */
    uint32_t RESERVED010C[61];           /* Address Offset: 0x010C */
    __IO uint32_t CTRL1;                /* Address Offset: 0x0200 */
    uint32_t RESERVED0204[4];            /* Address Offset: 0x0204 */
    __IO uint32_t AX1;              /* Address Offset: 0x0214 */
    __IO uint32_t ABIT1;                /* Address Offset: 0x0218 */
    uint32_t RESERVED021C[8];            /* Address Offset: 0x021C */
    __IO uint32_t DLL_CTRL1;                /* Address Offset: 0x023C */
    uint32_t RESERVED0240[4];            /* Address Offset: 0x0240 */
    __O  uint32_t XMMC_WCMD1;           /* Address Offset: 0x0250 */
    __O  uint32_t XMMC_RCMD1;           /* Address Offset: 0x0254 */
    uint32_t RESERVED0258[3];            /* Address Offset: 0x0258 */
    __IO uint32_t DEVSIZE1;             /* Address Offset: 0x0264 */
    __IO uint32_t TME1;             /* Address Offset: 0x0268 */
};

#define WRITE_REG(REG, VAL)  ((*(volatile uint32_t *)&(REG)) = (VAL))
#define READ_REG(REG)        ((*(volatile uint32_t *)&(REG)))

int snor_read_uuid(uint32_t reg, uint8_t *data, uint8_t len)
{
    uint32_t words;
    uint32_t timeout, *p_data;
    struct FSPI_REG *p_reg = (struct FSPI_REG *)reg;
    int ret;

    if (len & 0x3)
    {
        return -1;
    }

    words = len >> 2;
    p_data = (uint32_t *)data;

    WRITE_REG(p_reg->CTRL0, 2);
    WRITE_REG(p_reg->CMD, (len) << 16 | 2 << 14 | 0x4B);
    WRITE_REG(p_reg->ADDR, 0);
    timeout = 0;
    while (words)
    {
        if (((READ_REG(p_reg->FSR) >> 16) & 0x1f) > 0)
        {
            *p_data++ = READ_REG(p_reg->DATA);
            words--;
            timeout = 0;
        }
        else
        {
            udelay(1);
            if (timeout++ > 10000)
            {
                ret = -1;
                break;
            }
        }
    }
    timeout = 0;
    while (READ_REG(p_reg->SR) & 1)
    {
        udelay(1);
        if (timeout++ > 100000)
        {
            ret = -1;
            break;
        }
    }
    udelay(1); /* CS# High Time (read/write) >100ns */

    return ret;
}

int snor_key_verify(void *key)
{
    unsigned char uuid[8];
    int i;

    snor_read_uuid(FSPI0_BASE, uuid, 8);
    print_to_uart("uuid = ");
    for (i = 0; i < 8; i++)
        print_to_uart("%x ", uuid[i]);
    print_to_uart("\n");

    /* TODO: verify key */
    return 1;
}
