#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

#include "player_cube.h"

namespace Snake
{
    class Game
    {
    public:
        Game(int, int);
        ~Game();
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
        PlayerCube* player;

        void initializeSDL();
        void createWindow();
        void createRenderer();
        void update();
        void draw();
        void quit();
    };
}

#endif // GAME_H
