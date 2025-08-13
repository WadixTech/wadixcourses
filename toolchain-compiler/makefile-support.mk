# helper functions
create_dir = $(cygwintools)/mkdir -p $(1)
copy-file = $(cygwintools)/cp -r $(1) $(2)

define driver_rule
$(objsdir)/%.i : $(driverdir)/$(1)/src/%.c
	$$(call create_dir,$$(@D))
	$$(CC) $$(CFLAGS) -E  $$(<) -o $$(@)
	
$(objsdir)/%.s : $(objsdir)/%.i
	$$(call create_dir,$$(@D))
	$$(CC) $$(CFLAGS) -S $$(<) -o $$(@)
	
$(objsdir)/%.o : $(objsdir)/%.s
	$$(call create_dir,$$(@D))
	$$(CC) $$(CFLAGS) $$(<) -o $$(@)
endef