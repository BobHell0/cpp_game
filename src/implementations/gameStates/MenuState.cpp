#include "../../headerFiles/states/MenuState.hpp"


MenuState::MenuState(SDL_Renderer* renderer) {

    MenuState::renderer = renderer;
    MenuState::player = Player(renderer);

    EnvironmentObject** objList = new EnvironmentObject*[10];
    objList[0] = new EnvironmentObject(
        (SDL_FRect) {.x = 100, .y = 50, .w = 20, .h = 80}, 
        renderer, 
        // new TitaniumCollisionStrategy()
        std::make_shared<TitaniumCollisionStrategy>()
    );
    objList[1] = new EnvironmentObject(
        (SDL_FRect) {.x = 20, .y = 80, .w = 100, .h = 10}, 
        renderer, 
        // new TitaniumCollisionStrategy()
        std::make_shared<TitaniumCollisionStrategy>()
    );
    objList[2] = new EnvironmentObject(
        (SDL_FRect) {.x = 30, .y = 15, .w = 10, .h = 80}, 
        renderer, 
        // new TitaniumCollisionStrategy()
        std::make_shared<TitaniumCollisionStrategy>()
    );
    objList[3] = new EnvironmentObject(
        (SDL_FRect) {.x = -500, .y = 30, .w = 20, .h = 10}, 
        renderer, 
        // new TitaniumCollisionStrategy()
        std::make_shared<TitaniumCollisionStrategy>()
    );
    objList[4] = new EnvironmentObject(
        (SDL_FRect) {.x = 30, .y = -100, .w = 60, .h = 20}, 
        renderer, 
        // new TitaniumCollisionStrategy()
        std::make_shared<TitaniumCollisionStrategy>()
    );
    objList[5] = new EnvironmentObject(
        (SDL_FRect) {.x = 50, .y = -20, .w = 10, .h = 100}, 
        renderer, 
        // new TitaniumCollisionStrategy()
        std::make_shared<TitaniumCollisionStrategy>()
    );
    objList[6] = new EnvironmentObject(
        (SDL_FRect) {.x = 340, .y = 32, .w = 42, .h = 53}, 
        renderer, 
        // new TitaniumCollisionStrategy()
        std::make_shared<TitaniumCollisionStrategy>()
    );
    objList[7] = new EnvironmentObject(
        (SDL_FRect) {.x = -333, .y = -444, .w = 21, .h = 80}, 
        renderer, 
        // new TitaniumCollisionStrategy()
        std::make_shared<TitaniumCollisionStrategy>()
    );
    objList[8] = new EnvironmentObject(
        (SDL_FRect) {.x = 33, .y = 222, .w = 43, .h = 43}, 
        renderer, 
        // new TitaniumCollisionStrategy()
        std::make_shared<TitaniumCollisionStrategy>()
    );
    objList[9] = new EnvironmentObject(
        (SDL_FRect) {.x = 323, .y = 42, .w = 22, .h = 33}, 
        renderer, 
        // new TitaniumCollisionStrategy()
        std::make_shared<TitaniumCollisionStrategy>()
    );

    MenuState::allObjs = AllEnvironmentObjects(objList, 10);
    pressedArrow.fill(false);
}

bool MenuState::loadMedia() {
    SDL_Surface* tempCoverImage = SDL_LoadBMP("./src/images/coolCover.bmp");
    if (tempCoverImage == NULL) {
        std::cerr << "Unable to load image" << SDL_GetError() << std::endl;
        return false;
    }

    std::cout << "Image loaded successfully" << std::endl;


    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempCoverImage);

    if (texture == NULL) {
        std::cerr << "Unable to create texture from surface" << SDL_GetError() << std::endl;
    }

    SDL_FreeSurface(tempCoverImage);

    MenuState::coverTexture = texture;
    return true;
}

void MenuState::process_input(SDL_Event event, std::unique_ptr<AbstractState>& state) {

    switch (event.type) { 
        MenuState::lastFrameTime = SDL_GetTicks();
        case SDL_MOUSEBUTTONDOWN:
            MenuState::handleMouseClick(state);
            break;
        case SDL_KEYDOWN:

            if (event.key.keysym.sym == SDLK_UP) {
                // MenuState::player->movePlayerUp();
                MenuState::pressedArrow[UP] = true;

            } else if (event.key.keysym.sym == SDLK_RIGHT) {
                // MenuState::player->movePlayerRight();
                MenuState::pressedArrow[RIGHT] = true;

            } else if (event.key.keysym.sym == SDLK_DOWN) {
                // MenuState::player->movePlayerDown();
                MenuState::pressedArrow[DOWN] = true;

            } else if (event.key.keysym.sym == SDLK_LEFT) {
                // MenuState::player->movePlayerLeft();
                MenuState::pressedArrow[LEFT] = true;

            }
            break;
        case SDL_KEYUP:

            if (event.key.keysym.sym == SDLK_UP) {
                MenuState::pressedArrow[UP] = false;
            } else if (event.key.keysym.sym == SDLK_RIGHT) {
                MenuState::pressedArrow[RIGHT] = false;
            } else if (event.key.keysym.sym == SDLK_DOWN) {
                MenuState::pressedArrow[DOWN] = false;
            } else if (event.key.keysym.sym == SDLK_LEFT) {
                MenuState::pressedArrow[LEFT] = false;
            }
            break;
        default:
            break;
    }

}

void MenuState::handleMouseClick(std::unique_ptr<AbstractState>& state) {
    int x = 0, y = 0;
    if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
        int buttonLeftX = MenuState::startButton.getDRect().x;
        int buttonRightX = buttonLeftX + MenuState::startButton.getDRect().w;

        int buttonTopY = MenuState::startButton.getDRect().y;
        int buttonBottomY = buttonTopY + MenuState::startButton.getDRect().h;

        if (x >= buttonLeftX && x <= buttonRightX && y >= buttonTopY && y <= buttonBottomY) {

            state->transitionState(state, std::make_unique<IntroState>(renderer));
        }
        
    }
}

void MenuState::update() {
    MenuState::startButton.update();
    MenuState::handlePlayerMove();

    return;
}

void MenuState::handlePlayerMove() {
    float deltaTime = (SDL_GetTicks() - lastFrameTime) / 1000.0f;
    lastFrameTime = SDL_GetTicks();

    if (MenuState::pressedArrow[UP] && MenuState::pressedArrow[RIGHT]) {
        MenuState::player.movePlayerUpAndRight(deltaTime);
        MenuState::allObjs.moveAllObjectsDownAndLeft(deltaTime);
    } else if (MenuState::pressedArrow[UP] && MenuState::pressedArrow[LEFT]) {
        MenuState::player.movePlayerUpAndLeft(deltaTime);
        MenuState::allObjs.moveAllObjectsDownAndRight(deltaTime);
    } else if (MenuState::pressedArrow[DOWN] && MenuState::pressedArrow[RIGHT]) {
        MenuState::player.movePlayerDownAndRight(deltaTime);
        MenuState::allObjs.moveAllObjectsUpAndLeft(deltaTime);
    } else if (MenuState::pressedArrow[DOWN] && MenuState::pressedArrow[LEFT]) {
        MenuState::player.movePlayerDownAndLeft(deltaTime);
        MenuState::allObjs.moveAllObjectsUpAndRight(deltaTime);
    } else if (MenuState::pressedArrow[UP]) {
        MenuState::player.movePlayerUp(deltaTime);
        MenuState::allObjs.moveAllObjectsDown(deltaTime);
    } else if (MenuState::pressedArrow[RIGHT]) {
        MenuState::player.movePlayerRight(deltaTime);
        MenuState::allObjs.moveAllObjectsLeft(deltaTime);
    } else if (MenuState::pressedArrow[DOWN]) {
        MenuState::player.movePlayerDown(deltaTime);
        MenuState::allObjs.moveAllObjectsUp(deltaTime);
    } else if (MenuState::pressedArrow[LEFT]) {
        MenuState::player.movePlayerLeft(deltaTime);
        MenuState::allObjs.moveAllObjectsRight(deltaTime);
    }
}

void MenuState::render() {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
    MenuState::startButton.draw();
    MenuState::player.render();
    MenuState::allObjs.renderAllObjects();
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
    MenuState::startButton = Button(renderer, sRect, dRect);

    
    // Update screen
    SDL_RenderPresent( renderer );
    return true;
}

void MenuState::onExit() {
    MenuState::startButton.destroyButton();
    MenuState::allObjs.freeMemory();
}

std::string MenuState::getStateID() {
    return "MENU";
}