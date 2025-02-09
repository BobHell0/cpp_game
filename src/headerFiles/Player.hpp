#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>
#include "constants.hpp"
#define PLAYER_SPEED 40.0
#define PLAYER_SIDE_LENGTH 30

class Player {
public:
    Player(SDL_Window *window, SDL_Renderer *renderer);

    void render();
    void movePlayerUp(float deltaTime);
    void movePlayerLeft(float deltaTime);
    void movePlayerDown(float deltaTime);
    void movePlayerRight(float deltaTime);

    void movePlayerUpAndRight(float deltaTime);
    void movePlayerDownAndRight(float deltaTime);
    void movePlayerUpAndLeft(float deltaTime);
    void movePlayerDownAndLeft(float deltaTime);

    float getPlayerX();
    float getPlayerY();

private:
    void updatePlayerPosition(float xDisplacement, float yDisplacement);
    float calculateDiagonalSpeed();
    SDL_Window *window;
    SDL_Renderer *renderer;

    float x;
    float y;
};