#include <iostream>
#include <vector>
#include "../players/ParamsStrategy.h"
#include "../InplaceGame.h"

using namespace std;

#define PARAM_MAX 20
#define TEMPERATURA_MAX PARAM_MAX/2
#define TEMPERATURA_MIN 0

void calcularVecindario(const vector<int>& params, vector<vector<int>>& vecinos, int temperatura) {
    vecinos.clear();
    for (size_t i = 0; i < params.size(); ++i) {
        vecinos.push_back(params);
        vecinos.back()[i] = (vecinos.back()[i] + temperatura) % TEMPERATURA_MAX;

        vecinos.push_back(params);
        int param = vecinos.back()[i] - temperatura;
        if (param < 0) param = TEMPERATURA_MAX + param + 1;
        vecinos.back()[i] = param;
    }
}

const vector<int>& calcularMejorVecino(const vector<int>& params, const vector<vector<int>>& vecinos) {
    return vecinos[0]; // Completar llamando al juez y haciéndolos jugar una cantidad de veces
}

bool aceptarVecino(const vector<int>& params, const vector<int>& vecino, int temperatura) {
    return true; // Completar
}

int main() {
  int temperatura = TEMPERATURA_MAX;

  vector<int> params; // Leer de stdin o ver qué hacer

  while (temperatura >= TEMPERATURA_MIN) {
    vector<vector<int>> vecinos;
    calcularVecindario(params, vecinos, temperatura);
    const vector<int>& mejorVecino = calcularMejorVecino(params, vecinos);
    if (aceptarVecino(params, mejorVecino, temperatura)) {
        params = mejorVecino;
    }
    temperatura--;
  }
  

  return 0;
}