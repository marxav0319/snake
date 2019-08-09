#include <iostream>
#include "game.h"

Snake::Game::Game(int screenSize_) : status(0), window(nullptr), renderer(nullptr),
    screenSize(screenSize_)
{
    initializeSDL();
    createWindow();
    createRenderer();
}

Snake::Game::~Game()
{
    return;
}

void Snake::Game::initializeSDL()
{
    if(SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
        status = -1;
    }
}

void Snake::Game::createWindow()
{
    window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenSize,
                              screenSize, SDL_WINDOW_SHOWN);
    if(window == nullptr)
    {
        std::cout << "Error creating SDL window: " << SDL_GetError() << std::endl;
        status = -1;
    }
}

void Snake::Game::createRenderer()
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr)
    {
        std::cout << "Error creating SDL renderer: " << SDL_GetError() << std::endl;
        status = -1;
    }
    else
        SDL_RenderSetLogicalSize(renderer, screenSize, screenSize);
}

void Snake::Game::draw()
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(4000);
}

void Snake::Game::gameLoop()
{
    return;
}
