//
// Created by Christian nahuel Rivera on 17/6/19.
//

#include "../Diagonal45Strategy.h"

void Diagonal45Strategy::mejorDiagonal45(Tablero *tablero, int cObjetivo, int ficha) {
    this->moves->clear();

    for(int indiceColumna = 0; indiceColumna < tablero->getColumnas(); indiceColumna++){

        if(completarDiagonal45(tablero, cObjetivo, ficha, indiceColumna, true)){
            this->moves->push_back(indiceColumna);
        }
    }
}

bool
Diagonal45Strategy::completarDiagonal45(Tablero *tablero, int cObjetivo, int ficha, int indiceColumna,
                                        bool deboSumarUnaFicha) {
    if(deboSumarUnaFicha && tablero->jugadaEn(indiceColumna,tablero->ultimaJugadaEnColumna(indiceColumna)) != ficha){
        return false;
    }
    int consecutivosADerecha = 0;
    int indiceFila = indiceColumna + 1;
    while( tablero->hayJugada(indiceFila, indiceFila) ){
            if(tablero->jugadaEn(indiceFila, indiceFila) == ficha){
                consecutivosADerecha++;
            }else{
                break;
            }
            indiceFila++;
        }

    int consecutivosAIzquierda = 0;
    indiceFila = indiceColumna - 1;
    while( tablero->hayJugada(indiceFila, indiceFila) ){
            if(tablero->jugadaEn(indiceFila, indiceFila) == ficha){
                consecutivosAIzquierda++;
            }else{
                break;
            }
            indiceFila--;
        }

    // para poder re utilizar el código de la estrategia para el arbitro tengo que parametrizar si debo evaluar la parte
    // superior de la columna.
    int evaluacion = deboSumarUnaFicha ? 1 : 0;
    return consecutivosAIzquierda + consecutivosADerecha + evaluacion >= cObjetivo;
}
