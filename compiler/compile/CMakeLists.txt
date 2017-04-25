    #$(JIT_OMR_DIRTY_DIR)/compile/OSRData.cpp \
    #$(JIT_OMR_DIRTY_DIR)/compile/Method.cpp \
    #$(JIT_OMR_DIRTY_DIR)/compile/OMRCompilation.cpp \
    #$(JIT_OMR_DIRTY_DIR)/compile/TLSCompilationManager.cpp \
    #$(JIT_OMR_DIRTY_DIR)/compile/OMRSymbolReferenceTable.cpp \
    #$(JIT_OMR_DIRTY_DIR)/compile/OMRAliasBuilder.cpp \

add_library(tr_compile STATIC
	VirtualGuard.cpp
	OSRData.cpp
	Method.cpp
	OMRCompilation.cpp
	TLSCompilationManager.cpp
	OMRSymbolReferenceTable.cpp
	OMRAliasBuilder.cpp
)
