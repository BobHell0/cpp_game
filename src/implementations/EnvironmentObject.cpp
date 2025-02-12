#include "../headerFiles/EnvironmentObject.hpp"
EnvironmentObject::EnvironmentObject() {

}
EnvironmentObject::EnvironmentObject(
    SDL_FRect dRect, 
    SDL_Renderer* renderer,
    std::shared_ptr<AbstractCollisionStrategy> collisionStrategy
) {
    EnvironmentObject::dRect = dRect;
    EnvironmentObject::renderer = renderer;
    EnvironmentObject::x = dRect.x;
    EnvironmentObject::y = dRect.y;
    EnvironmentObject::collisionStrategy = collisionStrategy;
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
    ObjectPositionInfo info;
    info.x = x, info.y = y, info.dRect = dRect;

    return EnvironmentObject::collisionStrategy->playerMovesUpCollisionCheck(info);

}

bool EnvironmentObject::playerMovesDownCollisionCheck() {
    ObjectPositionInfo info;
    info.x = x, info.y = y, info.dRect = dRect;
    return EnvironmentObject::collisionStrategy->playerMovesDownCollisionCheck(info);


}

bool EnvironmentObject::playerMovesLeftCollisionCheck() {
    ObjectPositionInfo info;
    info.x = x, info.y = y, info.dRect = dRect;
    return EnvironmentObject::collisionStrategy->playerMovesLeftCollisionCheck(info);

}

bool EnvironmentObject::playerMovesRightCollisionCheck() {
    ObjectPositionInfo info;
    info.x = x, info.y = y, info.dRect = dRect;
    return EnvironmentObject::collisionStrategy->playerMovesRightCollisionCheck(info);
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