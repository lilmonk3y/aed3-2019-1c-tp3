//
// Created by Christian nahuel Rivera on 17/6/19.
//

#ifndef AED3_TP3_MEJORVERTICALOFENSIVO_H
#define AED3_TP3_MEJORVERTICALOFENSIVO_H


#include "../../entities/Defines.h"
#include "VerticalStrategy.h"

class VerticalOfensivo : public VerticalStrategy {
public:
    explicit VerticalOfensivo(int peso) : VerticalStrategy(peso, VERTICAL_OFENSIVO) {}
    void selectMoves(Tablero *tablero, int cObjetivo, int miFicha) override;
    STRATEGY_NAME getName() override;
};


#endif //AED3_TP3_MEJORVERTICALOFENSIVO_H
