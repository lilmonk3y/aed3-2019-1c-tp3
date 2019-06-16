//
// Created by Christian nahuel Rivera on 15/6/19.
//

#include "../Game.h"
#include "../strategies/GreedyStrategy.h"

int main(){
    Game *game = new Game();

    auto *pesos = new std::map<STRATEGY_NAME, PESO>();
    pesos->insert(std::make_pair(MEJOR_HORIZONTAL_OFENSIVO, 1));

    game->runGame(new GreedyStrategy(pesos));

    return 0;
}