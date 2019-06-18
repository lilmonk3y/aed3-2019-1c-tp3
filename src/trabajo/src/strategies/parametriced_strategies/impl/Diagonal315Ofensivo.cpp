//
// Created by Christian nahuel Rivera on 17/6/19.
//

#include "../Diagonal315Ofensivo.h"

void Diagonal315Ofensivo::selectMoves(Tablero *tablero, int cObjetivo) {
    this->moves->clear();

    for(int indiceColumna = 0; indiceColumna < tablero->getColumnas(); indiceColumna++){
        int consecutivosAIzquierda = 0;

        int indColumna = indiceColumna - 1;
        int indFila = tablero->getTamanoColumna(indColumna) + 1;
        while( tablero->hayJugada(indColumna,indFila) ){
            if( tablero->jugadaEn(indColumna, indFila) == JUGADA_ALIADA ){
                consecutivosAIzquierda++;
            }else{
                break;
            }
            indColumna--;
            indFila++;
        }

        int consecutivosADerecha = 0;

        indColumna = indiceColumna + 1;
        indFila = tablero->getTamanoColumna(indColumna) - 1;
        while( tablero->hayJugada(indColumna,indFila) ){
            if( tablero->jugadaEn(indColumna, indFila) == JUGADA_ALIADA ){
                consecutivosADerecha++;
            }else{
                break;
            }
            indColumna++;
            indFila--;
        }

        if(consecutivosAIzquierda + consecutivosADerecha + 1 >= cObjetivo){
            this->moves->push_back(indiceColumna);
        }
    }
}
