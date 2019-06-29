//
// Created by Christian nahuel Rivera on 15/6/19.
//

#ifndef AED3_TP3_MEJORHORIZONTALOFENSIVO_H
#define AED3_TP3_MEJORHORIZONTALOFENSIVO_H


#include "HorizontalStrategy.h"
#include "../../entities/Defines.h"

class HorizontalOfensivo : public HorizontalStrategy {
public:
    HorizontalOfensivo(int peso) : HorizontalStrategy(peso, HORIZONTAL_OFENSIVO) {};
    void selectMoves(Tablero *tablero, int cObjetivo, int miFicha) override;

};


#endif //AED3_TP3_MEJORHORIZONTALOFENSIVO_H
