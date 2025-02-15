#include "../headerFiles/Player.hpp"
Player::Player() {
    Player::x = 0;
    Player::y = 0;
}

Player::Player(SDL_Renderer* renderer) {
    Player::renderer = renderer;

    Player::x = 0;
    Player::y = 0;
}
bool Player::checkForCollision() {
    return false;
}

void Player::movePlayerUp(float deltaTime) {
    Player::updatePlayerPosition(0, -PLAYER_SPEED * deltaTime);
}

void Player::movePlayerRight(float deltaTime) {
    Player::updatePlayerPosition(PLAYER_SPEED * deltaTime, 0);
}

void Player::movePlayerDown(float deltaTime) {
    Player::updatePlayerPosition(0, PLAYER_SPEED * deltaTime);
}

void Player::movePlayerLeft(float deltaTime) {
    Player::updatePlayerPosition(-PLAYER_SPEED * deltaTime, 0);
}

void Player::movePlayerUpAndRight(float deltaTime) {
    Player::updatePlayerPosition(
        Player::calculateDiagonalSpeed() * deltaTime, 
        -Player::calculateDiagonalSpeed() * deltaTime
    );
}

void Player::movePlayerDownAndRight(float deltaTime) {
    Player::updatePlayerPosition(
        Player::calculateDiagonalSpeed() * deltaTime, 
        Player::calculateDiagonalSpeed() * deltaTime
    );
}

void Player::movePlayerUpAndLeft(float deltaTime) {
    Player::updatePlayerPosition(
        -Player::calculateDiagonalSpeed() * deltaTime, 
        -Player::calculateDiagonalSpeed() * deltaTime
    );
}

void Player::movePlayerDownAndLeft(float deltaTime) {
    Player::updatePlayerPosition(
        -Player::calculateDiagonalSpeed() * deltaTime, 
        Player::calculateDiagonalSpeed() * deltaTime
    );
}


void Player::render() {
    SDL_Rect playerRect;
    playerRect.x = PLAYER_POS_X;
    playerRect.y = PLAYER_POS_Y;
    playerRect.w = PLAYER_SIDE_LENGTH;
    playerRect.h = PLAYER_SIDE_LENGTH;

    // std::cout << "rect x and y = " << playerRect.x << " " << playerRect.y << "\n";

    SDL_SetRenderDrawColor(Player::renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(Player::renderer, &playerRect);
}

float Player::getPlayerX() {
    return Player::x;
}

float Player::getPlayerY() {
    return Player::y;
}

void Player::updatePlayerPosition(float xDisplacement, float yDisplacement) {

    Player::x += xDisplacement;
    Player::y += yDisplacement;
}

float Player::calculateDiagonalSpeed() {
    return PLAYER_SPEED / sqrt(2);
}


