//
// Created by Christian nahuel Rivera on 17/6/19.
//

#include "../Diagonal315Defensivo.h"

void Diagonal315Defensivo::selectMoves(Tablero *tablero, int cObjetivo, int miFicha) {
    mejorDiagonal315(tablero,cObjetivo, fichaContraria(miFicha));
}

STRATEGY_NAME Diagonal315Defensivo::getName() {
    return DIAGONAL_315_DEFENSIVO;
}
