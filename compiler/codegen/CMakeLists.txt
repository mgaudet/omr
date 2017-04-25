        #$(JIT_OMR_DIRTY_DIR)/codegen/OMRAheadOfTimeCompile.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/Analyser.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/CodeGenPrep.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/CodeGenGC.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/CodeGenRA.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/FrontEnd.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/OMRGCRegisterMap.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/OMRGCStackAtlas.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/OMRLinkage.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/LiveRegister.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/OutOfLineCodeSection.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/OMRRegisterDependency.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/Relocation.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/ScratchRegisterManager.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/StorageInfo.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/OMRTreeEvaluator.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/PreInstructionSelection.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/NodeEvaluation.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/OMRSnippet.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/OMRUnresolvedDataSnippet.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/OMRSnippetGCMap.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/OMRCodeGenerator.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/OMRCodeGenPhase.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/OMRMemoryReference.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/OMRMachine.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/OMRRegister.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/OMRRealRegister.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/OMRRegisterPair.cpp \
    #$(JIT_OMR_DIRTY_DIR)/codegen/OMRInstruction.cpp \

add_library(tr_codegen STATIC
	OMRAheadOfTimeCompile.cpp
	Analyser.cpp
	CodeGenPrep.cpp
	CodeGenGC.cpp
	CodeGenRA.cpp
	FrontEnd.cpp
	OMRGCRegisterMap.cpp
	OMRGCStackAtlas.cpp
	OMRLinkage.cpp
	LiveRegister.cpp
	OutOfLineCodeSection.cpp
	OMRRegisterDependency.cpp
	Relocation.cpp
	ScratchRegisterManager.cpp
	StorageInfo.cpp
	OMRTreeEvaluator.cpp
	PreInstructionSelection.cpp
	NodeEvaluation.cpp
	OMRSnippet.cpp
	OMRUnresolvedDataSnippet.cpp
	OMRSnippetGCMap.cpp
	OMRCodeGenerator.cpp
	OMRCodeGenPhase.cpp
	OMRMemoryReference.cpp
	OMRMachine.cpp
	OMRRegister.cpp
	OMRRealRegister.cpp
	OMRRegisterPair.cpp
	OMRInstruction.cpp
)
#TODO: this could be moved 1 dir up?
target_link_libraries(tr_codegen tr_TargetCodegen)
