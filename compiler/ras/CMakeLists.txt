
add_library(tr_ras INTERFACE)
target_sources(tr_ras INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}/CallStack.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/CFGChecker.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/Debug.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/DebugCounter.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/IgnoreLocale.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/LimitFile.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/LogTracer.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/OptionsDebug.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/PPCOpNames.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/Tree.cpp 
)
