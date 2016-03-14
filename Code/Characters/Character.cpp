//
// Created by richard on 11/03/16.
//

#include "Character.h"

Character::Character(int posX, int posY) {
    terrainPosX = posX;
    terrainPosY = posY;
}

void Character::setVars(int healthPts, int level, int attackPts, int defencePts) {
    this->healthPts = healthPts;
    this->level = level;
    this->attackPts = attackPts;
    this->defencePts = defencePts;

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
    }
    return false;
}

void Character::hit(int damage) {
    healthPts -= (damage - defencePts / 2);
    cout << healthPts << endl;

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
