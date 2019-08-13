#include <iostream>
#include <string>
#include <SDL2/SDL.h>

#include "game.h"

const int SCREEN_SIZE = 500;
const int NUM_ROWS = 20;

int main(int c, char* argv[])
{
    bool playGame = true;
    while(playGame)
    {
        Snake::Game game = Snake::Game(SCREEN_SIZE, NUM_ROWS);
        game.gameLoop();
        std::string keepPlaying = "";
        std::cout << "You've exited the game, play again? (y/n) ";
        std::cin >> keepPlaying;
        if(keepPlaying.compare("y") != 0)
            playGame = false;
    }

    return 0;
}
