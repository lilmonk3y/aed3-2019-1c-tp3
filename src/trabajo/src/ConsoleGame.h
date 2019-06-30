//
// Created by Christian nahuel Rivera on 15/6/19.
//

#ifndef AED3_TP3_GAME_H
#define AED3_TP3_GAME_H

#include <iostream>
#include "players/iPlayer.h"

class ConsoleGame {
public:
    void runGame(iPlayer& myPlayer);

    void send(const std::string& msg);
    void send(int msg);
    int read_int();
    std::string read_str();
};


#endif //AED3_TP3_GAME_H
