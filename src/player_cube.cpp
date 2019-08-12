#include <iostream>
#include "player_cube.h"

Snake::PlayerCube::PlayerCube(int x, int y, int size, int r, int g, int b, int a) :
    GameObject(x, y, size, r, g, b, a)
{
    x_velocity = 1;
    y_velocity = 0;
    return;
}

Snake::PlayerCube::~PlayerCube()
{
    return;
}

void Snake::PlayerCube::update()
{
    int xPositionUpdate = (size * x_velocity) + x;
    int yPositionUpdate = (size * y_velocity) + y;
    x = xPositionUpdate;
    y = yPositionUpdate;

    rectangle.x = x;
    rectangle.y = y;
    return;
}