#include <iostream>
#include <string>
#include "player.h"
#include "manager.hpp"

using namespace std;

extern Player* player;

int main() {
    while (manager.move_expected()) {
        int move = player->move(state); // column
        manager.send_move(move);
    }

    manager.send_exit_signal();
    delete player;
    return 0;
}
