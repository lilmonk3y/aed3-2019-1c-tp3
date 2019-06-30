//
// Created by Christian nahuel Rivera on 27/6/19.
//

#include "GreedyPlayer.h"
#include "parametriced_strategies/HorizontalOfensivo.h"
#include "parametriced_strategies/HorizontalDefensivo.h"
#include "parametriced_strategies/VerticalOfensivo.h"
#include "parametriced_strategies/Diagonal45Defensivo.h"
#include "parametriced_strategies/VerticalDefensivo.h"
#include "parametriced_strategies/Diagonal45Ofensivo.h"
#include "parametriced_strategies/Diagonal315Ofensivo.h"
#include "parametriced_strategies/Diagonal315Defensivo.h"
#include "parametriced_strategies/JugadaAleatoria.h"
#include <algorithm>

GreedyPlayer::GreedyPlayer( std::map<STRATEGY_NAME, PESO> *pesos) {
    this->strategies = new std::map<STRATEGY_NAME, Strategy*>();

    this->strategies->insert(std::make_pair(HORIZONTAL_OFENSIVO,
                                            new HorizontalOfensivo(pesos->at(HORIZONTAL_OFENSIVO))));
    this->strategies->insert(std::make_pair(HORIZONTAL_DEFENSIVO,
                                            new HorizontalDefensivo(pesos->at(HORIZONTAL_DEFENSIVO))));
    this->strategies->insert(std::make_pair(VERTICAL_OFENSIVO,
                                            new VerticalOfensivo(pesos->at(VERTICAL_OFENSIVO))));
    this->strategies->insert(std::make_pair(VERTICAL_DEFENSIVO,
                                            new VerticalDefensivo(pesos->at(VERTICAL_DEFENSIVO))));
    this->strategies->insert(std::make_pair(DIAGONAL_45_OFENSIVO,
                                            new Diagonal45Ofensivo(pesos->at(DIAGONAL_45_OFENSIVO))));
    this->strategies->insert(std::make_pair(DIAGONAL_45_DEFENSIVO,
                                            new Diagonal45Defensivo(pesos->at(DIAGONAL_45_DEFENSIVO))));
    this->strategies->insert(std::make_pair(DIAGONAL_315_OFENSIVO,
                                            new Diagonal315Ofensivo(pesos->at(DIAGONAL_315_OFENSIVO))));
    this->strategies->insert(std::make_pair(DIAGONAL_315_DEFENSIVO,
                                            new Diagonal315Defensivo(pesos->at(DIAGONAL_315_DEFENSIVO))));
    this->strategies->insert(std::make_pair(JUGADA_ALEATORIA,
                                            new JugadaAleatoria(pesos->at(JUGADA_ALEATORIA))));
}

int GreedyPlayer::play(Tablero& tablero, FICHA miColor) {
    std::vector<Strategy*> strategy;
    for (auto estrategia : *this->strategies) {
        estrategia.second->selectMoves(&tablero, tablero.getFichasParaGanar(), miColor);

        strategy.push_back( estrategia.second);
    }

    std::sort(strategy.begin(), strategy.end());

    auto mejoresMovimientos = new std::vector<int>(tablero.getColumnas(), 0);
    mejoresMovimientos = ponderarLosMovimientosDeLasEstrategias(strategy, mejoresMovimientos);

    return elegirMejorMovimientoFactible(&tablero, mejoresMovimientos);
}

std::vector<int> * GreedyPlayer::ponderarLosMovimientosDeLasEstrategias(const std::vector<Strategy *> &strategy,
                                                                          std::vector<int> *mejoresMovimientos)  {
    for (auto estrategia : strategy) {
        for (auto movimiento : *estrategia->getMoves()){
            mejoresMovimientos->at(movimiento) += estrategia->getWeigth();
        }
    }

    return mejoresMovimientos;
}

int GreedyPlayer::elegirMejorMovimientoFactible(Tablero *tablero, std::vector<int> *mejoresMovimientos)  {
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

int GreedyPlayer::elegirMejorIndice(std::vector<int> *mejoresMovimientos) {
    int columna = 0;
    for(int index = 0; index < mejoresMovimientos->size(); index++){
        if(mejoresMovimientos->at(columna) < mejoresMovimientos->at(index)){
            columna = index;
        }
    }
    return columna;
}