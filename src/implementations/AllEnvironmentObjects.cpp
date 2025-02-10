#include "../headerFiles/AllEnvironmentObjects.hpp"

AllEnvironmentObjects::AllEnvironmentObjects(EnvironmentObject **listOfObjects) {
    AllEnvironmentObjects::listOfObjects = listOfObjects;
    numberOfObjects = sizeof(listOfObjects) / sizeof(listOfObjects[0]);
}



void AllEnvironmentObjects::moveAllObjectsUp(float deltaTime) {
    for (int i = 0; i < numberOfObjects; i++) {
        EnvironmentObject *currObject = listOfObjects[i];
        currObject->moveObjectUp(deltaTime);
    }

}
void AllEnvironmentObjects::moveAllObjectsRight(float deltaTime) {
    for (int i = 0; i < numberOfObjects; i++) {
        EnvironmentObject *currObject = listOfObjects[i];
        currObject->moveObjectRight(deltaTime);
    }

}
void AllEnvironmentObjects::moveAllObjectsDown(float deltaTime) {
    for (int i = 0; i < numberOfObjects; i++) {
        EnvironmentObject *currObject = listOfObjects[i];
        currObject->moveObjectDown(deltaTime);
    }

}
void AllEnvironmentObjects::moveAllObjectsLeft(float deltaTime) {
    for (int i = 0; i < numberOfObjects; i++) {
        EnvironmentObject *currObject = listOfObjects[i];
        currObject->moveObjectLeft(deltaTime);
    }

}
void AllEnvironmentObjects::moveAllObjectsUpAndRight(float deltaTime) {
    moveAllObjectsUp(deltaTime);
    moveAllObjectsRight(deltaTime);

}
void AllEnvironmentObjects::moveAllObjectsUpAndLeft(float deltaTime) {
    moveAllObjectsUp(deltaTime);
    moveAllObjectsLeft(deltaTime);

}
void AllEnvironmentObjects::moveAllObjectsDownAndRight(float deltaTime) {
    moveAllObjectsDown(deltaTime);
    moveAllObjectsRight(deltaTime);
    

}
void AllEnvironmentObjects::moveAllObjectsDownAndLeft(float deltaTime) {
    moveAllObjectsDown(deltaTime);
    moveAllObjectsLeft(deltaTime);

}