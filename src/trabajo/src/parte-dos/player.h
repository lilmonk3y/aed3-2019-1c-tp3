#ifndef PLAYER_H
#define PLAYER_H

#include "manager.hpp"

using namespace std;

namespace player {

    typedef GameStateAndCommunicationManager::State State;
    int get_move(State& game_state);

}

#endif