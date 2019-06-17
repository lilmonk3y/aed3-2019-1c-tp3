//
// Created by Christian nahuel Rivera on 17/6/19.
//

#ifndef AED3_TP3_MEJORVERTICALOFENSIVO_H
#define AED3_TP3_MEJORVERTICALOFENSIVO_H


#include "../../entities/Defines.h"
#include "MejorVertical.h"

class MejorVerticalOfensivo : public MejorVertical {
public:
    explicit MejorVerticalOfensivo(int peso) : MejorVertical(peso, MEJOR_VERTICAL_OFENSIVO) {}
    void selectMoves(Tablero *tablero, int cObjetivo) override;
};


#endif //AED3_TP3_MEJORVERTICALOFENSIVO_H
