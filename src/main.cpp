/**
 * main.cpp
 *
 * This file holds the main entry point for the snake game. 
 *
 * Author: Mark Xavier
 */

#include <iostream>
#include <string>
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
