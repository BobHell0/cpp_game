#include "../../headerFiles/Button.hpp"
#include <SDL2/SDL.h>

Button::Button(SDL_Renderer *renderer, SDL_Rect sRect, SDL_Rect dRect) {
    this->isHovered = false;
    SDL_Surface *tempCoverImage = SDL_LoadBMP("./src/images/coolCover.bmp");
    if (tempCoverImage == NULL) {
        std::cerr << "Unable to load image" << SDL_GetError() << std::endl;
        return;
    }

    this->texture = SDL_CreateTextureFromSurface(renderer, tempCoverImage);
    
    this->sRect = sRect;
    this->dRect = dRect;



}

void Button::update() {
    int x = 0, y = 0;
    SDL_GetMouseState(&x, &y);
    SDL_Rect mouseRect = {x, y, 1, 1};

    if (SDL_HasIntersection(&(this->dRect), &mouseRect)) {
        this->isHovered = true;
        SDL_Rect newSRect = {100, 100, 100, 200};
        this->sRect = newSRect;
    } else {
        this->isHovered = false;
    }
    return;
}

void Button::draw(SDL_Renderer *renderer) {
    SDL_RenderCopy(renderer, texture, &sRect, &dRect);
}