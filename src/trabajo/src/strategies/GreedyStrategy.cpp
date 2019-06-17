//
// Created by Christian nahuel Rivera on 15/6/19.
//

#include "GreedyStrategy.h"
#include "parametriced_strategies/HorizontalOfensivo.h"
#include "parametriced_strategies/HorizontalDefensivo.h"
#include "parametriced_strategies/VerticalOfensivo.h"
#include "parametriced_strategies/VerticalDefensivo.h"


GreedyStrategy::GreedyStrategy( std::map<STRATEGY_NAME, PESO> *pesos) {
    this->strategies = new std::map<STRATEGY_NAME, Strategy*>();

    this->strategies->insert(std::make_pair(HORIZONTAL_OFENSIVO,
                                            new HorizontalOfensivo(pesos->at(HORIZONTAL_OFENSIVO))));
    this->strategies->insert(std::make_pair(HORIZONTAL_OFENSIVO,
                                            new HorizontalDefensivo(pesos->at(HORIZONTAL_DEFENSIVO))));
    this->strategies->insert(std::make_pair(VERTICAL_OFENSIVO,
                                            new VerticalOfensivo(pesos->at(VERTICAL_OFENSIVO))));
    this->strategies->insert(std::make_pair(VERTICAL_DEFENSIVO,
                                            new VerticalDefensivo(pesos->at(VERTICAL_DEFENSIVO))));
}

int GreedyStrategy::selectMove(Tablero *tablero, int cObjetivo, int cantidadFichas) {
    // unoParaGanar()
    // unoParaPerder()

    std::vector<Strategy*> strategy;
    for (auto estrategia : *this->strategies) {
        estrategia.second->selectMoves(tablero, cObjetivo);

        strategy.push_back( estrategia.second);
    }

    std::sort(strategy.begin(), strategy.end());

    auto mejoresMovimientos = new std::vector<int>(tablero->getFilas(), 0);
    mejoresMovimientos = ponderarLosMovimientosDeLasEstrategias(strategy, mejoresMovimientos);

    return elegirMejorMovimientoFactible(tablero, mejoresMovimientos);
}







std::vector<int> * GreedyStrategy::ponderarLosMovimientosDeLasEstrategias(const std::vector<Strategy *> &strategy,
                                                                          std::vector<int> *mejoresMovimientos)  {
    for (auto estrategia : strategy) {
        for (auto movimiento : *estrategia->getMoves()){
            mejoresMovimientos->at(movimiento) += movimiento / estrategia->getWeigth();
        }
    }

    return mejoresMovimientos;
}

int GreedyStrategy::elegirMejorMovimientoFactible(Tablero *tablero, std::vector<int> *mejoresMovimientos)  {
    int mejorMovimiento = -1;
    for(int indiceColumna = 0; indiceColumna < tablero->getColumnas(); indiceColumna++){
        mejorMovimiento = elegirMejorIndice(mejoresMovimientos);

        if( tablero->columnaLlena(mejorMovimiento) ){
            mejoresMovimientos->at(mejorMovimiento) = -1;
        }else{
            break;
        }
    }
    return mejorMovimiento;
}

int GreedyStrategy::elegirMejorIndice(std::vector<int> *mejoresMovimientos) {
    int columna = 0;
    for(int index = 0; index < mejoresMovimientos->size(); index++){
        if(mejoresMovimientos->at(columna) < mejoresMovimientos->at(index)){
            columna = index;
        }
    }
    return columna;
}

