include(../../cmake/compiler.cmake) 

set(COMPILERTEST_FILES
	ilgen/BinaryOpIlInjector.cpp
	ilgen/ChildlessUnaryOpIlInjector.cpp
	ilgen/CmpBranchOpIlInjector.cpp
	ilgen/OpIlInjector.cpp
	ilgen/StoreOpIlInjector.cpp
	ilgen/TernaryOpIlInjector.cpp
	ilgen/UnaryOpIlInjector.cpp
	tests/BarIlInjector.cpp
	tests/BuilderTest.cpp
	tests/CallIlInjector.cpp
	tests/IndirectLoadIlInjector.cpp
	tests/IndirectStoreIlInjector.cpp
	tests/FooBarTest.cpp
	tests/FooIlInjector.cpp
	tests/LimitFileTest.cpp
	tests/LogFileTest.cpp
	tests/OMRTestEnv.cpp
	tests/OptionSetTest.cpp
	tests/OpCodesTest.cpp
	tests/PPCOpCodesTest.cpp
	tests/Qux2Test.cpp
	tests/Qux2IlInjector.cpp
	tests/SimplifierFoldAndTest.cpp
	tests/S390OpCodesTest.cpp
	tests/OptTestDriver.cpp
	tests/TestDriver.cpp
	tests/X86OpCodesTest.cpp
	compile/Method.cpp
	control/TestJit.cpp
	env/FrontEnd.cpp
	ilgen/IlInjector.cpp
	ilgen/TestIlGeneratorMethodDetails.cpp
	optimizer/TestOptimizer.cpp
	runtime/TestCodeCacheManager.cpp
	runtime/TestJitConfig.cpp
)

if(OMR_ARCH_X86)
	list(APPEND COMPILERTEST_FILES 
		x/codegen/Evaluator.cpp
	)
endif()
create_omr_compiler_library(NAME       testcompiler 
                            OBJECTS    ${COMPILERTEST_FILES})

get_target_property(output testcompiler INCLUDE_DIRECTORIES)
message(STATUS "incudes before ${output}")

#dumb hack for gtest. Maybe not needed now that we link agains gtest?
target_include_directories( testcompiler PRIVATE 
	${PROJECT_SOURCE_DIR}/third_party/gtest-1.7.0/
	${PROJECT_SOURCE_DIR}/third_party/gtest-1.7.0/include
)

get_target_property(output testcompiler INCLUDE_DIRECTORIES)
message(STATUS "incudes after ${output}")

add_executable(compilertest
	tests/main.cpp
)


target_link_libraries(compilertest
	testcompiler	
	omrGtest
)
