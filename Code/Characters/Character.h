//
// Created by richard on 11/03/16.
//

#ifndef INDIVIDUALPROJECT_CHARACTER_H
#define INDIVIDUALPROJECT_CHARACTER_H


#include "../media/Texture.h"
#include "../media/textures.h"

class Character {
public:
    Character(int posX, int posY);

    /*
     * Check whether the character is on the screen before rendering
     */
    bool isOnScreen(int screenPosX, int screenPosY);

    void printOut();

private:
    int health;
    int level;
    int attack;
    int defence;

protected:
    void setVars(int health, int level, int attack, int defence);

    int terrainPosX;
    int terrainPosY;
};


#endif //INDIVIDUALPROJECT_CHARACTER_H
