add_executable(omrvmtest
	main.cpp
)

#TODO: this isnt a real list. I just kept adding things until the linker shuts up
target_link_libraries(omrvmtest
	omrGtestGlue
	omrtestutil
	j9thrstatic
	omrutil
	omrport
	j9hashtable
	j9avl
	j9pool
)


#MODULE_NAME := omrvmtest
#ARTIFACT_TYPE := cxx_executable


#ifeq (1,$(OMR_THR_FORK_SUPPORT))
  #OBJECTS += vmForkTest
#endif
#OBJECTS := $(addsuffix $(OBJEXT),$(OBJECTS))

#MODULE_INCLUDES += ../util
#MODULE_INCLUDES += $(OMR_GTEST_INCLUDES)
#MODULE_INCLUDES += $(OMR_IPATH)
#MODULE_CXXFLAGS += $(OMR_GTEST_CXXFLAGS)

#vpath argmain.cpp $(top_srcdir)/fvtest/omrGtestGlue

#MODULE_STATIC_LIBS += \
  #omrGtest \
  #testutil \
  #omrstatic

#ifeq (linux,$(OMR_HOST_OS))
  #MODULE_SHARED_LIBS += rt pthread
#endif
#ifeq (osx,$(OMR_HOST_OS))
  #MODULE_SHARED_LIBS += iconv pthread
#endif
#ifeq (aix,$(OMR_HOST_OS))
  #MODULE_SHARED_LIBS += iconv perfstat
#endif
#ifeq (win,$(OMR_HOST_OS))
  #MODULE_SHARED_LIBS += ws2_32 shell32 Iphlpapi psapi pdh
#endif

#include $(top_srcdir)/omrmakefiles/rules.mk

add_test(vmtest omrvmtest)
