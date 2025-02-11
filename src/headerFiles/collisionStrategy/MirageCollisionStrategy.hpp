#ifndef MIRAGECOLLISIONSTRATEGY_HPP
#define MIRAGECOLLISIONSTRATEGY_HPP

#include "AbstractCollisionStrategy.hpp"

class MirageCollisionStrategy : public AbstractCollisionStrategy {
    bool playerMovesUpCollisionCheck(ObjectPositionInfo info);
    bool playerMovesDownCollisionCheck(ObjectPositionInfo info);
    bool playerMovesLeftCollisionCheck(ObjectPositionInfo info);
    bool playerMovesRightCollisionCheck(ObjectPositionInfo info);

    std::string getStratId();
};

#endif