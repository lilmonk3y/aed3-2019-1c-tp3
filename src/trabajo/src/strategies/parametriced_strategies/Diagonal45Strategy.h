//
// Created by Christian nahuel Rivera on 17/6/19.
//

#ifndef AED3_TP3_DIAGONAL45STRATEGY_H
#define AED3_TP3_DIAGONAL45STRATEGY_H


#include "Strategy.h"

class Diagonal45Strategy : public Strategy{
public:
    Diagonal45Strategy(float peso, int name) : Strategy(peso, name) {}
    virtual void selectMoves(Tablero *tablero, int cObjetivo) = 0;

protected:
    void mejorDiagonal45(Tablero *tablero, int cObjetivo, int ofensivoOdefensivo);
};


#endif //AED3_TP3_DIAGONAL45STRATEGY_H
