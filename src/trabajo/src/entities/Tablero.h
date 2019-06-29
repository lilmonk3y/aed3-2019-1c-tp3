//
// Created by Christian nahuel Rivera on 14/6/19.
//

#ifndef AED3_TP3_TABLERO_H
#define AED3_TP3_TABLERO_H

#include <vector>
#include "Defines.h"

class Tablero{
public:
    Tablero(int columnas, int filas);
    void actualizar(int columna, FICHA ficha);

    bool columnaLlena(int columna);

    int getColumnas();

    bool hayJugada(int indiceEnColumna, int indiceFila);

    int jugadaEn(int columna, int fila);

    int getTamanoColumna(int i);

private:
    std::vector<std::vector<int> *> *matrizFichas;
    int columnas;
    int filas;
};


#endif //AED3_TP3_TABLERO_H
