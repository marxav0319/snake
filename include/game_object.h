#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL2/SDL.h>

namespace Snake
{
    class GameObject
    {
    public:
        GameObject(){};
        GameObject(int, int, int, int, int, int, int);
        virtual ~GameObject();
        int getX(){return x;}
        int getY(){return y;}
        virtual void draw(SDL_Renderer*);
    protected:
        int x;
        int y;
        int size;
        int red;
        int green;
        int blue;
        int alpha;
        SDL_Rect rectangle;
    private:
    };
}

#endif // GAME_OBJECT_H