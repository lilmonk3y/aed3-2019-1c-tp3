//
// Created by Christian nahuel Rivera on 15/6/19.
//

#include "../Strategy.h"
#include "../../../entities/Defines.h"

Strategy::Strategy(int peso, int name) {
    this->name = name;
    this->peso = peso;
    moves = new std::list<int>();
}

bool Strategy::operator!=(const Strategy &s) const {
    return name != s.name;
}

bool Strategy::operator==(const Strategy &s) const {
    return name == s.name;
}

bool Strategy::operator>(const Strategy &s) {
    return peso > s.peso;
}

bool Strategy::operator<(const Strategy &s) {
    return peso < s.peso;
}

int Strategy::getWeigth() {
    return this->peso;
}

std::list<int> *Strategy::getMoves() {
    return moves;

}

int Strategy::fichaContraria(int miFicha) const { return miFicha == FICHA_ALIADA ? FICHA_ENEMIGA : FICHA_ALIADA; }

void Strategy::setWeigth(int weigth) {
    this->peso = weigth;
}
