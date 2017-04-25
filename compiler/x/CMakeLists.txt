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
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/SIMDTreeEvaluator.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/HelperCallSnippet.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/IA32LinkageUtils.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/IntegerMultiplyDecomposer.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/OMRMemoryReference.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/OpBinary.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/codegen/OpNames.cpp
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

#TODO needs better guard?
if(OMR_ENV_DATA64)
	target_sources(tr_TargetCodegen INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}/amd64/codegen/OMRCodeGenerator.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/amd64/codegen/OMRMachine.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/amd64/codegen/OMRMemoryReference.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/amd64/codegen/OMRRealRegister.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/amd64/codegen/AMD64SystemLinkage.cpp

	)
	add_library(tr_CodegenJitbuilder INTERFACE)
	target_sources(tr_CodegenJitbuilder INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/amd64/codegen/OMRTreeEvaluator.cpp)
endif()

add_library(tr_TargetEnv INTERFACE)
target_sources(tr_TargetEnv INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}/env/OMRDebugEnv.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/enc/OMRCPU.cpp
)

