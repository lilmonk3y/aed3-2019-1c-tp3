//
// Created by Christian nahuel Rivera on 15/6/19.
//

#include "ParamsStrategy.h"
#include <cstdlib>
#include <limits>
#include "../entities/Defines.h"

ParamsStrategy::ParamsStrategy(int paramCentralidad, int paramLineaGanadora,
                               int paramRivalPuedeGanar,
                               int paramLongitudMaximaPropia, int paramLongitudMaximaRival)
  : paramCentralidad(paramCentralidad), paramLineaGanadora(paramLineaGanadora),
    paramRivalPuedeGanar(paramRivalPuedeGanar),
    paramLongitudMaximaPropia(paramLongitudMaximaPropia),
    paramLongitudMaximaRival(paramLongitudMaximaRival) {};

int ParamsStrategy::selectMove(Tablero *tablero, int cObjetivo, int cantidadFichas) {
  int mejorColumna = 0;
  int puntajeMaximo = std::numeric_limits<int>::min();

  for (int col = 0; col < tablero->getColumnas(); ++col) {
    if (tablero->columnaLlena(col)) continue;
    int puntaje = calcularPuntajeDelMovimiento(*tablero, cObjetivo, cantidadFichas, col);
    if (puntaje > puntajeMaximo) {
      puntajeMaximo = puntaje;
      mejorColumna = col;
    }
  }
  return mejorColumna;
}

int ParamsStrategy::calcularPuntajeDelMovimiento(const Tablero& tablero, int cObjetivo, int cantidadFichas, int columna) {
  int puntajeCentralidad = calcularPuntajeCentralidad(tablero, columna),
      puntajeLineaGanadora = calcularPuntajeLineaGanadora(tablero, cObjetivo, cantidadFichas, columna),
      puntajeRivalPuedeGanar = calcularPuntajeRivalPuedeGanar(tablero, cObjetivo, cantidadFichas, columna),
      puntajeLongitudMaximaPropia = calcularPuntajeLongitudMaxima(tablero, cObjetivo, cantidadFichas, columna, JUGADA_ALIADA),
      puntajeLongitudMaximaRival = calcularPuntajeLongitudMaxima(tablero, cObjetivo, cantidadFichas, columna, JUGADA_ENEMIGA);

  return puntajeCentralidad * paramCentralidad + puntajeLineaGanadora * paramLineaGanadora
    - puntajeRivalPuedeGanar * paramRivalPuedeGanar
    + puntajeLongitudMaximaPropia * paramLongitudMaximaPropia
    - puntajeLongitudMaximaRival * paramLongitudMaximaRival;
}

int ParamsStrategy::calcularPuntajeCentralidad(const Tablero& tablero, int columna) {
  // Devuelve un puntaje que es mayor cuanto más cerca esté la columna jugada del centro, ya que
  // jugar al centro puede ser beneficioso ya que deja más lugar para ganar luego.

  int columnaCentral = tablero.getColumnas()/2;
  return columna <= columnaCentral ? columna : columna - columnaCentral;
}

int ParamsStrategy::calcularPuntajeLineaGanadora(const Tablero& tablero, int cObjetivo, int cantidadFichas, int columnaJugada) {
  // Si realizando este movimiento hace crecer alguna línea que tenga espacio suficiente para ganar
  // devuelve un 1, si no devuelve un 0.

  int puntajeVertical = 0, puntajeHorizontal = 0, puntajeDiagonalDescendente = 0, puntajeDiagonalAscendente = 0;
  int fichasPropias;
  
  // Ver línea vertical:

  int filasVacias = 0;
  int fila = tablero.getFilas() - 1;
  while (filasVacias < cObjetivo and tablero.jugadaEn(columnaJugada, fila) == VACIO) { 
    filasVacias++;
    fila--;
  }
  if (filasVacias == cObjetivo) {
    puntajeVertical = 1;
    goto horizontal;
  }
  fichasPropias = 0;
  while (fila >= 0 and tablero.jugadaEn(columnaJugada, fila) == JUGADA_ALIADA) {
    fichasPropias++;
    fila--;
  }
  if (filasVacias + fichasPropias >= cObjetivo) {
    puntajeVertical = 1;
  }

  // Ver línea horizontal:

  horizontal:
  fila = tablero.getIndiceFila(columnaJugada) + 1;
  int columnaEnemigaAnterior = -1;
  for (int col = 0; col < tablero.getColumnas(); ++col) {
    if (tablero.jugadaEn(col, fila) == JUGADA_ENEMIGA) {
      if (columnaEnemigaAnterior == -1 and col >= cObjetivo) {
        puntajeHorizontal = 1;
        break;      
      }
      if (col - columnaEnemigaAnterior - 1 >= cObjetivo) {
        puntajeHorizontal = 1;
        break;
      }
      columnaEnemigaAnterior = col;
    }
  }
  if (tablero.getColumnas() - columnaEnemigaAnterior >= cObjetivo) puntajeHorizontal = 1;

  // Ver línea diagonal descendente de izquierda a derecha:

  //int filaJugada = tablero.getIndiceFila(columnaJugada) + 1;
  //if (filaJugada + 1 < cObjetivo) goto diagonalAscendente;

  //for (int col)

  //diagonalAscendente:

  return puntajeVertical + puntajeHorizontal + puntajeDiagonalDescendente + puntajeDiagonalAscendente;
}

int ParamsStrategy::calcularPuntajeRivalPuedeGanar(const Tablero& tablero, int cObjetivo, int cantidadFichas, int columnaJugada) {
  int puntaje = 0;
  // if (rival tiene una línea vertical a un movimiento de ganar) puntaje++;
  // if (rival tiene una línea horizontal a dos movimientos de ganar) puntaje++;
  // if (rival tiene una línea diagonal a dos movimientos de ganar) puntaje++;

  return puntaje;
}

int ParamsStrategy::calcularPuntajeLongitudMaxima(const Tablero& tablero, int cObjetivo, int cantidadFichas, int columnaJugada, int jugador) {
  // return longitudDeLíneaMáxima;
  return 0;
}
