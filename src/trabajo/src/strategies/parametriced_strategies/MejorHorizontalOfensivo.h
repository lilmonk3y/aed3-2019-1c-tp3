//
// Created by Christian nahuel Rivera on 15/6/19.
//

#ifndef AED3_TP3_MEJORHORIZONTALOFENSIVO_H
#define AED3_TP3_MEJORHORIZONTALOFENSIVO_H


#include "Strategy.h"

class MejorHorizontalOfensivo : public Strategy {
public:
    MejorHorizontalOfensivo(int nombre, int peso);
    void selectMoves(Tablero *tablero, int cObjetivo) override;

};


#endif //AED3_TP3_MEJORHORIZONTALOFENSIVO_H
