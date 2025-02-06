#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include <string>
#include <SDL2/SDL.h>

class MenuState {
public:
    SDL_Texture *coverTexture;

    void update();
    void render(SDL_Renderer *renderer);
    bool onEnter(SDL_Window *window, SDL_Renderer *renderer);
    void onExit();
    std::string getStateID();
private:
    bool loadMedia(SDL_Window *window);
};

#endif // MENUSTATE_HPP