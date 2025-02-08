#include "../headerFiles/Player.hpp"
Player::Player(SDL_Window *window, SDL_Renderer *renderer) {
    Player::window = window;
    Player::renderer = renderer;

    Player::x = 200;
    Player::y = 150;
}

void Player::updatePlayerPosition(int xDisplacement, int yDisplacement) {
    Player::x += xDisplacement;
    Player::y += yDisplacement;
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

    static int playerSpeed = 20;

}


