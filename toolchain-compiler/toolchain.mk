
# toolchain
CC = $(tools)/armgcc/bin/arm-none-eabi-gcc
#AS = $(tools)/armgcc/bin/arm-none-eabi-gcc
LD = $(tools)/armgcc/bin/arm-none-eabi-gcc
OBJDUMP = $(tools)/armgcc/bin/arm-none-eabi-objdump

### C compiler flags
CFLAGS += -c

### O0 O1 O2 O3, Os , Oz, Ofast, Og
## debug build: O0/Og, -g
## release build: Os, Oz, O2

ifeq ($(build_type),debug)
  CFLAGS += -O0
  CFLAGS += -g
else
  CFLAGS += -O2
endif


CFLAGS += -mcpu=cortex-m3
CFLAGS += -mfpu=fpv4-sp-d16
CFLAGS += -mfloat-abi=soft

#CFLAGS += -E
#CFLAGS += -S




CFLAGS += -std=c99
### option needed to automate creation of headers dependencies file .d
CFLAGS += -MMD
### add list of include pathes required by the compiler preprocessing stage
CFLAGS += -Iinc/
CFLAGS += -Icommon/inc/
CFLAGS += -Idrivers/uart/inc/
CFLAGS += -Idrivers/pwr/inc/
CFLAGS += -Idrivers/spi/inc/
CFLAGS += -Iexternal/inc/

### C Linker flags
LDFLAGS += -T $(linkerdir)/linker.ld
LDFLAGS += -Xlinker -static
LDFLAGS += -nostartfiles
LDFLAGS += -Wl,-Map=$(builddir)/map.txt