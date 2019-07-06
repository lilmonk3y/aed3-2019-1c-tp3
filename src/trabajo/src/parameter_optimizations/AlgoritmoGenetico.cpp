#include <iostream>
#include "AlgoritmoGenetico.h"
#include "../entities/ResultadosPartida.h"
#include "../InplaceGame.h"
#include <vector>

AlgoritmoGenetico::AlgoritmoGenetico(int cantidadGeneraciones, int cantIndividuos, int pesoLimite,
        Tablero *tablero, iPlayer *aliado, iPlayer *rival) {
    this->generacion = 0;
    this->cantidadDeGeneraciones = cantidadGeneraciones;
    this->cantidadIndividuos = cantIndividuos;
    this->pesoLimite = pesoLimite;
    this->tablero = tablero;
    this->cantidadMaximaDeJugadas = tablero->getColumnas() * tablero->getFilas();
    this->fitnessPromedio = tablero->getColumnas() * tablero->getFilas();
    this->aliado = aliado;
    this->rival = rival;
}

Individuo* AlgoritmoGenetico::correrAlgoritmo() {
    this->poblacionActual = this->generarPoblacion();
    this->evaluarTodosLosIndividuos();
    while(condicionTerminacion1() && condicionTerminacion2()) {
        std::vector<Individuo* >* nuevaGeneracion;
        for(int i = 0; i < (this->poblacionActual->size()/2); i = i + 1) { // itero todos los pares (selecciono de a 2)
            // seleccionar 2 individuos para luego reproducirse:
            std::pair<Individuo*, Individuo*> seleccionados = seleccion(); // seleccion1 o seleccion2
            Individuo* seleccionado1 = seleccionados.first;
            Individuo* seleccionado2 = seleccionados.second;
            // aplicar operaciones geneticas (reproduccion y mutación):
            std::pair <Individuo*, Individuo*> descendientes = crossover(seleccionado1,seleccionado2); // reproduccion
            Individuo* descendiente1 = descendientes.first;
            Individuo* descendiente2 = descendientes.second;

            mutacion(descendiente1);
            mutacion(descendiente2);
            // fitness a descendientes:
            fitness(descendiente1);
            fitness(descendiente2);
            nuevaGeneracion->push_back(descendiente1);
            nuevaGeneracion->push_back(descendiente2);
        }
        delete this->poblacionActual; // QUE NO HAYA ALIASING con nuevaGeneracion
        this->poblacionActual = nuevaGeneracion; //QUE  NO HAYA ALIASING con poblacionActual anterior
    }
    return mejorIndividuo(); // retornar al individuo con mejor aptitud (ademas imprime sus genes en la terminal)
}

//////////////////////////////////////OPERACIONES OBLIGATORIAS//////////////////////////////////////////////////////////////

std::vector<Individuo* >* AlgoritmoGenetico::generarPoblacion() {
    std::vector<Individuo*>* nuevaPoblacion = new std::vector<Individuo*>(cantidadIndividuos);

    for(int i = 0; i < cantidadIndividuos; i++) {
        // individuos con genes aleatorios entre 0 y pesoLimite-1:
        int evaluacionInicial = this->cantidadMaximaDeJugadas;
        Individuo* individuo = new Individuo(rand() % pesoLimite,
                rand() % pesoLimite,
                rand() % pesoLimite,
                rand() % pesoLimite,
                rand() % pesoLimite,
                rand() % pesoLimite,
                rand() % pesoLimite,
                rand() % pesoLimite,
                rand() % pesoLimite,
                evaluacionInicial);
        nuevaPoblacion->push_back(individuo);
    }

    return nuevaPoblacion;
}

void AlgoritmoGenetico::fitness1(Individuo* individuo) { // EVALUACION SOLO POR GANADOR
    setParametrosDesde(individuo, ((GreedyPlayer*)this->aliado) );
    ResultadosPartida datos = jugar(*tablero,*aliado,*rival, FICHA_ENEMIGA); // REVISAR
    tablero->setFichas(this->cantidadFichas);
    if(datos.isGanoNuestroJugador()){
        individuo->setEvaluacion(this->fitnessPromedio); // si gana es el promedio
    } else {
        individuo->setEvaluacion(this->tamanioLinea); // mas alta peor evaluacion
    }
}

void AlgoritmoGenetico::fitness2(Individuo* individuo) { // EVALUACION POR CANTIDAD DE JUGADAS
    setParametrosDesde(individuo, ((GreedyPlayer*) this->aliado));
    ResultadosPartida datos = jugar(*tablero,*aliado,*rival,FICHA_ALIADA);
    if(datos.isGanoNuestroJugador()){
        individuo->setEvaluacion(datos.getLargoPartida());
    } else {
        individuo->setEvaluacion(this->pesoLimite); // peor evaluacion es el valor mas alto
    }
 }

void AlgoritmoGenetico::fitness(Individuo* individuo) {
    if( rand()%2==0 ){ //%50
        fitness1(individuo);
    } else {
        fitness2(individuo);
    }
}

std::pair <Individuo*, Individuo*> AlgoritmoGenetico::crossover(Individuo* mejorIndividuo,Individuo* peorIndividuo) {
    std::pair <Individuo*, Individuo*> descendientes;
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

    descendientes.first = descendiente1; // el mejor sobrevive
    descendientes.second = descendiente2; // hereda cosas del otro individuo, del mejor, la mitad de genes
    return descendientes;
}

void AlgoritmoGenetico::mutacion(Individuo* individuo) {
    if(condicionDeMutacion(individuo)){ // % de probabilidad de mutacion depende del desempeño
        int valorAleatorio = rand()%pesoLimite; // aleatorio de 0 a pesoLimite-1
        int genAleatorio = rand()%10; // aleatorio de 0 a 9 (CANTIDAD DE GENES)
        if( genAleatorio==1 ){
            individuo->horizontal_defensivo = valorAleatorio;

        }
        if( genAleatorio==2 ){
            individuo->horizontal_ofensivo = valorAleatorio;

        }
        if( genAleatorio==3 ){
            individuo->vertical_defensivo = valorAleatorio;

        }
        if( genAleatorio==4 ){
            individuo->vertical_ofensivo = valorAleatorio;

        }
        if( genAleatorio==5 ){
            individuo->diagonal_315_defensivo = valorAleatorio;

        }
        if( genAleatorio==6 ){
            individuo->diagonal_315_ofensivo = valorAleatorio;

        }
        if( genAleatorio==7 ){
            individuo->diagonal_45_defensivo = valorAleatorio;

        }
        if( genAleatorio==8 ){
            individuo->diagonal_45_ofensivo = valorAleatorio;

        }
        if( genAleatorio==9 ){
            individuo->jugada_aleatoria = valorAleatorio;

        }
    }
}

std::pair <Individuo*, Individuo*> AlgoritmoGenetico::seleccion1() { // MEJOR Y PEOR INDIVIDUOS

    std::pair <Individuo*, Individuo*> individuosSeleccionados;
    int peorFitness = 0; // cantidad minima de jugadas (va aumentando cuando es peor)
    int mejorFitness = this->pesoLimite; // cantidad maxima de jugadas (va disminuyendo cuando es mejor)

    Individuo* mejorIndividuo;
    Individuo* peorIndividuo;
    for(std::size_t i=0; i<this->poblacionActual->size(); ++i) { // itero todos los individuos (DEBEN SER PARES)
        Individuo* individuo = this->poblacionActual->at(i);
        if(!individuo->fueSeleccionado() && individuo->getEvaluacion()<=mejorFitness) { // individuo mejor de todos (<= porque pueden ser todos iguales)
            mejorIndividuo = individuo;
            mejorFitness = individuo->getEvaluacion();
        }
    }

    mejorIndividuo->seleccionar(); // marcarlos, asi ya no se pueden seleccionar la proxima vez

    for(std::size_t i=0; i<this->poblacionActual->size(); ++i) { // itero todos los individuos (DEBEN SER PARES)
        Individuo* individuo = this->poblacionActual->at(i);
        if(!individuo->fueSeleccionado()) {
            if( peorFitness==0 || individuo->getEvaluacion()>=peorFitness){
                peorIndividuo = individuo;
                peorFitness = individuo->getEvaluacion();
            }
        }
    }

    peorIndividuo->seleccionar();  // marcarlos, asi ya no se pueden seleccionar la proxima vez

    individuosSeleccionados.first = mejorIndividuo;
    individuosSeleccionados.second = peorIndividuo;
    return individuosSeleccionados;
}

std::pair <Individuo*, Individuo*>  AlgoritmoGenetico::seleccion2() { // MEJOR Y SEGUNDO MEJOR

    int mejorFitness = this->pesoLimite; // cantidad maxima de jugadas (va disminuyendo cuando es mejor)

    std::pair <Individuo*, Individuo*> individuosSeleccionados;

    Individuo* mejorIndividuo=NULL;
    Individuo* segundoMejorIndividuo=NULL;

    for(std::size_t i=0; i<this->poblacionActual->size(); ++i) { // itero todos los individuos (DEBEN SER PARES)
        Individuo* individuo = this->poblacionActual->at(i);
        if(!individuo->fueSeleccionado() && individuo->getEvaluacion()<=mejorFitness) { // individuo mejor de todos

            if(mejorIndividuo!=NULL){
                segundoMejorIndividuo = mejorIndividuo;
            }
            mejorIndividuo = individuo;
            mejorFitness = individuo->getEvaluacion();
        }
    }

    mejorIndividuo->seleccionar(); // marcarlos, asi ya no se pueden seleccionar la proxima vez
    segundoMejorIndividuo->seleccionar();  // marcarlos, asi ya no se pueden seleccionar la proxima vez
    individuosSeleccionados.first = mejorIndividuo;
    individuosSeleccionados.second = segundoMejorIndividuo;
    return individuosSeleccionados;
}

std::pair <Individuo*, Individuo*> AlgoritmoGenetico::seleccion() {
    if( rand()%2==0 ) { //50%
        return seleccion1();
    } else {
        return seleccion2();
    }
}

//////////////////////////////////OTRAS FUNCIONES///////////////////////////////////////////////////

bool AlgoritmoGenetico::condicionDeMutacion(Individuo* individuo){ // peor fitness (mayor valor), mayor probabilidad
    return rand()%(this->cantidadMaximaDeJugadas-individuo->getEvaluacion()) == 0; // cantidad de jugadas cercanas a la maxima, es mas probable.
}

void AlgoritmoGenetico::evaluarTodosLosIndividuos() {
    for(std::size_t i=0; i<this->poblacionActual->size(); ++i) {
        Individuo* individuo = this->poblacionActual->at(i);
        fitness2(individuo);
    }
}

bool AlgoritmoGenetico::condicionTerminacion1() { // por cantidad de generaciones
    if(this->generacion<this->cantidadDeGeneraciones){
        this->generacion = this->generacion +1 ;
        return true;
    }
    return false;
}

bool AlgoritmoGenetico::condicionTerminacion2() { // si el promedio no cambia entre generaciones consecutivas termina
    int promedioGeneracionAnterior = this->fitnessPromedio;
    recalcularEvaluacionPromedioDeLaPoblacion();
    int promedioGeneracionActual = this->fitnessPromedio;
    if(promedioGeneracionAnterior == promedioGeneracionActual ){
        return false; // si son iguales los promedios terminar
    }
    return true; // sino seguir
}

void AlgoritmoGenetico::recalcularEvaluacionPromedioDeLaPoblacion() {
    int sumatoriaEvaluaciones = 0;
    for(std::size_t i=0; i<this->poblacionActual->size(); ++i) { // itero todos los individuos
        Individuo* individuo = this->poblacionActual->at(i);
        sumatoriaEvaluaciones = sumatoriaEvaluaciones + individuo->getEvaluacion();
    }
    this->fitnessPromedio = sumatoriaEvaluaciones/this->cantidadIndividuos;
}

Individuo* AlgoritmoGenetico::mejorIndividuo() {
    int mejorEvaluacion= this->cantidadMaximaDeJugadas;
    Individuo* mejorIndividuo;
    for(std::size_t i=0; i<this->poblacionActual->size(); ++i) {
        Individuo* individuo = this->poblacionActual->at(i);
        if(individuo->getEvaluacion()<=mejorEvaluacion){
            mejorIndividuo = individuo;
            mejorEvaluacion = individuo->getEvaluacion();
        }
    }
    std::cout << "evaluacion: " << mejorIndividuo->getEvaluacion() << std::endl;
    // mostrar genes en pantalla:
    std::cout << "horizontal_ofensivo: " << mejorIndividuo->horizontal_ofensivo << std::endl;
    std::cout << "horizontal_defensivo: " << mejorIndividuo->horizontal_defensivo << std::endl;
    std::cout << "vertical_ofensivo: " << mejorIndividuo->vertical_ofensivo << std::endl;
    std::cout << "vertical_defensivo: " << mejorIndividuo->vertical_defensivo << std::endl;
    std::cout << "diagonal_45_ofensivo: " << mejorIndividuo->diagonal_45_ofensivo << std::endl;
    std::cout << "diagonal_45_defensivo: " << mejorIndividuo->diagonal_45_defensivo << std::endl;
    std::cout << "diagonal_315_ofensivo: " << mejorIndividuo->diagonal_315_ofensivo << std::endl;
    std::cout << "diagonal_315_defensivo: " << mejorIndividuo->diagonal_315_defensivo << std::endl;
    std::cout << "jugada_aleatoria: " << mejorIndividuo->jugada_aleatoria << std::endl;
    return mejorIndividuo;
}

void AlgoritmoGenetico::setParametrosDesde(Individuo *individuo, GreedyPlayer *player) {
    auto *pesos = new std::map<STRATEGY_NAME, PESO>();
    pesos->insert(std::make_pair(HORIZONTAL_OFENSIVO, individuo->horizontal_ofensivo ));
    pesos->insert(std::make_pair(HORIZONTAL_DEFENSIVO, individuo->horizontal_defensivo ));
    pesos->insert(std::make_pair(VERTICAL_OFENSIVO, individuo->vertical_ofensivo ));
    pesos->insert(std::make_pair(VERTICAL_DEFENSIVO, individuo->vertical_defensivo ));
    pesos->insert(std::make_pair(DIAGONAL_45_OFENSIVO, individuo->diagonal_45_ofensivo ));
    pesos->insert(std::make_pair(DIAGONAL_45_DEFENSIVO,individuo->diagonal_45_defensivo ));
    pesos->insert(std::make_pair(DIAGONAL_315_OFENSIVO, individuo->diagonal_315_ofensivo ));
    pesos->insert(std::make_pair(DIAGONAL_315_DEFENSIVO,individuo->diagonal_315_defensivo ));
    pesos->insert(std::make_pair(JUGADA_ALEATORIA, individuo->jugada_aleatoria  ));

    player->setNuevosPesosParaEstrategias(pesos);
}
