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
                          iPlayer& jugadorA, iPlayer& jugadorB){
    Tablero tablero = Tablero(cantidadColumnas, cantidadFilas, c_objetivo, cantidad_fichas);
    iPlayer* jugador;
    int jugada;
    int duracionPartida = 0;
    bool jugadorAliado = true;
    do {
        jugadorAliado = !jugadorAliado;
        jugador = jugadorAliado ? &jugadorA : &jugadorB;
        jugada = jugador->play(&tablero, jugadorAliado ? FICHA_ALIADA : FICHA_ENEMIGA, c_objetivo);
        tablero.actualizar(jugada,jugadorAliado ? FICHA_ALIADA : FICHA_ENEMIGA);
        duracionPartida++;
    } while (not tablero.partidaTerminada());

    return ResultadosPartida(duracionPartida, tablero.obtenerGanador() == FICHA_ALIADA);
}
