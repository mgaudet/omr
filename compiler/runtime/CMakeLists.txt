    #$(JIT_OMR_DIRTY_DIR)/runtime/Runtime.cpp \
    #$(JIT_OMR_DIRTY_DIR)/runtime/Trampoline.cpp \
    #$(JIT_OMR_DIRTY_DIR)/runtime/Alignment.cpp \
    #$(JIT_OMR_DIRTY_DIR)/runtime/CodeCacheTypes.cpp \
    #$(JIT_OMR_DIRTY_DIR)/runtime/OMRCodeCache.cpp \
    #$(JIT_OMR_DIRTY_DIR)/runtime/OMRCodeCacheManager.cpp \
    #$(JIT_OMR_DIRTY_DIR)/runtime/OMRCodeCacheMemorySegment.cpp \
    #$(JIT_OMR_DIRTY_DIR)/runtime/OMRCodeCacheConfig.cpp \

add_library(tr_runtime STATIC
	Runtime.cpp
	Trampoline.cpp
	Alignment.cpp
	CodeCacheTypes.cpp
	OMRCodeCache.cpp
	OMRCodeCacheManager.cpp
	OMRCodeCacheMemorySegment.cpp
	OMRCodeCacheConfig.cpp
)

target_link_libraries(tr_runtime tr_TargetRuntime)
