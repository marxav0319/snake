
#include <SDL2/SDL.h>

namespace Snake
{
    class Game
    {
    public:
        Game(int);
        ~Game();
        void gameLoop();
        void draw();
    private:
        int screenSize;
        int status;
        SDL_Window* window;
        SDL_Renderer* renderer;

        void initializeSDL();
        void createWindow();
        void createRenderer();
    };
}
