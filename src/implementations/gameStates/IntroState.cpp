#include "../../headerFiles/states/IntroState.hpp"

IntroState::IntroState(SDL_Window *window, SDL_Renderer *renderer) {
    IntroState::window = window;
    IntroState::renderer = renderer;
}

void IntroState::process_input(SDL_Event event, AbstractState **state)
{
}

void IntroState::update() {
}

void IntroState::render() {
    SDL_SetRenderDrawColor(IntroState::renderer, 255, 255, 0, 255);
    SDL_RenderClear(IntroState::renderer);
    SDL_RenderPresent(IntroState::renderer);
}

bool IntroState::onEnter() {
    SDL_SetRenderDrawColor(IntroState::renderer, 255, 255, 0, 255);
    SDL_RenderClear(IntroState::renderer);
    SDL_RenderPresent(IntroState::renderer);
    std::cout << "I AM HERE!!!\n";
    return true;
}

void IntroState::onExit() {
}

std::string IntroState::getStateID() {
    return "INTRO";
}
