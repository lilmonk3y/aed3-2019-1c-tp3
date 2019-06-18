//
// Created by Christian nahuel Rivera on 17/6/19.
//

#include "Diagonal45Ofensivo.h"

void Diagonal45Ofensivo::selectMoves(Tablero *tablero, int cObjetivo) {
    this->moves->clear();

    for(int indiceColumna = 0; indiceColumna < tablero->getColumnas(); indiceColumna++){
        int consecutivosADerecha = 0;
        int indiceFila = indiceColumna + 1;
        while( tablero->hayJugada(indiceFila, indiceFila) ){
            if(tablero->jugadaEn(indiceFila, indiceFila) == JUGADA_ALIADA){
                consecutivosADerecha++;
            }else{
                break;
            }
            indiceFila++;
        }

        int consecutivosAIzquierda = 0;
        indiceFila = indiceColumna - 1;
        while( tablero->hayJugada(indiceFila, indiceFila) ){
            if(tablero->jugadaEn(indiceFila, indiceFila) == JUGADA_ALIADA){
                consecutivosAIzquierda++;
            }else{
                break;
            }
            indiceFila--;
        }

        if( consecutivosAIzquierda + consecutivosADerecha + 1 >= cObjetivo){
            this->moves->push_back(indiceColumna);
        }
    }
}
