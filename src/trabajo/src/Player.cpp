//
// Created by Christian nahuel Rivera on 15/6/19.
//

#include "Player.h"
#include "entities/Defines.h"

Player::Player(int columns, int rows, int cLinea, int cantidadFichas, PlayStrategy *strategy) {
    this->tablero = new Tablero(columns, rows);
    this->cLinea = cLinea;
    this->cantidadFichas = cantidadFichas;
    this->playStr = strategy;
}

int Player::play() {
    int jugada = playStr->selectMove(this->tablero, this->cLinea, this->cantidadFichas);
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