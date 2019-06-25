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
    AlgoritmoGenetico(Tablero *tablero);
    vector<Individuo>* correrAlgoritmo();
    int selectMove(Tablero* tablero, int cObjetivo, int cantidadFichas);// override;// deberia ser ESTATICO SIN INSTANCIA

private:
    // atributos:
        Tablero* tablero; //OK
        int columnasTablero; //OK
        int filasTablero; //OK
        map<int,bool> columnasDisponibles; //OK
        int generacion;
        int cantidadDeGeneraciones;

        vector<Individuo* >* poblacionActual; // se va pisando y borrando por la nueva (se va reduciendo)
        // termina cuando queda 1
        int minFitness;
        int maxFitness;

        // metodos:
        // cromosomas == genoma (genes == codificacion de los parametros)
        vector<Individuo* >* generarPoblacion();
        void fitness1(Individuo* individuo); // evaluacion ofensiva
        //void fitness2(Individuo* individuo); // evaluacion ofensiva y defensiva (extension de la anterior)
        pair <Individuo*, Individuo*> crossover(Individuo* individuo1,Individuo* individuo2); // cruza y reproduccion (dejo la buena, la mala)
        void mutacion(Individuo* individuo);
        pair <Individuo*, Individuo*> seleccion1(); // cualesquiera (retorna 2 individuos)
        //pair <Individuo*, Individuo*> seleccion2(vector<Individuo* >* poblacion); // torneo (retorna 2 individuos)
        void evaluarTodosLosIndividuos();
        bool condicionTerminacion();
        int valoracion(int largo);

        int largoFila(int columnaEscogida,int tacticaDefensivaOfensiva);
        int largoDiagonalDerecha(int columnaEscogida,int tacticaDefensivaOfensiva);
        int largoDiagonalIzquierda(int columnaEscogida,int tacticaDefensivaOfensiva);
        int largoColumna(int columnaEscogida,int tacticaDefensivaOfensiva);
};

#endif //AED3_TP3_ALGORITMOGENETICO_H
