#ifndef PLAYER_CUBE_H
#define PLAYER_CUBE_H

#include <SDL2/SDL.h>

#include "game_object.h"
#include "turn.h"

namespace Snake
{
    class PlayerCube : public GameObject
    {
    public:
        PlayerCube(){};
        PlayerCube(int, int, int, int, int, int, int, int, int, int, int);
        ~PlayerCube();

        int getXVelocity() {return xVelocity;}
        int getYVelocity() {return yVelocity;}

        virtual void update();
        bool updateVelocity(Turn*);
    private:
        int screenSize;
        int rows;
        int xVelocity;
        int yVelocity;
    }; 
}

#endif // PLAYER_CUBE_H