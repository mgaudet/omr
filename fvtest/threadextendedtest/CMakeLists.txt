add_executable(omrthreadextendedtest
	processTimeTest.cpp
	threadCpuTimeTest.cpp
	threadExtendedTestHelpers.cpp
	threadExtendedTestMain.cpp
	timeBaseTest.cpp
)

target_link_libraries(omrthreadextendedtest
	omrGtestGlue
	omrtestutil
	j9thrstatic
	omrport
)
