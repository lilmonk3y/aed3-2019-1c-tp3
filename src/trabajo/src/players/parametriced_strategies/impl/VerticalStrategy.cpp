//
// Created by Christian nahuel Rivera on 17/6/19.
//

#include "../VerticalStrategy.h"

void VerticalStrategy::mejorVertical(Tablero *tablero, int cObjetivo, int ficha) {
    this->moves->clear();

    for(int indexColumna = 0; indexColumna < tablero->getColumnas(); indexColumna++){
        if( ! tablero->columnaLlena(indexColumna) ){
            if(completarColumna(tablero, cObjetivo, ficha, indexColumna, true)){
                moves->push_back(indexColumna);
            }
        }
    }
}

bool VerticalStrategy::completarColumna(Tablero *tablero, int cObjetivo, int ficha, int indexColumna,
                                        bool deboSumarMiJugada) {
    int consecutivosHaciaAbajo = 0;
    // para poder re utilizar el código de la estrategia para el arbitro tengo que parametrizar si debo evaluar la parte
    // superior de la columna.
    int evaluacion = deboSumarMiJugada ? 1 : 0;
    for(int indexFila = tablero->getTamanoColumna(indexColumna) - evaluacion; indexFila >= 0; indexFila--){
        if(tablero->jugadaEn(indexColumna,indexFila) == ficha){
            consecutivosHaciaAbajo ++;
        }else{
            break;
        }
    }
    
    return consecutivosHaciaAbajo + evaluacion >= cObjetivo;
}
