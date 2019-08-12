#ifndef FOOD_H
#define FOOD_H

#include "game_object.h"

namespace Snake
{
    class Food : public GameObject
    {
    public:
        Food(){};
        Food(int, int, int);
        ~Food(){};
    private:
    };
}

#endif // FOOD_H