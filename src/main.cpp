#include <iostream>
#include <SDL2/SDL.h>

#include "game.h"

const int SCREEN_SIZE = 500;
const int NUM_ROWS = 20;

int main(int c, char* argv[])
{
    Snake::Game game = Snake::Game(SCREEN_SIZE, NUM_ROWS);
    game.gameLoop();

    return 0;
}
