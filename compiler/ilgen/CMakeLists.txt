
    
        

compiler_library(ilgen
	${CMAKE_CURRENT_SOURCE_DIR}/IlGenRequest.cpp 


)

compiler_library(ilbuilder 
	${CMAKE_CURRENT_SOURCE_DIR}/IlBuilder.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IlInjector.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/MethodBuilder.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/BytecodeBuilder.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/TypeDictionary.cpp

	#the following is only consumed by jitbuilder?
	${CMAKE_CURRENT_SOURCE_DIR}/ThunkBuilder.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/VirtualMachineOperandStack.cpp
)
