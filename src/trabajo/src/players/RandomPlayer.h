//
// Created by Christian nahuel Rivera on 15/6/19.
//

#ifndef AED3_TP3_TESTSTRATEGY_H
#define AED3_TP3_TESTSTRATEGY_H


#include "iPlayer.h"

class RandomPlayer : public iPlayer{
public:
    int play(Tablero *tablero, int miFicha, int c_objetivo) override;
};


#endif //AED3_TP3_TESTSTRATEGY_H
