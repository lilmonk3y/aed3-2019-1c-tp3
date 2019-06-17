//
// Created by Christian nahuel Rivera on 17/6/19.
//

#ifndef AED3_TP3_MEJORVERTICAL_H
#define AED3_TP3_MEJORVERTICAL_H


#include "Strategy.h"

class MejorVertical : public Strategy {
public:
    MejorVertical(int peso, int name) : Strategy(peso, name) {}
    virtual void selectMoves(Tablero *tablero, int cObjetivo) = 0;

protected:
    void mejorVertical(Tablero *tablero, int cObjetivo, int ofensivoOdefensivo);
};


#endif //AED3_TP3_MEJORVERTICAL_H
