//
// Created by Christian nahuel Rivera on 21/7/19.
//

#include <gtest/gtest.h>
#include "../../../src/players/parametriced_strategies/Strategy.h"
#include "../../../src/players/parametriced_strategies/Diagonal45Ofensivo.h"
#include "../../../src/players/parametriced_strategies/Diagonal45Defensivo.h"

struct Diagonal45StrategyTest : testing::Test{
    Strategy* diagonalStrategy;
    int jugada = FICHA_ALIADA;
    //int ficha = FICHA_ALIADA;
    int ficha = FICHA_ENEMIGA;
    Diagonal45StrategyTest(){
        //diagonalStrategy = new Diagonal45Ofensivo(std::rand());
        diagonalStrategy = new Diagonal45Defensivo(std::rand());
    }

    ~Diagonal45StrategyTest(){
        delete diagonalStrategy;
    }
};

TEST_F(Diagonal45StrategyTest, test1){
    Tablero tablero = Tablero(5,6,3,30);
    tablero.actualizar(2, FICHA_TEST);
    tablero.actualizar(2, ficha);
    tablero.actualizar(3, FICHA_TEST);
    tablero.actualizar(3, FICHA_TEST);
    tablero.actualizar(3, ficha);

    diagonalStrategy->selectMoves(&tablero,3,jugada);

    ASSERT_EQ(1, diagonalStrategy->getMoves()->size());
    ASSERT_EQ(1,diagonalStrategy->getMoves()->back());

}

TEST_F(Diagonal45StrategyTest, test2){
    Tablero tablero = Tablero(5,6,3,30);
    tablero.actualizar(1, ficha);
    tablero.actualizar(2, FICHA_TEST);
    tablero.actualizar(3, FICHA_TEST);
    tablero.actualizar(3, FICHA_TEST);
    tablero.actualizar(3, ficha);

    diagonalStrategy->selectMoves(&tablero,3,jugada);

    ASSERT_EQ(1, diagonalStrategy->getMoves()->size());
    ASSERT_EQ(2,diagonalStrategy->getMoves()->back());

}

TEST_F(Diagonal45StrategyTest, test3){
    Tablero tablero = Tablero(5,6,3,30);
    tablero.actualizar(1, ficha);
    tablero.actualizar(2, FICHA_TEST);
    tablero.actualizar(2, ficha);
    tablero.actualizar(3, FICHA_TEST);
    tablero.actualizar(3, FICHA_TEST);

    diagonalStrategy->selectMoves(&tablero,3,jugada);

    ASSERT_EQ(1, diagonalStrategy->getMoves()->size());
    ASSERT_EQ(3,diagonalStrategy->getMoves()->back());

}