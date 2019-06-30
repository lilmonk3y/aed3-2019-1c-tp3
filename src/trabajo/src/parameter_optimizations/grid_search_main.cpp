#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "../players/ParamsStrategy.h"
#include "../InplaceGame.h"

using namespace std;

#define PARAM_MAX 20
#define TEMPERATURA_MAX PARAM_MAX/2
#define TEMPERATURA_MIN 1

vector<vector<int>> subconjuntos;

void calcularSubconjuntos(vector<vector<int>>& subconjuntos, int n) {
  // Calcula todos los subconjuntos de {i natural : i <= n} excepto el subconjunto vacío

  subconjuntos.resize(pow(2, n) - 1);
  int numero_de_subconjunto = 0;

  for (int r = 1; r <= n; ++r) {
    vector<bool> v(n);
    fill(v.begin(), v.begin() + r, true);
    do {
      subconjuntos[numero_de_subconjunto].reserve(r);
      for (int i = 0; i < n; ++i) {
        if (v[i]) {
          subconjuntos[numero_de_subconjunto].push_back(i);
        }
      }
      numero_de_subconjunto++;
    } while (prev_permutation(v.begin(), v.end()));
  }
}

void calcularVecindario(const vector<int>& params, vector<vector<int>>& vecinos, int temperatura) {
  // Hace un offset sumando la temperatura y otro offset restando para cada parámetro.
  // Luego calcula el vecindario aplicando todas las combinaciones de offset posibles (manteniendo
  // separados el offset positivo y el negativo).
  // Es un vecindario "grande" pero nada comparado con el espacio de búsqueda.

  vector<int> paramsOffsetPositivo(params.size());
  vector<int> paramsOffsetNegativo(params.size());

  for (size_t i = 0; i < params.size(); ++i) {
    paramsOffsetPositivo[i] = (vecinos.back()[i] + temperatura) % TEMPERATURA_MAX;

    int param = vecinos.back()[i] - temperatura;
    if (param < 0) param = TEMPERATURA_MAX + param + 1;
    paramsOffsetNegativo[i] = param;
  }

  for (size_t i = 0; i < subconjuntos.size(); ++i) {
    vecinos[i] = vecinos[i + subconjuntos.size()] = params;
    for (size_t j = 0; j < subconjuntos[i].size(); ++j) {
        int indice_param = subconjuntos[i][j];
        vecinos[i][indice_param] = paramsOffsetPositivo[indice_param];
        vecinos[i + subconjuntos.size()][indice_param] = paramsOffsetNegativo[indice_param];

    }
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

  vector<int> params(5, PARAM_MAX/2);

  calcularSubconjuntos(subconjuntos, params.size());

  vector<vector<int>> vecinos(subconjuntos.size()*2);

  while (temperatura >= TEMPERATURA_MIN) {
    calcularVecindario(params, vecinos, temperatura);
    const vector<int>& mejorVecino = calcularMejorVecino(params, vecinos);
    if (aceptarVecino(params, mejorVecino, temperatura)) {
      params = mejorVecino;
    }
    temperatura--;
  }
  return 0;
}