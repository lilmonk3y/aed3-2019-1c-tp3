//
// Created by Christian nahuel Rivera on 21/7/19.
//

#include <gtest/gtest.h>
#include "../../../src/players/parametriced_strategies/Strategy.h"
#include "../../../src/players/parametriced_strategies/Diagonal315Ofensivo.h"
#include "../../../src/players/parametriced_strategies/Diagonal315Defensivo.h"

struct Diagonal315StrategyTest : testing::Test{
    Strategy* diagonalStrategy;
    int jugada = FICHA_ALIADA;
    //int ficha = FICHA_ALIADA;
    int ficha = FICHA_ENEMIGA;
    Diagonal315StrategyTest(){
        //diagonalStrategy = new Diagonal315Ofensivo(std::rand());
        diagonalStrategy = new Diagonal315Defensivo(std::rand());
    }

    ~Diagonal315StrategyTest(){
        delete diagonalStrategy;
    }
};

TEST_F(Diagonal315StrategyTest, test1){
Tablero tablero = Tablero(5,6,3,30);
tablero.actualizar(2, FICHA_TEST);
tablero.actualizar(2, ficha);
tablero.actualizar(1, FICHA_TEST);
tablero.actualizar(1, FICHA_TEST);
tablero.actualizar(1, ficha);

diagonalStrategy->selectMoves(&tablero,3,jugada);

ASSERT_EQ(1, diagonalStrategy->getMoves()->size());
ASSERT_EQ(3,diagonalStrategy->getMoves()->back());

}


TEST_F(Diagonal315StrategyTest, test2){
    Tablero tablero = Tablero(5,6,3,30);
    tablero.actualizar(3, ficha);
    tablero.actualizar(2, FICHA_TEST);
    tablero.actualizar(1, FICHA_TEST);
    tablero.actualizar(1, FICHA_TEST);
    tablero.actualizar(1, ficha);

    diagonalStrategy->selectMoves(&tablero,3,jugada);

    ASSERT_EQ(1, diagonalStrategy->getMoves()->size());
    ASSERT_EQ(2,diagonalStrategy->getMoves()->back());

}

TEST_F(Diagonal315StrategyTest, test3){
    Tablero tablero = Tablero(5,6,3,30);
    tablero.actualizar(3, ficha);
    tablero.actualizar(2, FICHA_TEST);
    tablero.actualizar(2, ficha);
    tablero.actualizar(1, FICHA_TEST);
    tablero.actualizar(1, FICHA_TEST);

    diagonalStrategy->selectMoves(&tablero,3,jugada);

    ASSERT_EQ(1, diagonalStrategy->getMoves()->size());
    ASSERT_EQ(1,diagonalStrategy->getMoves()->back());

}

TEST_F(Diagonal315StrategyTest, test4){
    Tablero tablero = Tablero(5,6,3,30);
    tablero.actualizar(1, FICHA_TEST);
    tablero.actualizar(2, FICHA_TEST);
    tablero.actualizar(3, FICHA_TEST);
    tablero.actualizar(3, ficha);
    tablero.actualizar(2, FICHA_TEST);
    tablero.actualizar(1, FICHA_TEST);
    tablero.actualizar(1, FICHA_TEST);
    tablero.actualizar(1, ficha);

    diagonalStrategy->selectMoves(&tablero,3,jugada);

    ASSERT_EQ(1, diagonalStrategy->getMoves()->size());
    ASSERT_EQ(2,diagonalStrategy->getMoves()->back());

}