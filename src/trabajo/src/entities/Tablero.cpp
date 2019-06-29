//
// Created by Christian nahuel Rivera on 14/6/19.
//

#include "Tablero.h"
#include "Defines.h"

Tablero::Tablero(int columnas, int filas) {
    this->columnas = columnas;
    this->filas = filas;
    this->matrizFichas = new std::vector<std::vector<int> *>();
    for (int i = 0; i < columnas; i++) {
        auto filas = new std::vector<int>();
        this->matrizFichas->push_back(filas);
    }
}

int Tablero::getColumnas() {
    return this->columnas;
}

bool Tablero::columnaLlena(int columna) {
    return this->matrizFichas->at(columna)->size() == this->filas;
}

bool Tablero::hayJugada(int indiceEnColumna, int indiceFila) {
    if( this->matrizFichas->size() <= indiceEnColumna || indiceEnColumna < 0) return false;
    if( this->matrizFichas->at(indiceEnColumna)->size() <= indiceFila || indiceFila < 0) return false;

    return indiceFila < this->matrizFichas->at(indiceEnColumna)->size();
}

int Tablero::jugadaEn(int columna, int fila) {
    return this->matrizFichas->at(columna)->at(fila);
}

int Tablero::getTamanoColumna(int i) {
    if( i >= this->getColumnas() || i < 0) return 0;
    return this->matrizFichas->at(i)->size() -1;
}

void Tablero::actualizar(int columna, FICHA ficha) {
    this->matrizFichas->at(columna)->push_back(ficha);
}
