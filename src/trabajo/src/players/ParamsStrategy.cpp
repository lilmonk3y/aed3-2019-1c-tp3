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

int ParamsStrategy::play(Tablero& tablero, FICHA miColor) {
  int mejorColumna = 0;
  int puntajeMaximo = std::numeric_limits<int>::min();

  for (int col = 0; col < tablero.getColumnas(); ++col) {
    if (tablero.columnaLlena(col)) continue;
    int puntaje = calcularPuntajeDelMovimiento(tablero, col, miColor);
    if (puntaje > puntajeMaximo) {
      puntajeMaximo = puntaje;
      mejorColumna = col;
    }
  }
  return mejorColumna;
}

int ParamsStrategy::calcularPuntajeDelMovimiento(const Tablero& tablero, int columna, FICHA miColor) {
  FICHA colorRival = miColor == FICHA_ALIADA ? FICHA_ENEMIGA : FICHA_ALIADA;
  int puntajeCentralidad = calcularPuntajeCentralidad(tablero, columna),
      puntajeLineaGanadora = calcularPuntajeLineaGanadora(tablero, columna, miColor),
      puntajeRivalPuedeGanar = calcularPuntajeRivalPuedeGanar(tablero, columna, miColor),
      puntajeLongitudMaximaPropia = calcularPuntajeLongitudMaxima(tablero, columna, miColor, miColor),
      puntajeLongitudMaximaRival = calcularPuntajeLongitudMaxima(tablero, columna, colorRival, miColor);

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

int ParamsStrategy::calcularPuntajeLineaGanadora(const Tablero& tablero, int columnaJugada, FICHA miColor) {
  // Si realizando este movimiento puede hacer crecer alguna línea que tenga espacio suficiente para
  // ganar devuelve un 1, si no devuelve un 0.

  int puntajeVertical = 0, puntajeHorizontal = 0,
      puntajeDiagonalDescendente = 0, puntajeDiagonalAscendente = 0;

  // Ver línea vertical:

  if (columnaVivaParaElJugador(columnaJugada, tablero, miColor)) puntajeVertical = 1;

  // Ver línea horizontal:

  int fila = tablero.getFichasEnColumna(columnaJugada);
  if (filaVivaParaElJugador(fila, tablero, miColor)) puntajeHorizontal = 1;

  // Ver líneas diagonales:
  // TODO

  return puntajeVertical + puntajeHorizontal + puntajeDiagonalDescendente + puntajeDiagonalAscendente;
}

bool ParamsStrategy::columnaVivaParaElJugador(int columna, const Tablero& tablero, FICHA color) {
  int filasVacias = 0;
  int fila = tablero.getFilas() - 1;
  while (filasVacias < tablero.getFichasParaGanar() and tablero.jugadaEn(columna, fila) == VACIO) { 
    filasVacias++;
    fila--;
  }
  if (filasVacias == tablero.getFichasParaGanar()) {
    return true;
  }
  int fichasPropias = 0;
  while (fila >= 0 and tablero.jugadaEn(columna, fila) == color) {
    fichasPropias++;
    fila--;
  }
  if (filasVacias + fichasPropias >= tablero.getFichasParaGanar()) {
    return true;
  }
  return false;
}

bool ParamsStrategy::filaVivaParaElJugador(int fila, const Tablero& tablero, FICHA color) {
  int columnaEnemigaAnterior = -1;
  int colorRival = color == FICHA_ALIADA ? FICHA_ENEMIGA : FICHA_ALIADA;
  for (int col = 0; col < tablero.getColumnas(); ++col) {
    if (tablero.jugadaEn(col, fila) == colorRival) {
      if (columnaEnemigaAnterior == -1 and col >= tablero.getFichasParaGanar()) {
        return true;     
      }
      if (col - columnaEnemigaAnterior - 1 >= tablero.getFichasParaGanar()) {
        return true;
      }
      columnaEnemigaAnterior = col;
    }
  }
  if (tablero.getColumnas() - columnaEnemigaAnterior >= tablero.getFichasParaGanar()) return true;
  return false;
}

int ParamsStrategy::calcularPuntajeRivalPuedeGanar(const Tablero& tablero, int columnaJugada, FICHA miColor) {
  FICHA colorRival = miColor == FICHA_ALIADA ? FICHA_ENEMIGA : FICHA_ALIADA;
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
    while (fila >= 0 and tablero.jugadaEn(col, fila) == colorRival) {
      fichasRivales++;
      fila--;
    }
    if (filasVacias + fichasRivales >= tablero.getFichasParaGanar() and fichasRivales == tablero.getFichasParaGanar() - 1) {
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
    if (not filaVivaParaElJugador(fila, tablero, colorRival)) continue;
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
      if (jugada == miColor) {
        longitud = 0;
      } else if (jugada == colorRival) {
        longitud++;
      } else if (longitud >= tablero.getFichasParaGanar() - 2) {
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

int ParamsStrategy::calcularPuntajeLongitudMaxima(const Tablero& tablero, int columnaJugada, FICHA color, FICHA miColor) {
  int colorRival = miColor == FICHA_ALIADA ? FICHA_ENEMIGA : FICHA_ALIADA;

  // Línea vertical:

  int longitudMaximaVertical = 0;
  for (int col = 0; col < tablero.getColumnas(); ++col) {
    if (tablero.columnaLlena(col) or (col == columnaJugada and color == colorRival)) continue;
    int filasVacias = 0;
    int fila = tablero.getFilas() - 1;
    while (fila >= 0 and tablero.jugadaEn(col, fila) == VACIO) { 
      filasVacias++;
      fila--;
    }
    int fichas = 0;
    while (fila >= 0 and tablero.jugadaEn(col, fila) == color) {
      fichas++;
      fila--;
    }
    if (color == miColor and columnaJugada == col) {
      filasVacias--;
      fichas++;
    }
    if (filasVacias + fichas >= tablero.getFichasParaGanar() and fichas > longitudMaximaVertical) {
      longitudMaximaVertical = fichas;
    } 
  }

  // Línea horizontal:

  int longitudMaximaHorizontal = 0, longitud = 0;
  for (int fila = 0; fila < tablero.getFilas() and not tablero.filaVacia(fila); ++fila) {
    longitud = 0;
    if (not filaVivaParaElJugador(fila, tablero, colorRival)) continue;
    for (int col = 0; col < tablero.getColumnas(); ++col) {
      if (tablero.getFichasEnColumna(col) < fila) {
        if (longitud > longitudMaximaHorizontal) longitudMaximaHorizontal = longitud;
        longitud = 0;
        continue;
      }
      int jugada = tablero.jugadaEn(fila, col);
      if (jugada == colorRival) {
        if (longitud > longitudMaximaHorizontal) longitudMaximaHorizontal = longitud;
        longitud = 0;
      } else if (jugada == VACIO) {
        if (tablero.getFichasEnColumna(col) == fila and col == columnaJugada) {
          if (color == miColor) {
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


