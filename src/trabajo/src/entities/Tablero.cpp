//
// Created by Christian nahuel Rivera on 14/6/19.
//

#include "Tablero.h"

Tablero::Tablero(int columnas, int filas) {
    this->columnas = columnas;
    this->filas = filas;
    this->matrizFichas = new std::vector<std::vector<int>*>();
    for(int i = 0; i < columnas; i++){
        auto filas = new std::vector<int>();
        this->matrizFichas->push_back(filas);
    }
}

int Tablero::getFilas() {
    return this->filas;
}

void Tablero::play(int fila, int jugador) {
    this->matrizFichas->at(fila)->push_back(jugador);
}

bool Tablero::columnaLlena(int columna) {
    return this->matrizFichas->at(columna)->size() == this->filas;
}

int Tablero::getColumnas() {
    return this->columnas;
}

bool Tablero::hayJugada(int indiceEnColumna, int indiceFila) {
    if( this->matrizFichas->size() <= indiceEnColumna || indiceEnColumna < 0) return false;
    if( this->matrizFichas->at(indiceEnColumna)->size() <= indiceFila || indiceFila < 0) return false;

    return indiceFila < this->matrizFichas->at(indiceEnColumna)->size();
}

/*
 * Obtengo el indice de la fila en la que sería la nueva jugada.
 * Como size = cantElementos desde el 1, me da la posición en la columna.
 */
int Tablero::getIndiceFila(int indiceColumna) {
    return this->matrizFichas->at(indiceColumna)->size() -1;
}

int Tablero::jugadaEn(int columna, int fila) {
    return this->matrizFichas->at(columna)->at(fila);
}

std::vector<int> *Tablero::getColumna(int columna) {
    return this->matrizFichas->at(columna);
}

int Tablero::getTamanoColumna(int i) {
    return this->matrizFichas->at(i)->size() -1;
}
