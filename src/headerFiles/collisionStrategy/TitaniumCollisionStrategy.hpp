#ifndef TITANIUMCOLLISIONSTRATEGY_HPP
#define TITANIUMCOLLISIONSTRATEGY_HPP

#include "AbstractCollisionStrategy.hpp"
#include "../constants.hpp"
class TitaniumCollisionStrategy : public AbstractCollisionStrategy {
    
public:
    bool playerMovesUpCollisionCheck(ObjectPositionInfo info);
    bool playerMovesDownCollisionCheck(ObjectPositionInfo info);
    bool playerMovesLeftCollisionCheck(ObjectPositionInfo info);
    bool playerMovesRightCollisionCheck(ObjectPositionInfo info);

};

#endif
