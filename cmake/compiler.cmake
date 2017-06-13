Find_package(Perl)

if (NOT PERL_FOUND )
	message(FATAL_ERROR "Perl not found")
else()
	message(STATUS PERL = ${PERL_EXECUTABLE})
endif()
	

set(MASM2GAS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../fvtest/compilertest/build/scripts/masm2gas.pl)
# Create an OMR Compiler component
# 
# call like this: 
#  create_omr_compiler_library(NAME <compilername>  
#                              GLUE_OBJECTS <list of objects to add to the glue> 
function(create_omr_compiler_library)

   set(CMAKE_INCLUDE_CURRENT_DIR OFF)
   #TODO these should not be force-set
   set(TR_TARGET_ARCH x)
   set(TR_TARGET_SUBARCH amd64)

   cmake_parse_arguments(COMPILER 
      "" # Optional Arguments
      "NAME" # One value arguments
      "OBJECTS" # Multi value args
      ${ARGN}
      )

   #TODO needs to be in compiler detection wrapper

   message(STATUS "Creating ${COMPILER_NAME} compiler component") 



   add_library(${COMPILER_NAME} STATIC
      ${COMPILER_OBJECTS}
      )    	

   function(create_compiler_target target) 
      target_compile_features(${target} PUBLIC cxx_static_assert)

      target_include_directories(${target} BEFORE PRIVATE 
         ./${TR_TARGET_ARCH}/${TR_TARGET_SUBARCH}
         ./${TR_TARGET_ARCH} 
         . 
         ${CMAKE_SOURCE_DIR}/compiler/${TR_TARGET_ARCH}/${TR_TARGET_SUBARCH}
         ${CMAKE_SOURCE_DIR}/compiler/${TR_TARGET_ARCH} 
         ${CMAKE_SOURCE_DIR}/compiler 
         ${CMAKE_SOURCE_DIR} 
         )

      #hack definitions in
      target_compile_definitions(${target} PRIVATE
         $<UPPER_CASE:${COMPILER_NAME}>_PROJECT_SPECIFIC
         BITVECTOR_BIT_NUMBERING_MSB
         UT_DIRECT_TRACE_REGISTRATION
         JITTEST
         TR_HOST_64BIT
         LINUX
         TR_HOST_X86
         TR_TARGET_X86
         TR_TARGET_64BIT
         )

      target_compile_options(${target} PRIVATE
         -w
         )


   endfunction(create_compiler_target)

   create_compiler_target(${COMPILER_NAME})

 
      #TODO there is a much cleaner way of doing this
   set(CMAKE_ASM-ATT_FLAGS
      -DBITVECTOR_BIT_NUMBERING_MSB
      -DUT_DIRECT_TRACE_REGISTRATION
      -DJITTEST
      -DTR_HOST_64BIT
      -DLINUX
      -DTR_HOST_X86
      -DTR_TARGET_X86
      -DTR_TARGET_64BIT
      )
 
   function(compiler_library libraryname)
    add_library(${COMPILER_NAME}_${libraryname} ${ARGN})
   endfunction(compiler_library)

   macro(add_compiler_subdirectory dir) 
      add_subdirectory(${CMAKE_SOURCE_DIR}/compiler/${dir}
                       ${CMAKE_CURRENT_BINARY_DIR}/compiler/${dir}_${COMPILER_NAME})
      target_link_Libraries(${COMPILER_NAME} PRIVATE ${COMPILER_NAME}_${dir})
      create_compiler_target(${COMPILER_NAME}_${dir}) 
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
   
endfunction(create_omr_compiler_library)
