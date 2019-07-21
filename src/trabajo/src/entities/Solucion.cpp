#include "Solucion.h"

Solucion::Solucion(int param1,int param2,int param3,int param4,int param5,int param6,int param7,int param8,int param9) {
    horizontal_ofensivo = param1;
    horizontal_defensivo = param2;
    vertical_ofensivo = param3;
    vertical_defensivo = param4;
    diagonal_45_ofensivo = param5;
    diagonal_45_defensivo = param6;
    diagonal_315_ofensivo = param7;
    diagonal_315_defensivo = param8;
    jugada_aleatoria = param9;

}


Solucion::Solucion(Solucion& anotherSolucion) {
    horizontal_ofensivo = anotherSolucion.horizontal_ofensivo;
    horizontal_defensivo = anotherSolucion.horizontal_defensivo;
    vertical_ofensivo = anotherSolucion.vertical_ofensivo;
    vertical_defensivo = anotherSolucion.vertical_defensivo;
    diagonal_45_ofensivo = anotherSolucion.diagonal_45_ofensivo;
    diagonal_45_defensivo = anotherSolucion.diagonal_45_defensivo;
    diagonal_315_ofensivo = anotherSolucion.diagonal_315_ofensivo;
    diagonal_315_defensivo = anotherSolucion.diagonal_315_defensivo;
    jugada_aleatoria = anotherSolucion.jugada_aleatoria;
}