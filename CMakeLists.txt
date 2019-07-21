cmake_minimum_required(VERSION 3.12)
project(aed3_tp3)

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -O2")

set(SOURCES
        src/trabajo/src/players/parametriced_strategies/impl/HorizontalOfensivo.cpp
        src/trabajo/src/players/parametriced_strategies/impl/HorizontalDefensivo.cpp
        src/trabajo/src/players/parametriced_strategies/impl/HorizontalStrategy.cpp
        src/trabajo/src/players/parametriced_strategies/HorizontalOfensivo.h
        src/trabajo/src/players/parametriced_strategies/HorizontalDefensivo.h
        src/trabajo/src/players/parametriced_strategies/HorizontalStrategy.h
        src/trabajo/src/players/parametriced_strategies/impl/VerticalDefensivo.cpp
        src/trabajo/src/players/parametriced_strategies/impl/VerticalOfensivo.cpp
        src/trabajo/src/players/parametriced_strategies/impl/VerticalStrategy.cpp
        src/trabajo/src/players/parametriced_strategies/VerticalDefensivo.h
        src/trabajo/src/players/parametriced_strategies/VerticalOfensivo.h
        src/trabajo/src/players/parametriced_strategies/VerticalStrategy.h
        src/trabajo/src/players/parametriced_strategies/impl/Diagonal45Ofensivo.cpp
        src/trabajo/src/players/parametriced_strategies/impl/Diagonal45Defensivo.cpp
        src/trabajo/src/players/parametriced_strategies/impl/Diagonal45Strategy.cpp
        src/trabajo/src/players/parametriced_strategies/Diagonal45Ofensivo.h
        src/trabajo/src/players/parametriced_strategies/Diagonal45Defensivo.h
        src/trabajo/src/players/parametriced_strategies/Diagonal45Strategy.h
        src/trabajo/src/players/parametriced_strategies/impl/Diagonal315Defensivo.cpp
        src/trabajo/src/players/parametriced_strategies/impl/Diagonal315Ofensivo.cpp
        src/trabajo/src/players/parametriced_strategies/impl/Diagonal315Strategy.cpp
        src/trabajo/src/players/parametriced_strategies/Diagonal315Defensivo.h
        src/trabajo/src/players/parametriced_strategies/Diagonal315Ofensivo.h
        src/trabajo/src/players/parametriced_strategies/Diagonal315Strategy.h
        src/trabajo/src/players/parametriced_strategies/impl/JugadaAleatoria.cpp
        src/trabajo/src/players/parametriced_strategies/JugadaAleatoria.h
        src/trabajo/src/players/parametriced_strategies/impl/Strategy.cpp
        src/trabajo/src/players/parametriced_strategies/Strategy.h
        src/trabajo/src/players/GreedyPlayer.cpp
        src/trabajo/src/players/GreedyPlayer.h
        src/trabajo/src/players/RandomPlayer.cpp
        src/trabajo/src/players/RandomPlayer.h
        src/trabajo/src/players/iPlayer.h
        src/trabajo/src/entities/Tablero.cpp
        src/trabajo/src/entities/Tablero.h
        src/trabajo/src/entities/Defines.h
        src/trabajo/src/entities/Individuo.h
        src/trabajo/src/entities/Individuo.cpp
        src/trabajo/src/entities/Solucion.h
        src/trabajo/src/entities/Solucion.cpp
        )

#GTEST_BEGIN
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

#Define your executable
add_executable(tests
        src/trabajo/src/entities/ResultadosPartida.h
        src/trabajo/src/InplaceGame.h
        src/trabajo/src/InplaceGame.cpp
        ${SOURCES}
        src/trabajo/test/test_main.cpp
        src/trabajo/test/players/PlayerTest.cpp
        src/trabajo/test/players/parametriced_strategies/VerticalStrategyTest.cpp
        src/trabajo/test/players/parametriced_strategies/HorizontalStrategyTest.cpp
        src/trabajo/test/players/parametriced_strategies/Diagonal45StrategyTest.cpp
        src/trabajo/test/players/parametriced_strategies/Diagonal315StrategyTest.cpp
        src/trabajo/test/InplaceGameTest.cpp)

#Link with GoogleTest
target_link_libraries(tests gtest gtest_main)

#Link with GoogleMock
target_link_libraries(tests gmock gmock_main)
#GTEST_END

add_executable(random_player
        src/trabajo/src/executables/random_player_main.cpp
        src/trabajo/src/ConsoleGame.cpp
        src/trabajo/src/ConsoleGame.h
        src/trabajo/src/players/RandomPlayer.cpp
        src/trabajo/src/players/RandomPlayer.h
        src/trabajo/src/entities/Tablero.cpp
        src/trabajo/src/entities/Tablero.h)

add_executable(jugador_greedy
        src/trabajo/src/executables/greedy_player_main.cpp
        src/trabajo/src/ConsoleGame.cpp
        src/trabajo/src/ConsoleGame.h
        ${SOURCES})

add_executable(test_inplace_game
        src/trabajo/src/executables/test_inplace_game.cpp
        src/trabajo/src/entities/ResultadosPartida.h
        src/trabajo/src/InplaceGame.h
        src/trabajo/src/InplaceGame.cpp
        ${SOURCES})

add_executable(optimizaciones_jugador_greedy
        src/trabajo/src/executables/optimizaciones_genetico_jugador_greedy_main.cpp
        src/trabajo/src/entities/ResultadosPartida.h
        src/trabajo/src/InplaceGame.h
        src/trabajo/src/InplaceGame.cpp
        src/trabajo/src/parameter_optimizations/AlgoritmoGenetico.h
        src/trabajo/src/parameter_optimizations/AlgoritmoGenetico.cpp
        src/trabajo/src/parameter_optimizations/GridSearch.h
        src/trabajo/src/parameter_optimizations/GridSearch.cpp
        ${SOURCES})

add_executable(grid_search_main
        src/trabajo/src/parameter_optimizations/grid_search_main.cpp
        src/trabajo/src/players/iPlayer.h
        src/trabajo/src/players/ParamsStrategy.h
        src/trabajo/src/players/ParamsStrategy.cpp
        src/trabajo/src/entities/Tablero.cpp
        src/trabajo/src/entities/Tablero.h
        src/trabajo/src/entities/Defines.h
        src/trabajo/src/InplaceGame.cpp
        src/trabajo/src/InplaceGame.h)