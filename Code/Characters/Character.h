//
// Created by richard on 11/03/16.
//

#ifndef INDIVIDUALPROJECT_CHARACTER_H
#define INDIVIDUALPROJECT_CHARACTER_H


#include "../media/Texture.h"
#include "../media/textures.h"
#include "../utilities/Timer.h"

class Character {
public:
    Character(int posX, int posY);

    /*
     * Check whether the character is on the screen before rendering
     */
    bool isOnScreen(int screenPosX, int screenPosY);

    void printOut();

    int getCantTraverseSize();
    int* getCantTraverse();

    int getPosX();
    int getPosY();

    int getIsAlive();

    int getHealthPts();
    int getLevel();
    int getDefencePts();
    int getAttackPts();

    int getMoveSpeed();

    Timer* getAttackTimer();
    //Time between attacks in milliseconds
    const int ATTACKDELAY = 500;

    bool hitDetection(Character enemy);

    void hit(int damage);

private:
    int isAlive;

    int level = 0;
    int attackPts = 0;
    int defencePts = 0;
    int healthPts = 0;
    int expPointsWorth = 0;

    int moveSpeed;

    //Stores the time since the last attack
    Timer attackTimer;
    const int cantTraverseSize = 1;

    int cantTraverse[1] = {
            TerrainTypes::Water_Ocean
    };
protected:

    //Will generate a character from the supplied values
    void setVars(int playerLevel, bool isBoss, int BASE_HEALTH,
                 int BASE_ATTACK, int BASE_DEFENCE, int BASE_MOVE_SPEED,
                 int BASE_EXP,
                 int MULTIPLIER_HEALTH, int MULTIPLIER_ATTACK,
                 int MULTIPLIER_DEFENCE, int MULTIPLIER_EXP);

    //Character has specified stats
    void setVars(int health, int level, int attack, int defence);

    int terrainPosX;
    int terrainPosY;
    int dir;
};


#endif //INDIVIDUALPROJECT_CHARACTER_H
