//
// Created by Christian nahuel Rivera on 17/6/19.
//

#ifndef AED3_TP3_MEJORVERTICALDEFENSIVO_H
#define AED3_TP3_MEJORVERTICALDEFENSIVO_H


#include "../../entities/Defines.h"
#include "../../entities/Tablero.h"
#include "MejorVertical.h"

class MejorVerticalDefensivo : public MejorVertical {
public:
    explicit MejorVerticalDefensivo(int peso) : MejorVertical(peso, MEJOR_VERTICAL_DEFENSIVO) {}
    void selectMoves(Tablero *tablero, int cObjetivo) override;
};


#endif //AED3_TP3_MEJORVERTICALDEFENSIVO_H
