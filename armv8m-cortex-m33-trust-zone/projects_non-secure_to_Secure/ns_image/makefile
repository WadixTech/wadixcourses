
### tools directiory
toolsdir = C:/Users/wassi/OneDrive/Bureau/tools

### cygwintools
cygwintools = $(toolsdir)/cygwin64/bin

### toolchain definition
keil-mdk = $(toolsdir)/Keil_v5/UV4/UV4.exe
CC = $(toolsdir)/Keil_v5/ARM/ARMCLANG/bin/armclang.exe
LD = $(toolsdir)/Keil_v5/ARM/ARMCLANG/bin/armlink.exe
AS = $(toolsdir)/Keil_v5/ARM/ARMCLANG/bin/armasm.exe
OBJDUMP = $(toolsdir)/Keil_v5/ARM/ARMCLANG/bin/fromelf.exe
OBJDUMPFLAGS = -c

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
CFLAGS += --target=arm-arm-none-eabi
CFLAGS += -march=armv8-m.base
CFLAGS += -mcmse # Needed for secure 
CFLAGS += -mfpu=none
CFLAGS += -mfloat-abi=soft
CFLAGS += -c
CFLAGS += -g
CFLAGS += -gdwarf-3
CFLAGS += -std=c99
### add example number macro , required by header file to declare corresponding example function
CFLAGS += -Dexample_number=$(example_number)

### C Linker flags
LDFLAGS += --no_remove
LDFLAGS += --map --list=$(builddir)/map.txt
LDFLAGS += ..\s_image\export\importlib.o
LDFLAGS += --scatter $(linkerdir)/linker_code_flash_ns.sct

### keil-mdk project to be used
KEIL_PROJECT = $(builddir)/loader/lpc55s69-keil-project-flash.uvprojx

### headers directories
HEADERS += -I$(incdir)
HEADERS += -Icmsis/Include
HEADERS += -I..\s_image\inc

create_dir = $(cygwintools)/mkdir -p $(1)
copy-file  = $(cygwintools)/cp -r $(1) $(2)

### makefile main recipe
all: $(example_disasm)

$(example_disasm): $(example_elf)
	$(OBJDUMP) $(OBJDUMPFLAGS) $(<) > $(@)
	$(call copy-file,$(loaddir),$(builddir)/loader)
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

download:
	$(keil-mdk) -d $(KEIL_PROJECT)
	
clean:
	$(cygwintools)/rm -rf $(builddir)
	