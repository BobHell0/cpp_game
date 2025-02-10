#ifndef ENVIRONMENTOBJECT_HPP
#define ENVIRONMENTOBJECT_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include "constants.hpp"

class EnvironmentObject {

public:
    EnvironmentObject(SDL_FRect dRect, SDL_Renderer *renderer);
    void render();

    void moveObjectUp(float deltaTime);
    void moveObjectLeft(float deltaTime);
    void moveObjectDown(float deltaTime);
    void moveObjectRight(float deltaTime);

    void moveObjectUpAndRight(float deltaTime);
    void moveObjectDownAndRight(float deltaTime);
    void moveObjectUpAndLeft(float deltaTime);
    void moveObjectDownAndLeft(float deltaTime);

    float x;
    float y;    // TODO: should be privatised with getters
    SDL_FRect dRect;


private:
    void updateObjectPosition(float xDisplacement, float yDisplacement);
    float calculateDiagonalSpeed();

    SDL_Renderer *renderer;




    
};

#endif