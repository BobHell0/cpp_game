#include "../../headerFiles/MenuState.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include "../../headerFiles/Button.hpp"

bool MenuState::loadMedia(SDL_Renderer *renderer) {
    SDL_Surface *tempCoverImage = SDL_LoadBMP("./src/images/coolCover.bmp");
    if (tempCoverImage == NULL) {
        std::cerr << "Unable to load image" << SDL_GetError() << std::endl;
        return false;
    }

    std::cout << "Image loaded successfully" << std::endl;


    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, tempCoverImage);

    if (texture == NULL) {
        std::cout << "Unable to create texture from surface" << SDL_GetError() << std::endl;
    }

    SDL_FreeSurface(tempCoverImage);

    MenuState::coverTexture = texture;
    return true;
}

void MenuState::process_input(SDL_Event event) {


    switch (event.type) {
        case SDL_MOUSEBUTTONDOWN:
            MenuState::handleMouseClick();
            break;
        default:
            break;
    }

}

void MenuState::handleMouseClick() {
    int x = 0, y = 0;
    if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
        if (x >= 150 && x <= 250 && y >= 200 && y <= 250) {
            std::cout << "Mouse button pressed; " << x << ", "<< y << std::endl;
            std::cout << "Clicked On The BIG RED BUTTON " << x << ", "<< y << std::endl;
        }
        
    } else {
        std::cout << "Mouse button not pressed; " << SDL_BUTTON(SDL_BUTTON_LEFT) << "   " << SDL_GetMouseState(&x, &y) << std::endl;
    }
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
    // if (!loadMedia(renderer)) {
    //     return false;
    // }

    // SDL_RenderCopy( SDL_GetRenderer(window), this->coverTexture, NULL, NULL );
    
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    // SDL_Rect rect = {150, 200, 100, 50};
    SDL_RenderClear(renderer);
    

    SDL_Rect sRect = {0, 0, 100, 200};
    SDL_Rect dRect = {150, 200, 100, 50};
    Button *button = new Button(renderer, sRect, dRect);
    button->draw(renderer);
    
    // Update screen
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