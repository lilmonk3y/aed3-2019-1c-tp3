//
// Created by Christian nahuel Rivera on 17/6/19.
//

#ifndef AED3_TP3_DIAGONAL315OFENSIVO_H
#define AED3_TP3_DIAGONAL315OFENSIVO_H


#include "Strategy.h"
#include "../../entities/Defines.h"

class Diagonal315Ofensivo : public Strategy {
public:
    explicit Diagonal315Ofensivo(float peso) : Strategy(peso, DIAGONAL_315_OFENSIVO) {}
    void selectMoves(Tablero *tablero, int cObjetivo) override;
};


#endif //AED3_TP3_DIAGONAL315OFENSIVO_H
