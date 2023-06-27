cmake_minimum_required (VERSION 3.12)

project(BlankCMakeProject)


set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/build/${PLATFORM_ARCHITECTURE}/$<CONFIG>)
set(PROJ_CONFIG $<CONFIG>)


add_executable(
	BlankCMakeProject 
	source/main.cpp
        source/Dependency.h source/DependencyImpl.cpp source/DependencyImpl.h source/MyServiceUsingDependency.h source/DemoDepenency.h)


# Add tests
add_subdirectory(tests)

