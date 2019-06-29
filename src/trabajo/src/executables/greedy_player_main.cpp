//
// Created by Christian nahuel Rivera on 15/6/19.
//

#include <map>
#include "../entities/Defines.h"
#include "../ConsoleGame.h"
#include "../players/GreedyPlayer.h"

int main(){
    ConsoleGame *game = new ConsoleGame();

    auto *pesos = new std::map<STRATEGY_NAME, PESO>();
    pesos->insert(std::make_pair(HORIZONTAL_OFENSIVO, std::rand()));
    pesos->insert(std::make_pair(HORIZONTAL_DEFENSIVO, std::rand()));
    pesos->insert(std::make_pair(VERTICAL_OFENSIVO, std::rand()));
    pesos->insert(std::make_pair(VERTICAL_DEFENSIVO, std::rand()));
    pesos->insert(std::make_pair(DIAGONAL_45_OFENSIVO, std::rand()));
    pesos->insert(std::make_pair(DIAGONAL_45_DEFENSIVO, std::rand()));
    pesos->insert(std::make_pair(DIAGONAL_315_OFENSIVO, std::rand()));
    pesos->insert(std::make_pair(DIAGONAL_315_DEFENSIVO, std::rand()));
    pesos->insert(std::make_pair(JUGADA_ALEATORIA, std::rand()));

    game->runGame(new GreedyPlayer(pesos));

    return 0;
}