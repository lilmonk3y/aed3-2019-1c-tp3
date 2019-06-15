//
// Created by Christian nahuel Rivera on 15/6/19.
//

#include "Player.h"

#define JUGADA_ENEMIGA 0
#define JUGADA_ALIADA 1

Player::Player(int columns, int rows, int cLinea, int cantidadFichas, PlayStrategy *strategy) {
    this->tablero = new Tablero(columns, rows);
    this->cLinea = cLinea;
    this->cantidadFichas = cantidadFichas;
    this->playStr = strategy;
}

int Player::play() {
    int jugada = playStr->selectMove(this->tablero->getFilas());
    updateMyPlay(jugada);
    return jugada;
}

/* Actualizo el tablero con la ultima jugada realizada. */
void Player::updateOponentPlay(int fila) {
    tablero->play(fila, JUGADA_ENEMIGA);
}

void Player::updateMyPlay(int fila) {
    tablero->play(fila, JUGADA_ALIADA);
}