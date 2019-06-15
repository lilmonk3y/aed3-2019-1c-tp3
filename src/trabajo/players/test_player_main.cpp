//
// Created by Christian nahuel Rivera on 15/6/19.
//

#include "../strategies/TestStrategy.h"
#include "../Game.h"

int main(){
    Game *game = new Game();
    game->runGame(new TestStrategy());

    return 0;
}