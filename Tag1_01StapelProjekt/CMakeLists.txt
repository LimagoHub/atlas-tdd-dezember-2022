cmake_minimum_required (VERSION 3.12)

project(Tag1_01StapelProjekt)


set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/build/${PLATFORM_ARCHITECTURE}/$<CONFIG>)
set(PROJ_CONFIG $<CONFIG>)


add_executable(
	Tag1_01StapelProjekt 
	source/main.cpp  
 "source/stapel.h" "source/StapelException.h" "source/Stapel.cpp")


# Add tests
add_subdirectory(tests)

