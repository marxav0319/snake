
#include <SDL2/SDL.h>

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
        int status;
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool gameRunning;

        void initializeSDL();
        void createWindow();
        void createRenderer();
        void draw();
    };
}
