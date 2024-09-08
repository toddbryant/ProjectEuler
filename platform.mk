TEST_DIR_EXISTS := test -d
CREATE_DIR := mkdir -p

# Determine system
RPATH          := -Wl,-rpath,
RPATH_LINK     := -Wl,-rpath-link,
SONAME         := -Wl,-soname,
RPATH_LIB_DIR   = $(RPATH)$(LIB_DIR) $(RPATH_LINK)$(LIB_DIR)

SYSTEM      := $(shell uname -s)

ifneq (,$(findstring MINGW,${SYSTEM}))
  LIBEXTENSION   := dll
endif

ifneq (,$(findstring Linux,${SYSTEM}))
  LIBEXTENSION   := so
endif

# Set compilation/linking flags 
ifdef ENABLE_COVERAGE
   COVERAGEFLAGS := -fprofile-arcs -ftest-coverage
endif

DEBUGFLAGS         := -g
CXXFLAGS           := $(CXXFLAGS) $(DEBUGFLAGS)
AS_OBJECT          := -c $(COVERAGEFLAGS)
AS_SHARED_OBJECT   := -fPIC -shared $(DEBUGFLAGS) $(COVERAGEFLAGS)
AS_EXECUTABLE      := $(DEBUGFLAGS) $(COVERAGEFLAGS)
