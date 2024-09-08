# Specify rules to build applications.

.SECONDEXPANSION:

$(APP): $($(APP)_OBJS) $($(APP)_LIBS)
	@$(TEST_DIR_EXISTS) $(@D) || $(CREATE_DIR) $(@D)
	$(CXX) $(AS_EXECUTABLE) $(EXEFLAGS) $(USING_ORIGIN) $(RPATH_LIB_DIR) $($@_OBJS) -o $@ $($@_LIBS) $($@_SPECIAL_FLAGS) $(STDLIBS)

include $(CONFIG_DIR)/make_objects.mk
-include $(patsubst %.o,%.P,$($(APP)_OBJS))

ifneq (,$(findstring clean,$(MAKECMDGOALS)))
   FILES_TO_CLEAN := $(FILES_TO_CLEAN) $(APP)
   DIRS_TO_CLEAN := $(DIRS_TO_CLEAN) $(OBJDIR)
endif
   	
