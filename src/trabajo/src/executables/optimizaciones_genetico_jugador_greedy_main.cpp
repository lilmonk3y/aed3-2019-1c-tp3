//
// Created by Christian nahuel Rivera on 30/6/19.
//

#include "../players/RandomPlayer.h"
#include "../parameter_optimizations/AlgoritmoGenetico.h"
#include "../players/GreedyPlayer.h"
#include "../entities/Tablero.h"
#include <map>

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

    AlgoritmoGenetico *optimizaciones = new AlgoritmoGenetico(10, 6, 10, new Tablero(8,8,4, 100), new GreedyPlayer(&pesos), new RandomPlayer());

    Individuo* individuo = optimizaciones->correrAlgoritmo();
}
