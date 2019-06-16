cmake_minimum_required(VERSION 3.12)
project(aed3_tp3)

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -O2")

add_executable(random_player src/random_player.cpp)

add_executable(jugador_test
        src/trabajo/src/players/test_player_main.cpp
        src/trabajo/src/Game.cpp
        src/trabajo/src/Game.h
        src/trabajo/src/Player.cpp
        src/trabajo/src/Player.h
        src/trabajo/src/strategies/PlayStrategy.h
        src/trabajo/src/strategies/TestStrategy.cpp
        src/trabajo/src/strategies/TestStrategy.h
        src/trabajo/src/entities/Tablero.cpp
        src/trabajo/src/entities/Tablero.h)