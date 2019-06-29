//
// Created by Christian nahuel Rivera on 17/6/19.
//

#ifndef AED3_TP3_MEJORVERTICALDEFENSIVO_H
#define AED3_TP3_MEJORVERTICALDEFENSIVO_H


#include "../../entities/Defines.h"
#include "../../entities/Tablero.h"
#include "VerticalStrategy.h"

class VerticalDefensivo : public VerticalStrategy {
public:
    explicit VerticalDefensivo(int peso) : VerticalStrategy(peso, VERTICAL_DEFENSIVO) {}
    void selectMoves(Tablero *tablero, int cObjetivo, int miFicha) override;
};


#endif //AED3_TP3_MEJORVERTICALDEFENSIVO_H
