//
// Created by Christian nahuel Rivera on 21/7/19.
//

#include <map>
#include <iostream>
#include "../entities/Defines.h"
#include "../InplaceGame.h"
#include "../players/GreedyPlayer.h"
#include "../players/RandomPlayer.h"


int main(){
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
    RandomPlayer randomPlayer1 = RandomPlayer();
    Tablero tablero = Tablero(8, 8, 4, 100);
    int ganar = 0;
    for(int index = 0; index < 100; index ++){
        ResultadosPartida resultadosPartida = jugar(tablero,player,randomPlayer1, FICHA_ALIADA);
        if(resultadosPartida.isGanoNuestroJugador()){
            ganar++;
        }
    }
    std::cout << ganar << std::endl;
    return 0;
}