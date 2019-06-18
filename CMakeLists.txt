cmake_minimum_required(VERSION 3.12)
project(aed3_tp3)

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -O2")

set(SOURCES
        src/trabajo/src/strategies/PlayStrategy.h
        src/trabajo/src/strategies/GreedyStrategy.cpp
        src/trabajo/src/strategies/GreedyStrategy.h
        src/trabajo/src/strategies/parametriced_strategies/impl/HorizontalOfensivo.cpp
        src/trabajo/src/strategies/parametriced_strategies/impl/HorizontalDefensivo.cpp
        src/trabajo/src/strategies/parametriced_strategies/impl/HorizontalStrategy.cpp
        src/trabajo/src/strategies/parametriced_strategies/HorizontalOfensivo.h
        src/trabajo/src/strategies/parametriced_strategies/HorizontalDefensivo.h
        src/trabajo/src/strategies/parametriced_strategies/HorizontalStrategy.h
        src/trabajo/src/strategies/parametriced_strategies/impl/VerticalDefensivo.cpp
        src/trabajo/src/strategies/parametriced_strategies/impl/VerticalOfensivo.cpp
        src/trabajo/src/strategies/parametriced_strategies/impl/VerticalStrategy.cpp
        src/trabajo/src/strategies/parametriced_strategies/VerticalDefensivo.h
        src/trabajo/src/strategies/parametriced_strategies/VerticalOfensivo.h
        src/trabajo/src/strategies/parametriced_strategies/VerticalStrategy.h
        src/trabajo/src/strategies/parametriced_strategies/impl/Diagonal45Ofensivo.cpp
        src/trabajo/src/strategies/parametriced_strategies/impl/Diagonal45Defensivo.cpp
        src/trabajo/src/strategies/parametriced_strategies/impl/Diagonal45Strategy.cpp
        src/trabajo/src/strategies/parametriced_strategies/Diagonal45Ofensivo.h
        src/trabajo/src/strategies/parametriced_strategies/Diagonal45Defensivo.h
        src/trabajo/src/strategies/parametriced_strategies/Diagonal45Strategy.h
        src/trabajo/src/strategies/parametriced_strategies/impl/Strategy.cpp
        src/trabajo/src/strategies/parametriced_strategies/Strategy.h
        src/trabajo/src/entities/Tablero.cpp
        src/trabajo/src/entities/Tablero.h
        src/trabajo/src/entities/Defines.h
        src/trabajo/src/Player.cpp
        src/trabajo/src/Player.h
        src/trabajo/src/Game.cpp
        src/trabajo/src/Game.h)

#GTEST_BEGIN
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

#Define your executable
add_executable(tests ${SOURCES} src/trabajo/test/test_main.cpp src/trabajo/test/PlayerTest.cpp src/trabajo/src/strategies/parametriced_strategies/impl/VerticalOfensivo.cpp src/trabajo/src/strategies/parametriced_strategies/VerticalOfensivo.h src/trabajo/src/strategies/parametriced_strategies/impl/VerticalDefensivo.cpp src/trabajo/src/strategies/parametriced_strategies/VerticalDefensivo.h src/trabajo/src/strategies/parametriced_strategies/impl/Diagonal45Ofensivo.cpp src/trabajo/src/strategies/parametriced_strategies/Diagonal45Ofensivo.h src/trabajo/src/strategies/parametriced_strategies/impl/Diagonal45Defensivo.cpp src/trabajo/src/strategies/parametriced_strategies/Diagonal45Defensivo.h)

#Link with GoogleTest
target_link_libraries(tests gtest gtest_main)

#Link with GoogleMock
target_link_libraries(tests gmock gmock_main)
#GTEST_END

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



add_executable(jugador_greedy
        src/trabajo/src/players/greedy_player_main.cpp
        ${SOURCES})