#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include <SDL2/SDL.h>
#include <iostream>

class MenuState {
public:
    SDL_Texture *coverTexture;

    void process_input(SDL_Event event);
    void update();
    void render(SDL_Renderer *renderer);
    bool onEnter(SDL_Window *window, SDL_Renderer *renderer);
    void onExit();
    std::string getStateID();
private:
    bool loadMedia(SDL_Renderer *renderer);
    void handleMouseClick();
};

#endif // MENUSTATE_HPP