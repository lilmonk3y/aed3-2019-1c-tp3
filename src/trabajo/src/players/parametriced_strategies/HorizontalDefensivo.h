//
// Created by Christian nahuel Rivera on 17/6/19.
//

#ifndef AED3_TP3_MEJORHORIZONTALDEFENSIVO_H
#define AED3_TP3_MEJORHORIZONTALDEFENSIVO_H


#include "HorizontalStrategy.h"
#include "../../entities/Defines.h"

class HorizontalDefensivo : public HorizontalStrategy {
public:
    explicit HorizontalDefensivo(int peso) : HorizontalStrategy(peso, HORIZONTAL_DEFENSIVO) {};
    void selectMoves(Tablero *tablero, int cObjetivo, int miFicha) override;
};


#endif //AED3_TP3_MEJORHORIZONTALDEFENSIVO_H
