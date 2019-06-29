//
// Created by Christian nahuel Rivera on 25/6/19.
//

#ifndef AED3_TP3_INPLACEGAME_H
#define AED3_TP3_INPLACEGAME_H

#include "entities/ResultadosPartida.h"
#include "players/iPlayer.h"

ResultadosPartida *jugar(int cantidadColumnas, int cantidadFilas, int c_objetivo, int cantidad_fichas,
                        iPlayer *nuestroJugador, iPlayer *contrincante);

bool gano(Tablero *tablero, int c_objetivo, bool jugadorAliado);

#endif //AED3_TP3_INPLACEGAME_H
