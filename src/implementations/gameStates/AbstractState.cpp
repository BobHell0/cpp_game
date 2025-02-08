#include "../../headerFiles/states/AbstractState.hpp"

void AbstractState::transitionState(AbstractState **currState, AbstractState *newState) {
    (*currState)->onExit();
    AbstractState *tempDelete = *currState;
    *currState = newState;
    delete tempDelete;
    (*currState)->onEnter();
}
