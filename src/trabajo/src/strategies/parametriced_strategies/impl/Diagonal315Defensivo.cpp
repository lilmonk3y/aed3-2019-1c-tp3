//
// Created by Christian nahuel Rivera on 17/6/19.
//

#include "../Diagonal315Defensivo.h"

void Diagonal315Defensivo::selectMoves(Tablero *tablero, int cObjetivo) {
    mejorDiagonal315(tablero,cObjetivo, JUGADA_ENEMIGA);
}
