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

    int getHealthPts();
    int getLevel();
    int getDefencePts();
    int getAttackPts();

    Timer* getAttackTimer();
    //Time between attacks in milliseconds
    const int ATTACKDELAY = 500;

    bool hitDetection(Character enemy);

    void hit(int damage);

private:
    int level = 0;
    int attackPts = 0;
    int defencePts = 0;
    int healthPts = 0;

    //Stores the time since the last attack
    Timer attackTimer;

    const int cantTraverseSize = 1;
    int cantTraverse[1] = {
            TerrainTypes::Water_Ocean
    };

protected:
    void setVars(int healthPts, int level, int attackPts, int defencePts);

    int terrainPosX;
    int terrainPosY;

    int dir;
};


#endif //INDIVIDUALPROJECT_CHARACTER_H
