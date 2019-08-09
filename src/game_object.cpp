#include "game_object.h"

Snake::GameObject::GameObject(int x_, int y_, int size_) : x(x_), y(y_), size(size_)
{
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = size;
    rectangle.h = size;
    return;
}

Snake::GameObject::~GameObject()
{
    return;
}

void Snake::GameObject::draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);
    SDL_RenderFillRect(renderer, &rectangle);
}
