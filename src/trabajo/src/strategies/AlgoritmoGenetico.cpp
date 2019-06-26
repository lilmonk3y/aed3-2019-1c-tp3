#include "AlgoritmoGenetico.h"

AlgoritmoGenetico::AlgoritmoGenetico(int generation,int cantidadGeneraciones) {
    this->generacion = 0;
    this->cantidadDeGeneraciones = cantidadGeneraciones;
}

vector<Individuo>* AlgoritmoGenetico::correrAlgoritmo() {
    this->poblacionActual = this->generarPoblacion();
    this->evaluarTodosLosIndividuos();
    while(condicionTerminacion()) {
        vector<Individuo* >* nuevaGeneracion;
        for(int i = 0; i < (this->poblacionActual->size()/2); i = i + 1) { // itero todos los pares (selecciono de a 2)
            // seleccionar 2 individuos para luego reproducirse:
            pair<Individuo*, Individuo*> seleccionados = seleccion1(); // tambien se puede usar seleccion2
            Individuo* seleccionado1 = seleccionados.first;
            Individuo* seleccionado2 = seleccionados.second;
            // aplicar operaciones geneticas (reproduccion y mutación):
            pair <Individuo*, Individuo*> descendientes = crossover(seleccionado1,seleccionado2); // reproduccion
            Individuo* descendiente1 = descendientes.first;
            Individuo* descendiente2 = descendientes.second;

            mutacion(descendiente1);
            mutacion(descendiente2);
            // fitness a descendientes:
            fitness1(descendiente1);  // tambien se puede usar fitness2
            fitness1(descendiente2);  // tambien se puede usar fitness2
            nuevaGeneracion->push_back(descendiente1);
            nuevaGeneracion->push_back(descendiente2);
        }
        delete this->poblacionActual; // NO HAYA ALIASING
        this->poblacionActual = nuevaGeneracion; // NO HAYA ALIASING
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

// fitness1, crossover, seleccion1

vector<Individuo* >* AlgoritmoGenetico::generarPoblacion() { // OK
    int pesoLimite = 100;  // CONFIGURACION
    int cantidadIndividuos = 1000;  // CONFIGURACION

    vector<Individuo*>* nuevaPoblacion = new vector<Individuo*>(cantidadIndividuos);

    for(int i = 0; i < cantidadIndividuos; i = i + 1) {
        // individuos con genes aleatorios entre 0 y pesoLimite-1:
        Individuo* individuo = new Individuo(rand() % pesoLimite,rand() % pesoLimite,rand() % pesoLimite,rand() % pesoLimite,rand() % pesoLimite,rand() % pesoLimite,rand() % pesoLimite,rand() % pesoLimite,rand() % pesoLimite);
        nuevaPoblacion->push_back(individuo);
    }

    return nuevaPoblacion;
}

void AlgoritmoGenetico::fitness1(Individuo* individuo) {
    int cantidadJugadas = hacerCompetir(individuo); // IMPLEMENTAR, si pierde deberia devolver 0
    individuo->setEvaluacion(valor);
}

//void AlgoritmoGenetico::fitness2(Individuo* individuo) {}

pair <Individuo*, Individuo*> AlgoritmoGenetico::crossover(Individuo* mejorIndividuo,Individuo* peorIndividuo) {
    pair <Individuo*, Individuo*> descendientes; // no hace falta iniciarlo??
    Individuo* descendiente1 = new Individuo(*mejorIndividuo); // clonacion
    Individuo* descendiente2 = new Individuo(*peorIndividuo); // clonacion

    if(rand()%2==0){ // 50%
        descendiente2->jugada_aleatoria = mejorIndividuo->jugada_aleatoria;
        descendiente2->vertical_ofensivo = mejorIndividuo->vertical_ofensivo;
        descendiente2->vertical_defensivo = mejorIndividuo->vertical_defensivo;
        descendiente2->horizontal_ofensivo = mejorIndividuo->horizontal_ofensivo;
        descendiente2->horizontal_defensivo = mejorIndividuo->horizontal_defensivo;
    } else {
        descendiente2->diagonal_45_ofensivo = mejorIndividuo->diagonal_45_ofensivo;
        descendiente2->diagonal_45_defensivo = mejorIndividuo->diagonal_45_defensivo;
        descendiente2->diagonal_315_ofensivo = mejorIndividuo->diagonal_315_ofensivo;
        descendiente2->diagonal_315_defensivo = mejorIndividuo->diagonal_315_defensivo;
    }

    descendientes.first = descendiente1; // queda igual al mejor
    descendientes.second = descendiente2; // hereda cosas del otro individuo, del mejor, la mitad de genes
    return descendientes;
}

void AlgoritmoGenetico::mutacion(Individuo* individuo) { // OK
    if(rand()%5==1){ // 20% de probabilidad de mutacion // CONFIGURACION: parametro probabilidad de mutacion
        int pesoLimite = 100; // CONFIGURACION
        int valorAleatorio = rand()%pesoLimite; // aleatorio de 0 a pesoLimite-1
        int genAleatorio = rand()%10; // aleatorio de 0 a 9
        if( genAleatorio==1 ){
            individuo->horizontal_defensivo =valorAleatorio;

        }
        if( genAleatorio==2 ){
            individuo->horizontal_ofensivo =valorAleatorio;

        }
        if( genAleatorio==3 ){
            individuo->vertical_defensivo =valorAleatorio;

        }
        if( genAleatorio==4 ){
            individuo->vertical_ofensivo =valorAleatorio;

        }
        if( genAleatorio==5 ){
            individuo->diagonal_315_defensivo =valorAleatorio;

        }
        if( genAleatorio==6 ){
            individuo->diagonal_315_ofensivo =valorAleatorio;

        }
        if( genAleatorio==7 ){
            individuo->diagonal_45_defensivo =valorAleatorio;

        }
        if( genAleatorio==8 ){
            individuo->diagonal_45_ofensivo =valorAleatorio;

        }
        if( genAleatorio==9 ){
            individuo->jugada_aleatoria =valorAleatorio;

        }
    }
}

pair <Individuo*, Individuo*> AlgoritmoGenetico::seleccion1() {// MEJOR Y PEOR INDIVIDUOS

    pair <Individuo*, Individuo*> individuosSeleccionados;

    int maxFitness=-1; // CONFIGURACION
    int minFitness=-1; // CONFIGURACION
    Individuo* mejorIndividuo;
    Individuo* peorIndividuo;
    for(std::size_t i=0; i<this->poblacionActual->size(); ++i) { // itero todos los individuos (DEBEN SER PARES)
        Individuo* individuo = this->poblacionActual->at(i);
        if(!individuo->fueSeleccionado() && individuo->getEvaluacion()>maxFitness) { // individuo mejor de todos
            mejorIndividuo = individuo;
            maxFitness = individuo->getEvaluacion();
        }
    }

    for(std::size_t i=0; i<this->poblacionActual->size(); ++i) { // itero todos los individuos (DEBEN SER PARES)
        Individuo* individuo = this->poblacionActual->at(i);
        if(!individuo->fueSeleccionado()) {
            if( minFitness==-1 || individuo->getEvaluacion()<minFitness){
                peorIndividuo = individuo;
                minFitness = individuo->getEvaluacion();
            }
        }
    }

    mejorIndividuo->seleccionar(); // marcarlos, asi ya no se pueden seleccionar la proxima vez
    peorIndividuo->seleccionar();  // marcarlos, asi ya no se pueden seleccionar la proxima vez
    individuosSeleccionados.first = mejorIndividuo;
    individuosSeleccionados.second = peorIndividuo;
    return individuosSeleccionados;
}

//vector<int> AlgoritmoGenetico::seleccion2(vector<Individuo* >* poblacion) {}

/////////////////////////////////////////////////////////////////////////////////////

void AlgoritmoGenetico::evaluarTodosLosIndividuos() { // OK
    for(std::size_t i=0; i<this->poblacionActual->size(); ++i) { // itero todos los individuos
        Individuo* individuo = this->poblacionActual->at(i);
        fitness1(individuo);
    }
}

bool AlgoritmoGenetico::condicionTerminacion() { // OK
    if(this->generacion<this->cantidadDeGeneraciones){
        this->generacion = this->generacion +1 ;
        return true;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////
/*
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
}*/