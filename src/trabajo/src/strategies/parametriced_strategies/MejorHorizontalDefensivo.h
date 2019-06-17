//
// Created by Christian nahuel Rivera on 17/6/19.
//

#ifndef AED3_TP3_MEJORHORIZONTALDEFENSIVO_H
#define AED3_TP3_MEJORHORIZONTALDEFENSIVO_H


#include "MejorHorizontal.h"
#include "../../entities/Defines.h"

class MejorHorizontalDefensivo : public MejorHorizontal {
public:
    explicit MejorHorizontalDefensivo(int peso) : MejorHorizontal(peso, MEJOR_HORIZONTAL_DEFENSIVO) {};
    void selectMoves(Tablero *tablero, int cObjetivo) override;
};


#endif //AED3_TP3_MEJORHORIZONTALDEFENSIVO_H
