//
// Created by Christian nahuel Rivera on 15/6/19.
//

#include "MejorHorizontalOfensivo.h"
#include "../../entities/Defines.h"

MejorHorizontalOfensivo::MejorHorizontalOfensivo(int nombre, int nuevoPeso) {
    estrategia = nombre;
    peso = nuevoPeso;
}

void MejorHorizontalOfensivo::selectMoves(Tablero *tablero, int cObjetivo) {
    this->getMoves()->clear(); // limpio los movimientos previos

    for(int indiceColumna = 0; indiceColumna < tablero->getColumnas(); indiceColumna++){
        if( completarFila(indiceColumna,tablero->getIndiceFila(indiceColumna), JUGADA_ALIADA, cObjetivo, tablero) ){
            this->getMoves()->push_back(indiceColumna);
        }
    }
}



