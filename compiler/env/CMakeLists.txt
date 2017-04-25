#$(JIT_OMR_DIRTY_DIR)/env/ExceptionTable.cpp \
    #$(JIT_OMR_DIRTY_DIR)/env/OMRCPU.cpp \
    #$(JIT_OMR_DIRTY_DIR)/env/OMRObjectModel.cpp \
    #$(JIT_OMR_DIRTY_DIR)/env/OMRArithEnv.cpp \
    #$(JIT_OMR_DIRTY_DIR)/env/OMRClassEnv.cpp \
    #$(JIT_OMR_DIRTY_DIR)/env/OMRDebugEnv.cpp \
    #$(JIT_OMR_DIRTY_DIR)/env/OMRVMEnv.cpp \
    #$(JIT_OMR_DIRTY_DIR)/env/SegmentProvider.cpp \
    #$(JIT_OMR_DIRTY_DIR)/env/SystemSegmentProvider.cpp \
    #$(JIT_OMR_DIRTY_DIR)/env/Region.cpp \
    #$(JIT_OMR_DIRTY_DIR)/env/StackMemoryRegion.cpp \
    #$(JIT_OMR_DIRTY_DIR)/env/OMRPersistentInfo.cpp \
    #$(JIT_OMR_DIRTY_DIR)/env/TRMemory.cpp \
    #$(JIT_OMR_DIRTY_DIR)/env/TRPersistentMemory.cpp \
    #$(JIT_OMR_DIRTY_DIR)/env/VerboseLog.cpp \
       #$(JIT_OMR_DIRTY_DIR)/env/FEBase.cpp \
    #$(JIT_OMR_DIRTY_DIR)/env/JitConfig.cpp \


	     #$(JIT_OMR_DIRTY_DIR)/env/OMRIO.cpp \
    #$(JIT_OMR_DIRTY_DIR)/env/OMRKnownObjectTable.cpp \
    #$(JIT_OMR_DIRTY_DIR)/env/Globals.cpp \
    #$(JIT_OMR_DIRTY_DIR)/env/OMRCompilerEnv.cpp \
    #$(JIT_OMR_DIRTY_DIR)/env/PersistentAllocator.cpp \

add_library(tr_env STATIC
	ExceptionTable.cpp
	OMRCPU.cpp
	OMRObjectModel.cpp
	OMRArithEnv.cpp
	OMRClassEnv.cpp
	OMRDebugEnv.cpp
	OMRVMEnv.cpp
	SegmentProvider.cpp
	Region.cpp
	StackMemoryRegion.cpp
	OMRPersistentInfo.cpp
	TRMemory.cpp
	TRPersistentMemory.cpp
	VerboseLog.cpp
	JitConfig.cpp

	OMRIO.cpp
	OMRKnownObjectTable.cpp
	Globals.cpp
	OMRCompilerEnv.cpp
	PersistentAllocator.cpp
)
