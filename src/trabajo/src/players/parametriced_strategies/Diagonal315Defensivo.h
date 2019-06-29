//
// Created by Christian nahuel Rivera on 17/6/19.
//

#ifndef AED3_TP3_DIAGONAL315DEFENSIVO_H
#define AED3_TP3_DIAGONAL315DEFENSIVO_H


#include "../../entities/Defines.h"
#include "Diagonal315Strategy.h"

class Diagonal315Defensivo : public Diagonal315Strategy {
public:
    explicit Diagonal315Defensivo(float peso) : Diagonal315Strategy(peso, DIAGONAL_315_DEFENSIVO) {}
    void selectMoves(Tablero *tablero, int cObjetivo, int miFicha) override;

};


#endif //AED3_TP3_DIAGONAL315DEFENSIVO_H
