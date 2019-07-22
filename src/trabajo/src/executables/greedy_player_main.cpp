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
    pesos[HORIZONTAL_OFENSIVO] = 47;
    pesos[HORIZONTAL_DEFENSIVO] = 80;
    pesos[VERTICAL_OFENSIVO] = 98;
    pesos[VERTICAL_DEFENSIVO] = 75;
    pesos[DIAGONAL_45_OFENSIVO] = 40;
    pesos[DIAGONAL_45_DEFENSIVO] = 78;
    pesos[DIAGONAL_315_OFENSIVO] = 28;
    pesos[DIAGONAL_315_DEFENSIVO] = 40;
    pesos[JUGADA_ALEATORIA] = 90;

    GreedyPlayer player(&pesos);

    game.runGame(player);

    return 0;
}