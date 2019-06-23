#include "../player.h"
#include "../manager.hpp"
#include "../statehelper.h"
#include <random>
#include <cstdint>
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

  double score_board_state(GameState state, uint32_t move_column, double aggressiveness) override {
    // The state in this function is a copy to enable temporary modifications

    StateHelper helper_before_move(state);

    double opponent_previous_score = score_board_state(helper_before_move, state.opponent_color);
    double my_previous_score = score_board_state(helper_before_move, state.my_color);

    state.fill_column(move_column, state.my_color);
    StateHelper helper_after_move(state);

    double opponent_score = score_board_state(helper_after_move, state.opponent_color);
    double my_score = score_board_state(helper_after_move, state.my_color);

    double offensive_score = my_score - my_previous_score;
    double deffensive_score = opponent_score - opponent_previous_score;

    // If the score function is robust enough this shouldn't be necessary, but since I'm not going
    // to do math analysis on it for now, I am hardcoding this value just to be safe
    bool opponent_can_win = helper_after_move.opponent_can_win();

    bool i_win = helper_after_move.i_win();
    bool useful_move = helper_before_move.useful_move(move_column);

    double mega_coef = 0.0;
    if (i_win) {
      mega_coef = 1.0;
    } else if (opponent_can_win) {
      mega_coef = -1.0;
    } else if (not useful_move) {
      mega_coef = -0.5;
    }

    return (offensive_score * aggressiveness + deffensive_score * (1 - aggressiveness)) / 2
      + mega * mega_coef;
  }

  // New methods:

private:
  double mega = numeric_limits<double>::max() / 2;

  double score_board_state(const StateHelper& helper, Color color) {
    return helper.get_euclids_norm_of_lines_length(color, StateHelper::VERTICAL)
      + helper.get_euclids_norm_of_lines_length(color, StateHelper::HORIZONTAL)
      + helper.get_euclids_norm_of_lines_length(color, StateHelper::DIAGONAL);
  }

};

LineSeekerPlayer* player = new LineSeekerPlayer();

