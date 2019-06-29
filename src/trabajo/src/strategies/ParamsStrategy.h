#ifndef AED3_TP3_PARAMS_STRATEGY_H
#define AED3_TP3_PARAMS_STRATEGY_H


#include "PlayStrategy.h"

class ParamsStrategy : public PlayStrategy{
public:
  ParamsStrategy(int paramCentralidad, int paramLineaGanadora, int paramRivalPuedeGanar,
    int paramLongitudMaximaPropia, int paramLongitudMaximaRival);
  int selectMove(Tablero *tablero, int cObjetivo, int cantidadFichas) override;

private:
  int paramCentralidad;
  int paramLineaGanadora;
  int paramRivalPuedeGanar;
  int paramLongitudMaximaPropia;
  int paramLongitudMaximaRival;

  // Da un puntaje a la columna jugada utilizando los indicadores de más abajo
  int calcularPuntajeDelMovimiento(const Tablero& tablero, int cObjetivo, int cantidadFichas, int columnaJugada);

  // Indicadores:
  int calcularPuntajeLongitudMaxima(const Tablero& tablero, int cObjetivo, int cantidadFichas, int columnaJugada, int jugador);
  int calcularPuntajeRivalPuedeGanar(const Tablero& tablero, int cObjetivo, int cantidadFichas, int columnaJugada);
  int calcularPuntajeLineaGanadora(const Tablero& tablero, int cObjetivo, int cantidadFichas, int columnaJugada);
  int calcularPuntajeCentralidad(const Tablero& tablero, int columna);

  // Métodos auxiliares:
  bool filaVivaParaElJugador(int fila, const Tablero& tablero, int cObjetivo, int jugador);
  bool columnaVivaParaElJugador(int columna, const Tablero& tablero, int cObjetivo, int jugador);
};


#endif //AED3_TP3_TESTSTRATEGY_H
