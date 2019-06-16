//
// Created by Christian nahuel Rivera on 15/6/19.
//

#ifndef AED3_TP3_PLAYER_H
#define AED3_TP3_PLAYER_H


#include "strategies/PlayStrategy.h"
#include "entities/Tablero.h"

class Player {
public:
    Player(int columns, int rows, int cLinea, int cantidadFichas, PlayStrategy * playStrategy);
    int play();
    void updateMyPlay(int fila);
    void updateOponentPlay(int fila);

private:
    Tablero *tablero;
    int cLinea;
    int cantidadFichas;
    PlayStrategy *playStr;
};


#endif //AED3_TP3_PLAYER_H
