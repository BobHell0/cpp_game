#include "../headerFiles/EnvironmentObject.hpp"
EnvironmentObject::EnvironmentObject(
    SDL_FRect dRect, 
    SDL_Renderer *renderer
) {

    EnvironmentObject::dRect = dRect;
    EnvironmentObject::renderer = renderer;
    EnvironmentObject::x = dRect.x;
    EnvironmentObject::y = dRect.y;
}

void EnvironmentObject::render() {
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);

    SDL_FRect objectRect;
    objectRect.x = EnvironmentObject::x + PLAYER_POS_X;
    objectRect.y = EnvironmentObject::y + PLAYER_POS_Y;
    objectRect.w = dRect.w;
    objectRect.h = dRect.h;

    SDL_RenderFillRectF(renderer, &objectRect);
}

bool EnvironmentObject::playerMovesUpCollisionCheck() {
    float objectBottomLeftX = EnvironmentObject::x + PLAYER_POS_X;
    float objectBottomLeftY = EnvironmentObject::y + PLAYER_POS_Y + dRect.h;

    float objectBottomRightX = EnvironmentObject::x + PLAYER_POS_X + dRect.w;

    float playerTopLeftX = PLAYER_POS_X;
    float playerTopLeftY = PLAYER_POS_Y;

    float playerTopRightX = PLAYER_POS_X + PLAYER_SIDE_LENGTH;

    return (objectBottomRightX > playerTopLeftX) 
        && (objectBottomLeftX < playerTopRightX) 
        && (abs(objectBottomLeftY - playerTopLeftY) < COLLISION_BUFFER);
}

bool EnvironmentObject::playerMovesDownCollisionCheck() {
    float objectTopLeftX = EnvironmentObject::x + PLAYER_POS_X;
    float objectTopLeftY = EnvironmentObject::y + PLAYER_POS_Y;

    float objectTopRightX = EnvironmentObject::x + PLAYER_POS_X + dRect.w;

    float playerBottomLeftX = PLAYER_POS_X;
    float playerBottomLeftY = PLAYER_POS_Y + PLAYER_SIDE_LENGTH;

    float playerBottomRightX = PLAYER_POS_X + PLAYER_SIDE_LENGTH;

    return (objectTopRightX > playerBottomLeftX) 
        && (objectTopLeftX < playerBottomRightX) 
        && (abs(objectTopLeftY - playerBottomLeftY) < COLLISION_BUFFER);

}

bool EnvironmentObject::playerMovesLeftCollisionCheck() {
    float objectTopRightX = EnvironmentObject::x + PLAYER_POS_X + dRect.w;
    float objectTopRightY = EnvironmentObject::y + PLAYER_POS_Y;

    float objectBottomRightY = EnvironmentObject::y + PLAYER_POS_Y + dRect.h;

    float playerBottomLeftX = PLAYER_POS_X;
    float playerBottomLeftY = PLAYER_POS_Y + PLAYER_SIDE_LENGTH;

    float playerTopLeftY = PLAYER_POS_Y;

    return (objectTopRightY < playerBottomLeftY) 
        && (objectBottomRightY > playerTopLeftY) 
        && (abs(objectTopRightX - playerBottomLeftX) < COLLISION_BUFFER);
}

bool EnvironmentObject::playerMovesRightCollisionCheck() {
    float objectTopLeftX = EnvironmentObject::x + PLAYER_POS_X;
    float objectTopLeftY = EnvironmentObject::y + PLAYER_POS_Y;

    float objectBottomLeftY = EnvironmentObject::y + PLAYER_POS_Y + dRect.h;

    float playerBottomRightX = PLAYER_POS_X + PLAYER_SIDE_LENGTH;
    float playerBottomRightY = PLAYER_POS_Y + PLAYER_SIDE_LENGTH;

    float playerTopRightY = PLAYER_POS_Y;

    return (objectTopLeftY < playerBottomRightY) 
        && (objectBottomLeftY > playerTopRightY) 
        && (abs(objectTopLeftX - playerBottomRightX) < COLLISION_BUFFER);
}

void EnvironmentObject::moveObjectUp(float deltaTime) {
    EnvironmentObject::updateObjectPosition(0, -PLAYER_SPEED * deltaTime);
}

void EnvironmentObject::moveObjectRight(float deltaTime) {
    EnvironmentObject::updateObjectPosition(PLAYER_SPEED * deltaTime, 0);
}

void EnvironmentObject::moveObjectDown(float deltaTime) {
    EnvironmentObject::updateObjectPosition(0, PLAYER_SPEED * deltaTime);
}

void EnvironmentObject::moveObjectLeft(float deltaTime) {
    EnvironmentObject::updateObjectPosition(-PLAYER_SPEED * deltaTime, 0);
}

void EnvironmentObject::moveObjectUpAndRight(float deltaTime) {
    EnvironmentObject::updateObjectPosition(
        EnvironmentObject::calculateDiagonalSpeed() * deltaTime, 
        -EnvironmentObject::calculateDiagonalSpeed() * deltaTime
    );
}

void EnvironmentObject::moveObjectDownAndRight(float deltaTime) {
    EnvironmentObject::updateObjectPosition(
        EnvironmentObject::calculateDiagonalSpeed() * deltaTime, 
        EnvironmentObject::calculateDiagonalSpeed() * deltaTime
    );
}

void EnvironmentObject::moveObjectUpAndLeft(float deltaTime) {
    EnvironmentObject::updateObjectPosition(
        -EnvironmentObject::calculateDiagonalSpeed() * deltaTime, 
        -EnvironmentObject::calculateDiagonalSpeed() * deltaTime
    );
}

void EnvironmentObject::moveObjectDownAndLeft(float deltaTime) {
    EnvironmentObject::updateObjectPosition(
        -EnvironmentObject::calculateDiagonalSpeed() * deltaTime, 
        EnvironmentObject::calculateDiagonalSpeed() * deltaTime
    );
}

void EnvironmentObject::updateObjectPosition(float xDisplacement, float yDisplacement) {

    EnvironmentObject::x += xDisplacement;
    EnvironmentObject::y += yDisplacement;
}

float EnvironmentObject::calculateDiagonalSpeed() {
    return PLAYER_SPEED / sqrt(2);
}