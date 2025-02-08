#include "../../headerFiles/states/MenuState.hpp"


MenuState::MenuState(SDL_Window *window, SDL_Renderer *renderer) {

    MenuState::renderer = renderer;
    MenuState::player = new Player(window, renderer);       // allocated memory - ensure you free it
}

bool MenuState::loadMedia() {
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

void MenuState::process_input(SDL_Event event, AbstractState **state) {

    switch (event.type) { 
        case SDL_MOUSEBUTTONDOWN:
            MenuState::handleMouseClick(state);
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_UP) {
                MenuState::player->updatePlayerPosition(0, -10);
            } else if (event.key.keysym.sym == SDLK_RIGHT) {
                MenuState::player->updatePlayerPosition(10, 0);
            } else if (event.key.keysym.sym == SDLK_DOWN) {
                MenuState::player->updatePlayerPosition(0, 10);
            } else if (event.key.keysym.sym == SDLK_LEFT) {
                MenuState::player->updatePlayerPosition(-10, 0);
            }
        default:
            break;
    }

}

void MenuState::handleMouseClick(AbstractState **state) {
    int x = 0, y = 0;
    if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
        int buttonLeftX = MenuState::startButton->getDRect().x;
        int buttonRightX = buttonLeftX + MenuState::startButton->getDRect().w;

        int buttonTopY = MenuState::startButton->getDRect().y;
        int buttonBottomY = buttonTopY + MenuState::startButton->getDRect().h;

        if (x >= buttonLeftX && x <= buttonRightX && y >= buttonTopY && y <= buttonBottomY) {
            std::cout << "Mouse button pressed; " << x << ", "<< y << std::endl;
            std::cout << "Clicked On The BIG RED BUTTON" << std::endl;

            (*state)->transitionState(state, new IntroState(window, renderer));
        }
        
    } else {
        std::cout << "Mouse button not pressed; " << SDL_BUTTON(SDL_BUTTON_LEFT) << "   " << SDL_GetMouseState(&x, &y) << std::endl;
    }
}

void MenuState::update() {
    MenuState::startButton->update();
    return;
}

void MenuState::render() {
    // std::cout << "Rendering MenuState" << std::endl;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
    MenuState::startButton->draw();
    MenuState::player->render();
    SDL_RenderPresent(renderer);
}

bool MenuState::onEnter() {
    // if (!loadMedia(renderer)) {
    //     return false;
    // }

    // SDL_RenderCopy( SDL_GetRenderer(window), this->coverTexture, NULL, NULL );
    
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    // SDL_Rect rect = {150, 200, 100, 50};
    SDL_RenderClear(renderer);

    SDL_Rect sRect = {0, 0, 100, 200};
    SDL_Rect dRect = {150, 200, 100, 50};
    this->startButton = new Button(renderer, sRect, dRect);

    
    // Update screen
    SDL_RenderPresent( renderer );
    return true;
}

void MenuState::onExit() {
    MenuState::startButton->destroyButton();
    delete MenuState::player;
}

std::string MenuState::getStateID() {
    return "MENU";
}