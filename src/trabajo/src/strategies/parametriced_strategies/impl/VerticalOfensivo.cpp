//
// Created by Christian nahuel Rivera on 17/6/19.
//

#include "../VerticalOfensivo.h"

void VerticalOfensivo::selectMoves(Tablero *tablero, int cObjetivo) {
    mejorVertical(tablero,cObjetivo,JUGADA_ALIADA);
}
