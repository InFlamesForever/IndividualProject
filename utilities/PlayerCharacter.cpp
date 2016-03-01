#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter() {
    //Initialize the position at the middle of the screen and in the middle
    // of a square
    mPosX = SCREEN_WIDTH/2 + 8;
    mPosY = SCREEN_HEIGHT/2;

    dir = 0;
    hasMoved = false;
}

void PlayerCharacter::render() {
    if(isMoving){
        hasMoved = true;
        lastDir = dir;
        //Flips the texture when moving left
        if(dir == LEFT){
            playerMoving[dir]->render((int)mPosX,(int)mPosY, NULL, 0.0, NULL, SDL_FLIP_HORIZONTAL);
        } else {
            playerMoving[dir]->render((int)mPosX,(int)mPosY);
        }
    } else {
        //For walking animation
        if(hasMoved){
            hasMoved = false;
            if(lastDir == DOWN){
                if(playerMoving[DOWN] == &gStock_Front_Walking1){
                    playerMoving[DOWN] = &gStock_Front_Walking2;
                } else {
                    playerMoving[DOWN] = &gStock_Front_Walking1;
                }
            } else if(lastDir == UP){
                if(playerMoving[UP] == &gStock_Back_Walking1){
                    playerMoving[UP] = &gStock_Back_Walking2;
                } else {
                    playerMoving[UP] = &gStock_Back_Walking1;
                }
            } else if(lastDir == LEFT || lastDir == RIGHT){
                if(playerMoving[lastDir] == &gStock_Side_Right_Walking){
                    playerMoving[lastDir] = &gStock_Side_Right_Walking2;
                } else if(playerMoving[lastDir] == &gStock_Side_Right_Walking2){
                    playerMoving[lastDir] = &gStock_Side_Right_Walking3;
                } else {
                    playerMoving[lastDir] = &gStock_Side_Right_Walking;
                }
            }

        }
        //Flips the texture when moving left
        if(dir == LEFT){
            playerStationary[dir]->render((int)mPosX,(int)mPosY, NULL, 0.0, NULL, SDL_FLIP_HORIZONTAL);
        } else {
            playerStationary[dir]->render((int)mPosX,(int)mPosY);
        }
    }

}

void PlayerCharacter::updateRender(bool isMoving, int dir) {
    this->isMoving = isMoving;
    this->dir = dir;

}
