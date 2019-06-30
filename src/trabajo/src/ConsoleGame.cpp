//
// Created by Christian nahuel Rivera on 15/6/19.
//

#include "ConsoleGame.h"

void ConsoleGame::runGame(iPlayer *myPlayer) {
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

        this->player = myPlayer;
        this->tablero = new Tablero(columns,rows);

        go_first = read_str();
        if (go_first == "vos") {
            move = this->player->play(tablero, FICHA_ALIADA, c_objective);
            send(move);
        }

        while (true){
            msg = read_str();
            if (msg == "ganaste" || msg == "perdiste" || msg == "empataron") {
                break;
            }

            //actualizar tablero con el movimiento del enemigo
            this->tablero->actualizar(stoi(msg), FICHA_ENEMIGA);

            move = this->player->play(tablero,FICHA_ALIADA, c_objective);

            send(move);
        }
    }
}

void ConsoleGame::send(const std::string& msg) {
    std::cout << msg << std::endl;
}

void ConsoleGame::send(int msg) {
    std::cout << msg << std::endl;
}

int ConsoleGame::read_int() {
    std::string msg;
    std::cin >> msg;
    if (msg == "salir") {
        send("listo");
        exit(0);
    }
    return stoi(msg);
}

std::string ConsoleGame::read_str() {
    std::string msg;
    std::cin >> msg;
    if (msg == "salir") {
        send("listo");
        exit(0);
    }
    return msg;
}