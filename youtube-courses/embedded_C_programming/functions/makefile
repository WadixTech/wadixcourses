
### tools directiory
toolsdir = C:/Users/wassi/OneDrive/Bureau/tools

### cygwintools
cygwintools = $(toolsdir)/cygwin64/bin

### toolchain definition
CC = $(toolsdir)/armgcc/bin/arm-none-eabi-gcc.exe
LD = $(toolsdir)/armgcc/bin/arm-none-eabi-gcc.exe
AS = $(toolsdir)/armgcc/bin/arm-none-eabi-gcc.exe
OBJDUMP = $(toolsdir)/armgcc/bin/arm-none-eabi-objdump.exe
OBJDUMPFLAGS = -d

### default example number
example_number ?= 

### build and source directories definitions
builddir = build
loaddir  = loader
objsdir = build/objs
linkerdir = linker
srcdir = src
incdir = inc
example_src = examples/example_$(example_number).c
example_obj = $(objsdir)/example_$(example_number).o
example_elf = $(builddir)/example_$(example_number).elf
example_disasm = $(builddir)/example_$(example_number).disasm

### C sources
C_SOURCES   := $(wildcard $(srcdir)/*.c)

### ASM sources
ASM_SOURCES := $(wildcard $(srcdir)/*.s)

### list of objects
FILES_OUT += $(C_SOURCES:.c=.o)
FILES_OUT += $(ASM_SOURCES:.s=.o)
objects = $(foreach source,$(FILES_OUT),$(addprefix $(objsdir)/,$(subst src/,,$(source))))

### C compiler flags
CFLAGS += -c
CFLAGS += -mcpu=cortex-m3
CFLAGS += -mfpu=fpv4-sp-d16
CFLAGS += -mfloat-abi=soft
CFLAGS += -ggdb
CFLAGS += -gdwarf-3
CFLAGS += -std=c99
### add example number macro , required by header file to declare corresponding example function
CFLAGS += -Dexample_number=$(example_number)

### C Linker flags
LDFLAGS += -Xlinker -static
LDFLAGS += -nostartfiles
LDFLAGS += -Wl,-Map=$(builddir)/map.txt

MEMORY_CONFIG ?= FLASH

### keil-mdk project to be used
ifeq ($(MEMORY_CONFIG),FLASH)
KEIL_PROJECT = $(builddir)/loader/stm32L432KC-keil-project-flash.uvprojx
LDFLAGS += -T $(linkerdir)/linker_code_flash.ld
else
KEIL_PROJECT = $(builddir)/loader/stm32L432KC-keil-project-ram.uvprojx
LDFLAGS += -T $(linkerdir)/linker_code_ram.ld
endif

### headers directories
HEADERS += -I$(incdir)
HEADERS += -I$(incdir)
HEADERS += -Icmsis/Include

create_dir = $(cygwintools)/mkdir -p $(1)
copy-file  = $(cygwintools)/cp -r $(1) $(2)

### makefile main recipe
all: $(example_disasm)

$(example_disasm): $(example_elf)
	$(OBJDUMP) $(OBJDUMPFLAGS) $(<) > $(@)
	$(call copy-file,$(loaddir)/$(MEMORY_CONFIG),$(builddir)/loader)
	$(cygwintools)/sed -i 's/example_xx.elf/example_$(example_number).elf/g' $(KEIL_PROJECT)

$(example_elf): $(example_obj) $(objects)
	$(call create_dir,$(@D))
	$(LD) $(LDFLAGS) $(^) -o $(@)
	
$(objsdir)/%.o: $(srcdir)/%.c
	$(call create_dir,$(@D))
	$(CC) $(CFLAGS) $(HEADERS) $(<) -o $(@)
	
$(objsdir)/%.o: $(srcdir)/%.s
	$(call create_dir,$(@D))
	$(CC) $(CFLAGS) $(HEADERS) $(<) -o $(@)
	
$(example_obj): $(example_src)
	$(call create_dir,$(@D))
	$(CC) $(CFLAGS) $(HEADERS) $(<) -o $(@)

clean:
	$(cygwintools)/rm -rf $(builddir)
	