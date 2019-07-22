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
    pesos[HORIZONTAL_OFENSIVO] = 40;
    pesos[HORIZONTAL_DEFENSIVO] = 9;
    pesos[VERTICAL_OFENSIVO] = 92;
    pesos[VERTICAL_DEFENSIVO] = 65;
    pesos[DIAGONAL_45_OFENSIVO] = 57;
    pesos[DIAGONAL_45_DEFENSIVO] = 9;
    pesos[DIAGONAL_315_OFENSIVO] = 33;
    pesos[DIAGONAL_315_DEFENSIVO] = 60;
    pesos[JUGADA_ALEATORIA] = 29;

    GreedyPlayer player(&pesos);

    game.runGame(player);

    return 0;
}