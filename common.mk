ifeq ($(origin COMMON_INC),undefined)
   COMMON_INC :=1
   $(warning Building dependency tree...)

   # Specify all as default target
   all:

   ifeq ($(origin BASE_DIR),undefined)
      BASE_DIR = $(dir $(shell pwd | sed "s,\(.*/euler\).*,\1,g"))
   endif

   CONFIG_DIR         := $(BASE_DIR)/Config

   include $(CONFIG_DIR)/platform.mk

   LIB_DIR            := $(BASE_DIR)/lib

   # Utility library dirs
   PRIMES_DIR         := $(BASE_DIR)/primes
   PYTHAG_DIR         := $(BASE_DIR)/pythag
   NUMBER_THEORY_DIR  := $(BASE_DIR)/number_theory

   # Utility libraries
   PRIMES_LIB         := $(LIB_DIR)/primes.$(LIBEXTENSION)
   PYTHAG_LIB         := $(LIB_DIR)/pythag.$(LIBEXTENSION)

   .PHONY: clean
   # Specify the clean target. Each included makefile will add the files it makes to FILES_TO_CLEAN
   clean clean_hla:
		rm -f $(FILES_TO_CLEAN)
		rm -rf $(DIRS_TO_CLEAN)

endif

