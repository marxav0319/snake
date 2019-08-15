/**
 * Declares the Game class.  The Game class holds all the GameObjects and runs the game loop.  It
 * intializes all objects and dictates when events cause updates to the state of the game.
 *
 * Author: Mark Xavier
 */

#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

#include "player.h"
#include "food.h"

namespace Snake
{
    class Game
    {
    public:
        /**
         * Parameterized Constructor for the Game Class.
         *
         * Args:
         *  screenSize_: the size of the SDL_Window (width and height are the same).
         *  rows_: the number of rows (and columns) in the SDL_Window - defines the grid for movement.
         */
        Game(int screenSize_, int rows);
        ~Game();

        /* Keeps the game in play until the user exits */
        void gameLoop();
    private:
        const int fps = 10;
        int screenSize;
        int numberOfRows;
        int gameObjectSize;
        int status;
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool gameRunning;
        Player* player;
        Food* food;
        bool playerLost;

        /* Initializes SDL components needed */
        void initializeSDL();

        /* Creates an SDL_Window */
        void createWindow();

        /* Creates and SDL_Renderer */
        void createRenderer();

        /* Generates a new food item at a random location not occupied by the Player */
        void generateFood();

        /* Returns true if the Player has collided with the Food, else false */
        bool detectFoodCollision();

        /* Updates the states and positions of all GameObjects and relevant variables */
        void update();

        /* Draws all GameObjects to the screen in their updated states */
        void draw();

        /* Deletes the Player and Food objects */
        void cleanGameObjects();

        /* Resets the state of the game to it's initial state (except for random food placement) */
        void reset();

        /* Quits the game and SDL */
        void quit();
    };
}

#endif // GAME_H
