//
// Created by Christian nahuel Rivera on 15/6/19.
//

#include <map>
#include "../entities/Defines.h"
#include "../ConsoleGame.h"
#include "../players/GreedyPlayer.h"

int main(){
    ConsoleGame game;

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

    GreedyPlayer player(&pesos);

    game.runGame(player);

    return 0;
}