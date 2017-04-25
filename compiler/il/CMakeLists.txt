
    #$(JIT_OMR_DIRTY_DIR)/il/symbol/OMRSymbol.cpp \
    #$(JIT_OMR_DIRTY_DIR)/il/OMRBlock.cpp \
    #$(JIT_OMR_DIRTY_DIR)/il/symbol/OMRAutomaticSymbol.cpp \
    #$(JIT_OMR_DIRTY_DIR)/il/symbol/OMRLabelSymbol.cpp \
    #$(JIT_OMR_DIRTY_DIR)/il/symbol/OMRMethodSymbol.cpp \
    #$(JIT_OMR_DIRTY_DIR)/il/symbol/OMRParameterSymbol.cpp \
    #$(JIT_OMR_DIRTY_DIR)/il/symbol/OMRRegisterMappedSymbol.cpp \
    #$(JIT_OMR_DIRTY_DIR)/il/symbol/OMRResolvedMethodSymbol.cpp \
    #$(JIT_OMR_DIRTY_DIR)/il/symbol/OMRStaticSymbol.cpp \
    #$(JIT_OMR_DIRTY_DIR)/il/OMRNode.cpp \
    #$(JIT_OMR_DIRTY_DIR)/il/NodePool.cpp \
    #$(JIT_OMR_DIRTY_DIR)/il/NodeUtils.cpp \
    #$(JIT_OMR_DIRTY_DIR)/il/OMRIL.cpp \
    #$(JIT_OMR_DIRTY_DIR)/il/OMRSymbolReference.cpp \
    #$(JIT_OMR_DIRTY_DIR)/il/Aliases.cpp \
    #$(JIT_OMR_DIRTY_DIR)/il/OMRDataTypes.cpp \
    #$(JIT_OMR_DIRTY_DIR)/il/OMRTreeTop.cpp \
    #$(JIT_OMR_DIRTY_DIR)/il/OMRILOps.cpp \

add_library(tr_il STATIC
	symbol/OMRSymbol.cpp
	symbol/OMRAutomaticSymbol.cpp
	symbol/OMRLabelSymbol.cpp
	symbol/OMRMethodSymbol.cpp
	symbol/OMRParameterSymbol.cpp
	symbol/OMRRegisterMappedSymbol.cpp
	symbol/OMRResolvedMethodSymbol.cpp
	symbol/OMRStaticSymbol.cpp
	OMRBlock.cpp
	OMRNode.cpp
	NodePool.cpp
	NodeUtils.cpp
	OMRIL.cpp
	OMRSymbolReference.cpp
	Aliases.cpp
	OMRDataTypes.cpp
	OMRTreeTop.cpp
	OMRILOps.cpp
)
