#ifndef PLAYER_H
#define PLAYER_H

#include <deque>
#include <SDL2/SDL.h>
#include "player_cube.h"

namespace Snake
{
    class Player
    {
    public:
        Player(int, int, int);
        ~Player();
        void updateVelocity(int, int);
        void update();
        void draw(SDL_Renderer*);
    private:
        int size;
        int xVelocity;
        int yVelocity;
        int screenSize;
        int rows;
        PlayerCube* head;
        std::deque<PlayerCube*> body;
    };
}

#endif // PLAYER_H