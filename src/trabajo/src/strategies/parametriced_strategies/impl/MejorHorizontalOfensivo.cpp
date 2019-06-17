//
// Created by Christian nahuel Rivera on 15/6/19.
//

#include "../MejorHorizontalOfensivo.h"
#include "../../../entities/Defines.h"

void MejorHorizontalOfensivo::selectMoves(Tablero *tablero, int cObjetivo) {
    mejorHorizontal(tablero, cObjetivo, JUGADA_ALIADA);
}



