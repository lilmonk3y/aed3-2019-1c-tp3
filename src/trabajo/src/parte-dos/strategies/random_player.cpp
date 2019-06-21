#include "../player.h"
#include "../manager.hpp"
#include <random>
#include <cstdint>

using namespace std;

/*
 * Random player
 *
 * Places a piece on a random non-full column
 */

random_device rd;
mt19937 generator(rd());

class RandomPlayer : Player {
public:
  uint32_t move(const GameState& state) override {
    uniform_int_distribution<uint32_t> random_numbers_distribution(0, state.columns-1);
    uint32_t column;
    do {
      column = random_numbers_distribution(generator);
    } while (state.column_full(column));
    return column;
  }
private:

};

RandomPlayer* player = new RandomPlayer();