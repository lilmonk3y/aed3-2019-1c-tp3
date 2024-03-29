#include "Individuo.h"

Individuo::Individuo(int pesoGenes,int eval) {
    this->evaluacion = eval;
    this->seleccionado = false;
    // genoma/genotipo: (conjunto de genes)
    this->horizontal_defensivo = pesoGenes;
    this->horizontal_ofensivo = pesoGenes;
    this->vertical_defensivo = pesoGenes;
    this->vertical_ofensivo = pesoGenes;
    this->diagonal_45_defensivo = pesoGenes;
    this->diagonal_45_ofensivo = pesoGenes;
    this->diagonal_315_defensivo = pesoGenes;
    this->diagonal_315_ofensivo = pesoGenes;
    this->jugada_aleatoria = pesoGenes;
}

Individuo::Individuo(PESO gen1,PESO gen2,PESO gen3,PESO gen4,PESO gen5,PESO gen6,PESO gen7,PESO gen8,PESO gen9,int eval) {
    this->evaluacion = eval;
    this->seleccionado = false;
    // genoma/genotipo: (conjunto de genes)
    this->horizontal_defensivo = gen1;
    this->horizontal_ofensivo = gen2;
    this->vertical_defensivo = gen3;
    this->vertical_ofensivo = gen4;
    this->diagonal_45_defensivo = gen5;
    this->diagonal_45_ofensivo = gen6;
    this->diagonal_315_defensivo = gen7;
    this->diagonal_315_ofensivo = gen8;
    this->jugada_aleatoria = gen9;
}

int Individuo::getEvaluacion() {
    return this->evaluacion;
}

void Individuo::setEvaluacion(int fitness ) {
    this->evaluacion = fitness;
}

bool Individuo::fueSeleccionado() {
    return this->seleccionado;
}

void Individuo::seleccionar() {
    this->seleccionado = true;
}

Individuo::Individuo(Individuo &anotherIndividuo) {
    this->evaluacion = anotherIndividuo.evaluacion;
    this->seleccionado = anotherIndividuo.seleccionado;
    // genoma/genotipo: (conjunto de genes)
    this->horizontal_defensivo = anotherIndividuo.horizontal_defensivo;
    this->horizontal_ofensivo = anotherIndividuo.horizontal_ofensivo;
    this->vertical_defensivo = anotherIndividuo.vertical_defensivo;
    this->vertical_ofensivo = anotherIndividuo.vertical_ofensivo;
    this->diagonal_45_defensivo = anotherIndividuo.diagonal_45_defensivo;
    this->diagonal_45_ofensivo = anotherIndividuo.diagonal_45_ofensivo;
    this->diagonal_315_defensivo = anotherIndividuo.diagonal_315_defensivo;
    this->diagonal_315_ofensivo = anotherIndividuo.diagonal_315_ofensivo;
    this->jugada_aleatoria = anotherIndividuo.jugada_aleatoria;

}
