//
// Created by Christian nahuel Rivera on 14/6/19.
//

#ifndef AED3_TP3_TABLERO_H
#define AED3_TP3_TABLERO_H

#include <vector>
#include "Defines.h"

class Tablero{
public:
    Tablero(int columnas, int filas, int fichasParaGanar, int fichasPorJugador);
    void actualizar(int columna, FICHA ficha);

    int getFilas() const;

    bool columnaLlena(int columna) const;

    int getColumnas() const;

    bool hayJugada(int indiceEnColumna, int indiceFila) const;

    int getIndiceFila(int indiceColumna) const;

    int jugadaEn(int columna, int fila) const;

    int getFichasEnColumna(int columna) const;

    bool filaVacia(int fila) const;

    std::vector<int> *getColumna(int i);

    int getTamanoColumna(int i) const;

    bool partidaTerminada() const;

    FICHA obtenerGanador() const;

    int getFichasParaGanar() const;

    int getFichasPorJugador() const;

private:
    std::vector<std::vector<int> *> *matrizFichas;
    int columnas;
    int filas;
    int mayorFilaNoVacia = -1;
    int fichasParaGanar;
    int fichasPorJugador;
    int fichasDisponibles;
    FICHA ganador = VACIO;
    void actualizarGanador();
    FICHA calcularGanadorEnLineasVerticales();
    FICHA calcularGanadorEnLineasHorizontales();
    FICHA calcularGanadorEnLineasDiagonales();
};


#endif //AED3_TP3_TABLERO_H
