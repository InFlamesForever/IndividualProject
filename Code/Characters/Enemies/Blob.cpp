//
// Created by richard on 11/03/16.
//

#include "Blob.h"

Blob::Blob(int playerLevel, bool isBoss, int posX, int posY)
        : EnemyCharacter(playerLevel, isBoss, posX, posY) {
    Texture* texts[3] = {
            &gEnemy_Blob,
            &gEnemy_Blob_Angry,
            &gEnemy_Blob_Attack
    };
    setTextures(texts);
}
