
    #$(JIT_OMR_DIRTY_DIR)/ilgen/IlGenRequest.cpp \
    #$(JIT_OMR_DIRTY_DIR)/ilgen/IlBuilder.cpp \
    #$(JIT_OMR_DIRTY_DIR)/ilgen/IlInjector.cpp \
    #$(JIT_OMR_DIRTY_DIR)/ilgen/MethodBuilder.cpp \
    #$(JIT_OMR_DIRTY_DIR)/ilgen/BytecodeBuilder.cpp \
    #$(JIT_OMR_DIRTY_DIR)/ilgen/TypeDictionary.cpp \

add_library(tr_ilgen STATIC
	IlGenRequest.cpp
	IlBuilder.cpp
	IlInjector.cpp
	MethodBuilder.cpp
	BytecodeBuilder.cpp
	TypeDictionary.cpp
)
