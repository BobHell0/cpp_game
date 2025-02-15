#include "../../headerFiles/collisionStrategy/MirageCollisionStrategy.hpp"
bool MirageCollisionStrategy::playerMovesUpCollisionCheck(ObjectPositionInfo info) {
    return false;
}
bool MirageCollisionStrategy::playerMovesDownCollisionCheck(ObjectPositionInfo info) {
    return false;
}
bool MirageCollisionStrategy::playerMovesLeftCollisionCheck(ObjectPositionInfo info) {
    return false;
}
bool MirageCollisionStrategy::playerMovesRightCollisionCheck(ObjectPositionInfo info) {
    return false;
}

std::string MirageCollisionStrategy::getStratId() {
    return "Mirage Collision Strategy";
}