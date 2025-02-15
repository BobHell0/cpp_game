#include "../../headerFiles/states/AbstractState.hpp"

void AbstractState::transitionState(std::unique_ptr<AbstractState>& currState, std::unique_ptr<AbstractState> newState) {
    currState->onExit();

    currState = std::move(newState);

    // trying to access new state fails because the move function 
    // std::cout << "trying to access new state stuff" << newState->getStateID() << "\n";
    currState->onEnter();
}
