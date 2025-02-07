#include <iostream>
#include <SDL2/SDL.h>
#include "./headerFiles/constants.hpp"
struct gameObject {
    float x;
    float y;
    float width;
    float height;
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
    // int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - lastFrameTime);
    // if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME) {
    //     SDL_Delay(time_to_wait);
    // } 
    // float delta_time = (SDL_GetTicks() - lastFrameTime) / 1000.0f;
    
    // lastFrameTime = SDL_GetTicks(); // Set the lastFrameTime to the current time.
    
    // player.x += 20.0 * delta_time;
    // player.y += 60.0 * delta_time; 
}

void render() {
    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
    SDL_RenderClear(renderer);      // clear the window to the draw color

    // SDL_Rect rect = {player.x, player.y, player.width, player.height};
    // SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    // SDL_RenderFillRect(renderer, &rect); // draw the rectangle
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
        process_input();
        update();
        render();
    }

    destroy_window();
    return 0;
}