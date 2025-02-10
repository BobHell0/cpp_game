#include "../../headerFiles/collisionStrategy/TitaniumCollisionStrategy.hpp"

bool TitaniumCollisionStrategy::playerMovesUpCollisionCheck(ObjectPositionInfo info) {
    float objectBottomLeftX = info.x + PLAYER_POS_X;
    float objectBottomLeftY = info.y + PLAYER_POS_Y + info.dRect.h;

    float objectBottomRightX = info.x + PLAYER_POS_X + info.dRect.w;

    float playerTopLeftX = PLAYER_POS_X;
    float playerTopLeftY = PLAYER_POS_Y;

    float playerTopRightX = PLAYER_POS_X + PLAYER_SIDE_LENGTH;

    return (objectBottomRightX > playerTopLeftX) 
        && (objectBottomLeftX < playerTopRightX) 
        && (abs(objectBottomLeftY - playerTopLeftY) < COLLISION_BUFFER);
}

bool TitaniumCollisionStrategy::playerMovesDownCollisionCheck(ObjectPositionInfo info) {
    float objectTopLeftX = info.x + PLAYER_POS_X;
    float objectTopLeftY = info.y + PLAYER_POS_Y;

    float objectTopRightX = info.x + PLAYER_POS_X + info.dRect.w;

    float playerBottomLeftX = PLAYER_POS_X;
    float playerBottomLeftY = PLAYER_POS_Y + PLAYER_SIDE_LENGTH;

    float playerBottomRightX = PLAYER_POS_X + PLAYER_SIDE_LENGTH;

    return (objectTopRightX > playerBottomLeftX) 
        && (objectTopLeftX < playerBottomRightX) 
        && (abs(objectTopLeftY - playerBottomLeftY) < COLLISION_BUFFER);

}

bool TitaniumCollisionStrategy::playerMovesLeftCollisionCheck(ObjectPositionInfo info) {
    float objectTopRightX = info.x + PLAYER_POS_X + info.dRect.w;
    float objectTopRightY = info.y + PLAYER_POS_Y;

    float objectBottomRightY = info.y + PLAYER_POS_Y + info.dRect.h;

    float playerBottomLeftX = PLAYER_POS_X;
    float playerBottomLeftY = PLAYER_POS_Y + PLAYER_SIDE_LENGTH;

    float playerTopLeftY = PLAYER_POS_Y;

    return (objectTopRightY < playerBottomLeftY) 
        && (objectBottomRightY > playerTopLeftY) 
        && (abs(objectTopRightX - playerBottomLeftX) < COLLISION_BUFFER);
}

bool TitaniumCollisionStrategy::playerMovesRightCollisionCheck(ObjectPositionInfo info) {
    float objectTopLeftX = info.x + PLAYER_POS_X;
    float objectTopLeftY = info.y + PLAYER_POS_Y;

    float objectBottomLeftY = info.y + PLAYER_POS_Y + info.dRect.h;

    float playerBottomRightX = PLAYER_POS_X + PLAYER_SIDE_LENGTH;
    float playerBottomRightY = PLAYER_POS_Y + PLAYER_SIDE_LENGTH;

    float playerTopRightY = PLAYER_POS_Y;

    return (objectTopLeftY < playerBottomRightY) 
        && (objectBottomLeftY > playerTopRightY) 
        && (abs(objectTopLeftX - playerBottomRightX) < COLLISION_BUFFER);
}
