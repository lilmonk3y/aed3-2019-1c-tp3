cmake_minimum_required(VERSION 3.12)
project(aed3_tp3)

set(CMAKE_CXX_STANDARD 14)

add_executable(aed3_tp3
        src/random_player.cpp src/trabajo/entities/Tablero.cpp src/trabajo/entities/Tablero.h src/trabajo/strategies/TestStrategy.cpp src/trabajo/strategies/TestStrategy.h src/trabajo/players/test_player_main.cpp src/trabajo/Game.cpp src/trabajo/Game.h src/trabajo/strategies/PlayStrategy.h src/trabajo/Player.cpp src/trabajo/Player.h)

add_executable(jugador_test src/trabajo/players/test_player_main.cpp src/trabajo/Game.cpp src/trabajo/Game.h src/trabajo/Player.cpp src/trabajo/Player.h src/trabajo/strategies/PlayStrategy.h src/trabajo/strategies/TestStrategy.cpp src/trabajo/strategies/TestStrategy.h src/trabajo/entities/Tablero.cpp src/trabajo/entities/Tablero.h)