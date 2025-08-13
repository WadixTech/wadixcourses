# helper functions
create_dir = $(cygwintools)/mkdir -p $(1)
copy-file = $(cygwintools)/cp -r $(1) $(2)

define driver_rule
$(objsdir)/%.o : $(driverdir)/$(1)/src/%.c
	$$(call create_dir,$$(@D))
	$$(CC) $$(CFLAGS) $$(<) -o $$(@)
endef