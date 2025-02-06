#include "./headerFiles/MenuState.hpp"
#include <iostream>
#include <SDL2/SDL.h>

bool MenuState::loadMedia(SDL_Window *window) {
    SDL_Surface *tempCoverImage = SDL_LoadBMP("/Users/unswaccount/Documents/PersonalProjects/cpp_game/src/images/coolCover.bmp");
    if (tempCoverImage == NULL) {
        std::cerr << "Unable to load image" << SDL_GetError() << std::endl;
        return false;
    }

    std::cout << "Image loaded successfully" << std::endl;


    SDL_Texture *texture = SDL_CreateTextureFromSurface(SDL_GetRenderer(window), tempCoverImage);

    if (texture == NULL) {
        std::cout << "Unable to create texture from surface" << SDL_GetError() << std::endl;
    }

    SDL_FreeSurface(tempCoverImage);

    MenuState::coverTexture = texture;
    return true;
}

void MenuState::update() {
    return;
}

void MenuState::render(SDL_Renderer *renderer) {
    // std::cout << "Rendering MenuState" << std::endl;
    // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    // SDL_RenderClear(renderer);
    // SDL_RenderPresent(renderer);
}

bool MenuState::onEnter(SDL_Window *window, SDL_Renderer *renderer) {
    if (!loadMedia(window)) {
        return false;
    }

    SDL_RenderCopy( SDL_GetRenderer(window), this->coverTexture, NULL, NULL );

    //Update screen
    SDL_RenderPresent( renderer );
    return true;
}

void MenuState::onExit() {
    SDL_DestroyTexture(this->coverTexture);
    return;
}

std::string MenuState::getStateID() {
    return "MENU";
}