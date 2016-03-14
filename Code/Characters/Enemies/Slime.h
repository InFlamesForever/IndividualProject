//
// Created by richard on 14/03/16.
//

#ifndef INDIVIDUALPROJECT_SLIME_H
#define INDIVIDUALPROJECT_SLIME_H

#include "../EnemyCharacter.h"

/*
 * Slime is a low health, low attack and high defence enemy
 */
class Slime: public EnemyCharacter {
public:
    Slime(int playerLevel, bool isBoss, int posX, int posY);

   // Slime& operator=(Slime&& other);

private:
    const int BASE_HEALTH = 45;
    const int BASE_ATTACK = 5;
    const int BASE_DEFENCE = 30;
    const int BASE_MOVE_SPEED = 1;
    const int BASE_EXP = 10;

    const int MULTIPLIER_HEALTH = 5;
    const int MULTIPLIER_ATTACK = 2;
    const int MULTIPLIER_DEFENCE = 10;
    const int MULTIPLIER_EXP = 5;
};


#endif //INDIVIDUALPROJECT_SLIME_H
