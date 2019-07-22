

#include "../players/RandomPlayer.h"
#include "../parameter_optimizations/GridSearch.h"
#include "../players/GreedyPlayer.h"
#include "../entities/Tablero.h"
#include <map>

int main(){
    GridSearch* optimizaciones = new GridSearch();

    int cantIteraciones = 10;
    int cantidadCandidatos = 10;
    int radio = 30;
    Solucion* solucionInicial = new Solucion(1,1,1,1,1,1,1,1,1);

    int columnas = 3;
    int filas = 3;
    int fichasParaGanar = 2;
    int fichasPorJugador = 10;
    Tablero tablero = Tablero(columnas,filas,fichasParaGanar, fichasPorJugador);

    optimizaciones->gridSearch(cantIteraciones,cantidadCandidatos,radio,solucionInicial,tablero);

}