
### tools directiory
toolsdir = C:/Users/wassi/OneDrive/Bureau/tools

### cygwintools
cygwintools = $(toolsdir)/cygwin64/bin

### toolchain definition
CC = $(toolsdir)/Keil_v5/ARM/ARMCLANG/bin/armclang.exe
LD = $(toolsdir)/Keil_v5/ARM/ARMCLANG/bin/armlink.exe
AS = $(toolsdir)/Keil_v5/ARM/ARMCLANG/bin/armasm.exe
OBJDUMP = $(toolsdir)/Keil_v5/ARM/ARMCLANG/bin/fromelf.exe
OBJDUMPFLAGS = -c

keil-mdk = $(toolsdir)/Keil_v5/UV4/UV4.exe

### build and source directories definitions
builddir = build
loaddir  = keil-loader
objsdir = build/objs
linkerdir = linker
srcdir = src
incdir = ../inc
ns_image_src = src/ns_image.c
ns_image_obj = $(objsdir)/ns_image.o
ns_image_elf = $(builddir)/ns_image.elf
ns_image_disasm = $(builddir)/ns_image.disasm

# keil project
KEIL_PROJECT = $(builddir)/keil-loader/lpc55s69-keil-project-flash.uvprojx

### C sources
C_SOURCES   := $(wildcard *.c)

### list of objects
FILES_OUT += $(C_SOURCES:.c=.o)
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

### C Linker flags
LDFLAGS += --no_remove
LDFLAGS += --map --list=$(builddir)/map.txt
LDFLAGS += --scatter $(linkerdir)/linker_image_ns.sct
LDFLAGS += --symdefs=image_symbols_ns.txt

### headers directories
HEADERS += -I$(incdir)
HEADERS += -I../cmsis/Include

create_dir = $(cygwintools)/mkdir -p $(1)
copy-file  = $(cygwintools)/cp -r $(1) $(2)

### makefile main recipe
all: $(ns_image_disasm)

$(ns_image_disasm): $(ns_image_elf)
	$(OBJDUMP) $(OBJDUMPFLAGS) $(<) > $(@)
	$(call copy-file,$(loaddir),$(builddir)/keil-loader)

$(ns_image_elf): $(ns_image_obj) $(objects)
	$(call create_dir,$(@D))
	$(LD) $(LDFLAGS) $(^) -o $(@)
	
$(objsdir)/%.o: $(srcdir)/%.c
	$(call create_dir,$(@D))
	$(CC) $(CFLAGS) $(HEADERS) $(<) -o $(@)
	
$(ns_image_obj): $(ns_image_src)
	$(call create_dir,$(@D))
	$(CC) $(CFLAGS) $(HEADERS) $(<) -o $(@)

download:
	$(keil-mdk) -d $(KEIL_PROJECT)
	
clean:
	$(cygwintools)/rm -rf $(builddir)
	