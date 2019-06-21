#include "../player.h"
#include "../manager.hpp"
#include <random>

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
  int move(const GameState& state) override {
    uniform_int_distribution<int> random_numbers_distribution(0, state.columns-1);
    int column;
    do {
      column = random_numbers_distribution(generator);
    } while (state.column_full(column));
    return column;
  }
private:

};

RandomPlayer* player = new RandomPlayer();