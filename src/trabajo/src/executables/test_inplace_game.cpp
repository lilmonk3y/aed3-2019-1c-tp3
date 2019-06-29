//
// Created by Christian nahuel Rivera on 29/6/19.
//

#include <utility>
#include <cstdlib>
#include <map>
#include "../entities/Defines.h"
#include "../players/GreedyPlayer.h"
#include "../entities/ResultadosPartida.h"
#include "../players/RandomPlayer.h"
#include "../InplaceGame.h"

int main(){
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

    ResultadosPartida *resultados = jugar(4,4,2,10, new GreedyPlayer(pesos), new RandomPlayer());

}