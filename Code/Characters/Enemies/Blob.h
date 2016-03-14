//
// Created by richard on 11/03/16.
//

#ifndef INDIVIDUALPROJECT_BLOB_H
#define INDIVIDUALPROJECT_BLOB_H

#include "../EnemyCharacter.h"

/*
 * Blob is an all round medium enemy
 */
class Blob: public EnemyCharacter {
public:
    Blob(int playerLevel, bool isBoss, int posX, int posY);

    Blob& operator=(Blob&& other);

private:
    const int BASE_HEALTH = 100;
    const int BASE_ATTACK = 10;
    const int BASE_DEFENCE = 20;
    const int BASE_MOVE_SPEED = 5;
    const int BASE_EXP = 15;

    const int MULTIPLIER_HEALTH = 10;
    const int MULTIPLIER_ATTACK = 5;
    const int MULTIPLIER_DEFENCE = 5;
    const int MULTIPLIER_EXP = 10;
};


#endif //INDIVIDUALPROJECT_BLOB_H
