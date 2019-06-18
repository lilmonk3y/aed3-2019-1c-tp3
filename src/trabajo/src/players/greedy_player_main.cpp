//
// Created by Christian nahuel Rivera on 15/6/19.
//

#include "../Game.h"
#include "../strategies/GreedyStrategy.h"
#include "../entities/Defines.h"


int main(){
    Game *game = new Game();

    auto *pesos = new std::map<STRATEGY_NAME, PESO>();
    pesos->insert(std::make_pair(HORIZONTAL_OFENSIVO, std::rand()));
    pesos->insert(std::make_pair(HORIZONTAL_DEFENSIVO, std::rand()));
    pesos->insert(std::make_pair(VERTICAL_OFENSIVO, std::rand()));
    pesos->insert(std::make_pair(VERTICAL_DEFENSIVO, std::rand()));
    pesos->insert(std::make_pair(DIAGONAL_45_OFENSIVO, std::rand()));
    pesos->insert(std::make_pair(DIAGONAL_45_DEFENSIVO, std::rand()));
    pesos->insert(std::make_pair(DIAGONAL_315_OFENSIVO, std::rand()));
    pesos->insert(std::make_pair(DIAGONAL_315_DEFENSIVO, std::rand()));

    game->runGame(new GreedyStrategy(pesos));

    return 0;
}