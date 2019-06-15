//
// Created by Christian nahuel Rivera on 15/6/19.
//

#include "Game.h"

void Game::runGame(PlayStrategy *strategy) {
    std::string msg, color, oponent_color, go_first;
    int columns, rows, c_objective, p_fichas, move;
    msg = read_str();
    while (msg != "salir"){
        color = (msg != "") ? msg : read_str();
        msg = "";
        oponent_color = read_str();

        columns = read_int();
        rows = read_int();
        c_objective = read_int();
        p_fichas = read_int();

        this->player = new Player(columns, rows, c_objective, p_fichas, strategy);

        go_first = read_str();
        if (go_first == "vos") {
            move = this->player->play();
            send(move);
        }

        while (true){
            msg = read_str();
            if (msg == "ganaste" || msg == "perdiste" || msg == "empataron") {
                break;
            }

            //actualizar tablero con el movimiento del enemigo
            this->player->updateOponentPlay(stoi(msg));

            move = this->player->play();

            send(move);
        }
    }
}

void Game::send(const std::string& msg) {
    std::cout << msg << std::endl;
}

void Game::send(int msg) {
    std::cout << msg << std::endl;
}

int Game::read_int() {
    std::string msg;
    std::cin >> msg;
    if (msg == "salir") {
        send("listo");
        exit(0);
    }
    return stoi(msg);
}

std::string Game::read_str() {
    std::string msg;
    std::cin >> msg;
    if (msg == "salir") {
        send("listo");
        exit(0);
    }
    return msg;
}