//
// Created by Christian nahuel Rivera on 6/7/19.
//

#include <gtest/gtest.h>
#include "../../../src/players/parametriced_strategies/Strategy.h"
#include "../../../src/players/parametriced_strategies/VerticalOfensivo.h"
#include "../../../src/players/parametriced_strategies/VerticalDefensivo.h"

struct VerticalStrategyTest : testing::Test{
    Strategy* verticalStrategy;
    int jugada = FICHA_ALIADA;
    //int ficha = FICHA_ALIADA;
    int ficha = FICHA_ENEMIGA;

    VerticalStrategyTest(){
        //verticalStrategy = new VerticalOfensivo(std::rand());
        verticalStrategy = new VerticalDefensivo(std::rand());
    }

    ~VerticalStrategyTest(){
        delete verticalStrategy;
    }
};

TEST_F(VerticalStrategyTest, whenNearToFillAColumn_mustPlayInIt){
    Tablero tablero = Tablero(5,6,3,30);
    tablero.actualizar(1,ficha);
    tablero.actualizar(1,ficha);

    verticalStrategy->selectMoves(&tablero,3,jugada);

    ASSERT_EQ(1, verticalStrategy->getMoves()->size());
    ASSERT_EQ(1,verticalStrategy->getMoves()->back());
}

TEST_F(VerticalStrategyTest, whenColumnIsLonguerWantNeeded_mustPlayInIt){
    Tablero tablero = Tablero(5,6,3,30);
    tablero.actualizar(3,ficha);
    tablero.actualizar(3,ficha);
    tablero.actualizar(3,ficha);
    tablero.actualizar(3,ficha);
    tablero.actualizar(3,ficha);

    tablero.actualizar(1,ficha);
    tablero.actualizar(1,ficha);

    verticalStrategy->selectMoves(&tablero,3,jugada);

    ASSERT_EQ(2, verticalStrategy->getMoves()->size());
    ASSERT_EQ(3,verticalStrategy->getMoves()->back());
    ASSERT_EQ(1,verticalStrategy->getMoves()->front());
}

TEST_F(VerticalStrategyTest, whenBoardHasNoEmptyRow_mustNotPlay){
    Tablero tablero = Tablero(1,6,3,30);
    tablero.actualizar(0,ficha);
    tablero.actualizar(0,ficha);
    tablero.actualizar(0,ficha);
    tablero.actualizar(0,ficha);
    tablero.actualizar(0,ficha);
    tablero.actualizar(0,ficha);

    verticalStrategy->selectMoves(&tablero,3,jugada);

    ASSERT_EQ(0, verticalStrategy->getMoves()->size());
}