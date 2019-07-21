#include "GridSearch.h"
#include <iostream>


GridSearch::GridSearch() {

}

Solucion* GridSearch::gridSearch(int cantidadIteraciones,int cantidadCandidatos,int radio,Solucion* solucionInicial,Tablero* tablero) {
    Solucion* solucion = solucionInicial;
    int cantIteraciones = cantidadIteraciones;
    bool hayMejorSolucion = true;
    while( cantIteraciones > 0 && hayMejorSolucion){
        cout << "iteracion: " << cantIteraciones << endl; // BORRAR
        vector<Solucion* >* candidatos = generarCandidatos(cantidadCandidatos,radio,solucion);
        vector<Solucion* >*  mejoresQueActualSolucion = comparar(candidatos,solucion,tablero);
        if(!mejoresQueActualSolucion->empty()) {
            solucion = mejorSolucion(mejoresQueActualSolucion, tablero);
        }else{
                hayMejorSolucion = false;
            }
            cantIteraciones = cantIteraciones - 1;
        }

    std::cout << "horizontal_ofensivo: " << solucion->horizontal_ofensivo << std::endl;
    std::cout << "horizontal_defensivo: " << solucion->horizontal_defensivo << std::endl;
    std::cout << "vertical_ofensivo: " << solucion->vertical_ofensivo << std::endl;
    std::cout << "vertical_defensivo: " << solucion->vertical_defensivo << std::endl;
    std::cout << "diagonal_45_ofensivo: " << solucion->diagonal_45_ofensivo << std::endl;
    std::cout << "diagonal_45_defensivo: " << solucion->diagonal_45_defensivo << std::endl;
    std::cout << "diagonal_315_ofensivo: " << solucion->diagonal_315_ofensivo << std::endl;
    std::cout << "diagonal_315_defensivo: " << solucion->diagonal_315_defensivo << std::endl;
    std::cout << "jugada_aleatoria: " << solucion->jugada_aleatoria << std::endl;
    return solucion;
}

vector<Solucion* >* GridSearch::generarCandidatos(int cantidadCandidatos,int radio,Solucion* solucion) {
    vector<Solucion* >* candidatos = new vector<Solucion* >();
    for(std::size_t i=0; i<cantidadCandidatos; ++i){

        int p1 = variacion(solucion->horizontal_ofensivo, radio);
        int p2 = variacion(solucion->horizontal_defensivo, radio);
        int p3 = variacion(solucion->vertical_ofensivo, radio);
        int p4 = variacion(solucion->vertical_defensivo, radio);
        int p5 = variacion(solucion->diagonal_45_ofensivo, radio);
        int p6 = variacion(solucion->diagonal_45_defensivo, radio);
        int p7 = variacion(solucion->diagonal_315_ofensivo, radio);
        int p8 = variacion(solucion->diagonal_315_defensivo, radio);
        int p9 = variacion(solucion->jugada_aleatoria, radio);

        Solucion* nuevoCandidato = new Solucion(p1,p2,p3,p4,p5,p6,p7,p8,p9);
        candidatos->push_back(nuevoCandidato);

    }
    return candidatos;
}

int GridSearch::variacion(int valor, int radio) {
    int nuevoValor = 0;
    if( (rand() % 2) == 0) {
        nuevoValor = valor + (rand() % radio);
    } else {
        nuevoValor = valor - (rand() % radio);
        if(nuevoValor < 0) {
            nuevoValor = 0;
        }
    }
    return nuevoValor;
}

vector<Solucion* >* GridSearch::comparar(vector<Solucion* >* candidatos,Solucion* solucion,Tablero* tablero) {
    vector<Solucion* >* mejoresSoluciones = new vector<Solucion* >();

    for(std::size_t i=0; i<candidatos->size(); ++i) { // itero todos los candidatos
        GreedyPlayer& mejorJugadorHastaAhora = generarJugador(solucion);
        GreedyPlayer& jugadorCandidato = generarJugador(candidatos->at(i));
        cout << "van a jugar" << endl; // BORRAR

        std::cout << "horizontal_ofensivo: " << solucion->horizontal_ofensivo << std::endl;
        std::cout << "horizontal_defensivo: " << solucion->horizontal_defensivo << std::endl;
        std::cout << "vertical_ofensivo: " << solucion->vertical_ofensivo << std::endl;
        std::cout << "vertical_defensivo: " << solucion->vertical_defensivo << std::endl;
        std::cout << "diagonal_45_ofensivo: " << solucion->diagonal_45_ofensivo << std::endl;
        std::cout << "diagonal_45_defensivo: " << solucion->diagonal_45_defensivo << std::endl;
        std::cout << "diagonal_315_ofensivo: " << solucion->diagonal_315_ofensivo << std::endl;
        std::cout << "diagonal_315_defensivo: " << solucion->diagonal_315_defensivo << std::endl;
        std::cout << "jugada_aleatoria: " << solucion->jugada_aleatoria << std::endl;

        std::cout << "------------------------------"  << std::endl;

        std::cout << "horizontal_ofensivo: " << candidatos->at(i)->horizontal_ofensivo << std::endl;
        std::cout << "horizontal_defensivo: " << candidatos->at(i)->horizontal_defensivo << std::endl;
        std::cout << "vertical_ofensivo: " << candidatos->at(i)->vertical_ofensivo << std::endl;
        std::cout << "vertical_defensivo: " << candidatos->at(i)->vertical_defensivo << std::endl;
        std::cout << "diagonal_45_ofensivo: " << candidatos->at(i)->diagonal_45_ofensivo << std::endl;
        std::cout << "diagonal_45_defensivo: " << candidatos->at(i)->diagonal_45_defensivo << std::endl;
        std::cout << "diagonal_315_ofensivo: " << candidatos->at(i)->diagonal_315_ofensivo << std::endl;
        std::cout << "diagonal_315_defensivo: " << candidatos->at(i)->diagonal_315_defensivo << std::endl;
        std::cout << "jugada_aleatoria: " << candidatos->at(i)->jugada_aleatoria << std::endl;

        ResultadosPartida datos = jugar(*tablero,jugadorCandidato,mejorJugadorHastaAhora, FICHA_ALIADA);
        cout << "ya jugaron" << endl; // BORRAR

        if(datos.isGanoNuestroJugador()) {
            mejoresSoluciones->push_back(candidatos->at(i));
        }
    }
    return mejoresSoluciones;
}

Solucion* GridSearch::mejorSolucion(vector<Solucion* >* mejoresQueActualSolucion,Tablero* tablero ) { //  no puede ser vacio el parametro
    Solucion* mejorSolucion = mejoresQueActualSolucion->at(0);

    for(std::size_t i=0; i<mejoresQueActualSolucion->size(); ++i) { // itero todos los candidatos
        GreedyPlayer& mejorJugadorHastaAhora = generarJugador(mejorSolucion);
        GreedyPlayer& jugador = generarJugador(mejoresQueActualSolucion->at(i));
        ResultadosPartida datos = jugar(*tablero,jugador,mejorJugadorHastaAhora, FICHA_ALIADA);

        if(datos.isGanoNuestroJugador()) {
            mejorSolucion = mejoresQueActualSolucion->at(i);
        }
    }

    return mejorSolucion;
}

GreedyPlayer& GridSearch::generarJugador(Solucion* solucion) {
    auto *pesos = new std::map<STRATEGY_NAME, PESO>();
    pesos->insert(std::make_pair(HORIZONTAL_OFENSIVO, solucion->horizontal_ofensivo ));
    pesos->insert(std::make_pair(HORIZONTAL_DEFENSIVO, solucion->horizontal_defensivo ));
    pesos->insert(std::make_pair(VERTICAL_OFENSIVO, solucion->vertical_ofensivo ));
    pesos->insert(std::make_pair(VERTICAL_DEFENSIVO, solucion->vertical_defensivo ));
    pesos->insert(std::make_pair(DIAGONAL_45_OFENSIVO, solucion->diagonal_45_ofensivo ));
    pesos->insert(std::make_pair(DIAGONAL_45_DEFENSIVO,solucion->diagonal_45_defensivo ));
    pesos->insert(std::make_pair(DIAGONAL_315_OFENSIVO, solucion->diagonal_315_ofensivo ));
    pesos->insert(std::make_pair(DIAGONAL_315_DEFENSIVO,solucion->diagonal_315_defensivo ));
    pesos->insert(std::make_pair(JUGADA_ALEATORIA, solucion->jugada_aleatoria  ));

    return *(new GreedyPlayer(pesos));
}

