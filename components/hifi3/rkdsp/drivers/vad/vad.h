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

#ifndef __VAD_H__
#define __VAD_H__

#include <stdint.h>

#define VAD_CONTROL           0x0000
#define VAD_RAM_START_ADDR    0x0050
#define VAD_RAM_END_ADDR      0x0054
#define VAD_RAM_CUR_ADDR      0x0058
#define VAD_INT               0x0074
#define VAD_AUX_CONTROL       0x0078
#define VAD_AUX_CONTROL1      0x008c
#define DSP_CON2              0x0168

#define VAD_ENABLE            BIT(0)
#define BUS_WRITE_EN_BIT      BIT(0)
#define DIS_RAM_ITF_BIT       BIT(1)

#define DET_INT_EN_BIT        BIT(0)
#define DET_INT_BIT           BIT(4)
#define DATA_TRANS_INT_EN_BIT BIT(10)
#define DATA_TRANS_INT_BIT    BIT(11)

#define SAMPLE_CNT_EN_BIT     BIT(29)
#define INT_TRIG_CTRL_EN_BIT  BIT(28)
#define INT_TRIG_VALID_THD    16

#define VAD_SPACE_SEL_BIT     (BIT(8) | BIT(9))

enum vad_int_type {
    DET_INT,
    TRANS_INT
};

enum intfc_mode {
    RAM_INTFC = 0, /* DTCM only for vad transfer */
    BUS_INTFC      /* DTCM can access for other unit */
};

typedef void (*vad_callback)(uint32_t data);

#ifdef __cplusplus
extern "C" {
#endif

extern void vad_set_space_sel(uint32_t size);
extern void vad_get_cur_addr(uint32_t *cur_addr);
extern void vad_get_addr(uint32_t *start_addr, uint32_t *end_addr,
                         uint32_t *cur_addr);
extern void vad_swich_mode(enum intfc_mode mode);
extern int vad_init(vad_callback callback);
extern void vad_start(void);
extern void vad_stop(void);
extern void vad_set_period(uint32_t period);
extern void vad_clr_int();
extern void vad_int_thd_enable(uint32_t sample, bool enable);
extern void vad_int_enable(enum vad_int_type type, bool enable);
extern void vad_enable(bool enable);

#ifdef __cplusplus
}
#endif

#endif
