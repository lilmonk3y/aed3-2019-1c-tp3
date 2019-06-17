//
// Created by Christian nahuel Rivera on 17/6/19.
//

#include "../HorizontalStrategy.h"

void HorizontalStrategy::mejorHorizontal(Tablero *tablero, int cObjetivo, int ofensivoOdefensivo) {
    this->getMoves()->clear(); // limpio los movimientos previos

    for(int indiceColumna = 0; indiceColumna < tablero->getColumnas(); indiceColumna++){
        if( completarFila(indiceColumna,tablero->getIndiceFila(indiceColumna), ofensivoOdefensivo, cObjetivo, tablero) ){
            this->getMoves()->push_back(indiceColumna);
        }
    }
}

bool HorizontalStrategy::completarFila(int columnaEsperada, int indiceFila,  int jugadasDelJugador, int cObjetivo, Tablero *tablero) {
    int jugadasConsecutivasADerecha = 0;
    for(int columnaADerecha = columnaEsperada+1; columnaADerecha < tablero->getColumnas(); columnaADerecha++){
        if( tablero->hayJugada(columnaADerecha, indiceFila) && tablero->jugadaEn(columnaADerecha, indiceFila) == jugadasDelJugador ){
            jugadasConsecutivasADerecha++;
        }else{
            break;
        }
    }

    int jugadasConsecutivasAIzquierda = 0;
    for(int columnaAIzquierda = columnaEsperada-1; columnaAIzquierda >= 0; columnaAIzquierda--){
        if( tablero->hayJugada(columnaAIzquierda, indiceFila) && tablero->jugadaEn(columnaAIzquierda, indiceFila) == jugadasDelJugador ){
            jugadasConsecutivasAIzquierda++;
        }else{
            break;
        }
    }

    return jugadasConsecutivasADerecha + jugadasConsecutivasAIzquierda + 1 >= cObjetivo;
}
