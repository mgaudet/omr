
find_program(
	CMAKE_ASM-TR_COMPILER
		NAMES "as"
		DOC "Assembler"
)
mark_as_advanced(CMAKE_TR-ASM_COMPILER)

set(CMAKE_ASM-TR_SOURCE_FILE_EXTENSIONS s)

configure_file(
	${CMAKE_CURRENT_LIST_DIR}/CMakeASM-TRCompiler.cmake.in
	${CMAKE_PLATFORM_INFO_DIR}/CMakeASM-TRCompiler.cmake.in
)
