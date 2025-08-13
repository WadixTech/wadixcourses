
# toolchain
CC = $(tools)/armgcc/bin/arm-none-eabi-gcc
AS = $(tools)/armgcc/bin/arm-none-eabi-gcc
LD = $(tools)/armgcc/bin/arm-none-eabi-gcc

### C compiler flags
CFLAGS += -c
CFLAGS += -mcpu=cortex-m3
CFLAGS += -mfpu=fpv4-sp-d16
CFLAGS += -mfloat-abi=soft
CFLAGS += -ggdb
CFLAGS += -gdwarf-3
CFLAGS += -std=c99
CFLAGS += -g
### option needed to automate creation of headers dependencies file .d
CFLAGS += -MMD
### add list of include pathes required by the compiler preprocessing stage
CFLAGS += -Iinc/
CFLAGS += -Icommon/inc/
CFLAGS += -Idrivers/uart/inc/
CFLAGS += -Idrivers/pwr/inc/
CFLAGS += -Idrivers/spi/inc/

### C Linker flags
LDFLAGS += -T $(linkerdir)/linker.ld
LDFLAGS += -Xlinker -static
LDFLAGS += -nostartfiles
LDFLAGS += -Wl,--map=$(builddir)/map.txt