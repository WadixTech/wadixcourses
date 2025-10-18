

linkerdir = linker
builddir = build
-include tools.mk
-include toolchain.mk

## helpers macros and functions needed to create directories, remove, or copy ....
create-directory = $(cygwin64)/mkdir -p $(1)
copy-file = $(cygwin64)/cp -r $(1) $(2)

## list of sources
src += $(wildcard common/src/*.c)
src += $(wildcard drivers/pwr/src/*.c)
src += $(wildcard drivers/spi/src/*.c)
src += $(wildcard drivers/uart/src/*.c)
src += $(wildcard src/*.c)


# objects
objects_dir = $(builddir)/objs
objects = $(src:.c=.o)

s_prefix = common/src drivers/pwr/src drivers/spi/src drivers/uart/src src

$(foreach p,$(s_prefix),$(eval objects := $(patsubst $(p)/%,$(objects_dir)/%,$(objects))))


.PHONY: all 
all: $(builddir)/program.elf

.PHONY: clean
clean:
	$(cygwin64)/rm -rf $(builddir)
	

$(builddir)/program.elf: $(objects)
	$(call create-directory,$(builddir))
	$(LD) $(LDFLAGS) $(^) -o $(@)
	

$(objects_dir)/%.o: common/src/%.c
	$(call create-directory,$(objects_dir))
	$(CC) $(CFLAGS) $(<) -o $(@)
	
$(objects_dir)/%.o: drivers/pwr/src/%.c
	$(call create-directory,$(objects_dir))
	$(CC) $(CFLAGS) $(<) -o $(@)
	
$(objects_dir)/%.o: drivers/spi/src/%.c
	$(call create-directory,$(objects_dir))
	$(CC) $(CFLAGS) $(<) -o $(@)
	
$(objects_dir)/%.o: drivers/uart/src/%.c
	$(call create-directory,$(objects_dir))
	$(CC) $(CFLAGS) $(<) -o $(@)
	
$(objects_dir)/%.o: src/%.c
	$(call create-directory,$(objects_dir))
	$(CC) $(CFLAGS) $(<) -o $(@)