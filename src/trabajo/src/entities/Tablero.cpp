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

bool Tablero::columnaLlena(int columna) {
    return this->matrizFichas.at(columna).size() == this->filas;
}

int Tablero::getColumnas() {
    return this->columnas;
}

bool Tablero::hayJugada(int indiceEnColumna, int indiceFila) {
    int columna = this->matrizFichas.at(indiceEnColumna).size();
    return columna >= indiceFila;
}

/*
 * Obtengo el indice de la fila en la que sería la nueva jugada.
 * Como size = cantElementos desde el 1, me da la posición en la columna.
 */
int Tablero::getIndiceFila(int indiceColumna) {
    return this->matrizFichas.at(indiceColumna).size();
}

int Tablero::jugadaEn(int columna, int fila) {
    return this->matrizFichas.at(columna).at(fila);
}
