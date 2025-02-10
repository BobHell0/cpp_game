#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include "../Button.hpp"
#include "AbstractState.hpp"
#include "IntroState.hpp"
#include "../constants.hpp"
#include "../Player.hpp"
#include "../EnvironmentObject.hpp"
#include "../AllEnvironmentObjects.hpp"

enum ARROW_KEYS {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
};

class MenuState : public AbstractState {
public:
    MenuState(SDL_Window *window, SDL_Renderer *renderer);

    void process_input(SDL_Event event, AbstractState **state);
    void update();
    void render();
    bool onEnter();
    void onExit();
    std::string getStateID();

private:
    bool loadMedia();
    void handleMouseClick(AbstractState **state);
    void handlePlayerMove();
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *coverTexture;
    
    Button *startButton;
    Player *player;
    EnvironmentObject *tree;
    AllEnvironmentObjects *allObjs;
    bool *pressedArrow;

    int lastFrameTime;
    
};

#endif // MENUSTATE_HPP