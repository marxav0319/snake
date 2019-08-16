#include <cstdlib>
#include "player.h"

Snake::Player::Player(int screenSize_, int rows_, int size_) : size(size_), screenSize(screenSize_),
    rows(rows_)
{
    head = new PlayerCube(0, 0, screenSize, rows, size, 0, 0, 225, 255, 1, 0);
    body.push_back(head);
}

Snake::Player::~Player()
{
    PlayerCube* toDelete;
    Turn* deleteTurn;

    while(!body.empty())
    {
        toDelete = body.front();
        body.pop_front();
        delete toDelete;
    }
    
    while(!turns.empty())
    {
        deleteTurn = turns.front();
        turns.pop_front();
        delete deleteTurn;
    }
}

void Snake::Player::updateVelocity(int newXVelocity, int newYVelocity)
{
    int currentVelocityX = head->getXVelocity();
    int currentVelocityY = head->getYVelocity();
    if(newXVelocity != head->getXVelocity() || newYVelocity != head->getYVelocity())
    {
        if((currentVelocityX + newXVelocity != 0) && (currentVelocityY + newYVelocity != 0))
        {
            Turn* tempTurn = new Turn(head->getX(), head->getY(), newXVelocity, newYVelocity);
            turns.push_front(tempTurn);
        }
    }
}

void Snake::Player::addBodySegment()
{
    PlayerCube* lastSegment = body.back();
    int segmentXPlacement = lastSegment->getXVelocity() * -1;
    int segmentYPlacement = lastSegment->getYVelocity() * -1;
    int newSegmentXPosition = lastSegment->getX();
    int newSegmentYPosition = lastSegment->getY();

    if(segmentXPlacement != 0)
        newSegmentXPosition += segmentXPlacement * size;
    else
        newSegmentYPosition += segmentYPlacement * size;

    PlayerCube* newSegment = new PlayerCube(newSegmentXPosition, newSegmentYPosition, screenSize,
        rows, size, 100, 149, 237, 255, lastSegment->getXVelocity(), lastSegment->getYVelocity());
    body.push_back(newSegment);
}

void Snake::Player::updateBodySegmentVelocities()
{
    std::deque<PlayerCube*>::iterator bodyIterator;
    std::deque<Turn*>::iterator turnIterator;
    bool firstTurnDone = false;
    for(bodyIterator = body.begin(); bodyIterator != body.end(); ++bodyIterator)
    {
        for(turnIterator = turns.begin(); turnIterator != turns.end(); ++turnIterator)
        {
            bool segmentUpdated = false;
            segmentUpdated = (*bodyIterator)->updateVelocity(*turnIterator);
            if(segmentUpdated && ((*bodyIterator) == body.back()))
                firstTurnDone = true;
        }
    }
    
    if(firstTurnDone)
    {
        Turn* tempTurn = turns.back();
        turns.pop_back();
        delete tempTurn;
    }
}

bool Snake::Player::bodyCollisionDetected()
{
    std::deque<PlayerCube*>::iterator bodyIterator = body.begin();
    bodyIterator++;
    while(bodyIterator != body.end())
    {
        if(head->getX() == (*bodyIterator)->getX())
        {
            if(head->getY() == (*bodyIterator)->getY())
            {
                return true;
            }
        }
        bodyIterator++;
    }
    return false;
}

void Snake::Player::update()
{
    updateBodySegmentVelocities();
    for(std::deque<PlayerCube*>::iterator it = body.begin(); it != body.end(); ++it)
        (*it)->update();
}

void Snake::Player::draw(SDL_Renderer* renderer)
{
    for(std::deque<PlayerCube*>::iterator it = body.begin(); it != body.end(); ++it)
        (*it)->draw(renderer);
}
