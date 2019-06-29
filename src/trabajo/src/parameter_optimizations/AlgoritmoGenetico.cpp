#include "AlgoritmoGenetico.h"
// includes Defines.H

int AlgoritmoGenetico::selectMove(Tablero* tablero, int cObjetivo, int cantidadFichas){
    AlgoritmoGenetico* algoritmoGenetico = new AlgoritmoGenetico(tablero);
    return algoritmoGenetico->correrAlgoritmo()->at(0).getFilaEscogida();
}

AlgoritmoGenetico::AlgoritmoGenetico(Tablero* tablero) {
    this -> tablero = tablero;
    this->columnasTablero = tablero->getColumnas();
    this->filasTablero = tablero->getFilas();
    for(int i = 0; i < columnasTablero; i = i + 1) {
        this->columnasDisponibles[i] = !(this->tablero->columnaLlena(i));
    }
    this->generacion = 0;
    this->cantidadDeGeneraciones = 100;
}

vector<Individuo>* AlgoritmoGenetico::correrAlgoritmo() {
    this->poblacionActual = this->generarPoblacion();
    this->evaluarTodosLosIndividuos();
    while(condicionTerminacion()) {
        vector<Individuo* >* nuevaGeneracion;
        for(int i = 0; i < (this->poblacionActual->size()/2); i = i + 1) { // itero todos los pares
            pair<Individuo*, Individuo*> seleccionados = this->seleccion1(); // PUEDE SER MODIFICADO por seleccion2
            Individuo* seleccionado1 = seleccionados.first;
            Individuo* seleccionado2 = seleccionados.second;
            // aplicar operaciones geneticas:
            pair <Individuo*, Individuo*> descendientes = crossover(seleccionado1,seleccionado2);
            Individuo* descendiente1 = descendientes.first;
            Individuo* descendiente2 = descendientes.second;

            mutacion(descendiente1);
            mutacion(seleccionado2);
            // fitness a descendientes:
            this->fitness1(descendiente1);  // PUEDE SER MODIFICADO por fitness2
            this->fitness1(descendiente2);  // PUEDE SER MODIFICADO por fitness2
            nuevaGeneracion->push_back(descendiente1);
            nuevaGeneracion->push_back(descendiente2);
        }
        delete this->poblacionActual; // NO HAYA ALIASING
        this->poblacionActual = nuevaGeneracion; // NO HAYA ALIASING
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

vector<Individuo* >* AlgoritmoGenetico::generarPoblacion() {
    vector<Individuo* > * nuevaPoblacion = new vector<Individuo*>(this->columnasTablero);
    for(int i = 0; i < columnasTablero; i = i + 1) {
        int fitnessIncial = 0;
        int columna = i;
        if(!this->tablero->columnaLlena(columna)){
            Individuo* individuoOfensivo = new Individuo(fitnessIncial, columna, JUGADA_ALIADA); // 1 == ofensivo (jugada aliada)
            Individuo* individuoDefensivo = new Individuo(fitnessIncial, columna, JUGADA_ENEMIGA); // 0 == defensivo (jugada enemiga)
            nuevaPoblacion->push_back(individuoOfensivo);
            nuevaPoblacion->push_back(individuoDefensivo);
        }
    }
    return nuevaPoblacion;
}

// LO MAS DIFICIL:
//#define JUGADA_ENEMIGA 0
//#define JUGADA_ALIADA 1
void AlgoritmoGenetico::fitness1(Individuo* individuo) {
    int columnaEscogida = individuo->getFilaEscogida();
    int estrategia = individuo->getEstrategia(); // defensiva, ofensiva
    int valorJugada = valoracion(largoFila( columnaEscogida, estrategia )) +
            valoracion(largoColumna( columnaEscogida, estrategia )) +
            valoracion(largoDiagonalIzquierda( columnaEscogida, estrategia)) +
            valoracion(largoDiagonalDerecha( columnaEscogida, estrategia));

    individuo->setEvaluacion(valorJugada);
}

//void AlgoritmoGenetico::fitness2(Individuo* individuo) {}

pair <Individuo*, Individuo*> AlgoritmoGenetico::crossover(Individuo* individuo1,Individuo* individuo2) {
    pair <Individuo*, Individuo*> descendientes; // no hace falta iniciarlo??
    int eval = 0;
    Individuo* descendiente1 = new Individuo(eval,individuo1->getFilaEscogida(),individuo1->getEstrategia());
    Individuo* descendiente2 = new Individuo(eval,individuo2->getFilaEscogida(),individuo2->getEstrategia());
    if(individuo1->getEvaluacion() - individuo2->getEvaluacion() > 4) {

        if(individuo1->getEvaluacion() > individuo2->getEvaluacion()){
            if(individuo1->getEstrategia()==individuo2->getEstrategia()) {
                descendiente2->setFilaEscogida(individuo1->getFilaEscogida());
            } else {
                descendiente2->setEstrategia(individuo1->getEstrategia());
            }
        }
        else{
            if(individuo1->getEstrategia()==individuo2->getEstrategia()) {
                descendiente1->setFilaEscogida(individuo2->getFilaEscogida());
            } else {
                descendiente1->setEstrategia(individuo2->getEstrategia());
            }
        }

    }
    descendientes.first = descendiente1;
    descendientes.second = descendiente2;
    return descendientes;
}

void AlgoritmoGenetico::mutacion(Individuo* individuo) {
    // ver como anda sin mutacion, pero debería ser minima si no se estanca
    //if(individuo->getEvaluacion() < 5) { // no muta, ya que gana
    //}
}

pair <Individuo*, Individuo*> AlgoritmoGenetico::seleccion1() {
    pair <Individuo*, Individuo*> individuosSeleccionados;
    for(int i = 0; i < columnasTablero; i = i + 1) {
        Individuo* individuo1 = poblacionActual->at(i);
        if(!individuo1->fueSeleccionado()){
            Individuo* individuo2 = poblacionActual->at(i+1);
            individuosSeleccionados.first = individuo1;
            individuosSeleccionados.second = individuo2;
            individuo1->seleccionar();
            individuo2->seleccionar();
            return individuosSeleccionados;
        }
    }
}

//vector<int> AlgoritmoGenetico::seleccion2(vector<Individuo* >* poblacion) {}

/////////////////////////////////////////////////////////////////////////////////////

void AlgoritmoGenetico::evaluarTodosLosIndividuos() {
    for(int i = 0; i < columnasTablero; i = i + 1) {
        Individuo* individuo = this->poblacionActual->at(i);
        this->fitness1(individuo); // esto puede cambiar por la funcion de fitness 2
    }
}

bool AlgoritmoGenetico::condicionTerminacion() {
    if(this->generacion<this->cantidadDeGeneraciones){
        this->generacion = this->generacion +1 ;
        return true;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////

int AlgoritmoGenetico::valoracion(int largo) {
    if(largo>=4){
        return 21; // ganas, vale mas que todo
    }
    if(largo==3) {
        return 5;
    }
    if(largo==2) {
        return 3;
    }
    return 1;
}

// PENSAR EN COMPLEJIDADES
int AlgoritmoGenetico::largoFila(int columnaEscogida,int tacticaDefensivaOfensiva) { // 0=def, 1 =of
    int filaDeFichaActual = this->tablero->getIndiceFila(columnaEscogida); // indice fila donde seria nueva jugada
    int largoFila = 1;
    // contar izquierda:
    int col = columnaEscogida-1;
    while( this->tablero->jugadaEn(col,filaDeFichaActual) == tacticaDefensivaOfensiva) { // LIMITES TABLERO
        largoFila++;
        col = col -1;
    }
    // contar derecha:
    col = columnaEscogida +1;
    while( this->tablero->jugadaEn(col,filaDeFichaActual) == tacticaDefensivaOfensiva) { // LIMITES TABLERO
        largoFila++;
        col = col +1;
    }
    return largoFila;
}

int AlgoritmoGenetico::largoColumna(int columnaEscogida,int tacticaDefensivaOfensiva) { // solo cuenta para abajo
    int largoColumna = 1;
    int fila = this->tablero->getIndiceFila(columnaEscogida)-1; // indice fila donde seria nueva jugada
    while( this->tablero->jugadaEn(columnaEscogida,fila) == tacticaDefensivaOfensiva) { // LIMITES TABLERO
        largoColumna++;
        fila = fila - 1;
    }
    return largoColumna;
}

int AlgoritmoGenetico::largoDiagonalIzquierda(int columnaEscogida,int tacticaDefensivaOfensiva) {
    int largoDiagonal = 1;

    int fila = this->tablero->getIndiceFila(columnaEscogida)-1;
    int columna = columnaEscogida-1;
    while( this->tablero->jugadaEn(columna,fila) == tacticaDefensivaOfensiva) { // LIMITES TABLERO
        largoDiagonal++;
        columna = columna-1;
        fila = fila-1; // QUIZAS SEA AL REVES +1
    }

    fila = this->tablero->getIndiceFila(columnaEscogida)+1;
    columna = columnaEscogida+1;
    while( this->tablero->jugadaEn(columna,fila) == tacticaDefensivaOfensiva) { // LIMITES TABLERO
        largoDiagonal++;
        columna = columna+1;
        fila = fila+1;  // QUIZAS SEA AL REVES +1
    }

    return largoDiagonal;
}

int AlgoritmoGenetico::largoDiagonalDerecha(int columnaEscogida,int tacticaDefensivaOfensiva) {
    int largoDiagonal = 1;

    int fila = this->tablero->getIndiceFila(columnaEscogida)-1;   // QUIZAS SEA AL REVES +1
    int columna = columnaEscogida-1;   // QUIZAS SEA AL REVES +1
    while( this->tablero->jugadaEn(columna,fila) == tacticaDefensivaOfensiva) { // LIMITES TABLERO
        largoDiagonal++;
        columna = columna-1;
        fila = fila-1; // QUIZAS SEA AL REVES +1
    }

    fila = this->tablero->getIndiceFila(columnaEscogida)+1;   // QUIZAS SEA AL REVES +1
    columna = columnaEscogida+1;   // QUIZAS SEA AL REVES +1
    while( this->tablero->jugadaEn(columna,fila) == tacticaDefensivaOfensiva) { // LIMITES TABLERO
        largoDiagonal++;
        columna = columna+1;
        fila = fila+1;  // QUIZAS SEA AL REVES +1
    }

    return largoDiagonal;
}