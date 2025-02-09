#include "../headerFiles/Player.hpp"
Player::Player(SDL_Window *window, SDL_Renderer *renderer) {
    Player::window = window;
    Player::renderer = renderer;

    Player::x = 200;
    Player::y = 150;
}

void Player::updatePlayerPosition(float xDisplacement, float yDisplacement) {
    Player::x += xDisplacement;
    Player::y += yDisplacement;
}

void Player::movePlayerUp() {
    Player::updatePlayerPosition(0, -PLAYER_SPEED);
}

void Player::movePlayerRight() {
    Player::updatePlayerPosition(PLAYER_SPEED, 0);
}

void Player::movePlayerDown() {
    Player::updatePlayerPosition(0, PLAYER_SPEED);
}

void Player::movePlayerLeft() {
    Player::updatePlayerPosition(-PLAYER_SPEED, 0);
}

void Player::movePlayerUpAndRight() {
    Player::updatePlayerPosition(
        Player::calculateDiagonalSpeed(), 
        -Player::calculateDiagonalSpeed()
    );
}

void Player::movePlayerDownAndRight() {
    Player::updatePlayerPosition(
        Player::calculateDiagonalSpeed(), 
        Player::calculateDiagonalSpeed()
    );
}

void Player::movePlayerUpAndLeft() {
    Player::updatePlayerPosition(
        -Player::calculateDiagonalSpeed(), 
        -Player::calculateDiagonalSpeed()
    );
}

void Player::movePlayerDownAndLeft() {
    Player::updatePlayerPosition(
        -Player::calculateDiagonalSpeed(), 
        Player::calculateDiagonalSpeed()
    );
}


void Player::render() {
    SDL_Rect playerRect;
    playerRect.x = Player::x;
    playerRect.y =  Player::y;
    playerRect.w = 20;
    playerRect.h = 20; // TODO: Remove magic number

    // std::cout << "rect x and y = " << playerRect.x << " " << playerRect.y << "\n";

    SDL_SetRenderDrawColor(Player::renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(Player::renderer, &playerRect);
}

float Player::calculateDiagonalSpeed() {
    return PLAYER_SPEED / sqrt(2);
}


