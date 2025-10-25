
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
incdir = ../ns_image/inc
s_image_src = src/s_image.c
s_image_obj = $(objsdir)/s_image.o
s_image_elf = $(builddir)/s_image.elf
s_image_disasm = $(builddir)/s_image.disasm

# keil project to be used to load secure image into target device
KEIL_PROJECT = $(builddir)/keil-loader/lpc55s69-keil-project-flash.uvprojx

### C sources
C_SOURCES   := $(wildcard src/*.c)

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
LDFLAGS += --scatter $(linkerdir)/linker_image_s.sct
LDFLAGS += --import-cmse-lib-out export\importlib.o
LDFLAGS += --cpu=cortex-m33

### headers directories
HEADERS += -I$(incdir)
HEADERS += -Iinc
HEADERS += -I../ns_image/cmsis/Include

create_dir = $(cygwintools)/mkdir -p $(1)
copy-file  = $(cygwintools)/cp -r $(1) $(2)

### makefile main recipe
all: $(s_image_disasm)

$(s_image_disasm): $(s_image_elf)
	$(OBJDUMP) $(OBJDUMPFLAGS) $(<) > $(@)
	$(call copy-file,$(loaddir),$(builddir)/keil-loader)

$(s_image_elf): $(s_image_obj) $(objects)
	$(call create_dir,$(@D))
	$(LD) $(LDFLAGS) $(^) -o $(@)
	
$(objsdir)/%.o: $(srcdir)/%.c
	$(call create_dir,$(@D))
	$(CC) $(CFLAGS) $(HEADERS) $(<) -o $(@)
	
$(s_image_obj): $(s_image_src)
	$(call create_dir,$(@D))
	$(CC) $(CFLAGS) $(HEADERS) $(<) -o $(@)
	
download:
	$(keil-mdk) -d $(KEIL_PROJECT)

clean:
	$(cygwintools)/rm -rf $(builddir)
	