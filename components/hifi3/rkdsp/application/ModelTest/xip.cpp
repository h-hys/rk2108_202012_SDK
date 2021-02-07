/*
 * Copyright (c) 2019 Rockchip Electronics Co. Ltd.
 * Author: Huaping Liao <huaping.liao@rock-chips.com>
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
#include "xip.h"

#include <xtensa/config/core-matmap.h>

#include "cache.h"
#include "io.h"
#include "section.h"
#include "trace.h"
#include "time.h"

#if CONFIG_ENABLE_XIP

#if CONFIG_SOC_RK2108
#define XIP_SRAM_BASE         0x64000000
#define XIP_SNOR_BASE         0x60000000
#define SRAM_SIZE             0x800000
#define SNOR_SIZE             0x1000000    // 16M
#else
#define XIP_SRAM_BASE         0x18000000
#define XIP_SNOR_BASE         0x10000000
#define SRAM_SIZE             0x800000
#define SNOR_SIZE             0x800000    // 16M
#endif

#define maxest_sector         4
#define LBA_SIZE              (4 * 1024)

#if 1
__sys__ int LOGD_HEX(char *s, void *buf, uint32_t width, uint32_t len)
{
    uint32_t i, j;
    unsigned char *p8 = (unsigned char *)buf;
    unsigned short *p16 = (unsigned short *)buf;
    uint32_t *p32 = (uint32_t *)buf;

    j = 0;
    for (i = 0; i < len; i++) {
        if (j == 0) {
            LOGD("[HAL_DBG_HEX] %s %p + 0x%lx:", s, buf, i * width);
        }

        if (width == 4) {
            LOGD("0x%x,", p32[i]);
        } else if (width == 2) {
            LOGD("0x%04x,", p16[i]);
        } else {
            LOGD("0x%02x,", p8[i]);
        }

        if (++j >= 16) {
            j = 0;
            LOGD("\n");
        }
    }
    LOGD("\n");
    return 0;
}
#endif
__sys__ void snor_write_byte(uint32_t addr, uint32_t value)
{
    __writel((void *)(XIP_SNOR_BASE + addr), value);
}

__sys__ uint32_t snor_read_byte(uint32_t addr)
{
    return __readl((void *)(XIP_SNOR_BASE + addr));
}

__sys__ void sram_write_byte(uint32_t addr, uint32_t value)
{
    __writel((void *)(XIP_SNOR_BASE + addr), value);
}

__sys__ uint32_t sram_read_byte(uint32_t addr)
{
    return __readl((void *)(XIP_SNOR_BASE + addr));
}

__sys__ int xip_sram_test(uint32_t addr, uint32_t testEndLBA)
{
    int ret = 0;
    unsigned int i;
    clock_t clock_start, clock_end, clock_tast;

    clock_start = clock();
    for (i = 0; i < testEndLBA * 512; i += 4)
        writel(addr + i, addr + i);
    clock_end = clock();
    clock_tast = (clock_end - clock_start);
    LOGD("write tack = %d\n", clock_tast);
    xthal_dcache_all_writeback_inv();
    clock_start = clock();
    for (i = 0; i < testEndLBA * 512; i += 4)
        if ((readl(addr + i)) != (addr + i)) {
             LOGD("no match, addr = %x, read val = %x\n", addr + i, readl(addr + i));
        }
    clock_end = clock();
    clock_tast = (clock_end - clock_start);
    LOGD("read tack = %d\n", clock_tast);
    if (ret == 0)
        LOGD("xip_sram_test success\n");
    return ret;
}

__sys__ int xip_snor_test(uint32_t addr, uint32_t testEndLBA)
{
    uint32_t i, j;
    uint32_t testLBA = 0;
    uint32_t testSecCount = 1;
    uint32_t printFlag;
    static uint8_t pwrite = (uint8_t)0x30210000;
    static uint8_t *pread;
    static uint32_t *pread32;
    static uint32_t *pwrite32 = (uint32_t *)0x30210000;
    clock_t clock_start, clock_end;
    uint32_t count = 0;

    for (i = 0; i < (maxest_sector * LBA_SIZE) / 4; i++)
        pwrite32[i] = i;

    testSecCount = 1;

    clock_start = clock();
    for (testLBA = 0x200; (testLBA + testSecCount) < testEndLBA;) {
       pwrite32[0] = testLBA;
       pread32 = (uint32_t *)(addr + testLBA * LBA_SIZE);
       for (j = 0; j < testSecCount * (LBA_SIZE / 4); j++) {
           if (pwrite32[j] != pread32[j]) {
               LOGD_HEX("w:", pwrite32, 4, testSecCount * 128);
               LOGD_HEX("r:", pread32, 4, testSecCount * 128);
               LOGD(
                   "xip not match:row=%x, num=%x, write=%x, read=%x\n",
                   testLBA, j, (uint32_t)pwrite32[j], (uint32_t)pread32[j]);

               return -1;
           }
       }
//       printFlag = testLBA & 0x1FF;
//       if (printFlag < testSecCount)
//           LOGD("testLBA = %lx\n", testLBA);
       testLBA += testSecCount;
      // testSecCount++;
       if (testSecCount > maxest_sector)
           testSecCount = 1;
    }
    clock_end = clock();
    LOGD("cycle tack = %d, count %d byte\n", clock_end - clock_start, count);
    LOGD("---------Test end---------\n");

    return 0;

}

__sys__ void xip_test()
{
    xthal_set_region_attribute((void *)0x18000000, SRAM_SIZE * 4, XCHAL_CA_WRITEBACK, 0);
    xthal_set_region_attribute((void *)0x10000000, SNOR_SIZE * 4, XCHAL_CA_WRITEBACK, 0);
    cache_enable();
 //   xthal_set_region_attribute((void *)0x60000000, SRAM_SIZE, XCHAL_CA_WRITEBACK_NOALLOC, 0);
//    xthal_set_region_attribute((void *)0x30000000, SRAM_SIZE, XCHAL_CA_WRITETHRU, 0);
    while(1)
    xip_sram_test(XIP_SRAM_BASE, SRAM_SIZE / 512);
    xip_snor_test(XIP_SNOR_BASE, SNOR_SIZE / LBA_SIZE);
    while(1);
}

#endif
