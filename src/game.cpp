#include <iostream>
#include "game.h"
#include "player_cube.h"

Snake::Game::Game(int screenSize_, int rows) : status(0), window(nullptr), renderer(nullptr),
    screenSize(screenSize_), numberOfRows(rows), gameRunning(true)
{
    initializeSDL();
    createWindow();
    createRenderer();
    gameObjectSize = screenSize / numberOfRows;
    player = new Player(screenSize, rows, gameObjectSize);
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

void Snake::Game::update()
{
    player->update();
}

void Snake::Game::draw()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    player->draw(renderer);
    SDL_RenderPresent(renderer);
}

void Snake::Game::gameLoop()
{
    int ticks_per_frame = 1000/fps;
    while(gameRunning)
    {
        int startTime = SDL_GetTicks();
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                quit();
            else if(event.type == SDL_KEYDOWN)
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_RIGHT:
                        player->updateVelocity(1, 0);
                        break;
                    case SDLK_LEFT:
                        player->updateVelocity(-1, 0);
                        break;
                    case SDLK_UP:
                        player->updateVelocity(0, -1);
                        break;
                    case SDLK_DOWN:
                        player->updateVelocity(0, 1);
                        break;
                    case SDLK_ESCAPE:
                        quit();
                    default:
                        break;
                }
            }
        }
        update();
        draw();
        int endTime = SDL_GetTicks();
        int diff = endTime - startTime;
        if(diff < ticks_per_frame)
            SDL_Delay(ticks_per_frame - diff);
    }
}

void Snake::Game::quit()
{
    gameRunning = false;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    delete player;
    SDL_Quit();
}
