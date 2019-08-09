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
        virtual ~GameObject();
        virtual void update(int, int) = 0;
        virtual void draw(SDL_Renderer*);
    protected:
        int x;
        int y;
        int size;
        SDL_Rect rectangle;
    private:
    };
}

#endif // GAME_OBJECT_H