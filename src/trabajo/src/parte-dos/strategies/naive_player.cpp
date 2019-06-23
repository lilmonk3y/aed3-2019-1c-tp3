#include "../player.h"
#include "../manager.hpp"
#include <random>
#include <cstdint>

using namespace std;

/*
 * Greedy player
 *
 */

random_device rd;
mt19937 generator(rd());

class NaivePlayer : Player {

  // Overriden methods:

  double score_board_state(GameState state, uint32_t move_column, double aggressiveness) override {
    uint32_t v = longest_vertical_line(state);
    uint32_t h = longest_horizontal_line(state);
    uint32_t d = longest_diagonal_line(state);
    return max(max(v, h), d)/3;
  }

  uint32_t move(const GameState& state) override {
    return state.first_move ? state.columns/2 : Player::move(state);
  }

  // New methods:

  uint32_t longest_vertical_line(const GameState& state) {
    uint32_t max_line_length = 0;
    for (uint32_t col = 0; col < state.columns; ++col) {
      uint32_t current_line_length = 0;
      for (uint32_t row = 0; row < state.rows; ++row) {
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

  uint32_t longest_horizontal_line(const GameState& state) {
    uint32_t max_line_length = 0;
    for (uint32_t row = 0; row < state.rows; ++row) {
      uint32_t current_line_length = 0;
      for (uint32_t col = 0; col < state.columns; ++col) {
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

  uint32_t longest_diagonal_line(const GameState& state) {
    // [TODO]
    return 0;
  }

};

NaivePlayer* player = new NaivePlayer();

