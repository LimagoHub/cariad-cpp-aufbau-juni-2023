cmake_minimum_required(VERSION 3.25)
project(NimSpielProjekt)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/build/${PLATFORM_ARCHITECTURE}/$<CONFIG>)
set(PROJ_CONFIG $<CONFIG>)

add_executable(NimSpielProjekt main.cpp game/game.h client/GameClient.h game/NimGame/nim_game_impl.h)
# Add tests
add_subdirectory(tests)