#include "../player.h"
#include "../manager.hpp"
#include <random>
#include <cstdint>
#include <math.h>
#include <limits>

using namespace std;

/*
 * Greedy player
 *
 */

random_device rd;
mt19937 generator(rd());

class LineSeekerPlayer : Player {

  // Overriden methods:

  uint32_t move(const GameState& state) override {
    return state.first_move ? state.columns/2 : Player::move(state);
  }

  double score_board_state(const GameState& state) override {
    uint32_t max_line_length = 0;
    
    double own_score = score_lines(state, state.my_color, max_line_length);
    if (max_line_length == state.pieces_to_win) return infinity;

    double opponent_score = score_lines(state, state.opponent_color, max_line_length);
    if (max_line_length == state.pieces_to_win-1) return infinity-1;

    return (own_score * 0.7 + opponent_score * 0.3) / 2;
  }

  // New methods:

  double infinity = numeric_limits<double>::max();

  double score_lines(const GameState& state, Color color, uint32_t& max_line_length) {
    double vertical_line_score, horizontal_line_score, diagonal_line_score;

    score_vertical_lines(state, vertical_line_score, color, max_line_length);
    score_horizontal_lines(state, horizontal_line_score, color, max_line_length);
    score_diagonal_lines(state, diagonal_line_score, color, max_line_length);

    return vertical_line_score + horizontal_line_score + diagonal_line_score;
  }

  void score_vertical_lines(const GameState& state, double& vertical_line_score, Color color,
      uint32_t& max_line_length) {
    uint32_t euclids_norm_squared = 0;
    for (uint32_t col = 0; col < state.columns; ++col) {
      uint32_t current_line_length = 0;

      for (uint32_t row = 0; row < state.rows; ++row) {
        if (state.board[col][row] == color) {
          current_line_length++;
          if (current_line_length > max_line_length) max_line_length = current_line_length;
        } else {
          if (current_line_length > 0) {
            euclids_norm_squared += current_line_length * current_line_length;
          }
          if (state.board[col][row] == NONE) break;
          current_line_length = 0;
        }
      }
    }
    vertical_line_score = sqrt(euclids_norm_squared);
  }

  void score_horizontal_lines(const GameState& state, double& horizontal_line_score, Color color,
      uint32_t& max_line_length) {
    uint32_t euclids_norm_squared = 0;
    bool empty_row = false;
    for (uint32_t row = 0; row < state.rows and not empty_row; ++row) {
      empty_row = true;
      uint32_t current_line_length = 0;
      for (uint32_t col = 0; col < state.columns; ++col) {
        if (state.board[col][row] == color) {
          current_line_length++;
          if (current_line_length > max_line_length) max_line_length = current_line_length;
        } else if (current_line_length > 0) {
          euclids_norm_squared += current_line_length * current_line_length;
        }

        if (state.board[col][row] != NONE) empty_row = false;
      }
    }
    horizontal_line_score = sqrt(euclids_norm_squared);
  }

  void score_diagonal_lines(const GameState& state, double& diagonal_line_score, Color color,
      uint32_t& max_line_length) {
    // [TODO]
    diagonal_line_score = 0.0;
  }

};

LineSeekerPlayer* player = new LineSeekerPlayer();

