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

class EnemyCharacter: public Character {

public:
    EnemyCharacter(int playerLevel, bool isBoss, int posX, int posY);

    void chooseMove(PlayerCharacter player,
                    float timeStep, int **terrain);

    void render(int screenPosX, int screenPosY,
                int offsetY, int offsetX);

    void move(float timeStep);

    void attack(Character other);
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
    int moveSpeed;

    const int withinAttackRange = 20;

    Timer attackTimer;
protected:
    void setTextures(Texture* texts[3]);
};


#endif //INDIVIDUALPROJECT_ENEMYCHARACTER_H
