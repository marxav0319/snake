/**
 * Declares the Food class, which inherits from GameObject.  The food class simply creates a
 * an SDL_Rect and draws it to the screen.  The game handles moving Food upon consumption.  The
 * constructor takes an x and a y position, along with a size so that the rectangle (square) can be
 * drawn.
 *
 * Author: Mark Xavier
 */

#ifndef FOOD_H
#define FOOD_H

#include "game_object.h"

namespace Snake
{
    class Food : public GameObject
    {
    public:
        Food(){};
        Food(int x, int y, int size);
        ~Food(){};
    private:
    };
}

#endif // FOOD_H