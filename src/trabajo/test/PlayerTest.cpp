//
// Created by Christian nahuel Rivera on 16/6/19.
//

#include "gtest/gtest.h"
#include "../src/players/GreedyPlayer.h"

struct PlayerTest : testing::Test{
    iPlayer *player;

    PlayerTest(){}

    ~PlayerTest(){
        delete player;
    }
};

TEST_F(PlayerTest, test)
{
    auto *pesos = new std::map<STRATEGY_NAME, PESO>();
    pesos->insert(std::make_pair(HORIZONTAL_OFENSIVO, 1));
    pesos->insert(std::make_pair(HORIZONTAL_DEFENSIVO, std::rand()));
    pesos->insert(std::make_pair(VERTICAL_OFENSIVO, std::rand()));
    pesos->insert(std::make_pair(VERTICAL_DEFENSIVO, std::rand()));
    pesos->insert(std::make_pair(DIAGONAL_45_OFENSIVO, std::rand()));
    pesos->insert(std::make_pair(DIAGONAL_45_DEFENSIVO, std::rand()));
    pesos->insert(std::make_pair(DIAGONAL_315_OFENSIVO, std::rand()));
    pesos->insert(std::make_pair(DIAGONAL_315_DEFENSIVO, std::rand()));
    pesos->insert(std::make_pair(JUGADA_ALEATORIA, std::rand()));
    player = new GreedyPlayer(pesos);
    Tablero *tablero = new Tablero(4,4,3,8);

    int move = player->play(tablero,FICHA_ALIADA,2);

    ASSERT_GE(move, 0);
    ASSERT_LE(move, 3);
}