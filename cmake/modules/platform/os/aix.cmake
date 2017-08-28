##############################################################################
#
# (c) Copyright IBM Corp. 2017
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

set(OMR_PLATFORM_DEFINITIONS
	-DRS6000
	-DAIXPPC
	-D_LARGE_FILES
	-D_ALL_SOURCE
)

list(APPEND OMR_PLATFORM_COMPILE_OPTIONS
	-qlanglvl=extended
	-qinfo=pro
	-qalias=noansi
	-qxflag=LTOL:LTOL0
)

if(OMR_ENV_DATA64)
	list(APPEND OMR_PLATFORM_COMPILE_OPTIONS
		-q64
	)
else()
	#-qarch should be there for 32 and 64 but 64 bit assembler has trouble with some assembly files if it is specified
	list(APPEND OMR_PLATFORM_COMPILE_OPTIONS
		-q32
		-qarch=ppc
	)
endif()

set(CMAKE_CXX_STANDARD_LIBRARIES "${CMAKE_CXX_STANDARD_LIBRARIES} -lm -liconv -ldl -lperfstat")

if(OMR_ENV_DATA64)
	set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -q64")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -q64")
	set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -q64")
	
	set(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> -X64 cr <TARGET> <LINK_FLAGS> <OBJECTS>")
	set(CMAKE_C_ARCHIVE_CREATE "<CMAKE_AR> -X64 cr <TARGET> <LINK_FLAGS> <OBJECTS>")
	set(CMAKE_C_ARCHIVE_FINISH "<CMAKE_RANLIB> -X64 <TARGET>")
endif()

# Testarossa build variables. Longer term the distinction between TR and the rest 
# of the OMR code should be heavily reduced. In the mean time, we keep
# the distinction
list(APPEND TR_COMPILE_DEFINITIONS -DSUPPORTS_THREAD_LOCAL -D_XOPEN_SOURCE_EXTENDED=1 -D_ALL_SOURCE -DAIX)
