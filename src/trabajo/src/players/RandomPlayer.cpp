//
// Created by Christian nahuel Rivera on 15/6/19.
//

#include <cstdlib>
#include "../entities/Tablero.h"
#include "RandomPlayer.h"

int RandomPlayer::play(Tablero *tablero, int miFicha, int c_objetivo) {
    return rand() % tablero->getColumnas();
}
