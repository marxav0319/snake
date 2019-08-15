/**
 * Declares the Player class.  The Player is essentially the snake in the game.  The Player holds
 * a deque of PlayerCube*, with the first one being the head of the snake.
 *
 * Author: Mark Xavier
 */

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
        /**
         * Parameterized Constructor for the Player class.
         *
         * Args:
         *  screenSize_: the size of the SDL_Window for the player to move in.
         *  rows_: the number of rows (and columns) that make up the grid for the player to move in.
         *  size_: the width and height of an individual PlayerCube.
         */
        Player(int screenSize_, int rows_, int size_);
        ~Player();

        /* Returns the x position of the head of the Player */
        int getX() {return head->getX();}

        /* Returns the y position of the head of the Player */
        int getY() {return head->getY();}

        /* Returns the deque<PlayerCube*> of body segments (including the head) of the Player */
        const std::deque<PlayerCube*>* getBody() {return &body;}

        /**
         * Updates the velocity of the Player if applicable.
         *
         * This update only occurs if the newXVelocity or newYVelocity passed are different from
         * the corresponding velocities of the head of the Player.
         *
         * Args:
         *  newXVelocity: the x velocity to check against Player.head
         *  newYVelocity: the y velocity to check against Player.head
         */
        void updateVelocity(int newXVelocity, int newYVelocity);

        /* Adds a new PlayerCube to the deque<PlayerCube*>. */
        void addBodySegment();

        /* Checks if the head of the Player has collided with the body of the snake. */
        bool bodyCollisionDetected();

        /* Updates the position of each PlayerCube* in the snake's body. */
        void update();

        /* Draws each PlayerCube* to the screen. */
        void draw(SDL_Renderer* renderer);
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