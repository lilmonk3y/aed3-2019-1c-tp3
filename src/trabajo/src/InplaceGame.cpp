//
// Created by Christian nahuel Rivera on 25/6/19.
//

#include "InplaceGame.h"
#include "entities/Defines.h"
#include "players/parametriced_strategies/VerticalStrategy.h"
#include "players/parametriced_strategies/HorizontalStrategy.h"
#include "players/parametriced_strategies/Diagonal315Strategy.h"
#include "players/parametriced_strategies/Diagonal45Strategy.h"

ResultadosPartida * jugar(int cantidadColumnas, int cantidadFilas, int c_objetivo, int cantidad_fichas,
                          iPlayer *nuestroJugador, iPlayer *contrincante){
    Tablero* tablero = new Tablero(cantidadColumnas, cantidadFilas);;
    iPlayer* jugador;
    int jugada;
    int duracionPartida = 0;
    bool jugadorAliado = true;
    do{
        jugadorAliado = !jugadorAliado;
        jugador = jugadorAliado ? nuestroJugador : contrincante;
        jugada = jugador->play(tablero, jugadorAliado ? FICHA_ALIADA : FICHA_ENEMIGA, c_objetivo);
        tablero->actualizar(jugada,jugadorAliado ? FICHA_ALIADA : FICHA_ENEMIGA);
        duracionPartida++;
        cantidad_fichas--;
    }while(!gano(tablero, c_objetivo, jugadorAliado) || cantidad_fichas > 0);

    return new ResultadosPartida(nuestroJugador,duracionPartida, gano(tablero, c_objetivo, true));
}

bool gano(Tablero *tablero, int c_objetivo, bool jugadorAliado) {
    bool gano = false;
    int miFicha = jugadorAliado ? FICHA_ALIADA : FICHA_ENEMIGA;
    for(int columna = 0; columna < tablero->getColumnas() && !gano; columna++){
        gano = VerticalStrategy::completarColumna(tablero, c_objetivo, miFicha, columna, false) ||
               HorizontalStrategy::completarFila(columna, tablero->getTamanoColumna(columna), miFicha, c_objetivo,
                                                 tablero, false) ||
               Diagonal315Strategy::completarDiagonal315(tablero, c_objetivo, miFicha, columna, false) ||
                Diagonal45Strategy::completarDiagonal45(tablero, c_objetivo, miFicha, columna, false);
    }
    return gano;
}
