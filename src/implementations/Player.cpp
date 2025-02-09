#include "../headerFiles/Player.hpp"
Player::Player(SDL_Window *window, SDL_Renderer *renderer) {
    Player::window = window;
    Player::renderer = renderer;

    Player::x = WINDOW_WIDTH / 2 - PLAYER_SIDE_LENGTH / 2;
    Player::y = WINDOW_HEIGHT / 2 - PLAYER_SIDE_LENGTH / 2;
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
    playerRect.x = WINDOW_WIDTH / 2 - PLAYER_SIDE_LENGTH / 2;
    playerRect.y = WINDOW_HEIGHT / 2 - PLAYER_SIDE_LENGTH / 2;
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


