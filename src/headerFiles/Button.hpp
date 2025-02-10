#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SDL2/SDL.h>
#include <iostream>

class Button {
    private: 
        SDL_Renderer *renderer;
        SDL_Texture *texture;
        SDL_Rect sRect, dRect;
        bool isHovered;
    
    public:
        Button(SDL_Renderer *renderer, SDL_Rect sRect, SDL_Rect dRect);

        void update();
        void draw();
        void destroyButton();

        SDL_Rect getDRect();

};

#endif // BUTTON_HPP