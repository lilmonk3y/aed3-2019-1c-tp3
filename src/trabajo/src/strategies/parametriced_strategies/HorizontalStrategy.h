//
// Created by Christian nahuel Rivera on 17/6/19.
//

#ifndef AED3_TP3_MEJORHORIZONTAL_H
#define AED3_TP3_MEJORHORIZONTAL_H


#include "Strategy.h"

class HorizontalStrategy : public Strategy {
public:
    HorizontalStrategy(int peso, int name) : Strategy(peso, name) {}
    virtual void selectMoves(Tablero *tablero, int cObjetivo) = 0;

protected:
    void mejorHorizontal(Tablero *tablero, int cObjetivo, int ofensivoOdefensivo);
    bool completarFila(int columnaEsperada, int indiceFila, int jugadasDelJugador, int cObjetivo, Tablero *tablero);
};


#endif //AED3_TP3_MEJORHORIZONTAL_H
