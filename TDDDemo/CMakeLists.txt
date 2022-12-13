cmake_minimum_required (VERSION 3.12)

project(TDDDemoProjekt)


set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/build/${PLATFORM_ARCHITECTURE}/$<CONFIG>)
set(PROJ_CONFIG $<CONFIG>)


add_executable(
	TDDDemoProjekt 
	source/main.cpp  
 "source/Stapel.h" "source/TranslatorClient.h" "source/Translator.h" source/StapelNeu.cpp source/StapelNeu.h)


# Add tests
add_subdirectory(tests)

