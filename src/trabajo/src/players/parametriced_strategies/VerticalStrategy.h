//
// Created by Christian nahuel Rivera on 17/6/19.
//

#ifndef AED3_TP3_MEJORVERTICAL_H
#define AED3_TP3_MEJORVERTICAL_H


#include "Strategy.h"

class VerticalStrategy : public Strategy {
public:
    virtual void selectMoves(Tablero *tablero, int cObjetivo, int miFicha) = 0;

    bool static completarColumna(Tablero *tablero, int cObjetivo, int ficha, int indexColumna,
                              bool deboSumarMiJugada);
protected:
    VerticalStrategy(int peso, int name) : Strategy(peso, name) {}
    void mejorVertical(Tablero *tablero, int cObjetivo, int ficha);

};


#endif //AED3_TP3_MEJORVERTICAL_H
