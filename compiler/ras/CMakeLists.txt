
    #$(JIT_OMR_DIRTY_DIR)/ras/CallStack.cpp \
    #$(JIT_OMR_DIRTY_DIR)/ras/CFGChecker.cpp \
    #$(JIT_OMR_DIRTY_DIR)/ras/Debug.cpp \
    #$(JIT_OMR_DIRTY_DIR)/ras/DebugCounter.cpp \
    #$(JIT_OMR_DIRTY_DIR)/ras/IgnoreLocale.cpp \
    #$(JIT_OMR_DIRTY_DIR)/ras/LimitFile.cpp \
    #$(JIT_OMR_DIRTY_DIR)/ras/LogTracer.cpp \
    #$(JIT_OMR_DIRTY_DIR)/ras/OptionsDebug.cpp \
    #$(JIT_OMR_DIRTY_DIR)/ras/PPCOpNames.cpp \
    #$(JIT_OMR_DIRTY_DIR)/ras/Tree.cpp \
    
add_library(tr_ras STATIC
	CallStack.cpp
	CFGChecker.cpp
	Debug.cpp
	DebugCounter.cpp
	IgnoreLocale.cpp
	LimitFile.cpp
	LogTracer.cpp
	OptionsDebug.cpp
	PPCOpNames.cpp
	Tree.cpp
)
