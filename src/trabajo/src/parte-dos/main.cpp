#include <iostream>
#include <string>
#include <cstdint>
#include "player.h"
#include "manager.hpp"

using namespace std;

extern Player* player; // it has to be a pointer (which I try to avoid) because of object slicing

int main() {
    while (manager.move_expected()) {
        uint32_t move = player->move(state); // column
        manager.send_move(move);
    }

    manager.send_exit_signal();
    delete player;
    return 0;
}
