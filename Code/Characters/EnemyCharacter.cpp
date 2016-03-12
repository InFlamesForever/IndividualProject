//
// Created by richard on 11/03/16.
//

#include "EnemyCharacter.h"

EnemyCharacter::EnemyCharacter(int playerLevel, bool isBoss,
                               int posX, int posY) :
        Character (posX, posY) {
    int level = playerLevel + randInteger(-2, 2);
    int health;
    int attack;
    int defence;

    if(isBoss) {
        health = 1000 + 100 * level;
        attack = 100 + 50 * level;
        defence = 250 + 50 * level;
        moveSpeed = level;
    } else {
        health = 100 + 10 * level;
        attack = 10 + 5 * level;
        defence = 25 + 5 * level;
        moveSpeed = 10 + level;
    }
    setVars(health, level, attack, defence);

    state = Normal;
}

void EnemyCharacter::setTextures(Texture **texts) {
    textures[0] = texts[0];
    textures[1] = texts[1];
    textures[2] = texts[2];

}

void EnemyCharacter::render(int screenPosX, int screenPosY) {
    if(isOnScreen(screenPosX, screenPosY)) {
        textures[state]->render(
                (terrainPosX - screenPosX) * BLOCK_WIDTH -
                        BLOCK_WIDTH/2 + (int)movingOffsetX,
                (terrainPosY - screenPosY - 1) * BLOCK_WIDTH -
                        BLOCK_WIDTH/2 + (int)movingOffsetY);
    }

}

void EnemyCharacter::move(int dir, float timeStep) {
    if(isMoving) {
        switch (dir) {
            case UP:
                movingOffsetY += -BLOCK_WIDTH * moveSpeed * timeStep;
                break;
            case DOWN:
                movingOffsetY += BLOCK_WIDTH * moveSpeed * timeStep;
                break;
            case LEFT:
                movingOffsetX += -BLOCK_WIDTH * moveSpeed * timeStep;
                break;
            case RIGHT:
                movingOffsetX += BLOCK_WIDTH * moveSpeed * timeStep;
                break;
        }
        if (movingOffsetX >= BLOCK_WIDTH || movingOffsetX <= -BLOCK_WIDTH
            || movingOffsetY >= BLOCK_WIDTH || movingOffsetY <= -BLOCK_WIDTH) {
            if(movingOffsetX >= BLOCK_WIDTH){
                terrainPosX++;
            } else if(movingOffsetX <= -BLOCK_WIDTH) {
                terrainPosX--;
            } else if(movingOffsetY >= BLOCK_WIDTH) {
                terrainPosY++;
            } else if(movingOffsetY <= -BLOCK_WIDTH) {
                terrainPosY--;
            }

            isMoving = false;
            movingOffsetX = 0;
            movingOffsetY = 0;
        }
    }
}

void EnemyCharacter::chooseMove(int playerPosX, int playerPosY, float timeStep) {
    isMoving = true;
    move(UP, timeStep);
}
