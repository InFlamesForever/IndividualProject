//
// Created by richard on 11/03/16.
//

#ifndef INDIVIDUALPROJECT_ENEMYCHARACTER_H
#define INDIVIDUALPROJECT_ENEMYCHARACTER_H


#include "Character.h"
#include "../utilities/random.h"
#include <memory>
#include <bits/shared_ptr.h>
#include "../terrain/TerrainNode.h"
#include "../utilities/AStarSearch.h"
#include "PlayerCharacter.h"
#include "../UI/healthBar.h"

class EnemyCharacter: public Character {

public:
    EnemyCharacter(int posX, int posY);

    void chooseMove(PlayerCharacter player, int **terrain);

    void render(int screenPosX, int screenPosY,
                int offsetY, int offsetX);

    void move(float timeStep);

    void attack(Character* other);
private:
    Texture* textures[3];
    enum States {
        Normal,
        Angry,
        Attack
    };
    int state;

    double movingOffsetY;
    double movingOffsetX;
    bool isMoving;
    const int withinAttackRange = 20;

    Timer attackAniTimer;

protected:
    void setTextures(Texture* texts[3]);
};


#endif //INDIVIDUALPROJECT_ENEMYCHARACTER_H
