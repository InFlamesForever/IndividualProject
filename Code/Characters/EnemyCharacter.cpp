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
    isMoving = false;
    dir = LEFT;
}

void EnemyCharacter::setTextures(Texture **texts) {
    textures[0] = texts[0];
    textures[1] = texts[1];
    textures[2] = texts[2];

}

void EnemyCharacter::render(int screenPosX, int screenPosY,
                            int offsetX, int offsetY) {
    if(isOnScreen(screenPosX, screenPosY)) {
        textures[state]->render(
                (terrainPosX - screenPosX) * BLOCK_WIDTH -
                        BLOCK_WIDTH/2 + (int)movingOffsetX + offsetX,
                (terrainPosY - screenPosY - 1) * BLOCK_WIDTH -
                        BLOCK_WIDTH/2 + (int)movingOffsetY + offsetY
        );
    }
}

void EnemyCharacter::move(float timeStep) {
    int speed;
    if(state == Angry) {
        speed = moveSpeed;
    } else {
        speed = 5;
    }
    if(isMoving) {
        switch (dir) {
            case UP:
                movingOffsetY += -BLOCK_WIDTH * speed * timeStep;
                break;
            case DOWN:
                movingOffsetY += BLOCK_WIDTH * speed * timeStep;
                break;
            case LEFT:
                movingOffsetX += -BLOCK_WIDTH * speed * timeStep;
                break;
            case RIGHT:
                movingOffsetX += BLOCK_WIDTH * speed * timeStep;
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

void EnemyCharacter::chooseMove(PlayerCharacter player,
                                float timeStep, int **terrain) {
    if (terrainPosX - player.getTerrainPosX() < withinRange 
        && terrainPosX - player.getTerrainPosX() > -withinRange
        && terrainPosY - player.getTerrainPosY() < withinRange 
        && terrainPosY - player.getTerrainPosY() > -withinRange) {
        if(!isMoving) {
            if (terrainPosX - player.getTerrainPosX() < withinAttackRange 
                && terrainPosX - player.getTerrainPosX() > -withinAttackRange
                && terrainPosY - player.getTerrainPosY() < withinAttackRange 
                && terrainPosY - player.getTerrainPosY() > -withinAttackRange) {
                AStarSearch search(terrain);
                shared_ptr<TerrainNode> temp(search.aStarSearch(
                        terrainPosX,terrainPosY,
                        player.getTerrainPosX(), player.getTerrainPosY(),
                        getCantTraverse(), getCantTraverseSize()));
                while(temp->getPrevNode()->getPrevNode() != NULL){
                    temp = temp->getPrevNode();
                }

                if(temp->getX() == terrainPosX - 1
                   && temp->getY() == terrainPosY){
                    dir = LEFT;
                    isMoving = true;
                } else if(temp->getX() == terrainPosX + 1
                          && temp->getY() == terrainPosY){
                    dir = RIGHT;
                    isMoving = true;
                } else if(temp->getY() == terrainPosY - 1
                          && temp->getX() == terrainPosX){
                    dir = UP;
                    isMoving = true;
                } else if(temp->getY() == terrainPosY + 1
                          && temp->getX() == terrainPosX){
                    dir = DOWN;
                    isMoving = true;
                } else {
                    isMoving = false;
                }
                state = Angry;

            } else {
                state = Normal;
                dir = randInteger(0, 3);
                isMoving = true;

                for(int i = 0; i < getCantTraverseSize(); i++) {
                    switch (dir) {
                        case UP:
                            if (terrain[terrainPosX][terrainPosY - 1] ==
                                    getCantTraverse()[i]){
                                isMoving = false;
                            }
                            break;
                        case DOWN:
                            if (terrain[terrainPosX][terrainPosY + 1] ==
                                    getCantTraverse()[i]){
                                isMoving = false;
                            }
                            break;
                        case LEFT:
                            if (terrain[terrainPosX - 1][terrainPosY] ==
                                    getCantTraverse()[i]){
                                isMoving = false;
                            }
                            break;
                        case RIGHT:
                            if (terrain[terrainPosX + 1][terrainPosY] ==
                                    getCantTraverse()[i]){
                                isMoving = false;
                            }
                            break;
                    }
                }
            }
        }
    }
}

bool EnemyCharacter::hitDetection(Character enemy) {
    switch(dir){
        case UP:
            if (enemy.getPosX() == terrainPosX && enemy.getPosY() == terrainPosY - 1){
                return false;
            }
            break;
        case DOWN:
            if (enemy.getPosX() == terrainPosX && enemy.getPosY() == terrainPosY + 1){
                return false;
            }
            break;
        case LEFT:
            if (enemy.getPosX() == terrainPosX - 1 && enemy.getPosY() == terrainPosY){
                return false;
            }
            break;
        case RIGHT:
            if (enemy.getPosX() == terrainPosX + 1 && enemy.getPosY() == terrainPosY - 1){
                return false;
            }
            break;
    }
    return false;
}
