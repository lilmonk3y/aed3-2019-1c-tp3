//
// Created by Christian nahuel Rivera on 16/7/19.
//

#include <gtest/gtest.h>
#include "../../../src/players/parametriced_strategies/Strategy.h"
#include "../../../src/players/parametriced_strategies/HorizontalStrategy.h"
#include "../../../src/players/parametriced_strategies/HorizontalOfensivo.h"
#include "../../../src/players/parametriced_strategies/HorizontalDefensivo.h"

struct HorizontalStrategyTest : testing::Test{
    Strategy* horizontalStrategy;
    int jugada = FICHA_ALIADA;
    //int ficha = FICHA_ALIADA;
    int ficha = FICHA_ENEMIGA;
    HorizontalStrategyTest(){
        //horizontalStrategy = new HorizontalOfensivo(std::rand());
        horizontalStrategy = new HorizontalDefensivo(std::rand());
    }

    ~HorizontalStrategyTest(){
        delete horizontalStrategy;
    }
};

TEST_F(HorizontalStrategyTest, test1){
    Tablero tablero = Tablero(5,6,3,30);
    tablero.actualizar(1,ficha);
    tablero.actualizar(3,ficha);

    horizontalStrategy->selectMoves(&tablero,3,jugada);

    ASSERT_EQ(1, horizontalStrategy->getMoves()->size());
    ASSERT_EQ(2,horizontalStrategy->getMoves()->back());
}

TEST_F(HorizontalStrategyTest, test2){
    Tablero tablero = Tablero(5,6,3,30);
    tablero.actualizar(1,FICHA_TEST);
    tablero.actualizar(3,FICHA_TEST);
    tablero.actualizar(2,FICHA_TEST);
    tablero.actualizar(1,FICHA_TEST);
    tablero.actualizar(3,FICHA_TEST);
    tablero.actualizar(2,FICHA_TEST);
    tablero.actualizar(1,ficha);
    tablero.actualizar(3,ficha);

    horizontalStrategy->selectMoves(&tablero,3,jugada);

    ASSERT_EQ(1, horizontalStrategy->getMoves()->size());
    ASSERT_EQ(2,horizontalStrategy->getMoves()->back());
}

TEST_F(HorizontalStrategyTest, test3){
    Tablero tablero = Tablero(5,6,3,30);
    tablero.actualizar(1,FICHA_TEST);
    tablero.actualizar(3,FICHA_TEST);
    tablero.actualizar(2,FICHA_TEST);
    tablero.actualizar(1,FICHA_TEST);
    tablero.actualizar(3,FICHA_TEST);
    tablero.actualizar(2,FICHA_TEST);
    tablero.actualizar(1,ficha);
    tablero.actualizar(2,ficha);

    horizontalStrategy->selectMoves(&tablero,3,jugada);

    ASSERT_EQ(1, horizontalStrategy->getMoves()->size());
    ASSERT_EQ(3,horizontalStrategy->getMoves()->back());
}

TEST_F(HorizontalStrategyTest, test4){
    Tablero tablero = Tablero(5,6,3,30);
    tablero.actualizar(1,FICHA_TEST);
    tablero.actualizar(3,FICHA_TEST);
    tablero.actualizar(2,FICHA_TEST);
    tablero.actualizar(1,FICHA_TEST);
    tablero.actualizar(3,FICHA_TEST);
    tablero.actualizar(2,FICHA_TEST);
    tablero.actualizar(2,ficha);
    tablero.actualizar(3,ficha);

    horizontalStrategy->selectMoves(&tablero,3,jugada);

    ASSERT_EQ(1, horizontalStrategy->getMoves()->size());
    ASSERT_EQ(1,horizontalStrategy->getMoves()->back());
}