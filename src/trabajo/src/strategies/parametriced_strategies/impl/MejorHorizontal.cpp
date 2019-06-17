//
// Created by Christian nahuel Rivera on 17/6/19.
//

#include "../MejorHorizontal.h"

void MejorHorizontal::mejorHorizontal(Tablero *tablero, int cObjetivo, int ofensivoOdefensivo) {
    this->getMoves()->clear(); // limpio los movimientos previos

    for(int indiceColumna = 0; indiceColumna < tablero->getColumnas(); indiceColumna++){
        if( completarFila(indiceColumna,tablero->getIndiceFila(indiceColumna), ofensivoOdefensivo, cObjetivo, tablero) ){
            this->getMoves()->push_back(indiceColumna);
        }
    }
}
