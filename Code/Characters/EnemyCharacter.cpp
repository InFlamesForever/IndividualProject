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
    } else {
        health = 100 + 10 * level;
        attack = 10 + 5 * level;
        defence = 25 + 5 * level;
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
        textures[state]->render((terrainPosX - screenPosX) * BLOCK_WIDTH,
                                (terrainPosY - screenPosY) * BLOCK_WIDTH);
    }

}
