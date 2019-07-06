//
// Created by Christian nahuel Rivera on 17/6/19.
//

#include "../Diagonal315Ofensivo.h"

void Diagonal315Ofensivo::selectMoves(Tablero *tablero, int cObjetivo, int miFicha) {
    mejorDiagonal315(tablero,cObjetivo,miFicha);
}

STRATEGY_NAME Diagonal315Ofensivo::getName() {
    return DIAGONAL_315_OFENSIVO;
}
