//
// Created by Christian nahuel Rivera on 18/6/19.
//

#include "../JugadaAleatoria.h"
#include <random>

void JugadaAleatoria::selectMoves(Tablero *tablero, int cObjetivo) {
    this->moves->clear();

    this->moves->push_back(std::rand() % tablero->getColumnas());
}
