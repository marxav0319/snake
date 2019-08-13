#ifndef PLAYER_H
#define PLAYER_H

#include <deque>
#include <SDL2/SDL.h>
#include "player_cube.h"
#include "turn.h"

namespace Snake
{
    class Player
    {
    public:
        Player(int, int, int);
        ~Player();
        int getX() {return head->getX();}
        int getY() {return head->getY();}
        const std::deque<PlayerCube*>* getBody() {return &body;}
        void updateVelocity(int, int);
        void addBodySegment();
        bool bodyCollisionDetected();
        void update();
        void draw(SDL_Renderer*);
    private:
        int size;
        int screenSize;
        int rows;
        PlayerCube* head;
        std::deque<PlayerCube*> body;
        std::deque<Turn*> turns;

        void updateBodySegmentVelocities();
    };
}

#endif // PLAYER_H