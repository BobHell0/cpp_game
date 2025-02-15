#ifndef INTROSTATE_HPP
#define INTROSTATE_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include "AbstractState.hpp"

class IntroState : public AbstractState {
public:
    IntroState(SDL_Renderer* renderer);
    void process_input(SDL_Event event, std::unique_ptr<AbstractState>& state);
    void update();
    void render();
    bool onEnter();
    void onExit();
    std::string getStateID();
private:
    SDL_Renderer* renderer;
};

#endif