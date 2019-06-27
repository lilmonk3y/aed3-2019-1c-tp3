#include "AlgoritmoGenetico.h"

AlgoritmoGenetico::AlgoritmoGenetico(int cantidadGeneraciones,int cols, int fils,int tamLinea, int cantFichas, int pesoLimite, int cantIndividuos, TestStrategy* rival) {
    this->generacion = 0;
    this->cantidadDeGeneraciones = cantidadGeneraciones;
    this->columnas = cols;
    this->filas = fils;
    this->tamanioLinea = tamLinea;
    this->cantidadFichas = cantFichas;
    this->cantidadMaximaDeJugadas = fils*cols;
    this->pesoLimite = pesoLimite;
    this->cantidadIndividuos = cantIndividuos;
    this->fitnessPromedio = 0;
    TestStrategy* jugadorRival = rival; // REVISAR
}

vector<Individuo>* AlgoritmoGenetico::correrAlgoritmo() {
    this->poblacionActual = this->generarPoblacion();
    this->evaluarTodosLosIndividuos();
    while(condicionTerminacion1() && condicionTerminacion2()) { // condicion 1 ó 2 ó ambas.
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
        delete this->poblacionActual; // QUE NO HAYA ALIASING con nuevaGeneracion
        this->poblacionActual = nuevaGeneracion; //QUE  NO HAYA ALIASING con poblacionActual anterior
    }
}

//////////////////////////////////////OPERACIONES OBLIGATORIAS//////////////////////////////////////////////////////////////

vector<Individuo* >* AlgoritmoGenetico::generarPoblacion() {
    vector<Individuo*>* nuevaPoblacion = new vector<Individuo*>(cantidadIndividuos);

    for(int i = 0; i < cantidadIndividuos; i = i + 1) {
        // individuos con genes aleatorios entre 0 y pesoLimite-1:
        Individuo* individuo = new Individuo(rand() % pesoLimite,rand() % pesoLimite,rand() % pesoLimite,rand() % pesoLimite,rand() % pesoLimite,rand() % pesoLimite,rand() % pesoLimite,rand() % pesoLimite,rand() % pesoLimite);
        nuevaPoblacion->push_back(individuo);
    }

    return nuevaPoblacion;
}

void AlgoritmoGenetico::fitness1(Individuo* individuo) { // EVALUACION SOLO POR GANADOR
    // REVISAR
    GreedyStrategy* playerNuestro = contruirPlayerNuestro(individuo);
    ResultadosPartida datos = CLASS.jugar(columnas,filas,tamanioLinea,cantidadFichas,playerNuestro,jugadorRival); // REVISAR
    if(datos->ganoNuestroJugador){
        individuo->setEvaluacion(0); // mas baja mejor evaluacion (alternativa:1)
    } else {
        individuo->setEvaluacion(1); // mas alta peor evaluacion (alternativa:filas*columnas)
    }
}

void AlgoritmoGenetico::fitness2(Individuo* individuo) { // EVALUACION POR CANTIDAD DE JUGADAS
    // REVISAR

    GreedyStrategy* playerNuestro = contruirPlayerNuestro(individuo);
    ResultadosPartida datos = CLASS.jugar(columnas,filas,tamanioLinea,cantidadFichas,playerNuestro,jugadorRival); // REVISAR
    if(datos->ganoNuestroJugador){
        individuo->setEvaluacion(datos->largoPartida);
    } else {
        individuo->setEvaluacion(this->columnas*this->filas); // peor evaluacion es el valor mas alto
    }
 }

pair <Individuo*, Individuo*> AlgoritmoGenetico::crossover(Individuo* mejorIndividuo,Individuo* peorIndividuo) {
    pair <Individuo*, Individuo*> descendientes;
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

pair <Individuo*, Individuo*> AlgoritmoGenetico::seleccion1() { // MEJOR Y PEOR INDIVIDUOS

    pair <Individuo*, Individuo*> individuosSeleccionados;
    int peorFitness = 0; // cantidad minima de jugadas (va aumentando cuando es peor)
    int mejorFitness = filas*columnas; // cantidad maxima de jugadas (va disminuyendo cuando es mejor)

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

pair <Individuo*, Individuo*>  AlgoritmoGenetico::seleccion2() { // MEJOR Y SEGUNDO MEJOR

    int mejorFitness = filas*columnas; // cantidad maxima de jugadas (va disminuyendo cuando es mejor)

    pair <Individuo*, Individuo*> individuosSeleccionados;

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

//////////////////////////////////OTRAS FUNCIONES///////////////////////////////////////////////////

bool AlgoritmoGenetico::condicionDeMutacion(Individuo* individuo){ // peor fitness (mayor valor), mayor probabilidad
    return rand()%(this->cantidadMaximaDeJugadas-individuo->getEvaluacion()) == 0; // cantidad de jugadas cercanas a la maxima, es mas probable.
}

void AlgoritmoGenetico::evaluarTodosLosIndividuos() {
    for(std::size_t i=0; i<this->poblacionActual->size(); ++i) { // itero todos los individuos
        Individuo* individuo = this->poblacionActual->at(i);
        fitness1(individuo); // tambien se puede usar fitness2
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

GreedyStrategy* AlgoritmoGenetico::contruirPlayerNuestro(Individuo* individuo) {
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

    return new GreedyStrategy(pesos);
}

