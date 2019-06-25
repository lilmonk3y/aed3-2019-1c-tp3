#ifndef AED3_TP3_INDIVIDUO_H
#define AED3_TP3_INDIVIDUO_H

#include <string>
using namespace std;

class Individuo {

public:
    Individuo(int evaluacion, int filaEscogida, int estrategia);
    int getFilaEscogida();
    void setFilaEscogida(int filaEscogida );
    int getEvaluacion();
    void setEvaluacion(int evaluacion );
    int getEstrategia();
    void setEstrategia(int evaluacion );
    bool fueSeleccionado();
    void seleccionar();

private:
    int evaluacion; // dado por la funcion fitness
    int filaEscogida;
    int estrategia; // defensa, ataque
    bool seleccionado;
    // guardar filas,columnas,diagonales aliadas y enemigas?
    // jugada 1,2,3 (posibilidades)
};


#endif //AED3_TP3_INDIVIDUO_H
