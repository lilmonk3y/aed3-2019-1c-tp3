//
// Created by Christian nahuel Rivera on 15/6/19.
//

#ifndef AED3_TP3_STRATEGY_H
#define AED3_TP3_STRATEGY_H

#include <list>
#include "../../entities/Tablero.h"

class Strategy{
public:
    virtual void selectMoves(Tablero *tablero, int cObjetivo, int miFicha) = 0;

    std::list<int> *getMoves();
    int getWeigth() ;
    virtual STRATEGY_NAME getName() = 0;
    void setWeigth(int weigth);

    bool operator<(const Strategy& s);
    bool operator>(const Strategy& s);
    bool operator==(const Strategy& s) const ;
    bool operator!=(const Strategy& s) const;



protected:
    int name;
    int peso;
    std::list<int> *moves;

    explicit Strategy(int peso, int name);
    int fichaContraria(int miFicha) const;
};
#endif //AED3_TP3_STRATEGY_H
