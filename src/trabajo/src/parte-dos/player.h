#ifndef PLAYER_H
#define PLAYER_H

#include "manager.hpp"

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
  virtual int move(const GameState& state) {
    return try_all_columns_and_return_best(state);
  }

  virtual ~Player() = default;

private:
  virtual int score_board_state(const GameState& state) {
    // ---------------------------------------------------------------------------------------------
    // Players based on evaluating all possible moves should override this function only
    // ---------------------------------------------------------------------------------------------
    return 0;
  }

  int try_all_columns_and_return_best(GameState state) {
    // The state in this function is a copy to enable temporary modifications

    int best_column = 0;
    int max_score = 0;

    for (int column = 0; column < state.columns; ++column) {
      if (state.column_full(column)) continue;

      state.fill_column(column, state.my_color);
      int score = score_board_state(state);
      if (score > max_score) {
        max_score = score;
        best_column = column;
      }

      state.remove_column_top(column);
    }

    return best_column;
  }

};

#endif