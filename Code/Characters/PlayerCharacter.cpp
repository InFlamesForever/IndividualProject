#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter(int posX, int posY, int screenPosX, int screenPosY)
        : Character(posX, posY) {
    this->screenPosX = (terrainPosX - screenPosX) * BLOCK_WIDTH - BLOCK_WIDTH/2;
    this->screenPosY = (terrainPosY - screenPosY - 1) * BLOCK_WIDTH - BLOCK_WIDTH/2;


    dir = 0;
    hasMoved = false;

    setVars(100, 1, 20, 20);
}

void PlayerCharacter::render() {
    if(isMoving){
        hasMoved = true;
        lastDir = dir;
        //Flips the texture when moving left
        if(dir == LEFT){
            playerMoving[dir]->render((int) screenPosX, (int) screenPosY, NULL, 0.0, NULL, SDL_FLIP_HORIZONTAL);
        } else {
            playerMoving[dir]->render((int) screenPosX, (int) screenPosY);
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

                //The player has moved down in the map by 1 square
                terrainPosY++;
            } else if(lastDir == UP){
                if(playerMoving[UP] == &gStock_Back_Walking1){
                    playerMoving[UP] = &gStock_Back_Walking2;
                } else {
                    playerMoving[UP] = &gStock_Back_Walking1;
                }

                //The player has moved up in the map by 1 square
                terrainPosY--;
            } else if(lastDir == LEFT || lastDir == RIGHT){
                if(playerMoving[lastDir] == &gStock_Side_Right_Walking){
                    playerMoving[lastDir] = &gStock_Side_Right_Walking2;
                } else if(playerMoving[lastDir] == &gStock_Side_Right_Walking2){
                    playerMoving[lastDir] = &gStock_Side_Right_Walking3;
                } else {
                    playerMoving[lastDir] = &gStock_Side_Right_Walking;
                }

                //The player has moved left or right
                lastDir == LEFT ? terrainPosX-- : terrainPosX++;
            }

        }
        //Flips the texture when moving left
        if(dir == LEFT){
            playerStationary[dir]->render((int) screenPosX, (int) screenPosY, NULL, 0.0, NULL, SDL_FLIP_HORIZONTAL);
        } else {
            playerStationary[dir]->render((int) screenPosX, (int) screenPosY);
        }
    }

}

void PlayerCharacter::updateRender(bool isMoving, int dir) {
    this->isMoving = isMoving;
    this->dir = dir;

}
