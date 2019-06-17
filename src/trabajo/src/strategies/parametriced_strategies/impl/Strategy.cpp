//
// Created by Christian nahuel Rivera on 15/6/19.
//

#include "../Strategy.h"

bool Strategy::completarFila(int columnaEsperada, int indiceFila,  int jugadasDelJugador, int cObjetivo, Tablero *tablero) {
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

Strategy::Strategy(float peso, int name) {
    this->name = name;
    this->peso = peso;
    moves = new std::list<int>();
}
