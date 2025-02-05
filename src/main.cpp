#include <iostream>
#include <SDL2/SDL.h>
#include "./constants.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
bool gameIsRunning = false;

bool initiialise_window(void) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(
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

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return false;
    }
    std::cout << "Renderer created successfully" << std::endl;
    return true;
}



void setup() {
}

void process_input() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                gameIsRunning = false;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    gameIsRunning = false;
                }
                break;
        }
    }
}


void update() {
    
}

void render() {
}

void destroy_window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main() {
    gameIsRunning = initiialise_window();

    setup(); // TODO: Implement this function

    while (gameIsRunning) {
        process_input(); // TODO: Implement this function
        update(); // TODO: Implement this function
        render(); // TODO: Implement this function

    }

    return 0;

}