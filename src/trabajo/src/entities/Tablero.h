//
// Created by Christian nahuel Rivera on 14/6/19.
//

#ifndef AED3_TP3_TABLERO_H
#define AED3_TP3_TABLERO_H

#include <vector>

class Tablero{
public:
    Tablero(int columnas, int filas);
    void play(int fila, int jugador);

    int getFilas();
    bool columnaLlena(int columna);

    int getColumnas();

    bool hayJugada(int indiceEnColumna, int indiceFila);

    int getIndiceFila(int indiceColumna);

    int jugadaEn(int columna, int fila);

    std::vector<int> *getColumna(int i);

    int getTamanoColumna(int i);

private:
    std::vector<std::vector<int> *> *matrizFichas;
    int columnas;
    int filas;
};


#endif //AED3_TP3_TABLERO_H
