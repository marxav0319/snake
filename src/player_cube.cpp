#include "player_cube.h"

Snake::PlayerCube::PlayerCube(int x, int y, int size) : GameObject(x, y, size)
{
    return;
}

Snake::PlayerCube::~PlayerCube()
{
    return;
}

void Snake::PlayerCube::update(int x_velocity, int y_velocity)
{
    return;
}

void Snake::PlayerCube::draw(SDL_Renderer* renderer)
{
    Snake::GameObject::draw(renderer);
}
