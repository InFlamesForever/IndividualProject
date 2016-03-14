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

    setVars(false,
            playerLevel, isBoss, BASE_HEALTH,
            BASE_ATTACK, BASE_DEFENCE, BASE_MOVE_SPEED,
            BASE_EXP,
            MULTIPLIER_HEALTH, MULTIPLIER_ATTACK,
            MULTIPLIER_DEFENCE, MULTIPLIER_EXP);
}

/*
Blob &Blob::operator=(Blob &&other) {
    EnemyCharacter::operator=(std::move(other));
    return *this;
}
*/

void Blob::levelUp() {

}
