#include <cstdlib>
#include "player.h"
#include "manager.hpp"

using namespace std;

int player::get_move(State& game_state) {
  return rand() % game_state.columns;
}