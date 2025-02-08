#include <SDL2/SDL.h>
#include "./states/AbstractState.hpp"
#include "./constants.hpp"
#include "./states/MenuState.hpp"
#include "./states/AbstractState.hpp"

class GameContext {
private:
    bool initialise_window(SDL_Window **window, SDL_Renderer **renderer);
    void global_process_input(bool *gameIsRunning, AbstractState **state);
    void update(int *lastFrameTime);
    void destroy_window(SDL_Window *window, SDL_Renderer *renderer);

public:    
    int launchGame();
    AbstractState *currState;

};