//
// Created by Christian nahuel Rivera on 17/6/19.
//

#include "../VerticalDefensivo.h"

void VerticalDefensivo::selectMoves(Tablero *tablero, int cObjetivo) {
    mejorVertical(tablero,cObjetivo,JUGADA_ENEMIGA);
}
