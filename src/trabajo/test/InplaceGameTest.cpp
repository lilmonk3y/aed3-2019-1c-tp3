//
// Created by Christian nahuel Rivera on 21/7/19.
//

#include <gtest/gtest.h>
#include "../src/entities/Tablero.h"
#include "../src/InplaceGame.h"
#include "../src/players/parametriced_strategies/VerticalStrategy.h"
#include "../src/players/parametriced_strategies/HorizontalStrategy.h"
#include "../src/players/parametriced_strategies/Diagonal315Strategy.h"
#include "../src/players/parametriced_strategies/Diagonal45Strategy.h"


TEST(Inplace, test1){
    Tablero tablero = Tablero(5,6,3,30);
    tablero.actualizar(3, FICHA_ALIADA);
    tablero.actualizar(2, FICHA_TEST);
    tablero.actualizar(2, FICHA_ALIADA);
    tablero.actualizar(1, FICHA_TEST);
    tablero.actualizar(1, FICHA_TEST);
    tablero.actualizar(1, FICHA_ALIADA);

    bool resultado = gano(&tablero, FICHA_ALIADA);

    ASSERT_TRUE(resultado);
}

TEST(Inplace, test2){
    Tablero tablero = Tablero(5,6,3,30);
    tablero.actualizar(1, FICHA_TEST);
    tablero.actualizar(2, FICHA_TEST);
    tablero.actualizar(3, FICHA_TEST);
    tablero.actualizar(1, FICHA_ALIADA);
    tablero.actualizar(2, FICHA_ALIADA);
    tablero.actualizar(3, FICHA_ALIADA);

    bool resultado = gano(&tablero, FICHA_ALIADA);

    ASSERT_TRUE(resultado);
}

TEST(Inplace, test3){
    Tablero tablero = Tablero(5,6,3,30);
    tablero.actualizar(1, FICHA_ALIADA);
    tablero.actualizar(2, FICHA_ALIADA);
    tablero.actualizar(3, FICHA_ALIADA);

    bool resultado = gano(&tablero, FICHA_ALIADA);

    ASSERT_TRUE(resultado);
}

TEST(Inplace, test4){
    Tablero tablero = Tablero(5,6,3,30);
    tablero.actualizar(1, FICHA_TEST);
    tablero.actualizar(2, FICHA_TEST);
    tablero.actualizar(3, FICHA_TEST);
    tablero.actualizar(3, FICHA_ALIADA);
    tablero.actualizar(2, FICHA_TEST);
    tablero.actualizar(2, FICHA_ALIADA);
    tablero.actualizar(1, FICHA_TEST);
    tablero.actualizar(1, FICHA_TEST);
    tablero.actualizar(1, FICHA_ALIADA);

    bool resultado = gano(&tablero, FICHA_ALIADA);

    ASSERT_TRUE(resultado);
}

TEST(Inplace, test5){
    Tablero tablero = Tablero(5,6,3,30);
    tablero.actualizar(3, FICHA_TEST);
    tablero.actualizar(3, FICHA_TEST);
    tablero.actualizar(3, FICHA_ALIADA);
    tablero.actualizar(2, FICHA_TEST);
    tablero.actualizar(2, FICHA_ALIADA);
    tablero.actualizar(1, FICHA_ALIADA);

    bool resultado = gano(&tablero, FICHA_ALIADA);

    ASSERT_TRUE(resultado);
}

TEST(Inplace, test6){
    Tablero tablero = Tablero(5,6,3,30);
    tablero.actualizar(1, FICHA_TEST);
    tablero.actualizar(2, FICHA_TEST);
    tablero.actualizar(3, FICHA_TEST);
    tablero.actualizar(3, FICHA_TEST);
    tablero.actualizar(3, FICHA_TEST);
    tablero.actualizar(3, FICHA_ALIADA);
    tablero.actualizar(2, FICHA_TEST);
    tablero.actualizar(2, FICHA_ALIADA);
    tablero.actualizar(1, FICHA_ALIADA);

    bool resultado = gano(&tablero, FICHA_ALIADA);

    ASSERT_TRUE(resultado);
}

TEST(Inplace, test7){
    Tablero tablero = Tablero(5,6,3,30);
    tablero.actualizar(3, FICHA_ALIADA);
    tablero.actualizar(3, FICHA_ALIADA);
    tablero.actualizar(3, FICHA_ALIADA);

    bool resultado = gano(&tablero, FICHA_ALIADA);

    ASSERT_TRUE(resultado);
}

TEST(Inplace, test8){
    Tablero tablero = Tablero(5,6,3,30);
    tablero.actualizar(3, FICHA_TEST);
    tablero.actualizar(3, FICHA_ALIADA);
    tablero.actualizar(3, FICHA_ALIADA);
    tablero.actualizar(3, FICHA_ALIADA);

    bool resultado = gano(&tablero, FICHA_ALIADA);

    ASSERT_TRUE(resultado);
}