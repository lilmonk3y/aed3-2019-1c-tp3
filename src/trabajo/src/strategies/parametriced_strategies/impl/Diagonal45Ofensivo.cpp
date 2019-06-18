//
// Created by Christian nahuel Rivera on 17/6/19.
//

#include "../Diagonal45Ofensivo.h"

void Diagonal45Ofensivo::selectMoves(Tablero *tablero, int cObjetivo) {
    mejorDiagonal45(tablero,cObjetivo,JUGADA_ALIADA);
}
