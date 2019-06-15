//
// Created by Christian nahuel Rivera on 15/6/19.
//

#ifndef AED3_TP3_GAME_H
#define AED3_TP3_GAME_H

#include <iostream>
#include "strategies/PlayStrategy.h"
#include "Player.h"

class Game {
public:
    void runGame(PlayStrategy *strategy);

    void send(const std::string& msg);
    void send(int msg);
    int read_int();
    std::string read_str();

private:
    Player *player;
};


#endif //AED3_TP3_GAME_H
