add_library(tr_TargetCodegen INTERFACE)
target_sources(tr_TargetCodegen INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/BinaryCommutativeAnalyser.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/BinaryEvaluator.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/CompareAnalyser.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/ConstantDataSnippet.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/ControlFlowEvaluator.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/DataSnippet.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/DivideCheckSnippet.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/FPBinaryArithmeticAnalyser.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/FPCompareAnalyser.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/FPTreeEvaluator.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/HelperCallSnippet.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/IA32LinkageUtils.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/IntegerMultiplyDecomposer.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/OMRMemoryReference.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/OpBinary.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/OpNames.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/OpProperties.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/OutlinedInstructions.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/RegisterRematerialization.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/SubtractAnalyser.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/Trampoline.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/OMRTreeEvaluator.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/UnaryEvaluator.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/X86BinaryEncoding.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/X86Debug.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/X86FPConversionSnippet.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/OMRInstruction.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/OMRX86Instruction.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/OMRMachine.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/OMRLinkage.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/OMRRegister.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/OMRRealRegister.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/OMRRegisterDependency.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/OMRSnippet.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/X86SystemLinkage.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/XMMBinaryArithmeticAnalyser.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/OMRCodeGenerator.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/OMRRegisterIterator.cpp


)

if(OMR_ENV_DATA64)
	target_sources(tr_TargetCodegen INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}/amd64/codegen/OMRCodeGenerator.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/amd64/codegen/OMRMachine.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/amd64/codegen/OMRMemoryReference.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/amd64/codegen/OMRRealRegister.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/amd64/codegen/AMD64FPConversionSnippet.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/amd64/codegen/AMD64SystemLinkage.cpp
	)
endif()


#TODO we need ability to hack on assembly commands
add_library(tr_TargetRuntime INTERFACE)
target_sources(tr_TargetRuntime
	INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}/runtime/CPUID.asm
)


    #$(JIT_OMR_DIRTY_DIR)/x/runtime/CPUID.asm
#JIT_PRODUCT_BACKEND_SOURCES+=\



#JIT_PRODUCT_SOURCE_FILES+=

#JIT_PRODUCT_BACKEND_SOURCES+=\

# H/W SPECIFIC


    #$(JIT_PRODUCT_DIR)/x/runtime/AsmUtil64.asm \
    #$(JIT_PRODUCT_DIR)/x/codegen/Evaluator.cpp \
