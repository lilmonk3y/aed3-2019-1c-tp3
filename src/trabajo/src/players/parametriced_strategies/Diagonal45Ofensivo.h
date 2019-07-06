//
// Created by Christian nahuel Rivera on 17/6/19.
//

#ifndef AED3_TP3_DIAGONAL45OFENSIVO_H
#define AED3_TP3_DIAGONAL45OFENSIVO_H


#include "Strategy.h"
#include "../../entities/Defines.h"
#include "Diagonal45Strategy.h"

class Diagonal45Ofensivo : public Diagonal45Strategy{
public:
    explicit Diagonal45Ofensivo(float peso) : Diagonal45Strategy(peso, DIAGONAL_45_OFENSIVO){}
    void selectMoves(Tablero *tablero, int cObjetivo, int miFicha) override;
    STRATEGY_NAME getName() override;
};


#endif //AED3_TP3_DIAGONAL45OFENSIVO_H
