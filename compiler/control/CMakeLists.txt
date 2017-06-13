    #$(JIT_OMR_DIRTY_DIR)/control/OMROptions.cpp \
    #$(JIT_OMR_DIRTY_DIR)/control/OptimizationPlan.cpp \
    #$(JIT_OMR_DIRTY_DIR)/control/OMRRecompilation.cpp  \
    #$(JIT_OMR_DIRTY_DIR)/control/CompilationController.cpp \
    
compiler_library(control 
	${CMAKE_CURRENT_SOURCE_DIR}/OMROptions.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/OptimizationPlan.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/OMRRecompilation.cpp


	# The following are listed under JIT_PRODUCT_SOURCE_FILES 
	# (for compiler test). 
	# TODO: figure out why and move if required
	# NOTE: they are backend source for jitbuilder
	${CMAKE_CURRENT_SOURCE_DIR}/CompilationController.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/CompileMethod.cpp
)
