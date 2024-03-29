#ifndef AED3_TP3_INDIVIDUO_H
#define AED3_TP3_INDIVIDUO_H

#include <string>
#include <map>
#include "Defines.h"

class Individuo {

public:
    Individuo(int pesoGenes,int evaluacion);
    Individuo(PESO,PESO,PESO,PESO,PESO,PESO,PESO,PESO,PESO,int evaluacion);
    Individuo(Individuo& anotherIndividuo); // constructor por copia
    int getEvaluacion();
    void setEvaluacion(int evaluacion);

    bool fueSeleccionado();
    void seleccionar();

    // genoma/genotipo: (conjunto de genes)
    PESO horizontal_ofensivo;
    PESO horizontal_defensivo;
    PESO vertical_ofensivo;
    PESO vertical_defensivo;
    PESO diagonal_45_ofensivo;
    PESO diagonal_45_defensivo;
    PESO diagonal_315_ofensivo;
    PESO diagonal_315_defensivo;
    PESO jugada_aleatoria;

private:
    // atributos de uso solo para el algoritmo genetico:
    int evaluacion; // dado por la funcion fitness
    bool seleccionado; // usado para la seleccion (marcar si fue seleccionado)

};


#endif //AED3_TP3_INDIVIDUO_H
