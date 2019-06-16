//
// Created by Christian nahuel Rivera on 15/6/19.
//

#include "GreedyStrategy.h"
#include "parametriced_strategies/MejorHorizontalOfensivo.h"


GreedyStrategy::GreedyStrategy( std::map<STRATEGY_NAME, PESO> *pesos) {
    this->strategies = new std::map<STRATEGY_NAME, Strategy*>();

    this->strategies->insert(std::make_pair(MEJOR_HORIZONTAL_OFENSIVO,
            new MejorHorizontalOfensivo( MEJOR_HORIZONTAL_OFENSIVO, pesos->at(MEJOR_HORIZONTAL_OFENSIVO))));
}

int GreedyStrategy::selectMove(Tablero *tablero, int cObjetivo, int cantidadFichas) {
    // unoParaGanar()
    // unoParaPerder()

    std::vector<Strategy*> strategy;
    for (auto estrategia : *this->strategies) {
        estrategia.second->selectMoves(tablero, cObjetivo);

        strategy.push_back( estrategia.second);
    }

    // std::vector<Strategy*> strategy(strategies->begin(), strategies->end()); ver si se puede hacer
    std::sort(strategy.begin(), strategy.end());

    std::vector<int> bestMoves(tablero->getFilas(), 0);
    for (auto estrategia : strategy) {
        for (auto movimiento : *estrategia->getMoves()){
            bestMoves.at(movimiento) += movimiento / estrategia->getWeigth();
        }
    }

    return std::max_element(bestMoves.begin(), bestMoves.end()).operator*();
}

