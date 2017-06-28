include(../cmake/compiler.cmake)

set(JITBUILDER_OBJECTS
    env/FrontEnd.cpp
    compile/Method.cpp
    control/Jit.cpp
    ilgen/JBIlGeneratorMethodDetails.cpp
    optimizer/JBOptimizer.hpp
    optimizer/JBOptimizer.cpp
    optimizer/Optimizer.hpp
    runtime/JBCodeCacheManager.cpp
    )



if(OMR_ARCH_X86)
    list(APPEND JITBUILDER_OBJECTS 
        x/codegen/Evaluator.cpp
        x/runtime/AsmUtil64.asm
        )
elseif(OMR_ARCH_S390) 
    list(APPEND JITBUILDER_OBJECTS 
        z/codegen/Evaluator.cpp
        z/codegen/JBCodeGenerator.cpp
        )
# elseif(OMR_ARCH_POWER)
#     list(APPEND JITBUILDER_OBJECTS 
#         p/codegen/Evaluator.cpp
#         p/runtime/CodeSync.cpp
#         p/runtime/AsmUtil.spp
#         p/runtime/CodeDispatch.spp
#         )
endif()


create_omr_compiler_library(NAME            jitbuilder
                            OBJECTS    ${JITBUILDER_OBJECTS})

# Add interface path so that include paths propagate. 
# NOTE: Relase isn't being automatically setup, so this 
#       Won't yet work on a clone!
target_include_directories(jitbuilder 
    INTERFACE release/include release/include/compiler
)


add_subdirectory(release)

# install(TARGETS jitbuilder 
#         ARCHIVE       DESTINATION ${CMAKE_BINARY_DIR}/jitbuilder_release
#         PUBLIC_HEADER DESTINATION ${CMAKE_BINARY_DIR}/jitbuilder_release/include
#         )
# 

# #Create release directory
# file(MAKE_DIRECTORY jitbuilder_release) 
# file(COPY ${jitbuilder_library} DESTINATION jitbuilder_release) 
# file(COPY ${CMAKE_SOURCE_DIR}/compiler/env   DESTINATION jitbuilder_release/include) 
# file(COPY ${CMAKE_SOURCE_DIR}/compiler/il    DESTINATION jitbuilder_release/include) 
# file(COPY ${CMAKE_SOURCE_DIR}/compiler/ilgen DESTINATION jitbuilder_release/include) 



