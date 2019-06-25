#include "Individuo.h"


Individuo::Individuo(int evaluacion, int filaEscogida, int estrategia) {
    this->evaluacion = evaluacion;
    this->filaEscogida = filaEscogida;
    this->estrategia = estrategia;
    this->seleccionado = false;
}

int Individuo::getFilaEscogida() {
    return this->filaEscogida;
}

void Individuo::setFilaEscogida(int filaEscogida ) {
    this->filaEscogida = filaEscogida;
}

int Individuo::getEvaluacion() {
    return this->evaluacion;
}

void Individuo::setEvaluacion(int evaluacion ) {
    this->evaluacion = evaluacion;
}

int Individuo::getEstrategia() {
    return this->estrategia;
}

void Individuo::setEstrategia(int estrategia ) {
    this->estrategia = estrategia;
}

bool Individuo::fueSeleccionado() {
    return this->seleccionado;
}

void Individuo::seleccionar() {
    this->seleccionado = true;
}