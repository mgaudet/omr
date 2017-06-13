
compiler_library(env 
	${CMAKE_CURRENT_SOURCE_DIR}/ExceptionTable.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/OMRCPU.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/OMRObjectModel.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/OMRArithEnv.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/OMRClassEnv.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/OMRDebugEnv.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/OMRVMEnv.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/SegmentProvider.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/SystemSegmentProvider.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/Region.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/StackMemoryRegion.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/OMRPersistentInfo.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/TRMemory.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/TRPersistentMemory.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/VerboseLog.cpp 


	# The following are listed under JIT_PRODUCT_SOURCE_FILES 
	# (for compiler test, but not jitbuilder). 
	# TODO: figure out why and move if required
	${CMAKE_CURRENT_SOURCE_DIR}/FEBase.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/JitConfig.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/OMRIO.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/OMRKnownObjectTable.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Globals.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/OMRCompilerEnv.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/PersistentAllocator.cpp

)
