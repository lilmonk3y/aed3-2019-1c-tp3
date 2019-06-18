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

    std::list<int> *getMoves();
    float getWeigth() ;

    bool operator<(const Strategy& s);
    bool operator>(const Strategy& s);
    bool operator==(const Strategy& s) const ;
    bool operator!=(const Strategy& s) const;



protected:
    int name;
    float peso;
    std::list<int> *moves;

    explicit Strategy(float peso, int name);
};
#endif //AED3_TP3_STRATEGY_H
