#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL2/SDL.h>

namespace Snake
{
    class GameObject
    {
    public:
        GameObject(){};
        GameObject(int, int, int);
        ~GameObject();
        void draw(SDL_Renderer*);
    private:
        int x;
        int y;
        int size;
        SDL_Rect rectangle;
    };
}

#endif // GAME_OBJECT_H