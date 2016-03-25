//
// Created by richard on 11/03/16.
//

#include "EnemyCharacter.h"


EnemyCharacter::EnemyCharacter(int posX, int posY) :
        Character (posX, posY) {
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

            AStarSearch search(terrain);
            shared_ptr<TerrainNode> temp(search.aStarSearch(
                    terrainPosX, terrainPosY,
                    player.getPosX(), player.getPosY(),
                    getCantTraverse(), getCantTraverseSize()));
            while (temp->getPrevNode()->getPrevNode() != NULL) {
                temp = temp->getPrevNode();
            }
            if (temp->getX() == terrainPosX - 1
                && temp->getY() == terrainPosY) {
                dir = LEFT;
                isMoving = true;
            } else if (temp->getX() == terrainPosX + 1
                       && temp->getY() == terrainPosY) {
                dir = RIGHT;
                isMoving = true;
            } else if (temp->getY() == terrainPosY - 1
                       && temp->getX() == terrainPosX) {
                dir = UP;
                isMoving = true;
            } else if (temp->getY() == terrainPosY + 1
                       && temp->getX() == terrainPosX) {
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
                    default:
                        break;
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