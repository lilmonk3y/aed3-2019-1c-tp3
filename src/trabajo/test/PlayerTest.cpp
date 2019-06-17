//
// Created by Christian nahuel Rivera on 16/6/19.
//

#include "gtest/gtest.h"
#include "../src/Player.h"
#include "../src/strategies/GreedyStrategy.h"

struct PlayerTest: testing::Test{
    Player *player;

    PlayerTest(){
        player = new Player();
    }

    ~PlayerTest(){
        delete player;
    }
};

TEST_F(PlayerTest, test)
{
    auto *pesos = new std::map<STRATEGY_NAME, PESO>();
    pesos->insert(std::make_pair(MEJOR_HORIZONTAL_OFENSIVO, 1));
    player = new Player(7, 6, 4, 21, new GreedyStrategy(pesos));

    int move = player->play();

    ASSERT_EQ(0, move);
}