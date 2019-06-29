//
// Created by Christian nahuel Rivera on 17/6/19.
//

#include "../Diagonal315Strategy.h"

void Diagonal315Strategy::mejorDiagonal315(Tablero *tablero, int cObjetivo, int ficha) {
    this->moves->clear();

    for(int indiceColumna = 0; indiceColumna < tablero->getColumnas(); indiceColumna++){

        if(completarDiagonal315(tablero, cObjetivo, ficha, indiceColumna, true)){
            this->moves->push_back(indiceColumna);
        }
    }
}

bool
Diagonal315Strategy::completarDiagonal315(Tablero *tablero, int cObjetivo, int ficha, int indiceColumna,
                                         bool deboSumarUnaFicha) {
    int consecutivosAIzquierda = 0;

    int indColumna = indiceColumna - 1;
    int indFila = tablero->getTamanoColumna(indColumna) + 1;
    while( tablero->hayJugada(indColumna,indFila) ){
            if( tablero->jugadaEn(indColumna, indFila) == ficha ){
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
            if( tablero->jugadaEn(indColumna, indFila) == ficha ){
                consecutivosADerecha++;
            }else{
                break;
            }
            indColumna++;
            indFila--;
        }

    // para poder re utilizar el código de la estrategia para el arbitro tengo que parametrizar si debo evaluar la parte
    // superior de la columna.
    int evaluacion = deboSumarUnaFicha ? 1 : 0;
    return consecutivosAIzquierda + consecutivosADerecha + evaluacion >= cObjetivo;
}
