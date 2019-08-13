#ifndef TURN_H
#define TURN_H

namespace Snake
{
    class Turn
    {
    public:
        int xPosition;
        int yPosition;
        int xVelocity;
        int yVelocity;

        Turn(int, int, int, int);
        ~Turn();
    };
}

#endif // TURN_H