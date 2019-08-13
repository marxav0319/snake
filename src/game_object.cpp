#include "game_object.h"

Snake::GameObject::GameObject(int x_, int y_, int size_, int r, int g, int b, int a) : x(x_), y(y_),
    size(size_), red(r), green(g), blue(b), alpha(a)
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
    SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
    SDL_RenderFillRect(renderer, &rectangle);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rectangle);
}
