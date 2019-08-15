/**
 * This file declares the GameObject class.  The GameObject is a standard object that serves as the
 * "sprite" for this game.  A GameObject is simply an SDL_Rect with the same width and height,
 * in other words it is a standard square for the game.  GameObjects serve as the snake head, body,
 * and food.
 *
 * A GameObject takes a number of arguments, see below method documentation for more information.
 * 
 * Author: Mark Xavier
 */

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL2/SDL.h>

namespace Snake
{
    class GameObject
    {
    public:
        /**
         * Parameterized Constructor for GameObject
         *
         * This constructor creates a full-fledged game object.
         *
         * Args:
         *  x_: the x position of the top-corner of the square.
         *  y_: the y position of the top-corner of the square.
         *  size_: the width and height of the square.
         *  r: the red value for the color of the square (0-255)
         *  g: the green value for the color of the square (0-255)
         *  b: the blue value for the color of the square (0-255)
         *  a: the alpha value for the color of the square (0-255)
         */
        GameObject(int x_, int y_, int size_, int r, int g, int b, int a);
        GameObject(){};
        virtual ~GameObject();

        /* Returns the x position of the top-corner of the object. */
        int getX(){return x;}

        /* Returns the y position of the top-corner of the object. */
        int getY(){return y;}

        /* Draws the SDL_Rect to the screen given the SDL_Renderer*. */
        virtual void draw(SDL_Renderer* renderer);
        
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