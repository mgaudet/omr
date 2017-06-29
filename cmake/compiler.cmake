Find_package(Perl)

if (NOT PERL_FOUND )
	message(FATAL_ERROR "Perl not found")
endif()
	
set(MASM2GAS_PATH ${CMAKE_SOURCE_DIR}/tools/compiler/scripts/masm2gas.pl)


#TODO These should be set by the appropriate platform detecton code
set(TR_TARGET_ARCH x)
set(TR_TARGET_SUBARCH amd64)

 
# Mark a target as consuming the comppiler components. 
# 
# This supplements the compile definitions, options and 
# include directories. 
function(make_compiler_target TARGET_NAME) 
   cmake_parse_arguments(TARGET 
      "" # Optional Arguments
      "COMPILER" # One value arguments
      ""
      ${ARGN}
      )

   set(COMPILER_DEFINES ${${TARGET_COMPILER}_DEFINES})
   message("making ${TARGET_NAME} into a compiler target, for ${TARGET_COMPILER}. Defines are ${COMPILER_DEFINES}") 
   target_compile_features(${TARGET_NAME} PUBLIC cxx_static_assert)


   target_include_directories(${TARGET_NAME} BEFORE PRIVATE 
      ./${TR_TARGET_ARCH}/${TR_TARGET_SUBARCH}
      ./${TR_TARGET_ARCH} 
      . 
      ${CMAKE_SOURCE_DIR}/compiler/${TR_TARGET_ARCH}/${TR_TARGET_SUBARCH}
      ${CMAKE_SOURCE_DIR}/compiler/${TR_TARGET_ARCH} 
      ${CMAKE_SOURCE_DIR}/compiler 
      ${CMAKE_SOURCE_DIR} 
      )

#hack definitions in
   target_compile_definitions(${TARGET_NAME} PRIVATE
      BITVECTOR_BIT_NUMBERING_MSB
      UT_DIRECT_TRACE_REGISTRATION
      TR_HOST_64BIT
      LINUX
      TR_HOST_X86
      TR_TARGET_X86
      TR_TARGET_64BIT
      ${COMPILER_DEFINES} 
      )

   target_compile_options(${TARGET_NAME} PRIVATE
      -w
      )

endfunction(make_compiler_target)

message(AUTHOR_WARNING "Currently creating a compiler target without any warnings enabled!") 



# Create an OMR Compiler component
# 
# call like this: 
#  create_omr_compiler_library(NAME <compilername>  
#                              OBJECTS <list of objects to add to the glue> 
#			       DEFINES <DEFINES for building library
function(create_omr_compiler_library)
   cmake_parse_arguments(COMPILER 
      "" # Optional Arguments
      "NAME" # One value arguments
      "OBJECTS;DEFINES" # Multi value args
      ${ARGV}
      )
   
   set(${COMPILER_NAME}_DEFINES ${COMPILER_DEFINES} CACHE INTERNAL "Defines for compiler ${COMPILER_NAME}") 
   #TODO there is a much cleaner way of doing this
   set(CMAKE_ASM-ATT_FLAGS
      BITVECTOR_BIT_NUMBERING_MSB
      UT_DIRECT_TRACE_REGISTRATION
      TR_HOST_64BIT
      LINUX
      TR_HOST_X86
      TR_TARGET_X86
      TR_TARGET_64BIT
      ${COMPILER_DEFINES}
      )



   set(EXTRA_COMPILER_OBJECTS "") 

   set(BUILD_NAME_FILE "${CMAKE_BINARY_DIR}/${COMPILER_NAME}Name.cpp")
   add_custom_command(OUTPUT ${BUILD_NAME_FILE}  
      		     COMMAND perl ${CMAKE_SOURCE_DIR}/tools/compiler/scripts/generateVersion.pl ${COMPILER_NAME} > ${BUILD_NAME_FILE}
		     VERBATIM
                     BYPRODUCTS ${BUILD_NAME_FILE}
                     COMMENT "Generate ${BUILD_NAME_FILE}"
      )
   # add_dependencies(${COMPILER_NAME} ${COMPILER_NAME}_name_file)


   add_library(${COMPILER_NAME} STATIC
      ${BUILD_NAME_FILE} 
      ${COMPILER_OBJECTS}
      )  


   macro(compiler_library libraryname)
      set(EXTRA_COMPILER_OBJECTS ${EXTRA_COMPILER_OBJECTS} ${ARGN} PARENT_SCOPE)
   endmacro(compiler_library)

   macro(add_compiler_subdirectory dir) 
      add_subdirectory(${CMAKE_SOURCE_DIR}/compiler/${dir}
                       ${CMAKE_CURRENT_BINARY_DIR}/compiler/${dir}_${COMPILER_NAME})
                    #target_link_Libraries(${COMPILER_NAME} PRIVATE ${COMPILER_NAME}_${dir}) # make_compiler_target(${COMPILER_NAME}_${dir}) 
   endmacro(add_compiler_subdirectory)


   if(OMR_ARCH_X86)
      add_compiler_subdirectory(x)
   endif()
   

   add_compiler_subdirectory(ras)
   add_compiler_subdirectory(compile)
   add_compiler_subdirectory(codegen)
   add_compiler_subdirectory(control)
   add_compiler_subdirectory(env)
   add_compiler_subdirectory(infra)
   add_compiler_subdirectory(il)
   add_compiler_subdirectory(optimizer)
   add_compiler_subdirectory(runtime)
   add_compiler_subdirectory(ilgen)

   #   message("Extra Compiler objects ${EXTRA_COMPILER_OBJECTS}") 

   target_sources(${COMPILER_NAME} PRIVATE ${EXTRA_COMPILER_OBJECTS})
   make_compiler_target(${COMPILER_NAME} COMPILER ${COMPILER_NAME})

endfunction(create_omr_compiler_library)
