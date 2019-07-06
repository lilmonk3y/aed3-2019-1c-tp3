//
// Created by Christian nahuel Rivera on 25/6/19.
//

#ifndef AED3_TP3_INPLACEGAME_H
#define AED3_TP3_INPLACEGAME_H

#include "entities/ResultadosPartida.h"
#include "players/iPlayer.h"

ResultadosPartida jugar(Tablero& tablero, iPlayer& jugadorA, iPlayer& jugadorB, FICHA colorPrimeraJugada);

#endif //AED3_TP3_INPLACEGAME_H
