#ifndef AED3_TP3_PARAMS_STRATEGY_H
#define AED3_TP3_PARAMS_STRATEGY_H


#include "iPlayer.h"

class ParamsStrategy : public iPlayer{
public:
  ParamsStrategy(int paramCentralidad, int paramLineaGanadora, int paramRivalPuedeGanar,
    int paramLongitudMaximaPropia, int paramLongitudMaximaRival);
  int play(Tablero& tablero, FICHA color) override;

private:
  int paramCentralidad;
  int paramLineaGanadora;
  int paramRivalPuedeGanar;
  int paramLongitudMaximaPropia;
  int paramLongitudMaximaRival;

  // Da un puntaje a la columna jugada utilizando los indicadores de más abajo
  int calcularPuntajeDelMovimiento(const Tablero& tablero, int columnaJugada, FICHA miColor);

  // Indicadores:
  int calcularPuntajeLongitudMaxima(const Tablero& tablero, int columnaJugada, FICHA color, FICHA miColor);
  int calcularPuntajeRivalPuedeGanar(const Tablero& tablero, int columnaJugada, FICHA miColor);
  int calcularPuntajeLineaGanadora(const Tablero& tablero, int columnaJugada, FICHA miColor);
  int calcularPuntajeCentralidad(const Tablero& tablero, int columna);

  // Métodos auxiliares:
  bool filaVivaParaElJugador(int fila, const Tablero& tablero, FICHA color);
  bool columnaVivaParaElJugador(int columna, const Tablero& tablero, FICHA color);
};


#endif //AED3_TP3_TESTSTRATEGY_H
