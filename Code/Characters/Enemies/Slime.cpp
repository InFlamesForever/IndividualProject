//
// Created by richard on 14/03/16.
//

#include "Slime.h"

Slime::Slime(int playerLevel, bool isBoss, int posX, int posY)
        : EnemyCharacter(posX, posY){
    Texture* texts[3] = {
            &gEnemy_Slime,
            &gEnemy_Slime_Angry,
            &gEnemy_Slime_Attack
    };
    setTextures(texts);

    setVars(playerLevel, isBoss, BASE_HEALTH,
            BASE_ATTACK, BASE_DEFENCE, BASE_MOVE_SPEED,
            BASE_EXP,
            MULTIPLIER_HEALTH, MULTIPLIER_ATTACK,
            MULTIPLIER_DEFENCE, MULTIPLIER_EXP);
}

Slime &Slime::operator=(Slime &&other) {
    EnemyCharacter::operator=(std::move(other));
    return *this;
}
