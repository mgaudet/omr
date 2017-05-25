
add_library(tr_compile INTERFACE)

target_sources(tr_compile INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}/OSRData.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Method.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/VirtualGuard.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/OMRSymbolReferenceTable.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/OMRAliasBuilder.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/OMRCompilation.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/TLSCompilationManager.cpp 

)
