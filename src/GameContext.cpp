#include <iostream>
#include <SDL2/SDL.h>

#include "./headerFiles/GameContext.hpp"

bool GameContext::initialise_window(SDL_Window **window, SDL_Renderer **renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    *window = SDL_CreateWindow(
        "Following a tutorial",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_BORDERLESS
    );
    if (window == NULL) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return false;
    }
    std::cout << "Window created successfully" << std::endl;

    *renderer = SDL_CreateRenderer(*window, -1, 0);
    if (renderer == NULL) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return false;
    }
    std::cout << "Renderer created successfully" << std::endl;
    return true;
}

void GameContext::global_process_input(bool *gameIsRunning, AbstractState **state) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                *gameIsRunning = false;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    *gameIsRunning = false;
                }
                break;
            default:
                (*state)->process_input(event, state);
                break;
        }
    }
}


void GameContext::update(int *lastFrameTime) {
    // float delta_time = (SDL_GetTicks() - *lastFrameTime) / 1000.0f;
    
    *lastFrameTime = SDL_GetTicks(); // Set the lastFrameTime to the current time.
}

void GameContext::destroy_window(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int GameContext::launchGame() {
    // variables required for basic SDL setup and loop
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    bool gameIsRunning = false;
    // int lastFrameTime = 0;

    gameIsRunning = GameContext::initialise_window(&window, &renderer);

    AbstractState *state = new MenuState(window, renderer);

    state->onEnter();

    while (gameIsRunning) {
        GameContext::global_process_input(&gameIsRunning, &state);
        state->update();
        state->render();

    }

    state->onExit();

    destroy_window(window, renderer);
    return 0;
}