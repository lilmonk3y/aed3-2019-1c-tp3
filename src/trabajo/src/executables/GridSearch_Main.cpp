

#include "../players/RandomPlayer.h"
#include "../parameter_optimizations/GridSearch.h"
#include "../players/GreedyPlayer.h"
#include "../entities/Tablero.h"
#include <map>

int main(){
    GridSearch* optimizaciones = new GridSearch();

    int cantIteraciones = 1000;
    int cantidadCandidatos = 30;
    int radio = 30;
    Solucion* solucionInicial = new Solucion(1,2,3,4,5,6,7,8,9);

    int columnas = 20;
    int filas = 20;
    int fichasParaGanar = 5;
    int fichasPorJugador = 1000;
    Tablero tablero = Tablero(columnas,filas,fichasParaGanar, fichasPorJugador);

    optimizaciones->gridSearch(cantIteraciones,cantidadCandidatos,radio,solucionInicial,tablero);

}