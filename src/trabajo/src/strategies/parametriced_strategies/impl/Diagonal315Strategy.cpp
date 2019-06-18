//
// Created by Christian nahuel Rivera on 17/6/19.
//

#include "../Diagonal315Strategy.h"

void Diagonal315Strategy::mejorDiagonal315(Tablero *tablero, int cObjetivo, int ofensivoOdefensivo) {
    this->moves->clear();

    for(int indiceColumna = 0; indiceColumna < tablero->getColumnas(); indiceColumna++){
        int consecutivosAIzquierda = 0;

        int indColumna = indiceColumna - 1;
        int indFila = tablero->getTamanoColumna(indColumna) + 1;
        while( tablero->hayJugada(indColumna,indFila) ){
            if( tablero->jugadaEn(indColumna, indFila) == ofensivoOdefensivo ){
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
            if( tablero->jugadaEn(indColumna, indFila) == ofensivoOdefensivo ){
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
