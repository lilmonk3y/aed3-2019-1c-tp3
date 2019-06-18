//
// Created by Christian nahuel Rivera on 17/6/19.
//

#include "../Diagonal315Ofensivo.h"

void Diagonal315Ofensivo::selectMoves(Tablero *tablero, int cObjetivo) {
    mejorDiagonal315(tablero,cObjetivo,JUGADA_ALIADA);
}
