#ifndef GAME_STATE_AND_COMMUNICATION_MANAGER_HPP
#define GAME_STATE_AND_COMMUNICATION_MANAGER_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define EXIT_REQUEST_SIGNAL "salir"
#define RED_SIGNAL "rojo"
#define BLUE_SIGNAL "blue"
#define VICTORY_SIGNAL "ganaste"
#define DEFEAT_SIGNAL "perdiste"
#define TIE_SIGNAL "empataron"
#define OPPONENT_MOVES_FIRST_SIGNAL "el"
#define EXIT_ACKNOWLEDGED_SIGNAL "listo"

#define EXIT_REQUESTED(msg) msg == EXIT_REQUEST_SIGNAL
#define MATCH_FINISHED(msg) msg == VICTORY_SIGNAL || msg == DEFEAT_SIGNAL || msg == TIE_SIGNAL
#define NEW_GAME(msg) msg == "rojo" || msg == "azul"

enum Color {RED, BLUE, NONE};

// -------------------------------------------------------------------------------------------------
// ------------------------------------------- GameState -------------------------------------------
// -------------------------------------------------------------------------------------------------

static class GameState {
public:
    vector<vector<Color>> board;
    Color my_color;
    Color opponent_color;
    int columns;
    int rows;
    int pieces_per_player;
    int pieces_to_win;
    int matches_won = 0;
    int matches_lost = 0;
    int matches_tied = 0;
    vector<int> pieces_on_column;
    bool first_move = true;

    bool board_empty() {
        for (int col = 0; col < columns; ++col) {
            if (pieces_on_column[col] > 0) return false;
        }
        return true;
    }

    // True if and only if column is full
    // Pre: column < columns
    bool column_full(int column) const {
        return pieces_on_column[column] == rows;
    }

    // Pre: column < columns and not column_full(column)
    void fill_column(int column, Color color) {
        first_move = false;
        int row = pieces_on_column[column]++;
        board[column][row] = color;
    }

    // Pre: column < columns and pieces_on_column[column] > 0
    void remove_column_top(int column) {
        int row = --pieces_on_column[column];
        board[column][row] = NONE;
    }

    void inform_winner(Color color) {
        if (color == my_color) matches_won += 1;
        else if (color == opponent_color) matches_lost += 1;
        else matches_tied += 1;
    }

    void start_new_game(int columns, int rows, int pieces_to_win, int pieces_per_player,
        Color my_color, Color opponent_color) {
        // Starting a new game does not modify matches_won, matches_lost and matches_tied record

        this->columns = columns;
        this->rows = rows;
        this->pieces_to_win = pieces_to_win;
        this->pieces_per_player = pieces_per_player;
        this->my_color = my_color;
        this->opponent_color = opponent_color;

        // board[COLUMN][ROW]
        board.resize(columns);
        for (int col = 0; col < columns; ++col) {
            board[col].assign(rows, NONE);
        }
        pieces_on_column.assign(columns, 0);
    }
} state;

// -------------------------------------------------------------------------------------------------
// ----------------------------------- GameCommunicationManager ------------------------------------
// -------------------------------------------------------------------------------------------------

static class GameCommunicationManager {
public: 

    void send_move(int column) {
        state.fill_column(column, state.my_color);
        cout << column << endl;
    }

    void send_exit_signal() {
        cout << EXIT_ACKNOWLEDGED_SIGNAL;
    }

    bool move_expected() {
        string msg;
        cin >> msg;

        if (MATCH_FINISHED(msg)) {
            update_state_on_finished_match(msg);
            cin >> msg;
        }

        if (EXIT_REQUESTED(msg)) return false;

        if (NEW_GAME(msg)) {
            start_new_game(msg);
        } else {
            int opponent_move_column = stoi(msg);
            state.fill_column(opponent_move_column, state.opponent_color);
        }

        return true;
    }

private:

    Color get_color(const string& color_signal) {
        return color_signal == RED_SIGNAL ? RED : BLUE;
    }

    void update_state_on_finished_match(const string& match_result) {
        if (match_result == VICTORY_SIGNAL) state.inform_winner(state.my_color);
        else if (match_result == DEFEAT_SIGNAL) state.inform_winner(state.opponent_color);
        else if (match_result == TIE_SIGNAL) state.inform_winner(NONE);
    }

    void start_new_game(const string& my_color_signal) {
        Color my_color = get_color(my_color_signal);

        string opponent_color_signal;
        cin >> opponent_color_signal;
        Color opponent_color = get_color(opponent_color_signal);


        int columns, rows, pieces_to_win, pieces_per_player;

        cin >> columns >> rows >> pieces_to_win >> pieces_per_player;

        state.start_new_game(columns, rows, pieces_to_win, pieces_per_player,
            my_color, opponent_color);

        string who_moves_first;
        cin >> who_moves_first;
        if (who_moves_first == OPPONENT_MOVES_FIRST_SIGNAL) {
            int opponent_move_column;
            cin >> opponent_move_column;
            state.fill_column(opponent_move_column, state.opponent_color);
        }
    }
} manager;

#endif