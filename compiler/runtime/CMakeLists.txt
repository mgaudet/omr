    
compiler_library(runtime 
	# The following are listed under JIT_PRODUCT_SOURCE_FILES 
	# (for compiler test). 
	# TODO: figure out why and move if required
	# NOTE: they are backend sources for jitbuilder
	${CMAKE_CURRENT_SOURCE_DIR}/Runtime.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Trampoline.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Alignment.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/CodeCacheTypes.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/OMRCodeCache.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/OMRCodeCacheManager.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/OMRCodeCacheMemorySegment.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/OMRCodeCacheConfig.cpp
)

#target_link_libraries(tr_runtime tr_TargetRuntime)
