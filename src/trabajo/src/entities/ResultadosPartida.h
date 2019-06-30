//
// Created by Christian nahuel Rivera on 26/6/19.
//

#ifndef AED3_TP3_RESULTADOSPARTIDA_H
#define AED3_TP3_RESULTADOSPARTIDA_H

#include "../players/GreedyPlayer.h"

class ResultadosPartida{
public:
    ResultadosPartida (int largoPartida, bool ganoNuestroJugador){
        this->ganoNuestroJugador = ganoNuestroJugador;
        this->largoPartida = largoPartida;
    }

    int getLargoPartida() const {
        return largoPartida;
    }

    bool isGanoNuestroJugador() const {
        return ganoNuestroJugador;
    }

private:
    int largoPartida;
    bool ganoNuestroJugador;
};
#endif //AED3_TP3_RESULTADOSPARTIDA_H
