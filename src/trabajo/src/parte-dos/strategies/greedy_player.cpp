#include "../player.h"
#include "../manager.hpp"
#include <random>

using namespace std;

/*
 * Greedy player
 *
 */

random_device rd;
mt19937 generator(rd());

class GreedyPlayer : Player {

  // Overriden methods:

  int score_board_state(const GameState& state) override {
    int v = longest_vertical_line(state);
    int h = longest_horizontal_line(state);
    int d = longest_diagonal_line(state);
    return max(max(v, h), d);
  }

  int move(const GameState& state) override {
    if (state.first_move) {
      uniform_int_distribution<int> distribution(0, state.columns-1);
      return distribution(generator);
    }
    return Player::move(state);
  }

  // New methods:

  int longest_vertical_line(const GameState& state) {
    int max_line_length = 0;
    for (int col = 0; col < state.columns; ++col) {
      int current_line_length = 0;
      for (int row = 0; row < state.rows; ++row) {
        if (state.board[col][row] == NONE) break;
        if (state.board[col][row] == state.opponent_color) {
          current_line_length = 0;
          continue;
        }
        current_line_length++;
        if (current_line_length > max_line_length) max_line_length = current_line_length;
      }
    }
    return max_line_length;
  }

  int longest_horizontal_line(const GameState& state) {
    int max_line_length = 0;
    for (int row = 0; row < state.rows; ++row) {
      int current_line_length = 0;
      for (int col = 0; col < state.columns; ++col) {
        if (state.board[col][row] != state.my_color) {
          current_line_length = 0;
          continue;
        }
        current_line_length++;
        if (current_line_length > max_line_length) max_line_length = current_line_length;
      }
    }
    return max_line_length;
  }

  int longest_diagonal_line(const GameState& state) {
    // [TODO]
    return 0;
  }

};

GreedyPlayer* player = new GreedyPlayer();

