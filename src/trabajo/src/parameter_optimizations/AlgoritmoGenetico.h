#ifndef AED3_TP3_ALGORITMOGENETICO_H
#define AED3_TP3_ALGORITMOGENETICO_H

#include "../entities/Individuo.h"
#include "../entities/Tablero.h"
#include "../entities/Defines.h"
#include "../players/iPlayer.h"
#include "../players/GreedyPlayer.h"
#include <vector>
#include <utility>

using namespace std;

class AlgoritmoGenetico {
public:
    AlgoritmoGenetico(int cantidadGeneraciones, int cantIndividuos, int pesoLimite, Tablero* tablero, iPlayer* aliado, iPlayer* rival);

        Individuo* correrAlgoritmo();

private:
        // ATRIBUTOS:
        std::vector<Individuo* >* poblacionActual;// se va reemplazando por la nueva generacion.
        int generacion;
        int cantidadDeGeneraciones;
        int tamanioLinea;
        int cantidadFichas;
        int cantidadMaximaDeJugadas;
        int pesoLimite;
        int cantidadIndividuos;
        int fitnessPromedio;
        Tablero* tablero;
        iPlayer* aliado;
        iPlayer* rival;

        // METODOS:

        // metodos obligatorios de la heuristica:
        std::vector<Individuo* >* generarPoblacion();
        void fitness(Individuo* individuo);
        void fitness1(Individuo* individuo);
        void fitness2(Individuo* individuo);

        std::pair <Individuo*, Individuo*> seleccion();
        std::pair <Individuo*, Individuo*> seleccion1();
        std::pair <Individuo*, Individuo*> seleccion2();

        // operadores geneticos (obligatorios)
        std::pair <Individuo*, Individuo*> crossover(Individuo* individuo1,Individuo* individuo2); // cruza y reproduccion
        void mutacion(Individuo* individuo);

        // metodos para emprolijar el codigo:
        void evaluarTodosLosIndividuos(); // puede ser por fitness1 o fitness2 (cambiar adentro)
        bool condicionTerminacion1(); // por cantidad de generaciones
        bool condicionTerminacion2(); // por promedio entre generaciones
        bool condicionDeMutacion(Individuo* individuo); // probabilidad por evaluacion del individuo
        void recalcularEvaluacionPromedioDeLaPoblacion();
        Individuo* mejorIndividuo();
        void setParametrosDesde(Individuo *individuo, GreedyPlayer *player);
};

#endif //AED3_TP3_ALGORITMOGENETICO_H
