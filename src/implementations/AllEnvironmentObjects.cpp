#include "../headerFiles/AllEnvironmentObjects.hpp"
AllEnvironmentObjects::AllEnvironmentObjects() {
    numberOfObjects = 0;
}

AllEnvironmentObjects::AllEnvironmentObjects(EnvironmentObject **listOfObjects) {
    AllEnvironmentObjects::listOfObjects = listOfObjects;
    numberOfObjects = sizeof(listOfObjects) / sizeof(listOfObjects[0]);
}

bool AllEnvironmentObjects::playerMovesUpCollisionCheck() {
    for (int i = 0; i < numberOfObjects; i++) {
        EnvironmentObject *currObject = listOfObjects[i];
        if (currObject->playerMovesUpCollisionCheck()) {
            return true;
        }
    }
    
    return false;
}

bool AllEnvironmentObjects::playerMovesDownCollisionCheck() {
    for (int i = 0; i < numberOfObjects; i++) {
        EnvironmentObject *currObject = listOfObjects[i];
        if (currObject->playerMovesDownCollisionCheck()) {
            return true;
        }
    }
    
    return false;
}

bool AllEnvironmentObjects::playerMovesLeftCollisionCheck() {
    for (int i = 0; i < numberOfObjects; i++) {
        EnvironmentObject *currObject = listOfObjects[i];
        if (currObject->playerMovesLeftCollisionCheck()) {
            return true;
        }
    }
    
    return false;
}

bool AllEnvironmentObjects::playerMovesRightCollisionCheck() {
    for (int i = 0; i < numberOfObjects; i++) {
        EnvironmentObject *currObject = listOfObjects[i];
        if (currObject->playerMovesRightCollisionCheck()) {
            return true;
        }
    }
    
    return false;
}

void AllEnvironmentObjects::moveAllObjectsUp(float deltaTime) {
    if (playerMovesDownCollisionCheck()) {
        return;
    }
    for (int i = 0; i < numberOfObjects; i++) {
        EnvironmentObject *currObject = listOfObjects[i];
        currObject->moveObjectUp(deltaTime);
    }

}
void AllEnvironmentObjects::moveAllObjectsRight(float deltaTime) {
    if (playerMovesLeftCollisionCheck()) {
        return;
    }

    for (int i = 0; i < numberOfObjects; i++) {
        EnvironmentObject *currObject = listOfObjects[i];
        currObject->moveObjectRight(deltaTime);
    }

}
void AllEnvironmentObjects::moveAllObjectsDown(float deltaTime) {
    if (playerMovesUpCollisionCheck()) {
        return; // block movement
    }
    for (int i = 0; i < numberOfObjects; i++) {
        EnvironmentObject *currObject = listOfObjects[i];
        currObject->moveObjectDown(deltaTime);
    }

}
void AllEnvironmentObjects::moveAllObjectsLeft(float deltaTime) {
    if (playerMovesRightCollisionCheck()) {
        return;
    }
    
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