//
// Created by Christian nahuel Rivera on 16/6/19.
//

#include "gtest/gtest.h"
#include "../../src/players/GreedyPlayer.h"

struct PlayerTest : testing::Test{
    iPlayer *player;

    PlayerTest(){}

    ~PlayerTest(){
        delete player;
    }
};

TEST_F(PlayerTest, test) {
    std::map<STRATEGY_NAME, PESO> pesos;
    pesos[HORIZONTAL_OFENSIVO] = std::rand();
    pesos[HORIZONTAL_DEFENSIVO] = std::rand();
    pesos[VERTICAL_OFENSIVO] = std::rand();
    pesos[VERTICAL_DEFENSIVO] = std::rand();
    pesos[DIAGONAL_45_OFENSIVO] = std::rand();
    pesos[DIAGONAL_45_DEFENSIVO] = std::rand();
    pesos[DIAGONAL_315_OFENSIVO] = std::rand();
    pesos[DIAGONAL_315_DEFENSIVO] = std::rand();
    pesos[JUGADA_ALEATORIA] = std::rand();
    
    player = new GreedyPlayer(&pesos);
    Tablero tablero(4, 4, 3, 8);

    int move = player->play(tablero, FICHA_ALIADA);

    ASSERT_GE(move, 0);
    ASSERT_LE(move, 3);
}