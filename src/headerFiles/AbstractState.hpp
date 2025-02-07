#ifndef ABSTRACTSTATE_HPP
#define ABSTRACTSTATE_HPP

#include <SDL2/SDL.h>
#include <iostream>

class AbstractState {
public:
    virtual void process_input(SDL_Event event, AbstractState **state) = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual bool onEnter() = 0;
    virtual void onExit() = 0;
    virtual std::string getStateID() = 0;
};

#endif