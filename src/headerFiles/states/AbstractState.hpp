#ifndef ABSTRACTSTATE_HPP
#define ABSTRACTSTATE_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include "../AllEnvironmentObjects.hpp"

class AbstractState {
public:
    virtual void process_input(SDL_Event event, std::unique_ptr<AbstractState>& state) = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual bool onEnter() = 0;
    virtual void onExit() = 0;
    
    virtual std::string getStateID() = 0;
    /**
     * currState refers to the address of the currState pointer stored in gameContext instance
     * newState is a pointer to the new state
     */
    void transitionState(std::unique_ptr<AbstractState>& currState, std::unique_ptr<AbstractState> newState);

    virtual ~AbstractState() {};
};

#endif