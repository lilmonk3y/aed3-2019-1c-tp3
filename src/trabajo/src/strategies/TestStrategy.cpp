//
// Created by Christian nahuel Rivera on 15/6/19.
//

#include "TestStrategy.h"
#include <cstdlib>

int TestStrategy::selectMove(Tablero *tablero, int cObjetivo, int cantidadFichas) {
    return rand() % tablero->getFilas();
}
