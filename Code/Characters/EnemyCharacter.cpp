//
// Created by richard on 11/03/16.
//

#include "EnemyCharacter.h"


EnemyCharacter::EnemyCharacter(int posX, int posY) :
        Character (posX, posY) {
    state = Normal;
    isMoving = false;
    dir = LEFT;

    playerLastPosX = -1;
    playerLastPosY = -1;
}

void EnemyCharacter::setTextures(Texture **texts) {
    textures[0] = texts[0];
    textures[1] = texts[1];
    textures[2] = texts[2];

}

void EnemyCharacter::render(int screenPosX, int screenPosY,
                            int offsetX, int offsetY) {
    if(isOnScreen(screenPosX, screenPosY)) {
        if(state == Attack) {
            if (attackAniTimer.getTicks() > 100) {
                state = Angry;
            }
        }
        int x = (terrainPosX - screenPosX) * BLOCK_WIDTH -
                BLOCK_WIDTH/2 + (int)movingOffsetX + offsetX;
        int y = (terrainPosY - screenPosY - 1) * BLOCK_WIDTH -
                BLOCK_WIDTH/2 + (int)movingOffsetY + offsetY;
        textures[state]->render(x,y);
        renderHealthBar(getHealthPts(), x, y);
    }
}

void EnemyCharacter::move(float timeStep) {
    int speed;
    if(state == Angry || state == Attack) {
        speed = getMoveSpeed();
    } else {
        speed = 2;
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

void EnemyCharacter::chooseMove(PlayerCharacter player, int **terrain) {
    if (!isMoving) {
        if (terrainPosX - player.getPosX() < withinAttackRange
            && terrainPosX - player.getPosX() > -withinAttackRange
            && terrainPosY - player.getPosY() < withinAttackRange
            && terrainPosY - player.getPosY() > -withinAttackRange) {
            if(playerLastPosX != player.getPosX() && 
                    playerLastPosY != player.getPosY()) {
                
                //Set the players last position
                playerLastPosX = player.getPosX();
                playerLastPosY = player.getPosY();
                
                //Search for the best path
                AStarSearch search(terrain);
                movementPath = search.aStarSearch(
                        terrainPosX, terrainPosY,
                        player.getPosX(), player.getPosY(),
                        getCantTraverse(), getCantTraverseSize());
            }
            //Go to the second to last node, which is the next move for the 
            // character
            shared_ptr<TerrainNode> secondToLastNode = movementPath;
            while (secondToLastNode->getPrevNode()->getPrevNode()->getPrevNode() != NULL) {
                secondToLastNode = secondToLastNode->getPrevNode();
            }
            shared_ptr<TerrainNode> lastNode = secondToLastNode->getPrevNode();
            if (lastNode->getX() == terrainPosX - 1
                && lastNode->getY() == terrainPosY) {
                dir = LEFT;
                isMoving = true;
            } else if (lastNode->getX() == terrainPosX + 1
                       && lastNode->getY() == terrainPosY) {
                dir = RIGHT;
                isMoving = true;
            } else if (lastNode->getY() == terrainPosY - 1
                       && lastNode->getX() == terrainPosX) {
                dir = UP;
                isMoving = true;
            } else if (lastNode->getY() == terrainPosY + 1
                       && lastNode->getX() == terrainPosX) {
                dir = DOWN;
                isMoving = true;
            } else {
                isMoving = false;
            }
            state = Angry;
            secondToLastNode->setPreNodeToNULL();

        } else {
            state = Normal;
            dir = randInteger(0, 3);
            isMoving = true;

            for (int i = 0; i < getCantTraverseSize(); i++) {
                switch (dir) {
                    case UP:
                        if (terrain[terrainPosX][terrainPosY - 1] ==
                            getCantTraverse()[i]) {
                            isMoving = false;
                        }
                        break;
                    case DOWN:
                        if (terrain[terrainPosX][terrainPosY + 1] ==
                            getCantTraverse()[i]) {
                            isMoving = false;
                        }
                        break;
                    case LEFT:
                        if (terrain[terrainPosX - 1][terrainPosY] ==
                            getCantTraverse()[i]) {
                            isMoving = false;
                        }
                        break;
                    case RIGHT:
                        if (terrain[terrainPosX + 1][terrainPosY] ==
                            getCantTraverse()[i]) {
                            isMoving = false;
                        }
                        break;
                    default:break;
                }
            }
        }
    }
}

void EnemyCharacter::attack(Character* other) {
    if(hitDetection(*other)){
        if(!getAttackTimer()->isStarted()
           || getAttackTimer()->getTicks() > ATTACKDELAY){
            other->hit(getAttackPts());
            state = Attack;
            attackAniTimer.reset();
            attackAniTimer.start();
            getAttackTimer()->reset();
            getAttackTimer()->start();
        }
    }
}
/*

EnemyCharacter &EnemyCharacter::operator=(EnemyCharacter &&other) {
    Character::operator=(std::move(other));
    textures[0] = other.textures[0];
    textures[1] = other.textures[1];
    textures[2] = other.textures[2];

    state = other.state;

    movingOffsetY = other.movingOffsetY;
    movingOffsetX = other.movingOffsetX;
    isMoving = other.isMoving;

    attackAniTimer = other.attackAniTimer;

    return *this;
}
*/