#include "../../headerFiles/IntroState.hpp"

IntroState::IntroState(SDL_Renderer *renderer) {
    IntroState::renderer = renderer;
}

void IntroState::process_input(SDL_Event event)
{
}

void IntroState::update() {
}

void IntroState::render() {

}

bool IntroState::onEnter(SDL_Window *window) {
    SDL_SetRenderDrawColor(IntroState::renderer, 255, 255, 0, 255);
    SDL_RenderClear(IntroState::renderer);
    SDL_RenderPresent(IntroState::renderer);
    return true;
}

void IntroState::onExit() {
}

std::string IntroState::getStateID() {
    return "INTRO";
}
