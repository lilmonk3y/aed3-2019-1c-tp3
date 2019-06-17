//
// Created by Christian nahuel Rivera on 17/6/19.
//

#include "../MejorVerticalDefensivo.h"

void MejorVerticalDefensivo::selectMoves(Tablero *tablero, int cObjetivo) {
    mejorVertical(tablero,cObjetivo,JUGADA_ENEMIGA);
}
