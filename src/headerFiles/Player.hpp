#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>
#define PLAYER_SPEED 10.0

class Player {
public:
    Player(SDL_Window *window, SDL_Renderer *renderer);

    void render();
    void movePlayerUp();
    void movePlayerLeft();
    void movePlayerDown();
    void movePlayerRight();

    void movePlayerUpAndRight();
    void movePlayerDownAndRight();
    void movePlayerUpAndLeft();
    void movePlayerDownAndLeft();



private:
    void updatePlayerPosition(float xDisplacement, float yDisplacement);
    float calculateDiagonalSpeed();
    SDL_Window *window;
    SDL_Renderer *renderer;

    int x;
    int y;
};