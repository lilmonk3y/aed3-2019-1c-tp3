#ifndef AED3_TP3_ALGORITMOGENETICO_H
#define AED3_TP3_ALGORITMOGENETICO_H

#include "../entities/Individuo.h"
#include "../entities/Tablero.h"
#include <vector>
#include <map>
#include "../entities/Defines.h"

#include "GreedyStrategy.h"
#include "TestStrategy.h"
#include "../Game.h"

using namespace std;

class AlgoritmoGenetico {
public:
        AlgoritmoGenetico(int cantidadGeneraciones,int cols, int fils,int tamLinea, int cantFichas, int pesoLimite, int cantIndividuos,PlayStrategy* rival);
        Individuo* correrAlgoritmo();

private:
        // ATRIBUTOS:
        vector<Individuo* >* poblacionActual;// se va reemplazando por la nueva generacion.
        int generacion;
        int cantidadDeGeneraciones;
        int columnas;
        int filas;
        int tamanioLinea;
        int cantidadFichas;
        int cantidadMaximaDeJugadas;
        int pesoLimite;
        int cantidadIndividuos;
        int fitnessPromedio;
        TestStrategy* jugadorRival; // REVISAR

        // METODOS:

        // metodos obligatorios de la heuristica:
        vector<Individuo* >* generarPoblacion();
        void fitness(Individuo* individuo);
        void fitness1(Individuo* individuo);
        void fitness2(Individuo* individuo);

        pair <Individuo*, Individuo*> seleccion();
        pair <Individuo*, Individuo*> seleccion1();
        pair <Individuo*, Individuo*> seleccion2();

        // operadores geneticos (obligatorios)
        pair <Individuo*, Individuo*> crossover(Individuo* individuo1,Individuo* individuo2); // cruza y reproduccion
        void mutacion(Individuo* individuo);

        // metodos para emprolijar el codigo:
        void evaluarTodosLosIndividuos(); // puede ser por fitness1 o fitness2 (cambiar adentro)
        bool condicionTerminacion1(); // por cantidad de generaciones
        bool condicionTerminacion2(); // por promedio entre generaciones
        bool condicionDeMutacion(Individuo* individuo); // probabilidad por evaluacion del individuo
        void recalcularEvaluacionPromedioDeLaPoblacion();
        Individuo* mejorIndividuo();
        GreedyStrategy* contruirPlayerNuestro(Individuo* individuo);
};

#endif //AED3_TP3_ALGORITMOGENETICO_H
