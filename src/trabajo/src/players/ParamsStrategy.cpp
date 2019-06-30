#include "ParamsStrategy.h"
#include <cstdlib>
#include <limits>
#include <cmath>
#include "../entities/Defines.h"

ParamsStrategy::ParamsStrategy(int paramCentralidad, int paramLineaGanadora,
                               int paramRivalPuedeGanar,
                               int paramLongitudMaximaPropia, int paramLongitudMaximaRival)
  : paramCentralidad(paramCentralidad), paramLineaGanadora(paramLineaGanadora),
    paramRivalPuedeGanar(paramRivalPuedeGanar),
    paramLongitudMaximaPropia(paramLongitudMaximaPropia),
    paramLongitudMaximaRival(paramLongitudMaximaRival) {};

int ParamsStrategy::play(Tablero *tablero, int cObjetivo, int cantidadFichas) {
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
      puntajeLongitudMaximaPropia = calcularPuntajeLongitudMaxima(tablero, cObjetivo, cantidadFichas, columna, FICHA_ALIADA),
      puntajeLongitudMaximaRival = calcularPuntajeLongitudMaxima(tablero, cObjetivo, cantidadFichas, columna, FICHA_ENEMIGA);

  return puntajeCentralidad * paramCentralidad
    + puntajeLineaGanadora * paramLineaGanadora
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
  // Si realizando este movimiento puede hacer crecer alguna línea que tenga espacio suficiente para
  // ganar devuelve un 1, si no devuelve un 0.

  int puntajeVertical = 0, puntajeHorizontal = 0,
      puntajeDiagonalDescendente = 0, puntajeDiagonalAscendente = 0;

  // Ver línea vertical:

  if (columnaVivaParaElJugador(columnaJugada, tablero, cObjetivo, FICHA_ALIADA)) puntajeVertical = 1;

  // Ver línea horizontal:

  int fila = tablero.getFichasEnColumna(columnaJugada);
  if (filaVivaParaElJugador(fila, tablero, cObjetivo, FICHA_ALIADA)) puntajeHorizontal = 1;

  // Ver líneas diagonales:
  // TODO

  return puntajeVertical + puntajeHorizontal + puntajeDiagonalDescendente + puntajeDiagonalAscendente;
}

bool ParamsStrategy::columnaVivaParaElJugador(int columna, const Tablero& tablero, int cObjetivo, int jugador) {
  int filasVacias = 0;
  int fila = tablero.getFilas() - 1;
  while (filasVacias < cObjetivo and tablero.jugadaEn(columna, fila) == VACIO) { 
    filasVacias++;
    fila--;
  }
  if (filasVacias == cObjetivo) {
    return true;
  }
  int fichasPropias = 0;
  while (fila >= 0 and tablero.jugadaEn(columna, fila) == jugador) {
    fichasPropias++;
    fila--;
  }
  if (filasVacias + fichasPropias >= cObjetivo) {
    return true;
  }
  return false;
}

bool ParamsStrategy::filaVivaParaElJugador(int fila, const Tablero& tablero, int cObjetivo, int jugador) {
  int columnaEnemigaAnterior = -1;
  int jugadorRival = jugador == FICHA_ALIADA ? FICHA_ENEMIGA : FICHA_ALIADA;
  for (int col = 0; col < tablero.getColumnas(); ++col) {
    if (tablero.jugadaEn(col, fila) == jugadorRival) {
      if (columnaEnemigaAnterior == -1 and col >= cObjetivo) {
        return true;     
      }
      if (col - columnaEnemigaAnterior - 1 >= cObjetivo) {
        return true;
      }
      columnaEnemigaAnterior = col;
    }
  }
  if (tablero.getColumnas() - columnaEnemigaAnterior >= cObjetivo) return true;
  return false;
}

int ParamsStrategy::calcularPuntajeRivalPuedeGanar(const Tablero& tablero, int cObjetivo, int cantidadFichas, int columnaJugada) {
  int puntaje = 0;

  // Líneas verticales:
  // idea: if (rival tiene una línea vertical a un movimiento de ganar) puntaje++;

  for (int col = 0; col < tablero.getColumnas(); ++col) {
    if (tablero.columnaLlena(col) or col == columnaJugada) continue;
    int filasVacias = 0;
    int fila = tablero.getFilas() - 1;
    while (fila >= 0 and tablero.jugadaEn(col, fila) == VACIO) { 
      filasVacias++;
      fila--;
    }
    int fichasRivales = 0;
    while (fila >= 0 and tablero.jugadaEn(col, fila) == FICHA_ENEMIGA) {
      fichasRivales++;
      fila--;
    }
    if (filasVacias + fichasRivales >= cObjetivo and fichasRivales == cObjetivo - 1) {
      puntaje++;
      break;
    } 
  }

  // Líneas horizontales:
  // idea: if (rival tiene una línea horizontal a dos movimientos de ganar) puntaje++;
  // se hace con dos movimientos porque si el rival tiene una línea en el medio con lugar a los dos
  // lados puede dejarte en una situación en que te gana sí o sí porque lo bloqueás en un lado y te
  // gana por el otro lado

  bool cortar = false;
  for (int fila = 0; fila < tablero.getFilas() and not tablero.filaVacia(fila) and not cortar; ++fila) {
    int longitud = 0;
    if (not filaVivaParaElJugador(fila, tablero, cObjetivo, FICHA_ENEMIGA)) continue;
    for (int col = 0; col < tablero.getColumnas(); ++col) {
      if (tablero.getFichasEnColumna(col) < fila) {
        longitud = 0;
        continue;
      }
      if (tablero.getFichasEnColumna(col) == fila and col == columnaJugada) {
        longitud = 0;
        continue;
      }
      int jugada = tablero.jugadaEn(fila, col);
      if (jugada == FICHA_ALIADA) {
        longitud = 0;
      } else if (jugada == FICHA_ENEMIGA) {
        longitud++;
      } else if (longitud >= cObjetivo - 2) {
        puntaje++;
        cortar = true;
        break;
      } else {
        longitud = 0;
      }
    }
  }

  // Líneas diagonales
  // if (rival tiene una línea diagonal a dos movimientos de ganar) puntaje++;
  // TODO


  // Faltaría ver que el rival no tenga dos líneas separadas por un espacio en blanco, porque así
  // también podría completar y ganar en un movimiento, pero no lo voy a hacer por el momento.

  return puntaje;
}

int ParamsStrategy::calcularPuntajeLongitudMaxima(const Tablero& tablero, int cObjetivo, int cantidadFichas, int columnaJugada, int jugador) {
  int jugadorRival = jugador == FICHA_ALIADA ? FICHA_ENEMIGA : FICHA_ALIADA;

  // Línea vertical:

  int longitudMaximaVertical = 0;
  for (int col = 0; col < tablero.getColumnas(); ++col) {
    if (tablero.columnaLlena(col) or (col == columnaJugada and jugador == FICHA_ENEMIGA)) continue;
    int filasVacias = 0;
    int fila = tablero.getFilas() - 1;
    while (fila >= 0 and tablero.jugadaEn(col, fila) == VACIO) { 
      filasVacias++;
      fila--;
    }
    int fichas = 0;
    while (fila >= 0 and tablero.jugadaEn(col, fila) == jugador) {
      fichas++;
      fila--;
    }
    if (jugador == FICHA_ALIADA and columnaJugada == col) {
      filasVacias--;
      fichas++;
    }
    if (filasVacias + fichas >= cObjetivo and fichas > longitudMaximaVertical) {
      longitudMaximaVertical = fichas;
    } 
  }

  // Línea horizontal:

  int longitudMaximaHorizontal = 0, longitud = 0;
  for (int fila = 0; fila < tablero.getFilas() and not tablero.filaVacia(fila); ++fila) {
    longitud = 0;
    if (not filaVivaParaElJugador(fila, tablero, cObjetivo, jugadorRival)) continue;
    for (int col = 0; col < tablero.getColumnas(); ++col) {
      if (tablero.getFichasEnColumna(col) < fila) {
        if (longitud > longitudMaximaHorizontal) longitudMaximaHorizontal = longitud;
        longitud = 0;
        continue;
      }
      int jugada = tablero.jugadaEn(fila, col);
      if (jugada == jugadorRival) {
        if (longitud > longitudMaximaHorizontal) longitudMaximaHorizontal = longitud;
        longitud = 0;
      } else if (jugada == VACIO) {
        if (tablero.getFichasEnColumna(col) == fila and col == columnaJugada) {
          if (jugador == FICHA_ALIADA) {
            longitud++;
          } else {
            if (longitud > longitudMaximaHorizontal) longitudMaximaHorizontal = longitud;
            longitud = 0;
          }
        } else {
          if (longitud > longitudMaximaHorizontal) longitudMaximaHorizontal = longitud;
          longitud = 0;
        }
      } else {
        longitud++;
      }
    }
  }
  if (longitud > longitudMaximaHorizontal) longitudMaximaHorizontal = longitud;

  // Longitud máxima diagonal:
  // TODO

  return std::max(longitudMaximaVertical, longitudMaximaHorizontal);
}


