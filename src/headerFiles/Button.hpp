#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "./structs/rgba.hpp"
#include <SDL2/SDL.h>
#include <iostream>

class Button {
    private: 
        SDL_Renderer *renderer;
        struct rgba colour;
        struct rgba hoverColour;
        struct rgba clickColour;
        SDL_Rect rect;
        SDL_Texture *texture;
        SDL_Rect sRect, dRect;
        bool isHovered;
    
    public:
        Button(SDL_Renderer *renderer, SDL_Rect sRect, SDL_Rect dRect);

        void update();
        void draw();

};

#endif // BUTTON_HPP