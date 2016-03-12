//
// Created by richard on 11/03/16.
//

#ifndef INDIVIDUALPROJECT_ENEMYCHARACTER_H
#define INDIVIDUALPROJECT_ENEMYCHARACTER_H


#include "Character.h"
#include "../utilities/random.h"

class EnemyCharacter: public Character {

public:
    EnemyCharacter(int playerLevel, bool isBoss, int posX, int posY);

    void render(int screenPosX, int screenPosY);

private:
    Texture* textures[3];
    enum States {
        Normal,
        Angry,
        Attack
    };
    int state;

protected:
    void setTextures(Texture* texts[3]);
};


#endif //INDIVIDUALPROJECT_ENEMYCHARACTER_H
