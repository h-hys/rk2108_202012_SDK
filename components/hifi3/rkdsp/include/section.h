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

#ifndef __SECTION_H__
#define __SECTION_H__

#include <asm-dsp.h>

#define SECT(name) name

#define __DATA_NAME(name) ".DSECT "SECT(name)
#define __CODE_NAME(name) ".CSECT "SECT(name)

#define __GET_DATA_NAME(name) __DATA_NAME(#name)
#define __GET_CODE_NAME(name) __CODE_NAME(#name)

#if CONFIG_SOC_RK2108
#  if CONFIG_XIP_CODE
#    define CODE(name) __attribute__ ((section((".srom.text"))))
#  else
#    define CODE(name) __attribute__ ((section((".iram0.text"))))
#  endif
#  define DATA(name) __attribute__ ((section((".dram0.data"))))
#  if CONFIG_XIP_DATA
#    define DATA_ROM   __attribute__ ((section((".srom.rodata"))))
#    define CODE_ROM   __attribute__ ((section((".srom.text"))))
#  else
#    define DATA_ROM   __attribute__ ((section((".sram.rodata"))))
#    define CODE_ROM   __attribute__ ((section((".sram.text"))))
#  endif
#else
#  if ENABLE_SPEECH_AEC
#    define CODE(name) __attribute__ ((section((".sram.text"))))
#    define DATA(name) __attribute__ ((section((".psram.data"))))
#    define DATA_ROM   __attribute__ ((section((".psram.rodata"))))
#  else
#    if ENABLE_LITE_WAKEUP
#      define CODE(name) __attribute__ ((section((".sram.text"))))
#    else
#      define CODE(name) __attribute__ ((section((".iram0.text"))))
#    endif
#    define DATA(name) __attribute__ ((section((".dram0.data"))))
#    define DATA_ROM   __attribute__ ((section((".sram.rodata"))))
#  endif
#endif

#if CONFIG_VERSION_CHECK
#define INFO     __attribute__ ((section((".dram0.info.data"))))
#define INFO_ROM __attribute__ ((section((".srom.info.rodata"))))
#endif

#define ALIGN_16 __attribute__ ((aligned (16)))
#define ALIGN_32 __attribute__ ((aligned (32)))
#define ALIGN_64 __attribute__ ((aligned (64)))

#define __interrupt __attribute__((interrupt))

#define CODE_INIT       CODE(code_init)
#define DATA_INIT       CODE(data_init)
#define CODE_EXT        CODE(code_ext)
#define DATA_EXT        DATA(data_ext)
#define CODE_INT        CODE(code_int)
#define DATA_INT        DATA(data_int)
#define DEBUG_DUMP      DATA(debug_dump)

// System section definitions
#define __init__         CODE_INIT
#define __init_data__    DATA_INIT
#define __sys__          CODE_EXT
#define __sys_data__     DATA_EXT
#define __driver__       CODE_INT
#define __driver_data__  DATA_INT
#define __debug_dump__   DEBUG_DUMP

#define __rom_data__     DATA_ROM
#define __rom_code__     CODE_ROM

#if CONFIG_VERSION_CHECK
#define __sys_info__     INFO
#define __rom_info__     INFO_ROM
#endif

// Algorithm section definitions
#define __test__       CODE(code_test)
#define __test_ext__   CODE(code_ext_test)
#define __test_data__  DATA(data_test)

#endif
