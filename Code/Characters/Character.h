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

    int getCantTraverseSize();
    int* getCantTraverse();

private:
    int health;
    int level;
    int attack;
    int defence;

    const int cantTraverseSize = 1;
    int cantTraverse[1] = {
            TerrainTypes::Water_Ocean
    };

protected:
    void setVars(int health, int level, int attack, int defence);

    int terrainPosX;
    int terrainPosY;
};


#endif //INDIVIDUALPROJECT_CHARACTER_H
