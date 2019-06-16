cmake_minimum_required(VERSION 3.12)
project(aed3_tp3)

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -O2")

add_executable(random_player random_player.cpp)

add_executable(jugador_test
        trabajo/players/test_player_main.cpp
        trabajo/Game.cpp
        trabajo/Game.h
        trabajo/Player.cpp
        trabajo/Player.h
        trabajo/strategies/PlayStrategy.h
        trabajo/strategies/TestStrategy.cpp
        trabajo/strategies/TestStrategy.h
        trabajo/entities/Tablero.cpp
        trabajo/entities/Tablero.h)