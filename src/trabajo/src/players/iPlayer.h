//
// Created by Christian nahuel Rivera on 27/6/19.
//

#ifndef AED3_TP3_IPLAYER_H
#define AED3_TP3_IPLAYER_H

#include "../entities/Tablero.h"

class iPlayer{
public:
    virtual int play(Tablero& tablero, FICHA color) = 0;
};
#endif //AED3_TP3_IPLAYER_H
