#include "player.h"

Snake::Player::Player(int screenSize_, int rows_, int size_) : size(size_), xVelocity(1),
    yVelocity(0), screenSize(screenSize_), rows(rows_)
{
    head = new PlayerCube(0, 0, screenSize, rows, size, size, 0, 255, 0, xVelocity, yVelocity);
    body.push_back(head);
}

Snake::Player::~Player()
{
    PlayerCube* toDelete;
    while(!body.empty())
    {
        toDelete = body.front();
        body.pop_front();
        delete toDelete;
    }
}

void Snake::Player::updateVelocity(int newXVelocity, int newYVelocity)
{
    head->updateVelocity(newXVelocity, newYVelocity);
}

void Snake::Player::update()
{
    for(std::deque<PlayerCube*>::iterator it = body.begin(); it != body.end(); ++it)
        (*it)->update();
}

void Snake::Player::draw(SDL_Renderer* renderer)
{
    for(std::deque<PlayerCube*>::iterator it = body.begin(); it != body.end(); ++it)
        (*it)->draw(renderer);
}
