#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>
#include "constants.hpp"
#include "EnvironmentObject.hpp"

class Player {
public:
    Player();
    Player(SDL_Renderer* renderer);

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


private:
    void updatePlayerPosition(float xDisplacement, float yDisplacement);
    float calculateDiagonalSpeed();
    SDL_Renderer* renderer;


    float x;
    float y;
};

#endif