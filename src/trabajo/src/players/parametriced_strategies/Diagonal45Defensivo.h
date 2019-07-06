//
// Created by Christian nahuel Rivera on 17/6/19.
//

#ifndef AED3_TP3_DIAGONAL45DEFENSIVO_H
#define AED3_TP3_DIAGONAL45DEFENSIVO_H


#include "Diagonal45Strategy.h"
#include "../../entities/Defines.h"

class Diagonal45Defensivo : public Diagonal45Strategy {
public:
    explicit Diagonal45Defensivo(float peso) : Diagonal45Strategy(peso, DIAGONAL_45_DEFENSIVO) {}
    void selectMoves(Tablero *tablero, int cObjetivo, int miFicha);
    STRATEGY_NAME getName();

};


#endif //AED3_TP3_DIAGONAL45DEFENSIVO_H
