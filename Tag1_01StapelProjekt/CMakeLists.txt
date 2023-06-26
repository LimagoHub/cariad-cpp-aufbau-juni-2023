cmake_minimum_required (VERSION 3.12)

project(StapelProjektProject)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/build/${PLATFORM_ARCHITECTURE}/$<CONFIG>)
set(PROJ_CONFIG $<CONFIG>)


add_executable(
	StapelProjektProject 
	source/main.cpp  
	"source/collections/Stapel.h" 
	"source/collections/StapelException.h" 
	"source/collections/Stapel.cpp")


# Add tests
add_subdirectory(tests)

