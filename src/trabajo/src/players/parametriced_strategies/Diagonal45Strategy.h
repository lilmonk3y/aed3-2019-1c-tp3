//
// Created by Christian nahuel Rivera on 17/6/19.
//

#ifndef AED3_TP3_DIAGONAL45STRATEGY_H
#define AED3_TP3_DIAGONAL45STRATEGY_H


#include "Strategy.h"

class Diagonal45Strategy : public Strategy{
public:
    virtual void selectMoves(Tablero *tablero, int cObjetivo, int miFicha) = 0;

    bool static completarDiagonal45(Tablero *tablero, int cObjetivo, int ficha, int indiceColumna,
                                    bool deboSumarUnaFicha);
protected:
    Diagonal45Strategy(float peso, int name) : Strategy(peso, name) {}
    void mejorDiagonal45(Tablero *tablero, int cObjetivo, int ficha);

};


#endif //AED3_TP3_DIAGONAL45STRATEGY_H
