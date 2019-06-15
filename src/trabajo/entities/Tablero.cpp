//
// Created by Christian nahuel Rivera on 14/6/19.
//

#include "Tablero.h"

Tablero::Tablero(int columnas, int filas) {
    this->columnas = columnas;
    this->filas = filas;
    for(int i = 0; i < columnas; i++){
        std::vector<int> filas;
        this->matrizFichas.push_back(filas);
    }
}

int Tablero::getFilas() {
    return this->filas;
}

void Tablero::play(int fila, int jugador) {
    this->matrizFichas.at(fila).push_back(jugador);
}
