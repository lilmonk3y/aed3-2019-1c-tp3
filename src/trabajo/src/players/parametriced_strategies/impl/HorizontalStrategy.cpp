//
// Created by Christian nahuel Rivera on 17/6/19.
//

#include "../HorizontalStrategy.h"

void HorizontalStrategy::mejorHorizontal(Tablero *tablero, int cObjetivo, int ficha) {
    this->getMoves()->clear(); // limpio los movimientos previos

    for(int indiceColumna = 0; indiceColumna < tablero->getColumnas(); indiceColumna++){
        if(completarFila(indiceColumna, ficha, cObjetivo,tablero, true)){
            this->getMoves()->push_back(indiceColumna);
        }
    }
}

bool HorizontalStrategy::completarFila(int indiceColumna, int ficha, int cObjetivo, Tablero *tablero,
                                      bool deboSumarUnaJugada) {
    int indiceFila = tablero->hayJugada(indiceColumna) ? tablero->ultimaJugadaEnColumna(indiceColumna) : 0;

    if(!deboSumarUnaJugada && tablero->columnaLlena(indiceColumna)){
        return false;
    }else if(!tablero->columnaVacia(indiceColumna)){
        indiceFila += 1;
    }

    int jugadasConsecutivasADerecha = 0;
    for(int columnaADerecha = indiceColumna+1; columnaADerecha < tablero->getColumnas(); columnaADerecha++){
        if( tablero->hayJugada(columnaADerecha, indiceFila) && tablero->jugadaEn(columnaADerecha, indiceFila) == ficha ){
            jugadasConsecutivasADerecha++;
        }else{
            break;
        }
    }

    int jugadasConsecutivasAIzquierda = 0;
    for(int columnaAIzquierda = indiceColumna-1; columnaAIzquierda >= 0; columnaAIzquierda--){
        if( tablero->hayJugada(columnaAIzquierda, indiceFila) && tablero->jugadaEn(columnaAIzquierda, indiceFila) == ficha ){
            jugadasConsecutivasAIzquierda++;
        }else{
            break;
        }
    }

    // para poder re utilizar el código de la estrategia para el arbitro tengo que parametrizar si debo evaluar la parte
    // superior de la columna.
    int evaluacion = deboSumarUnaJugada ? 1 : 0;
    return jugadasConsecutivasADerecha + jugadasConsecutivasAIzquierda + evaluacion >= cObjetivo;
}
