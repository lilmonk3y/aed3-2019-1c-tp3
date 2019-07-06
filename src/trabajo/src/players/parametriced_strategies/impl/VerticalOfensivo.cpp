//
// Created by Christian nahuel Rivera on 17/6/19.
//

#include "../VerticalOfensivo.h"

void VerticalOfensivo::selectMoves(Tablero *tablero, int cObjetivo, int miFicha) {
    mejorVertical(tablero,cObjetivo,miFicha);
}

STRATEGY_NAME VerticalOfensivo::getName() {
    return VERTICAL_OFENSIVO;
}
