    #$(JIT_OMR_DIRTY_DIR)/control/OMROptions.cpp \
    #$(JIT_OMR_DIRTY_DIR)/control/OptimizationPlan.cpp \
    #$(JIT_OMR_DIRTY_DIR)/control/OMRRecompilation.cpp  \
    #$(JIT_OMR_DIRTY_DIR)/control/CompilationController.cpp \

    #$(JIT_OMR_DIRTY_DIR)/control/CompileMethod.cpp \
    
add_library(tr_control STATIC
	OMROptions.cpp
	OptimizationPlan.cpp
	OMRRecompilation.cpp
	CompilationController.cpp
	CompileMethod.cpp
)
