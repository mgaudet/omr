    #$(JIT_OMR_DIRTY_DIR)/infra/Assert.cpp \
    #$(JIT_OMR_DIRTY_DIR)/infra/BitVector.cpp \
    #$(JIT_OMR_DIRTY_DIR)/infra/Checklist.cpp \
    #$(JIT_OMR_DIRTY_DIR)/infra/HashTab.cpp \
    #$(JIT_OMR_DIRTY_DIR)/infra/IGBase.cpp \
    #$(JIT_OMR_DIRTY_DIR)/infra/IGNode.cpp \
    #$(JIT_OMR_DIRTY_DIR)/infra/ILWalk.cpp \
    #$(JIT_OMR_DIRTY_DIR)/infra/InterferenceGraph.cpp \
    #$(JIT_OMR_DIRTY_DIR)/infra/OMRMonitor.cpp \
    #$(JIT_OMR_DIRTY_DIR)/infra/OMRMonitorTable.cpp \
    #$(JIT_OMR_DIRTY_DIR)/infra/Random.cpp \
    #$(JIT_OMR_DIRTY_DIR)/infra/Timer.cpp \
    #$(JIT_OMR_DIRTY_DIR)/infra/TreeServices.cpp \
    #$(JIT_OMR_DIRTY_DIR)/infra/OMRCfg.cpp \
    #$(JIT_OMR_DIRTY_DIR)/infra/SimpleRegex.cpp \
    
add_library(tr_infra STATIC
	Assert.cpp
	BitVector.cpp
	Checklist.cpp
	HashTab.cpp
	IGBase.cpp
	IGNode.cpp
	ILWalk.cpp
	InterferenceGraph.cpp
	OMRMonitor.cpp
	OMRMonitorTable.cpp
	Random.cpp
	Timer.cpp
	TreeServices.cpp
	OMRCfg.cpp
	SimpleRegex.cpp
)
