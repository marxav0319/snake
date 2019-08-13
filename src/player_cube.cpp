#include <iostream>
#include "player_cube.h"

Snake::PlayerCube::PlayerCube(int x, int y, int screenSize_, int rows_, int size, int r, int g, int b,
    int a, int x_vel, int y_vel) : GameObject(x, y, size, r, g, b, a), screenSize(screenSize_),
    rows(rows_), xVelocity(x_vel), yVelocity(y_vel)
{
    return;
}

Snake::PlayerCube::~PlayerCube()
{
    return;
}

bool Snake::PlayerCube::updateVelocity(Turn* turn)
{
    if(turn->xPosition == this->x && turn->yPosition == this->y)
    {
        this->xVelocity = turn->xVelocity;
        this->yVelocity = turn->yVelocity;
        return true;
    }
    return false;
}

void Snake::PlayerCube::update()
{
    int xPositionUpdate = (size * xVelocity) + x;
    int yPositionUpdate = (size * yVelocity) + y;

    if(xPositionUpdate < 0)
        xPositionUpdate = screenSize - size;
    else if(xPositionUpdate >= screenSize)
        xPositionUpdate = 0;

    if(yPositionUpdate < 0)
        yPositionUpdate = screenSize - size;
    else if(yPositionUpdate >= screenSize)
        yPositionUpdate = 0;

    x = xPositionUpdate;
    y = yPositionUpdate;

    rectangle.x = x;
    rectangle.y = y;
    return;
}