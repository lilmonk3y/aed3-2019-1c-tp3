#include "statehelper.h"
#include <math.h>

using namespace std;

StateHelper::StateHelper(const GameState& state) : state(state) {
  calculate_vertical_lines(BLUE);
  calculate_vertical_lines(RED);
  calculate_horizontal_lines(BLUE);
  calculate_horizontal_lines(RED);
  calculate_diagonal_lines(BLUE);
  calculate_diagonal_lines(RED);
};

void StateHelper::calculate_vertical_lines(Color color) {
  vector<line_t>* lines;
  if (color == state.my_color) lines = &my_vertical_lines;
  else lines = &opponent_vertical_lines;

  for (uint32_t col = 0; col < state.columns; ++col) {
    if (state.pieces_on_column[col] == 0) continue;
    bool calculating_line = false;
    line_t line;
    for (uint32_t row = 0; row < state.rows; ++row) {
      switch (state.board[col][row]) {
        case NONE:
          if (calculating_line) {
            calculating_line = false;
            line.empty_slots_after = state.rows - row;
            line.end = row-1;
            lines->push_back(line);
          }
          continue;
        case BLUE:
          switch (color) {
            case BLUE:
              if (not calculating_line) {
                calculating_line = true;
                line.set_new_line(row);
              }
              break;
            case RED:
              if (calculating_line) {
                line.end = row-1;
                line.length = line.end - line.start + 1;
                lines->push_back(line);
                calculating_line = false;
              }
              break;
          }
          break;
        case RED:
          switch (color) {
            case RED:
              if (not calculating_line) {
                calculating_line = true;
                line.set_new_line(row);
              }
              break;
            case BLUE:
              if (calculating_line) {
                line.end = row-1;
                line.length = line.end - line.start + 1;
                lines->push_back(line);
                calculating_line = false;
              }
              break;
          }
          break;
      }
    }
    if (calculating_line) {
      line.end = state.rows-1;
      line.length = line.end - line.start + 1;
      lines->push_back(line);
    }
  }
}

void StateHelper::calculate_horizontal_lines(Color color) {
  vector<line_t>* lines;
  if (color == state.my_color) lines = &my_vertical_lines;
  else lines = &opponent_vertical_lines;

  bool empty_row = false;
  for (uint32_t row = 0; row < state.rows and not empty_row; ++row) {
    empty_row = true;
    bool calculating_line = false;
    line_t line;
    uint32_t none_count = 0;
    for (uint32_t col = 0; col < state.columns; ++col) {
      switch (state.board[col][row]) {
        case NONE:
          none_count++;
          if (calculating_line) {
            calculating_line = false;
            line.empty_slots_after = 1;
            while (col+1 < state.columns and state.board[col][row] == NONE) {
              col++;
              line.empty_slots_after++;
            }
            line.end = col-1;
            line.length = line.end - line.start + 1;
            lines->push_back(line);
          }
          break;
        case BLUE:
          empty_row = false;
          switch (color) {
            case BLUE:
              if (not calculating_line) {
                calculating_line = true;
                line.set_new_line(col);
                line.empty_slots_before = none_count;
              }
              break;
            case RED:
              if (calculating_line) {
                line.end = col-1;
                line.length = line.end - line.start + 1;
                lines->push_back(line);
                calculating_line = false;
              }
              break;
          }
          none_count = 0;
          break;
        case RED:
          empty_row = false;
          switch (color) {
            case RED:
              if (not calculating_line) {
                calculating_line = true;
                line.set_new_line(col);
                line.empty_slots_before = none_count;
              }
              break;
            case BLUE:
              if (calculating_line) {
                line.end = col-1;
                line.length = line.end - line.start + 1;
                lines->push_back(line);
                calculating_line = false;
              }
              break;
          }
          none_count = 0;
          break;
      }
    }
    if (calculating_line) {
      line.end = state.columns-1;
      line.length = line.end - line.start + 1;
      lines->push_back(line);
    }
  }
}

void StateHelper::calculate_diagonal_lines(Color color) {
  // TODO
}

const vector<StateHelper::line_t>& StateHelper::get_lines_vector(Color color,
    LineDirection line_direction) const {
  const vector<line_t>* lines;
  switch (line_direction) {
    case VERTICAL:
      if (color == state.my_color) lines = &my_vertical_lines;
      else lines = &opponent_vertical_lines;
      break;
    case HORIZONTAL:
      if (color == state.my_color) lines = &my_horizontal_lines;
      else lines = &opponent_horizontal_lines;
      break;
    case DIAGONAL:
      if (color == state.my_color) lines = &my_diagonal_lines;
      else lines = &opponent_diagonal_lines;
      break;
  }
  return *lines;
}

double StateHelper::get_euclids_norm_of_lines_length(Color color, LineDirection direction) const {
  const vector<line_t>& lines = get_lines_vector(color, direction);
  uint32_t euclids_norm_squared = 0.0;
  for (const line_t& line : lines) {
    euclids_norm_squared += line.length * line.length;
  }
  return sqrt(euclids_norm_squared);
}

bool StateHelper::opponent_can_win(LineDirection direction) const {
  const vector<line_t>& lines = get_lines_vector(state.opponent_color, direction);
  for (const line_t& line : lines) {
    if (line.length == state.pieces_to_win - 1 and
        (line.empty_slots_before > 0 or line.empty_slots_after > 0)) {
      return true;
    }
  }
  return false;
}

bool StateHelper::opponent_can_win() const {
  return opponent_can_win(VERTICAL) or opponent_can_win(HORIZONTAL) or opponent_can_win(DIAGONAL);
}

bool StateHelper::i_win(LineDirection direction) const {
  const vector<line_t>& lines = get_lines_vector(state.my_color, direction);
  for (const line_t& line : lines) {
    if (line.length == state.pieces_to_win) return true;
  }
  return false;
}

bool StateHelper::i_win() const {
  return i_win(VERTICAL) or i_win(HORIZONTAL) or i_win(DIAGONAL);
}

bool StateHelper::useful_move(uint32_t column) const {
  return useful_move(column, VERTICAL) or useful_move(column, HORIZONTAL)
         or useful_move(column, DIAGONAL);
}

bool StateHelper::useful_move(uint32_t column, LineDirection direction) const {
  const vector<line_t>& lines = get_lines_vector(state.my_color, direction);
  if (direction == VERTICAL) {
    for (const line_t& line : lines) {
      if (line.start == column and line.empty_slots_after >= state.pieces_to_win-line.length) {
        return true;
      }
    }
  } else {
    // HORIZONTAL, DIAGONAL
    for (const line_t& line : lines) {
      if (line.start <= column and column <= line.end and
          line.empty_slots_before+line.empty_slots_after >= state.pieces_to_win-line.length) {
        return true;
      }
    }
  }
  return false;
}