#include <iostream>
#include <string>
#include "player.h"
#include "manager.hpp"

using namespace std;

int main() {
    while (manager.move_expected()) {
        int move = player::get_move(manager.state);
        manager.send_move(move);
    }

    manager.exit();
}
