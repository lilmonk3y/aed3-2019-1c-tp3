cmake_minimum_required(VERSION 3.12)
project(aed3_tp3)

set(CMAKE_CXX_STANDARD 14)

add_executable(aed3_tp3
        src/random_player.cpp src/trabajo/entities/Tablero.cpp src/trabajo/entities/Tablero.h src/trabajo/strategies/TestStrategy.cpp src/trabajo/strategies/TestStrategy.h src/trabajo/players/test_player_main.cpp src/trabajo/Game.cpp src/trabajo/Game.h src/trabajo/strategies/PlayStrategy.h src/trabajo/Player.cpp src/trabajo/Player.h src/trabajo/players/greedy_player_main.cpp src/trabajo/strategies/GreedyStrategy.cpp src/trabajo/strategies/GreedyStrategy.h src/trabajo/strategies/parametriced_strategies/Strategy.h src/trabajo/strategies/parametriced_strategies/Strategy.cpp src/trabajo/strategies/parametriced_strategies/MejorHorizontalOfensivo.cpp src/trabajo/strategies/parametriced_strategies/MejorHorizontalOfensivo.h src/trabajo/entities/Defines.h)

add_executable(jugador_test src/trabajo/players/test_player_main.cpp src/trabajo/Game.cpp src/trabajo/Game.h src/trabajo/Player.cpp src/trabajo/Player.h src/trabajo/strategies/PlayStrategy.h src/trabajo/strategies/TestStrategy.cpp src/trabajo/strategies/TestStrategy.h src/trabajo/entities/Tablero.cpp src/trabajo/entities/Tablero.h)

add_executable(jugador_greedy src/trabajo/players/greedy_player_main.cpp src/trabajo/Game.h src/trabajo/Player.h src/trabajo/strategies/GreedyStrategy.h src/trabajo/strategies/parametriced_strategies/Strategy.h src/trabajo/strategies/PlayStrategy.h src/trabajo/entities/Tablero.h src/trabajo/strategies/parametriced_strategies/MejorHorizontalOfensivo.h src/trabajo/entities/Defines.h  src/trabajo/strategies/GreedyStrategy.cpp src/trabajo/strategies/parametriced_strategies/MejorHorizontalOfensivo.cpp src/trabajo/Game.cpp src/trabajo/Player.cpp src/trabajo/entities/Tablero.cpp src/trabajo/strategies/parametriced_strategies/Strategy.cpp)