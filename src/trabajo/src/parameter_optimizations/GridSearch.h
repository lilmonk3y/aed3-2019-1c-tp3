#ifndef AED3_TP3_GRIDSEARCH_H
#define AED3_TP3_GRIDSEARCH_H

#include "../entities/Solucion.h"
#include "../entities/ResultadosPartida.h"
#include "../InplaceGame.h"
#include <vector>

using namespace std;

class GridSearch {

public:

    Solucion* gridSearch(int cantIteraciones,int cantidadCandidatos,int radio,Solucion* solucionInicial,Tablero& tablero);

    vector<Solucion* >* generarCandidatos(int cantidadCandidatos,int radio,Solucion* solucion);

    vector<Solucion* >* comparar(vector<Solucion* >* candidatos,Solucion* solucion, Tablero& tablero);

    Solucion* mejorSolucion(vector<Solucion* >* mejoresQueActualSolucion,Tablero& tablero );

    void setParametrosDesde(Solucion* solucion, GreedyPlayer* player);

    int variacion(int valor, int radio);

    GreedyPlayer& generarJugador(Solucion* solucion);
};

#endif //AED3_TP3_GRIDSEARCH_H
