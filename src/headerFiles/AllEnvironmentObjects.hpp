#ifndef ALLENVIRONMENTOBJECTS_HPP
#define ALLENVIRONMENTOBJECTS_HPP
#include <SDL2/SDL.h>
#include "EnvironmentObject.hpp"

class AllEnvironmentObjects {
public:
    AllEnvironmentObjects(EnvironmentObject **listOfObjects);

    void moveAllObjectsUp(float deltaTime);
    void moveAllObjectsRight(float deltaTime);
    void moveAllObjectsDown(float deltaTime);
    void moveAllObjectsLeft(float deltaTime);
    void moveAllObjectsUpAndRight(float deltaTime);
    void moveAllObjectsUpAndLeft(float deltaTime);
    void moveAllObjectsDownAndRight(float deltaTime);
    void moveAllObjectsDownAndLeft(float deltaTime);
private:
    EnvironmentObject **listOfObjects; 
    int numberOfObjects;

};
#endif