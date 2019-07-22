//
// Created by Christian nahuel Rivera on 25/6/19.
//

#include "InplaceGame.h"
#include "entities/Defines.h"
#include "players/parametriced_strategies/VerticalStrategy.h"
#include "players/parametriced_strategies/HorizontalStrategy.h"
#include "players/parametriced_strategies/Diagonal315Strategy.h"
#include "players/parametriced_strategies/Diagonal45Strategy.h"

ResultadosPartida jugar(Tablero& tablero,iPlayer& jugadorAliado, iPlayer& jugadorEnemigo, FICHA colorPrimeraJugada){
    int duracionPartida = 0;
    FICHA color = colorPrimeraJugada;
    iPlayer* jugador = colorPrimeraJugada == FICHA_ALIADA ? &jugadorAliado : &jugadorEnemigo;
    do {
        int jugada = jugador->play(tablero, color);
        tablero.actualizar(jugada, color);
        duracionPartida++;
        if (color == FICHA_ALIADA) {
            color = FICHA_ENEMIGA;
            jugador = &jugadorEnemigo;
        } else {
            color = FICHA_ALIADA;
            jugador = &jugadorAliado;
        }
    } while (not gano(&tablero, color == FICHA_ALIADA ? FICHA_ENEMIGA : FICHA_ALIADA));

    return ResultadosPartida(duracionPartida, gano(&tablero,FICHA_ALIADA));
}

bool gano(Tablero* tablero, FICHA colorRecienJugado){
    bool hayGanador = false;
    for(int indiceColumna = 0; indiceColumna < tablero->getColumnas() && !hayGanador; indiceColumna++){
        bool horizontal = HorizontalStrategy::completarFila(indiceColumna, colorRecienJugado, tablero->getFichasParaGanar(), tablero, false);
        bool vertical = VerticalStrategy::completarColumna(tablero, tablero->getFichasParaGanar(), colorRecienJugado, indiceColumna, false);
        bool diagonal315 = Diagonal315Strategy::completarDiagonal315(tablero, tablero->getFichasParaGanar(), colorRecienJugado, indiceColumna, false);
        bool diagonal45 = Diagonal45Strategy::completarDiagonal45(tablero, tablero->getFichasParaGanar(), colorRecienJugado, indiceColumna, false);
        hayGanador = horizontal || vertical || diagonal315 || diagonal45;
    }
    return hayGanador;
}
