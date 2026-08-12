#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      %.i         - preprocessed output (make main.i)
#      %.asm       - assembly output từng file nguồn (make main.asm)
#      %.o         - object file, không link (make main.o)
#      compile-all - compile tất cả object file, không link
#      build       - compile + link ra c1m2.out
#      clean       - xoá toàn bộ file build ra
#
# Platform Overrides:
#      PLATFORM=HOST   - build native bằng gcc
#      PLATFORM=MSP432 - cross-compile bằng arm-none-eabi-gcc
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST
TARGET = c1m2

# Architectures Specific Flags
LINKER_FILE = ../msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs

# Compiler Flags and Defines
ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size
	OBJDUMP = arm-none-eabi-objdump
 
	ARCH_FLAGS = -mcpu=$(CPU) \
	             -mthumb \
	             -march=$(ARCH) \
	             -mfloat-abi=hard \
	             -mfpu=fpv4-sp-d16 \
	             --specs=$(SPECS)
 
	CFLAGS = -Wall -Werror -g -O0 -std=c99 $(ARCH_FLAGS)
	CPPFLAGS = -DMSP432 $(INCLUDES)
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE) $(ARCH_FLAGS)
 
else
 
	CC = gcc
	LD = ld
	SIZE = size
	OBJDUMP = objdump
 
	CFLAGS = -Wall -Werror -g -O0 -std=c99
	CPPFLAGS = -DHOST $(INCLUDES)
	LDFLAGS = -Wl,-Map=$(TARGET).map
 
endif
 
OBJS := $(SOURCES:.c=.o)
DEPS := $(SOURCES:.c=.d)
PPS  := $(SOURCES:.c=.i)
ASMS := $(SOURCES:.c=.asm)

# ------------------- Pattern rules -------------------
 
# Preprocessor output for each source file
%.i : %.c
	$(CC) -E $(CPPFLAGS) $(CFLAGS) $< -o $@
 
# Assembly output for each source file
%.asm : %.c
	$(CC) -S $(CPPFLAGS) $(CFLAGS) $< -o $@
 
# Object file (and dependency file) for each source file
%.o : %.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) -MMD -MP -MF $(@:.o=.d) $< -o $@

 
# ------------------- PPhony targets -------------------
 
.PHONY: compile-all
compile-all: $(OBJS)
 
.PHONY: build
build: $(TARGET).out
 
$(TARGET).out: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@
	$(SIZE) $@
 
# Assembly output of the final linked executable
$(TARGET).asm: $(TARGET).out
	$(OBJDUMP) -d $< > $@
 
.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) $(PPS) $(ASMS) \
	      $(TARGET).out $(TARGET).map $(TARGET).asm

# Pull in generated dependency files if they exist
-include $(DEPS)