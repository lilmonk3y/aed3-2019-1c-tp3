//
// Created by Christian nahuel Rivera on 17/6/19.
//

#ifndef AED3_TP3_MEJORVERTICALOFENSIVO_H
#define AED3_TP3_MEJORVERTICALOFENSIVO_H


#include "Strategy.h"
#include "../../entities/Defines.h"

class MejorVerticalOfensivo : public Strategy {
public:
    MejorVerticalOfensivo(int peso) : Strategy(peso, MEJOR_VERTICAL_OFENSIVO) {}
    void selectMoves(Tablero *tablero, int cObjetivo) override;
};


#endif //AED3_TP3_MEJORVERTICALOFENSIVO_H
