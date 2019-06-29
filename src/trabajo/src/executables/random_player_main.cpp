//
// Created by Christian nahuel Rivera on 15/6/19.
//

#include "../ConsoleGame.h"
#include "../players/RandomPlayer.h"

int main(){
    ConsoleGame *game = new ConsoleGame();
    game->runGame(new RandomPlayer());

    return 0;
}