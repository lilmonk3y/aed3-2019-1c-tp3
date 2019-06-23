#ifndef STATE_HELPER_H
#define STATE_HELPER_H

#include "manager.hpp"
#include <cstdint>
#include <vector>

using namespace std;

class StateHelper {
public:
  StateHelper(const GameState& state);

  enum LineDirection {VERTICAL, HORIZONTAL, DIAGONAL};

  double get_euclids_norm_of_lines_length(Color color, LineDirection line_direction) const;
  bool i_win() const;
  bool opponent_can_win() const;
  bool useful_move(uint32_t column) const;

private:
  typedef struct s_line_t {
    uint32_t start;
    uint32_t end;
    uint32_t empty_slots_before;
    uint32_t empty_slots_after;
    uint32_t length;
    void set_new_line(uint32_t st) {
      start = end = st;
      empty_slots_before = empty_slots_after = length = 0;
    }
  } line_t;

  GameState state;

  vector<line_t> my_vertical_lines;
  vector<line_t> my_horizontal_lines;
  vector<line_t> my_diagonal_lines;
  vector<line_t> opponent_vertical_lines;
  vector<line_t> opponent_horizontal_lines;
  vector<line_t> opponent_diagonal_lines;

  void calculate_vertical_lines(Color color);
  void calculate_horizontal_lines(Color color);
  void calculate_diagonal_lines(Color color);

  const vector<line_t>& get_lines_vector(Color color, LineDirection line_direction) const;

  bool opponent_can_win(LineDirection direction) const;
  bool i_win(LineDirection direction) const;
  bool useful_move(uint32_t column, LineDirection direction) const;
};

#endif