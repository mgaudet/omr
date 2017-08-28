###############################################################################
#
# (c) Copyright IBM Corp. 2017, 2017
#
#  This program and the accompanying materials are made available
#  under the terms of the Eclipse Public License v1.0 and
#  Apache License v2.0 which accompanies this distribution.
#
#      The Eclipse Public License is available at
#      http://www.eclipse.org/legal/epl-v10.html
#
#      The Apache License v2.0 is available at
#      http://www.opensource.org/licenses/apache2.0.php
#
# Contributors:
#    Multiple authors (IBM Corp.) - initial implementation and documentation
###############################################################################

include(OmrUtility)

set(OMR_WARNING_AS_ERROR_FLAG /WX)

list(APPEND OMR_PLATFORM_COMPILE_OPTIONS
	/MD     # Use a multithreaded runtime dll
	/GR-    # Disable RTTI
	/Zm400  # Precompiled header memory allocation limit
	/wd4577 # Disable warning: Specifying noexcept when exceptions are disabled
	/wd4091 # Disable warning: Caused by broken windows SDK, see also https://connect.microsoft.com/VisualStudio/feedback/details/1302025/warning-c4091-in-sdk-7-1a-shlobj-h-1051-dbghelp-h-1054-3056
)

if(OMR_ENV_DATA64)
	set(TARGET_MACHINE "AMD64")
else()
	set(TARGET_MACHINE "i386")
endif()

list(APPEND OMR_PLATFORM_LINKER_OPTIONS
	-subsystem:console
	-machine:${TARGET_MACHINE}
	/NOLOGO # Don't print the msvc logo
)

list(APPEND OMR_PLATFORM_EXE_LINKER_OPTIONS
	/LARGEADDRESSAWARE
	/INCREMENTAL:NO
	wsetargv.obj
)

list(APPEND OMR_PLATFORM_SHARED_LINKER_OPTIONS
	/INCREMENTAL:NO
)

if(OMR_ENV_DATA64)
	list(APPEND OMR_PLATFORM_SHARED_LINKER_OPTIONS
		-entry:_DllMainCRTStartup
		# TODO: makefile has this but it seems to break linker
		# /NODEFAULTLIB:MSVCRTD
	)
elseif(OMR_ENV_DATA32)
	list(APPEND OMR_PLATFORM_LINKER_OPTIONS
		/SAFESEH
	)
	list(APPEND OMR_PLATFORM_SHARED_LINKER_OPTIONS
		-entry:_DllMainCRTStartup@12
	)
endif(OMR_ENV_DATA64)

macro(omr_toolconfig_global_setup)
	# Make sure we are building without incremental linking
	omr_remove_flags(CMAKE_EXE_LINKER_FLAGS    /INCREMENTAL)
	omr_remove_flags(CMAKE_SHARED_LINKER_FLAGS /INCREMENTAL)

	foreach(build_type IN LISTS CMAKE_CONFIGURATION_TYPES)
		string(TOUPPER ${build_type} build_type)
		omr_remove_flags(CMAKE_EXE_LINKER_FLAGS_${build_type}    /INCREMENTAL)
		omr_remove_flags(CMAKE_SHARED_LINKER_FLAGS_${build_type} /INCREMENTAL)
	endforeach()

	# Strip out exception handling flags (added by default by cmake)
	omr_remove_flags(CMAKE_CXX_FLAGS /EHsc /GR)

	# Hack up output dir to fix dll dependency issues on windows
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
endmacro(omr_toolconfig_global_setup)
