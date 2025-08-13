# dependencies to external environment, 
  # to toolchain
  # external package tools: create folder, copy, modify, print ,...

# 1. create makefile vraiables to point to the location of toolchain andexternal pakcage tools
# 2. makefile varaibles to point to the locations and directories where sources and headers are located, as well as makefile variable pointin
#    to output location of outputs files : 
# 3. list all sources and headers to : create dependencies to them , to be able to compile sources one by one
# 4. list all expected objects files output, as well as the final program .elf => program.elf files
# 5. we need to create maekfile variables to hold the compielr flags/witches as well as the linker flags/witches
# 6. makefile rules and targets:
#    6.1 rule 1 : .PHONY: all => entry point for build procedure 
#    6.2 rule 2: .PHONY: clean => cleanup and remove the output build folder witll objects and .elf file
#    6.3 all <-- program.elf
#    6.4 rule 3 : program.elf: list_objects ==> linking stage
#    6.5 rule 4: common objects : sources under common directory, headers  ==> compiler invokation + compielr flags + the source to be compiler
#    6.6 rule 5: src objects : sources under src directory, headers  ==> compiler invokation + compielr flags + the source to be compiler
#    6.7 rule 6: driver uart objects : sources under uart driver directory, headers  ==> compiler invokation + compielr flags + the source to be compiler
#    6.8 rule 7: driver spi objects : sources under spi driver directory, headers  ==> compiler invokation + compielr flags + the source to be compiler
#    6.9 rule 8: driver pwr objects : sources under pwr driver directory, headers  ==> compiler invokation + compielr flags + the source to be compiler

-include tools.mk

# create makefile directories variables
builddir = build
objsdir = $(builddir)/objs
srcdir = src
commondir = common
bootdir = boot
driverdir = drivers
linkerdir = linker

build_type ?= release

-include toolchain.mk

# list all sources to be provided as inputs to the build procedure
C_SOURCES = $(wildcard $(srcdir)/*.c)
C_COMMON_SOURCES = $(wildcard $(commondir)/src/*.c)
C_BOOT_SOURCES = $(wildcard $(bootdir)/src/*.c)
C_DRIVER_UART_SOURCES = $(wildcard $(driverdir)/uart/src/*.c)
C_DRIVER_SPI_SOURCES = $(wildcard $(driverdir)/spi/src/*.c)
C_DRIVER_PWR_SOURCES = $(wildcard $(driverdir)/pwr/src/*.c)

# create the list of objects files
FILES_OUT_SRC = $(C_SOURCES:.c=.o)
FILES_OUT_COMMON = $(C_COMMON_SOURCES:.c=.o)
FILES_OUT_BOOT = $(C_BOOT_SOURCES:.c=.o)
FILES_OUT_UART_DRIVER = $(C_DRIVER_UART_SOURCES:.c=.o)
FILES_OUT_SPI_DRIVER = $(C_DRIVER_SPI_SOURCES:.c=.o)
FILES_OUT_PWR_DRIVER = $(C_DRIVER_PWR_SOURCES:.c=.o)
objects = $(foreach source,$(FILES_OUT_SRC),$(subst src/,$(objsdir)/,$(source)))
objects += $(foreach source,$(FILES_OUT_COMMON),$(subst $(commondir)/src/,$(objsdir)/,$(source)))
objects += $(foreach source,$(FILES_OUT_BOOT),$(subst $(bootdir)/src/,$(objsdir)/,$(source)))
objects += $(foreach source,$(FILES_OUT_UART_DRIVER),$(subst $(driverdir)/uart/src/,$(objsdir)/,$(source)))
objects += $(foreach source,$(FILES_OUT_SPI_DRIVER),$(subst $(driverdir)/spi/src/,$(objsdir)/,$(source)))
objects += $(foreach source,$(FILES_OUT_PWR_DRIVER),$(subst $(driverdir)/pwr/src/,$(objsdir)/,$(source)))

-include makefile-support.mk
COMPONENT_DRIVER = uart spi pwr
$(foreach component,$(COMPONENT_DRIVER),$(eval $(call driver_rule,$(component))))

# create list of .d file
DEPS = $(objects:%.o=%.d)
-include $(DEPS)

.SECONDARY: $(%.o)
.SECONDARY: $(%.i)
.SECONDARY: $(%.s)




.PHONY: all
all: $(builddir)/program.elf
	$(OBJDUMP) -D $(^) > $(^).disasm

.PHONY: clean
clean:
	$(cygwintools)/rm -rf $(builddir)
	
.PHONY: debug
debug:
	$(info objects list $(objects))
	
	
$(builddir)/program.elf: $(objects)
	$(call create_dir,$(@D))
	$(LD) $(LDFLAGS) $(^) -o $(@)
	
$(objsdir)/%.i : $(srcdir)/%.c
	$(call create_dir,$(@D))
	$(CC) $(CFLAGS) -E $(<) -o $(@)
	
$(objsdir)/%.i : $(commondir)/src/%.c
	$(call create_dir,$(@D))
	$(CC) $(CFLAGS) -E $(<) -o $(@)
	
$(objsdir)/%.i : $(bootdir)/src/%.c
	$(call create_dir,$(@D))
	$(CC) $(CFLAGS) -E $(<) -o $(@)
	
$(objsdir)/%.s : $(objsdir)/%.i
	$(call create_dir,$(@D))
	$(CC) $(CFLAGS) -S $(<) -o $(@)
	
$(objsdir)/%.s : $(objsdir)/%.i
	$(call create_dir,$(@D))
	$(CC) $(CFLAGS) -S $(<) -o $(@)
	
$(objsdir)/%.s : $(objsdir)/%.i
	$(call create_dir,$(@D))
	$(CC) $(CFLAGS) -S $(<) -o $(@)
	
	
$(objsdir)/%.o : $(objsdir)/%.s
	$(call create_dir,$(@D))
	$(CC) $(CFLAGS) $(<) -o $(@)
	
$(objsdir)/%.o : $(objsdir)/%.s
	$(call create_dir,$(@D))
	$(CC) $(CFLAGS) $(<) -o $(@)
	
$(objsdir)/%.o : $(objsdir)/%.s
	$(call create_dir,$(@D))
	$(CC) $(CFLAGS) $(<) -o $(@)
	
	