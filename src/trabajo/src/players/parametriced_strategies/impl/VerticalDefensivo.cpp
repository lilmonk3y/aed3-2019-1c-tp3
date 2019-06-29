//
// Created by Christian nahuel Rivera on 17/6/19.
//

#include "../VerticalDefensivo.h"

void VerticalDefensivo::selectMoves(Tablero *tablero, int cObjetivo, int miFicha) {
    mejorVertical(tablero,cObjetivo,fichaContraria(miFicha));
}
