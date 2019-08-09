#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

#include "game_object.h"

namespace Snake
{
    class Game
    {
    public:
        Game(int, int);
        ~Game();
        void gameLoop();
    private:
        int screenSize;
        int numberOfRows;
        int gameObjectSize;
        int status;
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool gameRunning;
        GameObject player;

        void initializeSDL();
        void createWindow();
        void createRenderer();
        void draw();
    };
}

#endif // GAME_H
