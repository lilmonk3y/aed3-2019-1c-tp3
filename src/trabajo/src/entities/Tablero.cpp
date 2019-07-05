//
// Created by Christian nahuel Rivera on 14/6/19.
//

#include "Tablero.h"
#include "Defines.h"

Tablero::Tablero(int columnas, int filas, int fichasParaGanar, int fichasPorJugador) :
        columnas(columnas), filas(filas), fichasPorJugador(fichasPorJugador),
        fichasParaGanar(fichasParaGanar), fichasDisponibles(2*fichasPorJugador) {
    this->matrizFichas = new std::vector<std::vector<int> *>();
    for (int i = 0; i < columnas; i++) {
        auto filas = new std::vector<int>();
        this->matrizFichas->push_back(filas);
    }
}

bool Tablero::filaVacia(int fila) const {
    return fila > mayorFilaNoVacia;
}

int Tablero::getFilas() const {
    return this->filas;
}

bool Tablero::columnaLlena(int columna) const {
    return this->matrizFichas->at(columna)->size() == this->filas;
}

int Tablero::getColumnas() const {
    return this->columnas;
}

bool Tablero::hayJugada(int indiceEnColumna, int indiceFila) const {
    if( this->matrizFichas->size() <= indiceEnColumna || indiceEnColumna < 0) return false;
    if( this->matrizFichas->at(indiceEnColumna)->size() <= indiceFila || indiceFila < 0) return false;

    return indiceFila < this->matrizFichas->at(indiceEnColumna)->size();
}

int Tablero::jugadaEn(int columna, int fila) const {
    return hayJugada(columna, fila) ? this->matrizFichas->at(columna)->at(fila) : VACIO;
}

int Tablero::getFichasEnColumna(int columna) const {
    return (*matrizFichas)[columna]->size();
}

std::vector<int> *Tablero::getColumna(int columna) {
    return this->matrizFichas->at(columna);
}

int Tablero::getTamanoColumna(int i) const {
    if( i >= this->getColumnas() || i < 0) return -1;
    return this->matrizFichas->at(i)->size() -1;
}

void Tablero::actualizar(int columna, FICHA ficha) {
    this->matrizFichas->at(columna)->push_back(ficha);
    int filaDeLaFicha = getFichasEnColumna(columna)-1;
    if (filaDeLaFicha > mayorFilaNoVacia) mayorFilaNoVacia = filaDeLaFicha;
    actualizarGanador();
    --fichasDisponibles;
}

bool Tablero::partidaTerminada() const {
    return ganador != VACIO or fichasDisponibles == 0;
}

FICHA Tablero::obtenerGanador() const {
    return ganador;
}

void Tablero::actualizarGanador() {
    ganador = calcularGanadorEnLineasVerticales();
    if (ganador != VACIO) return;

    ganador = calcularGanadorEnLineasHorizontales();
    if (ganador != VACIO) return;

    ganador = calcularGanadorEnLineasDiagonales();
}

FICHA Tablero::calcularGanadorEnLineasVerticales() {
    for (int col = 0; col < getColumnas(); ++col) {
        int fichasEnColumna = getFichasEnColumna(col);
        if (fichasEnColumna < fichasParaGanar) continue;
        FICHA colorAnterior = VACIO;
        int longitud = 0;
        for (int fila = 0; fila < fichasEnColumna; ++fila) {
            int color = jugadaEn(col, fila);
            if (color == colorAnterior) {
                longitud++;
                if (longitud == fichasParaGanar) return color;
            } else {
                longitud = 1;
                colorAnterior = color; 
            } 
        }
    }
    return VACIO;
}

FICHA Tablero::calcularGanadorEnLineasHorizontales() {
    for (int fila = 0; fila < getFilas() and not filaVacia(fila); ++fila) {
        FICHA colorAnterior = VACIO;
        int longitud = 0;
        for (int col = 0; col < getColumnas(); ++col) {
            int color = jugadaEn(col, fila);
            if (color == VACIO) {
                longitud = 0;
            } else if (color == colorAnterior) {
                longitud++;
                if (longitud == fichasParaGanar) return color;
            } else {
                longitud = 1;
                colorAnterior = color; 
            } 
        }
    }
    return VACIO;
}
    
FICHA Tablero::calcularGanadorEnLineasDiagonales() {
    int diagonales = getFilas() + getColumnas() - 2 * fichasParaGanar + 1;
    
    // Diagonales principales:

    int diagFila = fichasParaGanar, diagCol = 0;
    for (int i = 0; i < diagonales; ++i) {
        FICHA colorAnterior = VACIO;
        int longitud = 0;
        for (int fila = diagFila, col = diagCol; fila >= 0 and col < getColumnas(); --fila, ++col) {
            int color = jugadaEn(col, fila);
            if (color == VACIO) {
                longitud = 0;
            } else if (color == colorAnterior) {
                longitud++;
                if (longitud == fichasParaGanar) return color;
            } else {
                longitud = 1;
                colorAnterior = color; 
            } 
        }
        if (diagFila < getFilas()-1) ++diagFila;
        else ++diagCol;
    }

    // Diagonales secundarias:

    diagFila = fichasParaGanar;
    diagCol = getColumnas() - 1;
    for (int i = 0; i < diagonales; ++i) {
        FICHA colorAnterior = VACIO;
        int longitud = 0;
        for (int fila = diagFila, col = diagCol; fila >= 0 and col >= 0; --fila, --col) {
            int color = jugadaEn(col, fila);
            if (color == VACIO) {
                longitud = 0;
            } else if (color == colorAnterior) {
                longitud++;
                if (longitud == fichasParaGanar) return color;
            } else {
                longitud = 1;
                colorAnterior = color; 
            } 
        }
        if (diagFila < getFilas()-1) ++diagFila;
        else --diagCol;
    }
}

int Tablero::getFichasParaGanar() const {
    return fichasParaGanar;
}

int Tablero::getFichasPorJugador() const {
    return fichasPorJugador;
}