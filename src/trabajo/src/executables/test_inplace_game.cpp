//
// Created by Christian nahuel Rivera on 29/6/19.
//

#include <utility>
#include <cstdlib>
#include <map>
#include <iostream>
#include "../entities/Defines.h"
#include "../players/GreedyPlayer.h"
#include "../entities/ResultadosPartida.h"
#include "../players/RandomPlayer.h"
#include "../InplaceGame.h"

int main(){
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

    GreedyPlayer jugadorAliado(&pesos);
    RandomPlayer jugadorEnemigo;

    ResultadosPartida resultados = jugar(4,4,2,10, jugadorAliado, jugadorEnemigo, FICHA_ALIADA);

    std::cout << "Ganador: " << resultados.isGanoNuestroJugador() << std::endl;

}