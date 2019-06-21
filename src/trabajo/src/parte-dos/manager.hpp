#ifndef GAME_STATE_AND_COMMUNICATION_MANAGER_HPP
#define GAME_STATE_AND_COMMUNICATION_MANAGER_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define EXIT_REQUESTED(msg) msg == "salir"
#define MATCH_FINISHED(msg) msg == "ganaste" || msg == "perdiste" || msg == "empataron"
#define NEW_GAME(msg) msg == "rojo" || msg == "azul"

enum Color {RED, BLUE, EMPTY};

static class GameStateAndCommunicationManager {
public:
    typedef struct {
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
    } State;

    State state;
    
    void send_move(int column) {
        cout << column << endl;
    }

    bool move_expected() {
        string msg;
        cin >> msg;

        if (MATCH_FINISHED(msg)) {
            update_state_on_finished_match(msg);
            cin >> msg;
        }

        if (EXIT_REQUESTED(msg)) {
            cout << "listo";
            std::exit(0);
        }

        if (NEW_GAME(msg)) {
            start_new_game(msg);
        } else {
            int opponent_move_column = stoi(msg);
            update_state_on_opponent_move(opponent_move_column);
        }

        return true;
    }

    void exit() {
        cout << "listo";
        std::exit(0);
    }

private:
    Color get_color(const string& color) {
        if (color == "rojo") return RED;
        else return BLUE;
    }

    void update_state_on_finished_match(const string& match_result) {
        if (match_result == "ganaste") ++state.matches_won;
        else if (match_result == "perdiste") ++state.matches_lost;
        else if (match_result == "empataron") ++state.matches_tied;
    }

    void update_state_on_opponent_move(int opponent_move_column) {
        int row = state.pieces_on_column[opponent_move_column]-1;
        state.board[opponent_move_column][row] = state.opponent_color;
    }

    void start_new_game(const string& my_color) {
        state.my_color = get_color(my_color);

        string opponent_color;
        cin >> opponent_color;
        state.opponent_color = get_color(opponent_color);

        cin >> state.columns >> state.rows >> state.pieces_to_win >> state.pieces_per_player;

        // state.board[COLUMN][ROW]
        state.board.resize(state.columns);
        for (int col = 0; col < state.columns; ++col) {
            state.board[col].assign(state.rows, EMPTY);
        }
        state.pieces_on_column.assign(state.columns, 0);

        string who_moves_first;
        cin >> who_moves_first;
        if (who_moves_first != "vos") {
            int opponent_move_column;
            cin >> opponent_move_column;
            update_state_on_opponent_move(opponent_move_column);
        }
    }
} manager;

#endif