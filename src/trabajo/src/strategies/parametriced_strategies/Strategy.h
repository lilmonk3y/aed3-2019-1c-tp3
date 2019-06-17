//
// Created by Christian nahuel Rivera on 15/6/19.
//

#ifndef AED3_TP3_STRATEGY_H
#define AED3_TP3_STRATEGY_H

#include <list>
#include "../../entities/Tablero.h"

class Strategy{
public:
    explicit Strategy(float peso, int name);
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

    bool operator==(const Strategy& s) const {
        return name == s.name;
    }

    bool operator!=(const Strategy& s) const{
        return name != s.name;
    }

    bool completarFila(int columnaEsperada, int indiceFila, int jugadasDelJugador, int cObjetivo, Tablero *tablero);


protected:
    int name;
    float peso;
    std::list<int> *moves;
};
#endif //AED3_TP3_STRATEGY_H
