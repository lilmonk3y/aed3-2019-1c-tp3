//
// Created by Christian nahuel Rivera on 18/6/19.
//

#ifndef AED3_TP3_JUGADAALEATORIA_H
#define AED3_TP3_JUGADAALEATORIA_H


#include "Strategy.h"
#include "../../entities/Defines.h"

class JugadaAleatoria : public Strategy{
public:
    JugadaAleatoria(float peso) : Strategy(peso, JUGADA_ALEATORIA) {}
    void selectMoves(Tablero *tablero, int cObjetivo, int miFicha);
};


#endif //AED3_TP3_JUGADAALEATORIA_H
