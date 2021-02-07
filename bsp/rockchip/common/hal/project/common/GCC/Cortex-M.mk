# SPDX-License-Identifier: BSD-3-Clause */

# Copyright (c) 2020 Rockchip Electronics Co., Ltd.

ROOT_PATH	:= ../../..

#############################################################################
# Cross compiler
#############################################################################
ifneq ($(wildcard ${ROOT_PATH}/../prebuilts/gcc-arm-none-eabi-7-2018-q2-update/bin),)
CROSS_COMPILE	?= ${ROOT_PATH}/../prebuilts/gcc-arm-none-eabi-7-2018-q2-update/bin/arm-none-eabi-
else
CROSS_COMPILE	?= arm-none-eabi-
endif

AS		= $(CROSS_COMPILE)as
LD		= $(CROSS_COMPILE)ld
CC		= $(CROSS_COMPILE)gcc
CPP		= $(CC) -E
AR		= $(CROSS_COMPILE)ar
NM		= $(CROSS_COMPILE)nm
STRIP		= $(CROSS_COMPILE)strip
OBJCOPY		= $(CROSS_COMPILE)objcopy
OBJDUMP		= $(CROSS_COMPILE)objdump

CPU		+= -mthumb
ASFLAGS         += $(CPU) -D__ASSEMBLY__
CFLAGS		+= $(CPU) -std=c99 -O2 -g
LDFLAGS		+= $(CPU) -Wl,--gc-sections --specs=nosys.specs -lm -lgcc
OCFLAGS		= -R .note -R .note.gnu.build-id -R .comment -S

HAL_CFLAGS	:= -Wformat=2 -Wall -Wextra -Wno-unused-parameter -Werror
HAL_CFLAGS	+= -Wstrict-prototypes -Wmissing-prototypes

LINKER_SCRIPT	:= $(ROOT_PATH)/lib/CMSIS/Device/$(PROJECT)/Source/Templates/GCC/gcc_arm$(if $(findstring 1,$(XIP)),_xip).ld

#############################################################################
# Output files
#############################################################################
BIN		:= TestDemo.bin
ELF		:= TestDemo.elf
MAP		:= TestDemo.map

#############################################################################
# Options
#############################################################################
QUIET ?= n

ifeq ($(QUIET), y)
  Q := @
  S := -s
endif

#############################################################################
# Source code and include
#############################################################################
INCLUDES := \
-I"../src" \
-I"$(ROOT_PATH)/lib/CMSIS/Core/Include" \

SRC_DIRS := \
    ../src \
    $(ROOT_PATH)/lib/CMSIS/Device/$(PROJECT)/Source/Templates/GCC \

export HAL_PATH := $(ROOT_PATH)
include $(HAL_PATH)/tools/build_lib.mk
include $(HAL_PATH)/tools/build_test.mk
SRC_DIRS += $(HAL_LIB_SRC)
SRC_DIRS += $(HAL_TEST_SRC)
INCLUDES += $(HAL_LIB_INC)
INCLUDES += $(HAL_TEST_INC)

SRCS += $(basename $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.[cS])))
OBJS += $(addsuffix .o,$(basename $(SRCS)))
CFLAGS += $(INCLUDES)
ASFLAGS += $(INCLUDES)

all: $(BIN)

$(ELF): $(OBJS) $(LINKER_SCRIPT)
	$(Q) $(CC) $(OBJS) $(LDFLAGS) $(CFLAGS) -T$(LINKER_SCRIPT) -Wl,-Map=$(MAP),-cref -o $@

$(BIN): $(ELF)
	$(Q) $(OBJCOPY) $(OCFLAGS) -O binary $< $@

clean:
	rm -f $(OBJS)
	rm -f TestDemo*

.PHONY: all clean
