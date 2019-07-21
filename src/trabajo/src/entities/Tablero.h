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

    int jugadaEn(int columna, int fila) const;

    bool hayJugada(int indiceColumna) const;

    int ultimaJugadaEnColumna(int indiceColumna) const;

    int getFichasParaGanar() const;

    void setFichas(int i);

    bool columnaVacia(int indiceColumna)const ;

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
