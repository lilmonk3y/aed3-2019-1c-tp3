//
// Created by Christian nahuel Rivera on 15/6/19.
//

#ifndef AED3_TP3_STRATEGY_H
#define AED3_TP3_STRATEGY_H

#include <list>
#include "../../entities/Tablero.h"

class Strategy{
public:

    virtual void selectMoves(Tablero *tablero, int cObjetivo)= 0;

    std::list<int> *getMoves(){
        return moves;
    };

    int getWeigth() {
        return this->peso;
    }

    bool operator<(const Strategy& s){
        return peso < s.peso;
    }

    bool operator>(const Strategy& s){
        return peso > s.peso;
    }

    bool operator==(const Strategy& s){
        return estrategia == s.estrategia;
    }

    bool operator!=(const Strategy& s){
        return estrategia != s.estrategia;
    }

    bool completarFila(int columnaEsperada, int indiceFila, int jugadasDelJugador, int cObjetivo, Tablero *tablero);


private:
    std::list<int> *moves;

protected:
    int estrategia;
    int peso;
};
#endif //AED3_TP3_STRATEGY_H
