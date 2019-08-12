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
        PlayerCube(int, int, int, int, int, int, int);
        ~PlayerCube();
        virtual void update();
    private:
        int x_velocity;
        int y_velocity;
    }; 
}

#endif // PLAYER_CUBE_H