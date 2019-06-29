//
// Created by Christian nahuel Rivera on 27/6/19.
//

#ifndef AED3_TP3_GREEDYPLAYER_H
#define AED3_TP3_GREEDYPLAYER_H

#include "iPlayer.h"
#include "../entities/Defines.h"
#include "parametriced_strategies/Strategy.h"
#include <map>

class GreedyPlayer : public iPlayer {
public:
    GreedyPlayer(std::map<STRATEGY_NAME,PESO> *pesosEstrategias);
    int play(Tablero *tablero, int miFicha, int c_objetivo) override;

private:
    std::map<STRATEGY_NAME, Strategy*> *strategies;

    int elegirMejorMovimientoFactible(Tablero *tablero, std::vector<int> *mejoresMovimientos);

    std::vector<int> *
    ponderarLosMovimientosDeLasEstrategias(const std::vector<Strategy *> &strategy,
                                           std::vector<int> *mejoresMovimientos);

    int elegirMejorIndice(std::vector<int> *pVector);
};


#endif //AED3_TP3_GREEDYPLAYER_H
