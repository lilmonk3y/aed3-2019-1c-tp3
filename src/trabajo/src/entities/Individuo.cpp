#include "Individuo.h"

Individuo::Individuo() {
    this->evaluacion = 0;
    this->seleccionado = false;
    // genoma/genotipo: (conjunto de genes)
    this->horizontal_defensivo = 0;
    this->horizontal_ofensivo = 0;
    this->vertical_defensivo = 0;
    this->vertical_ofensivo = 0;
    this->diagonal_45_defensivo = 0;
    this->diagonal_45_ofensivo = 0;
    this->diagonal_315_defensivo = 0;
    this->diagonal_315_ofensivo = 0;
    this->jugada_aleatoria = 0;
}

Individuo::Individuo(PESO gen1,PESO gen2,PESO gen3,PESO gen4,PESO gen5,PESO gen6,PESO gen7,PESO gen8,PESO gen9) {
    this->evaluacion = 0;
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
