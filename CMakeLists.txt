cmake_minimum_required(VERSION 3.12)
project(aed3_tp3)

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -O2")

set(SOURCES
        src/trabajo/src/strategies/PlayStrategy.h
        src/trabajo/src/strategies/GreedyStrategy.cpp
        src/trabajo/src/strategies/GreedyStrategy.h
        src/trabajo/src/strategies/parametriced_strategies/impl/MejorHorizontalOfensivo.cpp
        src/trabajo/src/strategies/parametriced_strategies/impl/MejorHorizontalDefensivo.cpp
        src/trabajo/src/strategies/parametriced_strategies/impl/MejorHorizontal.cpp
        src/trabajo/src/strategies/parametriced_strategies/MejorHorizontalOfensivo.h
        src/trabajo/src/strategies/parametriced_strategies/MejorHorizontalDefensivo.h
        src/trabajo/src/strategies/parametriced_strategies/MejorHorizontal.h
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
add_executable(tests ${SOURCES} src/trabajo/test/test_main.cpp src/trabajo/test/PlayerTest.cpp src/trabajo/src/strategies/parametriced_strategies/MejorVerticalOfensivo.cpp src/trabajo/src/strategies/parametriced_strategies/MejorVerticalOfensivo.h)

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
        ${SOURCES} src/trabajo/src/strategies/parametriced_strategies/impl/MejorHorizontal.cpp src/trabajo/src/strategies/parametriced_strategies/MejorHorizontal.h src/trabajo/src/strategies/parametriced_strategies/impl/MejorHorizontalDefensivo.cpp src/trabajo/src/strategies/parametriced_strategies/MejorHorizontalDefensivo.h src/trabajo/src/strategies/parametriced_strategies/MejorVerticalOfensivo.cpp src/trabajo/src/strategies/parametriced_strategies/MejorVerticalOfensivo.h)