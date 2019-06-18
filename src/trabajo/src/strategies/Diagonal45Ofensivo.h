//
// Created by Christian nahuel Rivera on 17/6/19.
//

#ifndef AED3_TP3_DIAGONAL45OFENSIVO_H
#define AED3_TP3_DIAGONAL45OFENSIVO_H


#include "parametriced_strategies/Strategy.h"
#include "../entities/Defines.h"

class Diagonal45Ofensivo : public Strategy{
public:
    Diagonal45Ofensivo(float peso) : Strategy(peso, DIAGONAL_45_OFENSIVO){}
    void selectMoves(Tablero *tablero, int cObjetivo) override;

};


#endif //AED3_TP3_DIAGONAL45OFENSIVO_H
