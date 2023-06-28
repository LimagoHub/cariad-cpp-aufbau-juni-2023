cmake_minimum_required(VERSION 3.25)
project(NimSpielProjekt)

set(CMAKE_CXX_STANDARD 17)

add_executable(NimSpielProjekt main.cpp game/game.h client/GameClient.h game/NimGame/nim_game_impl.h)
