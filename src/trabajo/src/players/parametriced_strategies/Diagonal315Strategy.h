//
// Created by Christian nahuel Rivera on 17/6/19.
//

#ifndef AED3_TP3_DIAGONAL315STRATEGY_H
#define AED3_TP3_DIAGONAL315STRATEGY_H


#include "Strategy.h"

class Diagonal315Strategy : public Strategy {
public:
    virtual void selectMoves(Tablero *tablero, int cObjetivo, int miFicha) = 0;

    bool static completarDiagonal315(Tablero *tablero, int cObjetivo, int ficha, int indiceColumna,
                                 bool deboSumarUnaFicha);
protected:
    Diagonal315Strategy(float peso, int name) : Strategy(peso, name) {}
    void mejorDiagonal315(Tablero *tablero, int cObjetivo, int ficha);

};


#endif //AED3_TP3_DIAGONAL315STRATEGY_H
