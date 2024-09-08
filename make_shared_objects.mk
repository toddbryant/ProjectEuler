#########################################################
# Specify rules to build shared objects.                #
#########################################################

.SECONDEXPANSION:
# Specify how to build the shared object

$(LIBRARY): $($(LIBRARY)_OBJS) $($(LIBRARY)_LIBS)
	@$(TEST_DIR_EXISTS) $(@D) || $(CREATE_DIR) $(@D)
	$($@_SPECIAL_RULES) 
	$(CXX) $(AS_SHARED_OBJECT) $+ $(USING_ORIGIN) $(RPATH_LIB_DIR) $($@_EXTERNAL_LIB_FLAGS) $(SONAME)$(@F) $(STDLIBS) -o $@

include $(CONFIG_DIR)/make_objects.mk
-include $(patsubst %.o,%.P,$($(LIBRARY)_OBJS))

ifneq (,$(findstring clean,$(MAKECMDGOALS)))
   FILES_TO_CLEAN := $(FILES_TO_CLEAN) $(LIBRARY)
endif
