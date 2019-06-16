//
// Created by Christian nahuel Rivera on 15/6/19.
//

#ifndef AED3_TP3_GREEDYSTRATEGY_H
#define AED3_TP3_GREEDYSTRATEGY_H


#include "PlayStrategy.h"
#include "parametriced_strategies/Strategy.h"
#include "../entities/Defines.h"
#include <map>
#define STRATEGY_NAME int

class GreedyStrategy : public PlayStrategy {
public:
    GreedyStrategy(std::map<STRATEGY_NAME, PESO> *pesos);
    int selectMove(Tablero *tablero, int cObjetivo, int cantidadFichas) override;

private:
    std::map<STRATEGY_NAME, Strategy*> *strategies;
};


#endif //AED3_TP3_GREEDYSTRATEGY_H
