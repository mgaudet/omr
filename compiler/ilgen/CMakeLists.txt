
    
        

add_library(tr_ilgen INTERFACE)
target_sources(tr_ilgen INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}/IlGenRequest.cpp 


)

add_library(tr_ilbuilder INTERFACE)
target_sources(tr_ilbuilder INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}/IlBuilder.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IlInjector.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/MethodBuilder.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/BytecodeBuilder.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/TypeDictionary.cpp

	#the following is only consumed by jitbuilder?
	${CMAKE_CURRENT_SOURCE_DIR}/ThunkBuilder.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/VirtualMachineOperandStack.cpp
)
