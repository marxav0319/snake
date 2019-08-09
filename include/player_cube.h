#ifndef PLAYER_CUBE_H
#define PLAYER_CUBE_H

#include <SDL2/SDL.h>

#include "game_object.h"

namespace Snake
{
    class PlayerCube : public GameObject
    {
    public:
        PlayerCube(){};
        PlayerCube(int, int, int);
        ~PlayerCube();
        virtual void update(int, int);
        virtual void draw(SDL_Renderer*);
    private:
    }; 
}

#endif // PLAYER_CUBE_H