#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>
#include "constants.hpp"
#include "EnvironmentObject.hpp"

#define PLAYER_SPEED 40.0
#define PLAYER_SIDE_LENGTH 30

class Player {
public:
    Player(SDL_Window *window, SDL_Renderer *renderer);

    void render();

    bool checkForCollision();

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

    EnvironmentObject **listOfObjects;      // needs to be freed
    int numObjects;


private:
    void updatePlayerPosition(float xDisplacement, float yDisplacement);
    float calculateDiagonalSpeed();
    SDL_Window *window;
    SDL_Renderer *renderer;


    float x;
    float y;
};

#endif