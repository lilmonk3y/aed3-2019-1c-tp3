#ifndef PLAYER_H
#define PLAYER_H

#include "manager.hpp"
#include <cstdint>

using namespace std;

/*
 * Base player class
 *
 * Designed to test all possible moves and decide the best based on score given by function
 * score_board_state that should be overriden according to different strategies.
 *
 * It is also possible to override the move function and do a completely different strategy.
 */

class Player {
public:
  virtual uint32_t move(const GameState& state) {
    return try_all_columns_and_return_best(state);
  }

  virtual ~Player() = default;

private:
  virtual double score_board_state(GameState state, uint32_t move_column, double aggressiveness) {
    // ---------------------------------------------------------------------------------------------
    // Players based on greedily evaluating all possible moves should override this function
    // ---------------------------------------------------------------------------------------------
    return 0;
  }

  uint32_t try_all_columns_and_return_best(const GameState& state) {
    uint32_t best_column = 0;
    double max_score = 0;

    for (uint32_t column = 0; column < state.columns; ++column) {
      if (state.column_full(column)) continue;

      double score = score_board_state(state, column, 0.7);
      if (score > max_score) {
        max_score = score;
        best_column = column;
      }

    }

    return best_column;
  }
};

#endif