//
// Created by Christian nahuel Rivera on 17/6/19.
//

#include "../VerticalStrategy.h"

void VerticalStrategy::mejorVertical(Tablero *tablero, int cObjetivo, int ofensivoOdefensivo) {
    this->moves->clear();

    for(int indexColumna = 0; indexColumna < tablero->getColumnas(); indexColumna++){
        if( ! tablero->columnaLlena(indexColumna) ){
            int consecutivosHaciaAbajo = 0;
            for(int indexFila = tablero->getColumna(indexColumna)->size()-1; indexFila > 0; indexFila++){
                if(tablero->jugadaEn(indexColumna,indexFila) == ofensivoOdefensivo){
                    consecutivosHaciaAbajo ++;
                }else{
                    break;
                }
            }

            if(consecutivosHaciaAbajo + 1 >= cObjetivo){
                moves->push_back(indexColumna);
            }
        }
    }
}
