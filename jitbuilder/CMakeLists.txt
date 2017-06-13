include(../cmake/compiler.cmake)

set(JITBUILDER_OBJECTS
    env/FrontEnd.cpp
    compile/Method.cpp
    control/Jit.cpp
    ilgen/JBIlGeneratorMethodDetails.cpp
    optimizer/JBOptimizer.hpp
    optimizer/JBOptimizer.cpp
    optimizer/Optimizer.hpp
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

