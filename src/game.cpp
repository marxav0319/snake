#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"
#include "player_cube.h"

Snake::Game::Game(int screenSize_, int rows) : status(0), window(nullptr), renderer(nullptr),
    screenSize(screenSize_), numberOfRows(rows), gameRunning(true), playerLost(false)
{
    initializeSDL();
    createWindow();
    createRenderer();
    gameObjectSize = screenSize / numberOfRows;
    player = new Player(screenSize, rows, gameObjectSize);
    std::srand(std::time(NULL));
    generateFood();
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

void Snake::Game::generateFood()
{
    bool searchingForValidCoordinates = true;
    while(searchingForValidCoordinates)
    {
        int xCoordinate = (std::rand() % numberOfRows) * gameObjectSize;
        int yCoordinate = (std::rand() % numberOfRows) * gameObjectSize;
        bool coordinatesInvalid = false;
        const std::deque<PlayerCube*>* playerBody = player->getBody();

        // Check the snake body to see if the random (x, y) is a body segment location, if it is
        // we need to recompute a new food location
        for(std::deque<PlayerCube*>::const_iterator it = playerBody->begin(); it != playerBody->end(); ++it)
        {
            if((*it)->getX() == xCoordinate && (*it)->getY() == yCoordinate)
                coordinatesInvalid = true;
        }

        // If it is a valid coordinate, create the object
        if(!coordinatesInvalid)
        {
            searchingForValidCoordinates = false;
            food = new Food(xCoordinate, yCoordinate, gameObjectSize);
        }
    }
}

bool Snake::Game::detectFoodCollision()
{
    if(player->getX() == food->getX())
    {
        if(player->getY() == food->getY())
        {
            delete food;
            player->addBodySegment();
            generateFood();
        }
    }
}

void Snake::Game::update()
{
    player->update();
    detectFoodCollision();
    if(player->bodyCollisionDetected())
    {
        SDL_Delay(1000);
        reset();
    }
}

void Snake::Game::draw()
{
    SDL_SetRenderDrawColor(renderer, 43, 9, 32, 255);
    SDL_RenderClear(renderer);
    food->draw(renderer);
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
                gameRunning = false;
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
                        gameRunning = false;
                        break;
                    case 'r':
                        reset();
                        break;
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
    quit();
}

void Snake::Game::cleanGameObjects()
{
    if(player != nullptr)
    {
        delete player;
        player = nullptr;
    }

    if(food != nullptr)
    {
        delete food;
        food = nullptr;
    }
}

void Snake::Game::reset()
{
    cleanGameObjects();
    player = new Player(screenSize, numberOfRows, gameObjectSize);
    generateFood();
}

void Snake::Game::quit()
{
    gameRunning = false;
    cleanGameObjects();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
