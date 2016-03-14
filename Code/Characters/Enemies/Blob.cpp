//
// Created by richard on 11/03/16.
//

#include "Blob.h"

Blob::Blob(int playerLevel, bool isBoss, int posX, int posY)
        : EnemyCharacter(posX, posY) {
    Texture* texts[3] = {
            &gEnemy_Blob,
            &gEnemy_Blob_Angry,
            &gEnemy_Blob_Attack
    };
    setTextures(texts);

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
        moveSpeed = 5 + level;
    }
    setVars(health, level, attack, defence);
}
