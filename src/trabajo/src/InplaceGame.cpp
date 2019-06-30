//
// Created by Christian nahuel Rivera on 25/6/19.
//

#include "InplaceGame.h"
#include "entities/Defines.h"
#include "players/parametriced_strategies/VerticalStrategy.h"
#include "players/parametriced_strategies/HorizontalStrategy.h"
#include "players/parametriced_strategies/Diagonal315Strategy.h"
#include "players/parametriced_strategies/Diagonal45Strategy.h"

ResultadosPartida jugar(int cantidadColumnas, int cantidadFilas, int c_objetivo, int cantidad_fichas,
                          iPlayer& jugadorAliado, iPlayer& jugadorEnemigo, FICHA colorPrimeraJugada){
    Tablero tablero(cantidadColumnas, cantidadFilas, c_objetivo, cantidad_fichas);
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
    } while (not tablero.partidaTerminada());

    return ResultadosPartida(duracionPartida, tablero.obtenerGanador() == FICHA_ALIADA);
}
