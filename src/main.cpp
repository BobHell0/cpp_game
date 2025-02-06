#include <iostream>
#include <SDL2/SDL.h>
#include "./constants.h"
struct gameObject {
    int x;
    int y;
    int width;
    int height;
};

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
bool gameIsRunning = false;
int lastFrameTime = 0;

struct gameObject player = {
    0,
    0,
    20,
    20
};



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
    // waste time time until we reach the frame target time
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), lastFrameTime + FRAME_TARGET_TIME));
    lastFrameTime = SDL_GetTicks(); // Set the lastFrameTime to the current time.
    player.x += 2;
    player.y += 2; 
}

void render() {
    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
    SDL_RenderClear(renderer);      // clear the window to the draw color

    SDL_Rect rect = {player.x, player.y, player.width, player.height};
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &rect); // draw the rectangle
    SDL_RenderPresent(renderer);    // draw the new image to the window

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