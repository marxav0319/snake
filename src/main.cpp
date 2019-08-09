#include <iostream>
#include <SDL2/SDL.h>

#include "game.h"

const int SCREEN_SIZE = 500;

int main(int c, char* argv[])
{
    Snake::Game game = Snake::Game(SCREEN_SIZE);
    game.draw();

    return 0;
}
