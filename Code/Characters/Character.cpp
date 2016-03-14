//
// Created by richard on 11/03/16.
//

#include "Character.h"

Character::Character(int posX, int posY) {
    terrainPosX = posX;
    terrainPosY = posY;

    isAlive = true;
}

void Character::setVars(int playerLevel, bool isBoss, int BASE_HEALTH,
                        int BASE_ATTACK, int BASE_DEFENCE, int BASE_MOVE_SPEED,
                        int BASE_EXP,
                        int MULTIPLIER_HEALTH, int MULTIPLIER_ATTACK,
                        int MULTIPLIER_DEFENCE, int MULTIPLIER_EXP) {
    level = playerLevel + randInteger(-2, 2);
    //Lowest level is 1 and highest is 100
    if(level < 1) {
        level = 1;
    } else if(level > 100){
        level = 100;
    }
    healthPts;
    attackPts;
    defencePts;

    if(isBoss) {
        healthPts = BASE_HEALTH * 10 + MULTIPLIER_HEALTH * 10 * level;
        attackPts = BASE_ATTACK * 10 + MULTIPLIER_ATTACK * 10 * level;
        defencePts = BASE_DEFENCE * 10 + MULTIPLIER_DEFENCE * 10 * level;
        expPointsWorth = BASE_EXP * 10 + MULTIPLIER_EXP * 10 * level;
        moveSpeed = level;
    } else {
        healthPts = BASE_HEALTH + MULTIPLIER_HEALTH * level;
        attackPts = BASE_ATTACK + MULTIPLIER_ATTACK * level;
        defencePts = BASE_DEFENCE + MULTIPLIER_DEFENCE * level;
        expPointsWorth = BASE_EXP + MULTIPLIER_EXP * level;
        moveSpeed = BASE_MOVE_SPEED + level;
    }
}

void Character::setVars(int health, int level, int attack, int defence) {
    healthPts = health;
    this->level = level;
    attackPts = attack;
    defencePts = defence;
}


bool Character::isOnScreen(int screenPosX, int screenPosY) {
    return terrainPosX >= screenPosX
            && terrainPosX <= screenPosX + SCREEN_WIDTH/BLOCK_WIDTH
            && terrainPosY >= screenPosY
            && terrainPosY <= screenPosY + SCREEN_HEIGHT/BLOCK_WIDTH;

}

void Character::printOut() {
    cout << "level: " << level << " health: " << healthPts <<
    " Attack: " << attackPts << " Defence: " << defencePts << endl;
}

int Character::getCantTraverseSize() {
    return cantTraverseSize;
}

int *Character::getCantTraverse() {
    return cantTraverse;
}

int Character::getPosX() {
    return terrainPosX;
}

int Character::getPosY() {
    return terrainPosY;
}

bool Character::hitDetection(Character enemy) {
    switch(dir){
        case UP:
            return enemy.getPosX() == terrainPosX && enemy.getPosY() == terrainPosY - 1;
        case DOWN:
            return enemy.getPosX() == terrainPosX && enemy.getPosY() == terrainPosY + 1;
        case LEFT:
            return enemy.getPosX() == terrainPosX - 1 && enemy.getPosY() == terrainPosY;
        case RIGHT:
            return enemy.getPosX() == terrainPosX + 1 && enemy.getPosY() == terrainPosY;
        default:break;
    }
    return false;
}

bool Character::hit(int damage) {
    int d = (damage - defencePts / 2);
    if(d < 5) d = 5;
    healthPts -= d;
    if(healthPts <= 0){
        isAlive = false;
    }
    return isAlive;

}

int Character::getHealthPts() {
    return healthPts;
}

int Character::getLevel() {
    return level;
}

int Character::getDefencePts() {
    return defencePts;
}

int Character::getAttackPts() {
    return attackPts;
}

Timer *Character::getAttackTimer() {
    return &attackTimer;
}

int Character::getIsAlive() {
    return isAlive;
}

int Character::getMoveSpeed() {
    return moveSpeed;
}

/*
Character &Character::operator=(Character &&other) {
    if(this != &other) {
        isAlive = other.isAlive;

        level = other.level;
        attackPts = other.attackPts;
        defencePts = other.defencePts;
        healthPts = other.healthPts;
        expPointsWorth = other.expPointsWorth;

        moveSpeed = other.moveSpeed;

        //Stores the time since the last attack
        attackTimer = other.attackTimer;

        terrainPosX = other.terrainPosX;
        terrainPosY = other.terrainPosY;
        dir = other.dir;
    }
    
    return *this;
}
*/