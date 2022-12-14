cmake_minimum_required (VERSION 3.12)

project(ParameterTestProjekt)


set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/build/${PLATFORM_ARCHITECTURE}/$<CONFIG>)
set(PROJ_CONFIG $<CONFIG>)


add_executable(
	ParameterTestProjekt 
	source/main.cpp  
)


# Add tests
add_subdirectory(tests)

