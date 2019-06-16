//
// Created by Christian nahuel Rivera on 15/6/19.
//

#ifndef AED3_TP3_TESTSTRATEGY_H
#define AED3_TP3_TESTSTRATEGY_H


#include "PlayStrategy.h"

class TestStrategy : public PlayStrategy{
public:
    int selectMove(Tablero *tablero, int cObjetivo, int cantidadFichas) override;

};


#endif //AED3_TP3_TESTSTRATEGY_H
