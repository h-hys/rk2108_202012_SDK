/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */

#include "hal_base.h"
#include "hal_bsp.h"

#if defined(HAL_HYPERPSRAM_MODULE_ENABLED) || defined(HAL_QPIPSRAM_MODULE_ENABLED)
#include "test_psram.h"

#define PROGRESSLEN   4
#define PROGRESSOFTEN 2500
#define ONE           0x00000001L
#define UL_ONEBITS    0xffffffff
#define UL_LEN        32
#define CHECKERBOARD1 0x55555555
#define CHECKERBOARD2 0xaaaaaaaa
#define UL_BYTE(x)    ((x | x << 8 | x << 16 | x << 24))

union {
    unsigned char bytes[UL_LEN / 8];
    uint32_t val;
} mword8;

union {
    unsigned short u16s[UL_LEN / 16];
    uint32_t val;
} mword16;

uint16_t MarchC_data[] = { 0x0000, 0xffff, 0x5555, 0xaaaa, 0x3333, 0xcccc,
                           0x0f0f, 0xf0f0, 0x00ff, 0xff00 };

/*unsigned int rand_r(unsigned int *seedp)
{
    *seedp ^= (*seedp << 13);
    *seedp ^= (*seedp >> 17);
    *seedp ^= (*seedp << 5);

    return *seedp;
}

unsigned int rand(void)
{
    return rand_r(&y);
}
*/
#define rand32()  ((unsigned int)rand() | ((unsigned int)rand() << 16))
#define rand_ul() rand32()

static int test_random_value(uint32_t *bufa, uint32_t *bufb, uint32_t count);
static int test_xor_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count);
static int test_sub_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count);
static int test_mul_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count);
static int test_div_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count);
static int test_or_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count);
static int test_and_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count);
static int test_seqinc_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count);
static int test_solidbits_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count);
static int test_blockseq_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count);
static int test_checkerboard_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count);
static int test_bitspread_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count);
static int test_bitflip_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count);
static int test_walkbits1_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count);
static int test_walkbits0_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count);
static int test_8bit_wide_random(uint32_t *bufa, uint32_t *bufb, uint32_t count);
static int test_16bit_wide_random(uint32_t *bufa, uint32_t *bufb, uint32_t count);

struct psram_test tests[] =
{
    { "Random Value", test_random_value },
    { "Compare XOR", test_xor_comparison },
    { "Compare SUB", test_sub_comparison },
    { "Compare MUL", test_mul_comparison },
    { "Compare DIV", test_div_comparison },
    { "Compare OR", test_or_comparison },
    { "Compare AND", test_and_comparison },
    { "Sequential Increment", test_seqinc_comparison },
    { "Solid Bits", test_solidbits_comparison },
    { "Block Sequential", test_blockseq_comparison },
    { "Checkerboard", test_checkerboard_comparison },
    { "Bit Spread", test_bitspread_comparison },
    { "Bit Flip", test_bitflip_comparison },
    { "Walking Ones", test_walkbits1_comparison },
    { "Walking Zeroes", test_walkbits0_comparison },
    { "8-bit Writes", test_8bit_wide_random },
    { "16-bit Writes", test_16bit_wide_random },
    { NULL, NULL }
};

static int compare_regions(uint32_t *bufa, uint32_t *bufb, size_t count)
{
    int ret = 0;
    uint32_t i;
    uint32_t *p1 = bufa;
    uint32_t *p2 = bufb;

#ifdef HAL_DCACHE_MODULE_ENABLED
    HAL_DCACHE_CleanInvalidate();
#endif
    for (i = 0; i < count; i++, p1++, p2++) {
        if (*p1 != *p2) {
            printf(
                "FAILURE: 0x%08lx != 0x%08lx at offset 0x%08lx. addr:%p or %p\n",
                (uint32_t)*p1, (uint32_t)*p2,
                (uint32_t)(i * sizeof(uint32_t)), bufa + i, bufb + i);
            ret = PSRAM_MEMTESTER_ERR;
        }
    }

    return ret;
}

static int test_random_value(uint32_t *bufa, uint32_t *bufb, uint32_t count)
{
    uint32_t i;
    uint32_t *p1 = bufa;
    uint32_t *p2 = bufb;

    for (i = 0; i < count; i++)
        *p1++ = *p2++ = rand_ul();

    return compare_regions(bufa, bufb, count);
}

static int test_xor_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count)
{
    uint32_t *p1 = bufa;
    uint32_t *p2 = bufb;
    uint32_t i;
    uint32_t q = rand_ul();

    for (i = 0; i < count; i++) {
        *p1++ ^= q;
        *p2++ ^= q;
    }

    return compare_regions(bufa, bufb, count);
}

static int test_sub_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count)
{
    uint32_t *p1 = bufa;
    uint32_t *p2 = bufb;
    uint32_t i;
    uint32_t q = rand_ul();

    for (i = 0; i < count; i++) {
        *p1++ -= q;
        *p2++ -= q;
    }

    return compare_regions(bufa, bufb, count);
}

static int test_mul_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count)
{
    uint32_t *p1 = bufa;
    uint32_t *p2 = bufb;
    uint32_t i;
    uint32_t q = rand_ul();

    for (i = 0; i < count; i++) {
        *p1++ *= q;
        *p2++ *= q;
    }

    return compare_regions(bufa, bufb, count);
}

static int test_div_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count)
{
    uint32_t *p1 = bufa;
    uint32_t *p2 = bufb;
    uint32_t i;
    uint32_t q = rand_ul();

    for (i = 0; i < count; i++) {
        if (!q)
            q++;
        *p1++ /= q;
        *p2++ /= q;
    }

    return compare_regions(bufa, bufb, count);
}

static int test_or_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count)
{
    uint32_t *p1 = bufa;
    uint32_t *p2 = bufb;
    uint32_t i;
    uint32_t q = rand_ul();

    for (i = 0; i < count; i++) {
        *p1++ |= q;
        *p2++ |= q;
    }

    return compare_regions(bufa, bufb, count);
}

static int test_and_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count)
{
    uint32_t *p1 = bufa;
    uint32_t *p2 = bufb;
    uint32_t i;
    uint32_t q = rand_ul();

    for (i = 0; i < count; i++) {
        *p1++ &= q;
        *p2++ &= q;
    }

    return compare_regions(bufa, bufb, count);
}

static int test_seqinc_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count)
{
    uint32_t *p1 = bufa;
    uint32_t *p2 = bufb;
    uint32_t i;
    uint32_t q = rand_ul();

    for (i = 0; i < count; i++)
        *p1++ = *p2++ = (i + q);

    return compare_regions(bufa, bufb, count);
}
static int test_solidbits_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count)
{
    uint32_t *p1 = bufa;
    uint32_t *p2 = bufb;
    uint32_t j;
    uint32_t q;
    uint32_t data[4];
    uint32_t i;

    for (j = 0; j < 64; j++) {
        q = (j % 2) == 0 ? 0xffffffff : 0;

        data[0] = data[2] = q;
        data[1] = data[3] = ~q;

        p1 = (uint32_t *)bufa;
        p2 = (uint32_t *)bufb;
        for (i = 0; i < count; i++)
            *p1++ = *p2++ = data[i & 3];
        if (compare_regions(bufa, bufb, count))
            return PSRAM_MEMTESTER_ERR;
    }

    return 0;
}

static int test_blockseq_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count)

{
    uint32_t *p1 = bufa;
    uint32_t *p2 = bufb;
    uint32_t j;
    uint32_t data[4];
    uint32_t q;
    uint32_t i;

    for (j = 0; j < 256; j++) {
        p1 = (uint32_t *)bufa;
        p2 = (uint32_t *)bufb;
        q = (uint32_t)UL_BYTE(j);

        data[0] = q;
        data[1] = q;
        data[2] = q;
        data[3] = q;

        for (i = 0; i < count; i++)
            *p1++ = *p2++ = data[i & 3];

        if (compare_regions(bufa, bufb, count))
            return PSRAM_MEMTESTER_ERR;
    }

    return 0;
}

static int test_checkerboard_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count)
{
    uint32_t *p1 = bufa;
    uint32_t *p2 = bufb;
    uint32_t j;
    uint32_t q;
    uint32_t data[4];
    uint32_t i;

    for (j = 0; j < 64; j++) {
        q = (j % 2) == 0 ? CHECKERBOARD1 : CHECKERBOARD2;
        data[0] = data[2] = q;
        data[1] = data[3] = ~q;

        p1 = (uint32_t *)bufa;
        p2 = (uint32_t *)bufb;
        for (i = 0; i < count; i++)
            *p1++ = *p2++ = data[i & 3];

        if (compare_regions(bufa, bufb, count))
            return PSRAM_MEMTESTER_ERR;
    }

    return 0;
}

static int test_bitspread_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count)
{
    uint32_t *p1 = bufa;
    uint32_t *p2 = bufb;
    uint32_t j;
    uint32_t data[4];
    uint32_t i;

    for (j = 0; j < UL_LEN * 2; j++) {
        p1 = (uint32_t *)bufa;
        p2 = (uint32_t *)bufb;

        if (j < UL_LEN) {
            data[0] = (ONE << j) | (ONE << (j + 2));
            data[1] = UL_ONEBITS ^ ((ONE << j) | (ONE << (j + 2)));
        } else {
            data[0] = (ONE << (UL_LEN * 2 - 1 - j)) |
                      (ONE << (UL_LEN * 2 + 1 - j));
            data[1] = UL_ONEBITS ^ (ONE << (UL_LEN * 2 - 1 - j)
                                    | (ONE << (UL_LEN * 2 + 1 - j)));
        }
        data[2] = data[0];
        data[3] = data[1];

        for (i = 0; i < count; i++) {
            *p1++ = *p2++ = data[i & 3];
        }

        if (compare_regions(bufa, bufb, count))
            return PSRAM_MEMTESTER_ERR;
    }

    return 0;
}

static int test_bitflip_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count)
{
    uint32_t *p1 = bufa;
    uint32_t *p2 = bufb;
    uint32_t j, k;
    uint32_t q;
    uint32_t data[4];
    uint32_t i;

    for (k = 0; k < UL_LEN; k++) {
        q = ONE << k;
        for (j = 0; j < 8; j++) {
            q = ~q;

            data[0] = data[2] = q;
            data[1] = data[3] = ~q;

            p1 = (uint32_t *)bufa;
            p2 = (uint32_t *)bufb;
            for (i = 0; i < count; i++)
                *p1++ = *p2++ = data[i & 3];
            if (compare_regions(bufa, bufb, count))
                return PSRAM_MEMTESTER_ERR;
        }
    }

    return 0;
}

static int test_walkbits1_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count)
{
    uint32_t *p1 = bufa;
    uint32_t *p2 = bufb;
    uint32_t j;
    uint32_t data[4];
    uint32_t q;
    uint32_t i;

    for (j = 0; j < UL_LEN * 2; j++) {
        p1 = (uint32_t *)bufa;
        p2 = (uint32_t *)bufb;
        if (j < UL_LEN)
            q = UL_ONEBITS ^ (ONE << j);
        else
            q = UL_ONEBITS ^ (ONE << (UL_LEN * 2 - j - 1));

        data[0] = q;
        data[1] = q;
        data[2] = q;
        data[3] = q;

        for (i = 0; i < count; i++) {
            *p1++ = *p2++ = data[i & 3];
        }
        if (compare_regions(bufa, bufb, count))
            return PSRAM_MEMTESTER_ERR;
    }

    return 0;
}

static int test_walkbits0_comparison(uint32_t *bufa, uint32_t *bufb, uint32_t count)
{
    uint32_t *p1 = bufa;
    uint32_t *p2 = bufb;
    uint32_t j;
    uint32_t data[4];
    uint32_t q;
    uint32_t i;

    for (j = 0; j < UL_LEN * 2; j++) {
        p1 = (uint32_t *)bufa;
        p2 = (uint32_t *)bufb;

        if (j < UL_LEN)
            q = ONE << j;
        else
            q = ONE << (UL_LEN * 2 - j - 1);

        data[0] = q;
        data[1] = q;
        data[2] = q;
        data[3] = q;

        for (i = 0; i < count; i++) {
            *p1++ = *p2++ = data[i & 3];
        }

        if (compare_regions(bufa, bufb, count))
            return PSRAM_MEMTESTER_ERR;
    }

    return 0;
}

static int test_8bit_wide_random(uint32_t *bufa, uint32_t *bufb, uint32_t count)
{
    uint8_t *p1, *t;
    uint32_t *p2;
    int attempt;
    uint32_t b;
    uint32_t i;

    for (attempt = 0; attempt < 2; attempt++) {
        if (attempt & 1) {
            p1 = (uint8_t *)bufa;
            p2 = bufb;
        } else {
            p1 = (uint8_t *)bufb;
            p2 = bufa;
        }
        for (i = 0; i < count; i++) {
            t = mword8.bytes;
            *p2++ = mword8.val = rand_ul();
            for (b = 0; b < UL_LEN / 8; b++)
                *p1++ = *t++;
        }
        if (compare_regions(bufa, bufb, count))
            return PSRAM_MEMTESTER_ERR;
    }

    return 0;
}

static int test_16bit_wide_random(uint32_t *bufa, uint32_t *bufb, uint32_t count)
{
    uint16_t *p1, *t;
    uint32_t *p2;
    int attempt;
    uint32_t b, i;

    for (attempt = 0; attempt < 2; attempt++) {
        if (attempt & 1) {
            p1 = (uint16_t *)bufa;
            p2 = bufb;
        } else {
            p1 = (uint16_t *)bufb;
            p2 = bufa;
        }
        for (i = 0; i < count; i++) {
            t = mword16.u16s;
            *p2++ = mword16.val = rand_ul();
            for (b = 0; b < UL_LEN / 16; b++)
                *p1++ = *t++;
        }
        if (compare_regions(bufa, bufb, count))
            return PSRAM_MEMTESTER_ERR;
    }

    return 0;
}

HAL_Status PSRAM_Memtester(uint32_t start, uint32_t length)
{
    uint32_t i, count;
    uint32_t *p1, *p2;
    int ret = 0;

    p1 = (uint32_t *)start;
    p2 = (uint32_t *)(start + length / 2);
    count = length / 2 / sizeof(uint32_t);

    HAL_DBG("\n");
    for (i = 0;; i++) {
        if (!tests[i].name)
            break;
        HAL_DBG("      %s: \n", tests[i].name);
    #ifdef HAL_DCACHE_MODULE_ENABLED
        HAL_DCACHE_CleanInvalidate();
    #endif
        ret = tests[i].fp(p1, p2, count);
        if (!ret) {
            HAL_DBG("        ok\n");
        } else {
            HAL_DBG("        fail\n");

            return HAL_ERROR;
        }
    }

    return HAL_OK;
}

HAL_Status PSRAM_MarchCTest(uint32_t start, uint32_t length)
{
    uint32_t i, j, k, l;
    uint16_t wr_data;
    uint16_t *p1 = (uint16_t *)start;

    for (j = 0; j < 10; j += 2) {
        p1 = (uint16_t *)start;

        /* March C- M0 section */
        for (i = 0; i < length; i += 2, p1++)
            *p1 = MarchC_data[0 + j];

        /* March C- M1~M4 section */
        for (l = 0; l < 2; l++) {
            for (k = 0; k < 2; k++) {
                if (l)
                    p1 = (uint16_t *)(start + length - 2);
                else
                    p1 = (uint16_t *)start;
            #ifdef HAL_DCACHE_MODULE_ENABLED
                HAL_DCACHE_CleanInvalidate();
            #endif
                for (i = 0; i < length; i += 2) {
                    if (*p1 == MarchC_data[0 + j + k]) {
                        *p1 = MarchC_data[1 + j - k];
                    } else {
                        wr_data = MarchC_data[0 + j + k];
                        goto err;
                    }
                    if (l)
                        p1--;
                    else
                        p1++;
                }
            }
        }

        p1 = (uint16_t *)start;
    #ifdef HAL_DCACHE_MODULE_ENABLED
        HAL_DCACHE_CleanInvalidate();
    #endif
        /* March C- M5 section */
        for (i = 0; i < length; i += 2, p1++) {
            if (*p1 != MarchC_data[0 + j]) {
                wr_data = MarchC_data[0 + j];
                goto err;
            }
        }
    }

    return HAL_OK;

err:
    HAL_DBG(
        "FAILURE: 0x%04x != 0x%04x at 0x%08lx.\n",
        wr_data, (uint16_t)*p1,
        (uint32_t)p1);

    return HAL_ERROR;
}

#endif
