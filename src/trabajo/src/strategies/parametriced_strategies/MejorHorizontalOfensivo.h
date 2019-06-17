//
// Created by Christian nahuel Rivera on 15/6/19.
//

#ifndef AED3_TP3_MEJORHORIZONTALOFENSIVO_H
#define AED3_TP3_MEJORHORIZONTALOFENSIVO_H


#include "MejorHorizontal.h"
#include "../../entities/Defines.h"

class MejorHorizontalOfensivo : public MejorHorizontal {
public:
    MejorHorizontalOfensivo(int peso) : MejorHorizontal(peso, MEJOR_HORIZONTAL_OFENSIVO) {};
    void selectMoves(Tablero *tablero, int cObjetivo) override;

};


#endif //AED3_TP3_MEJORHORIZONTALOFENSIVO_H
