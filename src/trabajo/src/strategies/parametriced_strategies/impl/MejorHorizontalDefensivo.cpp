//
// Created by Christian nahuel Rivera on 17/6/19.
//

#include "../MejorHorizontalDefensivo.h"
#include "../../../entities/Defines.h"

void MejorHorizontalDefensivo::selectMoves(Tablero *tablero, int cObjetivo) {
    mejorHorizontal(tablero, cObjetivo, JUGADA_ENEMIGA);
}


