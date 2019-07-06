//
// Created by Christian nahuel Rivera on 15/6/19.
//

#include "../HorizontalOfensivo.h"
#include "../../../entities/Defines.h"

void HorizontalOfensivo::selectMoves(Tablero *tablero, int cObjetivo, int miFicha) {
    mejorHorizontal(tablero, cObjetivo, miFicha);
}

STRATEGY_NAME HorizontalOfensivo::getName() {
    return HORIZONTAL_OFENSIVO;
}



