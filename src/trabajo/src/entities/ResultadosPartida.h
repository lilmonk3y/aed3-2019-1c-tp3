//
// Created by Christian nahuel Rivera on 26/6/19.
//

#ifndef AED3_TP3_RESULTADOSPARTIDA_H
#define AED3_TP3_RESULTADOSPARTIDA_H

#include "../players/GreedyPlayer.h"

class ResultadosPartida{
public:
    ResultadosPartida (iPlayer *nuestroJugador, int largoPartida, bool ganoNuestroJugador){
        this->ganoNuestroJugador = ganoNuestroJugador;
        this->largoPartida = largoPartida;
        this->nuestroJugador = nuestroJugador;
    }

    iPlayer *getNuestroJugador() const {
        return nuestroJugador;
    }

    int getLargoPartida() const {
        return largoPartida;
    }

    bool isGanoNuestroJugador() const {
        return ganoNuestroJugador;
    }

private:
    iPlayer *nuestroJugador;
    int largoPartida;
    bool ganoNuestroJugador;
};
#endif //AED3_TP3_RESULTADOSPARTIDA_H
