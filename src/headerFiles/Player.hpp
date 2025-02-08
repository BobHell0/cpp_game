#include <SDL2/SDL.h>
#include <iostream>
class Player {
public:
    Player(SDL_Window *window, SDL_Renderer *renderer);

    void updatePlayerPosition(int xDisplacement, int yDisplacement);
    void render();


private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    int x;
    int y;
};