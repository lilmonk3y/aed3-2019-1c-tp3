//
// Created by Christian nahuel Rivera on 17/6/19.
//

#ifndef AED3_TP3_MEJORHORIZONTAL_H
#define AED3_TP3_MEJORHORIZONTAL_H


#include "Strategy.h"

class HorizontalStrategy : public Strategy {
public:
    virtual void selectMoves(Tablero *tablero, int cObjetivo, int miFicha) = 0;

    static bool completarFila(int indiceColumna, int ficha, int cObjetivo, Tablero *tablero,
                              bool deboSumarUnaJugada);
protected:
    HorizontalStrategy(int peso, int name) : Strategy(peso, name) {}
    void mejorHorizontal(Tablero *tablero, int cObjetivo, int ficha);
};


#endif //AED3_TP3_MEJORHORIZONTAL_H
