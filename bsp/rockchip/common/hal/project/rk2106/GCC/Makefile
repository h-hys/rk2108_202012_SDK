# SPDX-License-Identifier: BSD-3-Clause */

# Copyright (c) 2018-2020 Rockchip Electronics Co., Ltd.

ROOT_PATH	:= ../../..
PROJECT           := RK2106

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

CPU		= -mcpu=cortex-m3 -mthumb

ASFLAGS         += $(CPU) -D__ASSEMBLY__
CFLAGS		+= $(CPU) -std=c99 -O2 -g -Wformat=2 -Wall -Wextra -Wno-unused-parameter -Werror
LDFLAGS		+= $(CPU) -Wl,--gc-sections --specs=nosys.specs -lm -lgcc -nostartfiles
OCFLAGS		= -R .note -R .note.gnu.build-id -R .comment -S

LINKER_SCRIPT	:= ./gcc_arm.ld

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
# Head files
#############################################################################
INCLUDES += \
-I"$(ROOT_PATH)/lib/hal/inc" \
-I"$(ROOT_PATH)/lib/bsp/$(PROJECT)" \
-I"$(ROOT_PATH)/lib/CMSIS/Device/$(PROJECT)/Include" \
-I"$(ROOT_PATH)/lib/CMSIS/Core/Include" \
-I"$(ROOT_PATH)/lib/CMSIS/Device" \
-I"$(ROOT_PATH)/test/unity/src" \
-I"$(ROOT_PATH)/test/unity/extras/fixture/src" \
-I"$(ROOT_PATH)/test" \
-I"$(ROOT_PATH)/test/coremark" \
-I"$(ROOT_PATH)/test/coremark/barebones" \
-I"../src" \
-I"../Scatter" \

#############################################################################
# Source Files
#############################################################################
DIRS := $(ROOT_PATH)/lib/hal/src \
	$(ROOT_PATH)/lib/hal/src/*/ \
	$(ROOT_PATH)/lib/bsp/$(PROJECT) \
	$(ROOT_PATH)/lib/CMSIS/Device/$(PROJECT)/Source/Templates/GCC \
	$(ROOT_PATH)/lib/CMSIS/Device/$(PROJECT)/Source/Templates \
	$(ROOT_PATH)/test/unity/extras/fixture/src \
	$(ROOT_PATH)/test/unity/src \
	$(ROOT_PATH)/test/hal \
	$(ROOT_PATH)/test \
	$(ROOT_PATH)/test/coremark \
	$(ROOT_PATH)/test/coremark/barebones \
	../Scatter \
	../src \
	. \

SRCS += $(basename $(foreach dir,$(DIRS),$(wildcard $(dir)/*.[cS])))

OBJS := $(addsuffix .o,$(basename $(SRCS)))

CPPFLAGS += $(INCLUDES)

all: $(BIN)

$(ELF): $(OBJS) $(LINKER_SCRIPT)
	$(Q) $(CC) $(OBJS) $(LDFLAGS) $(CFLAGS) -T$(LINKER_SCRIPT) -Wl,-Map=$(MAP),-cref -o $@

$(BIN): $(ELF)
	$(Q) $(OBJCOPY) $(OCFLAGS) -O binary $< $@

clean:
	rm -f $(OBJS)
	rm -f TestDemo*

.PHONY: all clean
