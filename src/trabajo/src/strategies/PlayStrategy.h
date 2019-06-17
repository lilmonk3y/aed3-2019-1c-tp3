//
// Created by Christian nahuel Rivera on 15/6/19.
//

#ifndef AED3_TP3_PLAYSTRATEGY_H
#define AED3_TP3_PLAYSTRATEGY_H


#include "../entities/Tablero.h"

class PlayStrategy{
public:
    virtual int selectMove(Tablero *tablero, int cObjetivo, int cantidadFichas) = 0;

};

#endif //AED3_TP3_PLAYSTRATEGY_H
