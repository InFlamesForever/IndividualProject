#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter(int posX, int posY, int screenPosX, int screenPosY)
        : Character(posX, posY) {
    this->screenPosX = (terrainPosX - screenPosX) * BLOCK_WIDTH - BLOCK_WIDTH/2;
    this->screenPosY = (terrainPosY - screenPosY - 1) * BLOCK_WIDTH - BLOCK_WIDTH/2;


    dir = 0;
    exp = 0;
    hasMoved = false;

    int playerLevel = 1;
    bool isBoss = false;
    int BASE_HEALTH = 180;
    int BASE_ATTACK = 20;
    int BASE_DEFENCE = 20;
    int BASE_MOVE_SPEED = 10;
    int BASE_EXP = 0;

    int MULTIPLIER_HEALTH = 20;
    int MULTIPLIER_ATTACK = 10;
    int MULTIPLIER_DEFENCE = 10;
    int MULTIPLIER_EXP = 0;

    setVars(true,
            playerLevel, isBoss, BASE_HEALTH,
            BASE_ATTACK, BASE_DEFENCE, BASE_MOVE_SPEED,
            BASE_EXP,
            MULTIPLIER_HEALTH, MULTIPLIER_ATTACK,
            MULTIPLIER_DEFENCE, MULTIPLIER_EXP);

    regenerationAmount = 5;
}

void PlayerCharacter::render() {
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = BLOCK_WIDTH * 2;
    rect.h = BLOCK_WIDTH * 2;
    if(isMoving){
        hasMoved = true;
        lastDir = dir;
        //Flips the texture when moving left
        if(dir == LEFT){
            playerMoving[dir]->render((int) screenPosX, (int) screenPosY, &rect, 0.0, NULL, SDL_FLIP_HORIZONTAL);
        } else {
            playerMoving[dir]->render((int) screenPosX, (int) screenPosY, &rect);
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
            playerStationary[dir]->render((int) screenPosX, (int) screenPosY, &rect, 0.0, NULL, SDL_FLIP_HORIZONTAL);
        } else {
            playerStationary[dir]->render((int) screenPosX, (int) screenPosY, &rect);
        }
    }

}

void PlayerCharacter::updateRender(bool isMoving, int dir) {
    this->isMoving = isMoving;
    this->dir = dir;

}

bool PlayerCharacter::addExp(int exp) {
    this->exp += exp;
    if(this->exp >= BASE_LEVEL_UP_LINE * (getLevel()*3)){
        levelUp();
        return true;
    } else {
        return false;
    }
}

int PlayerCharacter::getExp() {
    return exp;
}

void PlayerCharacter::regenerate() {
    if(!healthRenegerator.isStarted()
       || healthRenegerator.getTicks() > REGENERATOR_DELAY){
        regenerateAmount(regenerationAmount);
        healthRenegerator.reset();
        healthRenegerator.start();
    }
}

void PlayerCharacter::changeZoom(int screenPosX, int screenPosY) {
    this->screenPosX = (terrainPosX - screenPosX) * BLOCK_WIDTH - BLOCK_WIDTH/2;
    this->screenPosY = (terrainPosY - screenPosY - 1) * BLOCK_WIDTH - BLOCK_WIDTH/2;
}
