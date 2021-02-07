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

#ifndef __POWER_MANAGE_H__
#define __POWER_MANAGE_H__

#include <stdint.h>

enum gpio_edge {
    EDGE_POS = 0,
    EDGE_NEG,
};

enum sleep_type {
    SLEEP_NOR = 0, /* Sleep normal */
    SLEEP_SYS,     /* Accord to system status to sleep or shutdown */
};

enum pm_wakeup_status {
    WAKEUP_INT = 0,
    WAKEUP_SFT,
    WAKEUP_VAD,
};

enum ldo_vol {
    VOL_0_75    = 0,    /* 0.75v */
    VOL_0_8     = 1,    /* 0.8v  */
    VOL_0_85    = 2,    /* 0.85v */
    VOL_0_9     = 3,    /* 0.9v  */
    VOL_0_95    = 4,    /* 0.95v */
    VOL_1_0     = 5,    /* 1.0v  */
    VOL_1_05    = 6,    /* 1.05v */
    VOL_1_1     = 7,    /* 1.1v  */
    VOL_NO_SET  = 8,
};

#define DSP_TCM_SEL(a) (0x1 << a)
/** dsp tcm sel */
#define    DTCM0 DSP_TCM_SEL(0)    /* 0x30200000 ~ 0x30210000 */
#define    DTCM1 DSP_TCM_SEL(1)    /* 0x30210000 ~ 0x30220000 */
#define    DTCM2 DSP_TCM_SEL(2)    /* 0x30220000 ~ 0x30230000 */
#define    DTCM3 DSP_TCM_SEL(3)    /* 0x30230000 ~ 0x30240000 */
#define    DTCM4 DSP_TCM_SEL(4)    /* 0x30240000 ~ 0x30250000 */
#define    DTCM5 DSP_TCM_SEL(5)    /* 0x30250000 ~ 0x30260000 */
#define    DTCM6 DSP_TCM_SEL(6)    /* 0x30260000 ~ 0x30270000 */
#define    DTCM7 DSP_TCM_SEL(7)    /* 0x30270000 ~ 0x30280000 */
#define    ITCM  DSP_TCM_SEL(8)    /* 0x30000000 ~ 0x30010000 */

#define DSP_PWR_DOWN_VAL           0x12344321
/**
 * enum tcm_mode - dsp memory work mode.
 */
 enum tcm_mode {
    NOR_MODE = 0,
    RET1N_MODE,
    RET2N_MODE,
    PWR_DOWN_MODE
};

#ifdef __cplusplus
extern "C" {
#endif
int pm_set_tcm_mode(uint32_t tcmSel, enum tcm_mode mode, bool isAuto);
enum pm_wakeup_status pm_get_wakeup_status();
void pm_pwrdown_config();
void pm_pwrdown_enable(bool enable);
void pm_sleep(enum sleep_type type);
void pm_set_pwr_state(uint32_t value);
uint32_t pm_get_pwr_state(void);
int pm_wakeup_m4(uint32_t delayMs);
void pm_soft_wakeup();
uint32_t pm_get_m4_status();
void pm_freq_reduce(bool enable);

#ifdef __cplusplus
}
#endif

#endif
