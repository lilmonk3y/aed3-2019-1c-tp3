

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
    Tablero* tablero = new Tablero(8,8,4, 100);

    optimizaciones->gridSearch(cantIteraciones,cantidadCandidatos,radio,solucionInicial,tablero);

}