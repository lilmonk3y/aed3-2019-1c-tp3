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
    if(deboSumarUnaFicha && tablero->ultimaJugadaEnColumna(indiceColumna) == tablero->getFilas() - 2){
        return false;
    }
    int evaluacion = deboSumarUnaFicha ? 1 : 0;

    int consecutivosAIzquierda = 0;
    int indColumna = indiceColumna - 1;
    int indFila = tablero->ultimaJugadaEnColumna(indiceColumna) + 1 + evaluacion;
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
    indFila = tablero->ultimaJugadaEnColumna(indiceColumna) - 1 + evaluacion;
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
    int sumar = deboSumarUnaFicha ? 1 : tablero->jugadaEn(indiceColumna,tablero->ultimaJugadaEnColumna(indiceColumna));

    return consecutivosAIzquierda + consecutivosADerecha + sumar >= cObjetivo;
}
