#ifndef AED3_TP3_ALGORITMOGENETICO_H
#define AED3_TP3_ALGORITMOGENETICO_H

#include "../entities/Individuo.h"
#include "../entities/Tablero.h"
#include <vector>
#include <map>
#include "../entities/Defines.h"

using namespace std;

class AlgoritmoGenetico {
public:
        AlgoritmoGenetico(int generation,int cantidadGeneraciones);
        vector<Individuo>* correrAlgoritmo();

private:
        // atributo obligatorio:
        vector<Individuo* >* poblacionActual;// se va reemplazando por la nueva generacion.

        // atributos para el criterio de terminacion y funcion fitness (tener memoria)
        int generacion;
        int cantidadDeGeneraciones;
        int minFitness;
        int maxFitness;

        // metodos obligatorios de la heuristica:
        vector<Individuo* >* generarPoblacion();
        void fitness1(Individuo* individuo); // evaluacion ofensiva
        //void fitness2(Individuo* individuo); // evaluacion ofensiva y defensiva (extension de la anterior)
        pair <Individuo*, Individuo*> seleccion1(); // cualesquiera (retorna 2 individuos)
        //pair <Individuo*, Individuo*> seleccion2(vector<Individuo* >* poblacion); // torneo (retorna 2 individuos)

        // operadores geneticos (obligatorios)
        pair <Individuo*, Individuo*> crossover(Individuo* individuo1,Individuo* individuo2); // cruza y reproduccion (dejo la buena, la mala)
        void mutacion(Individuo* individuo);

        // metodos para emprolijar el codigo:
        void evaluarTodosLosIndividuos();
        bool condicionTerminacion(); // puede haber multiples criterios de terminacion (1 o varios ANDS)

        // seran borradas:
        int valoracion(int largo);
        int largoFila(int columnaEscogida,int tacticaDefensivaOfensiva);
        int largoDiagonalDerecha(int columnaEscogida,int tacticaDefensivaOfensiva);
        int largoDiagonalIzquierda(int columnaEscogida,int tacticaDefensivaOfensiva);
        int largoColumna(int columnaEscogida,int tacticaDefensivaOfensiva);
};

#endif //AED3_TP3_ALGORITMOGENETICO_H
