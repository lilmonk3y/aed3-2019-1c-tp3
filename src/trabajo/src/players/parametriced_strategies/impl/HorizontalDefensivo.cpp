//
// Created by Christian nahuel Rivera on 17/6/19.
//

#include "../HorizontalDefensivo.h"
#include "../../../entities/Defines.h"

void HorizontalDefensivo::selectMoves(Tablero *tablero, int cObjetivo, int miFicha) {
    mejorHorizontal(tablero, cObjetivo, fichaContraria(miFicha));
}


