#ifndef ABSTRACTCOLLISIONSTRATEGY_HPP
#define ABSTRACTCOLLISIONSTRATEGY_HPP
#include <SDL2/SDL.h>

struct ObjectPositionInfo {
    float x;
    float y;
    SDL_FRect dRect;
};

class AbstractCollisionStrategy {
public:
    virtual bool playerMovesUpCollisionCheck(ObjectPositionInfo info) = 0;
    virtual bool playerMovesDownCollisionCheck(ObjectPositionInfo info) = 0;
    virtual bool playerMovesLeftCollisionCheck(ObjectPositionInfo info) = 0;
    virtual bool playerMovesRightCollisionCheck(ObjectPositionInfo info) = 0;
};

#endif
