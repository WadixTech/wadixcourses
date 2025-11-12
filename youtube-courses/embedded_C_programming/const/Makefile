

linkerdir = linker
builddir = build

-include tools.mk
-include toolchain.mk

## helpers macros and functions needed to create directories, remove, or copy ....
create-directory = $(cygwin64)/mkdir -p $(1)
copy-file = $(cygwin64)/cp -r $(1) $(2)

## list of sources
src += $(wildcard src/*.c)


# objects
objects_dir = $(builddir)/objs
objects = $(objects_dir)/main.o

.PHONY: all 
all: $(builddir)/program.elf

.PHONY: clean
clean:
	$(cygwin64)/rm -rf $(builddir)
	

$(builddir)/program.elf: $(objects)
	$(call create-directory,$(builddir))
	$(LD) $(LDFLAGS) $(^) -o $(@)
		
$(objects_dir)/main.o: src/main.c
	$(call create-directory,$(objects_dir))
	$(CC) $(CFLAGS) $(<) -o $(@)