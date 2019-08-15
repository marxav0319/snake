/**
 * Declares the Turn class.  This class holds information on the turns the Player has taken if the
 * turn is not yet done.  A turn is not yet done if not every body segment in the Player class has
 * gone through the turn yet.
 * 
 * Turn takes an xPosition, yPosition, xVelocity, and yVelocity.  The
 * position variables determine where on the grid the turn took place, and the velocities detail
 * the change in velocity that the body segment must take when the coordinate (xPosition, yPosition)
 * is reached.
 *
 * Author: Mark Xavier
 */

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

        Turn(int xPos, int yPos, int xVel, int yVel);
        ~Turn();
    };
}

#endif // TURN_H