

macro(create_jitbuilder_target target) 
    add_executable(${target} ${ARGN})
    target_link_libraries(${target} 
        jitbuilder
        ${CMAKE_DL_LIBS}) 
endmacro(create_jitbuilder_target) 


create_jitbuilder_target(simple       src/Simple.cpp) 
create_jitbuilder_target(conditionals src/Conditionals.cpp) 
create_jitbuilder_target(dotproduct   src/DotProduct.cpp) 
create_jitbuilder_target(mandelbrot   src/Mandelbrot.cpp) 
