#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include "Button.hpp"
#include "AbstractState.hpp"


class MenuState : public AbstractState {
public:
    MenuState(SDL_Renderer *renderer);

    void process_input(SDL_Event event);
    void update();
    void render();
    bool onEnter(SDL_Window *window);
    void onExit();
    std::string getStateID();

private:
    bool loadMedia();
    void handleMouseClick();

    SDL_Renderer *renderer;
    SDL_Texture *coverTexture;
    Button *startButton;
};

#endif // MENUSTATE_HPP