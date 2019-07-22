

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
    Tablero tablero = Tablero(3,3,2, 10);

    optimizaciones->gridSearch(cantIteraciones,cantidadCandidatos,radio,solucionInicial,tablero);

}