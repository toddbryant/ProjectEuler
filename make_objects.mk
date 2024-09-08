#########################################################
# Specify rules to build object files.                  #
#########################################################

DEPFILE              = $(patsubst %.o,%.d,$@)
NEWDEPFILE           = $(patsubst %.o,%.P,$@)

COMPILE_WITH_DEPFILE = $(CXX) -MMD $(AS_OBJECT) $(CXXFLAGS) $($(@D)_SPECIAL_FLAGS) $(addprefix -I,$($(@D)_INCLUDE_DIRS)) -o $@ $<

PROCESS_DEPFILE_SEDSCRIPT = $(CONFIG_DIR)/process_dfile.sed
PROCESS_DEPFILE      = sed -f $(PROCESS_DEPFILE_SEDSCRIPT)

# Compile a .o for each .cpp in the directory
$(OBJDIR)/%.o : $($(OBJDIR)_SRCDIR)/%.cpp
	@$(TEST_DIR_EXISTS) $(@D) || $(CREATE_DIR) $(@D)
	$($(@D)_SPECIAL_RULES)
	$(COMPILE_WITH_DEPFILE)
	cp -f $(DEPFILE) $(NEWDEPFILE); \
	$(PROCESS_DEPFILE) $(DEPFILE) >> $(NEWDEPFILE)

ifneq (,$(findstring clean,$(MAKECMDGOALS)))
   DIRS_TO_CLEAN := $(DIRS_TO_CLEAN) $(OBJDIR)
endif

