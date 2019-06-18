//
// Created by Christian nahuel Rivera on 15/6/19.
//

#include "../Strategy.h"

Strategy::Strategy(float peso, int name) {
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

float Strategy::getWeigth() {
    return this->peso;
}

std::list<int> *Strategy::getMoves() {
    return moves;

}
