/**
 * Declares the PlayerCube class.  The PlayerCube is an object that inherits from the generic
 * GameObject defined in this project.  Each PlayerCube has it's own x position and y position,
 * along with a velocity in both the x and y directions that is updated on each call to the object's
 * update() method.  The PlayerCube is in constant motion, and therefore always has either a
 * non-zero velocity in the x direction or in the y direction.
 */

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
        /**
         * Parameterized Constructor for the PlayerCube class.
         *
         * Args:
         *  x: the x position of the top-left corner of the PlayerCube
         *  y: the y position of the top-left corner of the PlayerCube
         *  screenSize_: an integer representing both the width and the height of the screen
         *  rows_: the number of rows and columns in the screen
         *  size: the width and height of a GameObject
         *  r: the red value for the color of the square (0-255)
         *  g: the green value for the color of the square (0-255)
         *  b: the blue value for the color of the square (0-255)
         *  a: the alpha value for the color of the square (0-255)
         *  xVel: the direction in the x-axis that the cube is moving in (-1, 0, 1)
         *  yVel: the direction in the y-axis that the cube is moving in (-1, 0, 1)
         */
        PlayerCube(int x, int y, int screenSize_, int rows_, int size, int r, int g, int b, int a,
                   int xVel, int yVel);
        PlayerCube(){};
        ~PlayerCube();

        /* Return this instances movement in the x-axis */
        int getXVelocity() {return xVelocity;}

        /* Return this instances movement in the y-axis */
        int getYVelocity() {return yVelocity;}

        /* Move the PlayerCube to (xPosition + xVelocity, yPosition + yVelocity) */
        virtual void update();

        /**
         * Given a Turn*, if the PlayerCube is at the position that the Turn* holds, update the
         * velocity of this PlayerCube with the Turn*'s stored velocities.  This in effect changes
         * the direction of the player cube to match that described in the Turn*.
         *
         * Args:
         *  Turn* turn: an object holding the x-coordinates and x-velocities of the turn.
         */
        bool updateVelocity(Turn* turn);
        
    private:
        int screenSize;
        int rows;
        int xVelocity;
        int yVelocity;
    }; 
}

#endif // PLAYER_CUBE_H