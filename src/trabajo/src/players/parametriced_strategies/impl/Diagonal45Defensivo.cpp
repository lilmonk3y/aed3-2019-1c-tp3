//
// Created by Christian nahuel Rivera on 17/6/19.
//

#include "../Diagonal45Defensivo.h"

void Diagonal45Defensivo::selectMoves(Tablero *tablero, int cObjetivo, int miFicha) {
    mejorDiagonal45(tablero, cObjetivo, fichaContraria(miFicha));
}

STRATEGY_NAME Diagonal45Defensivo::getName() {
    return DIAGONAL_45_DEFENSIVO;
}
