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

bool Diagonal45Strategy::completarDiagonal45(Tablero *tablero, int cObjetivo, int ficha, int indiceColumna,
                                        bool deboSumarUnaFicha) {
    if(deboSumarUnaFicha && tablero->ultimaJugadaEnColumna(indiceColumna) == tablero->getFilas() - 2){
        return false;
    }
    int evaluacion = deboSumarUnaFicha ? 1 : 0;

    int consecutivosADerecha = 0;
    int indiceColumnaIterar = indiceColumna +1;
    int indiceFila = tablero->ultimaJugadaEnColumna(indiceColumna) + 1 + evaluacion;
    while( tablero->hayJugada(indiceColumnaIterar, indiceFila) ){
        if(tablero->jugadaEn(indiceColumnaIterar, indiceFila) == ficha){
            consecutivosADerecha++;
        }else{
            break;
        }
        indiceFila++;
        indiceColumnaIterar++;
    }

    int consecutivosAIzquierda = 0;
    indiceColumnaIterar = indiceColumna - 1;
    indiceFila = tablero->ultimaJugadaEnColumna(indiceColumna) - 1 + evaluacion;
    while( tablero->hayJugada(indiceColumnaIterar, indiceFila) ){
        if(tablero->jugadaEn(indiceColumnaIterar, indiceFila) == ficha){
            consecutivosAIzquierda++;
        }else{
            break;
        }
        indiceFila--;
        indiceColumnaIterar--;
    }

    // para poder re utilizar el código de la estrategia para el arbitro tengo que parametrizar si debo evaluar la parte
    // superior de la columna.

    return consecutivosAIzquierda + consecutivosADerecha + evaluacion >= cObjetivo;
}
