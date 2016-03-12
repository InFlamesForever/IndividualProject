//
// Created by richard on 17/12/15.
//

#ifndef INDIVIDUALPROJECT_DOT_H
#define INDIVIDUALPROJECT_DOT_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "../utilities/constants.h"
#include "../utilities/textures.h"
#include "../utilities/Timer.h"

//The dot that will move around on the screen
class PlayerCharacter
{
public:
    //Initializes the variables
    PlayerCharacter();

    //Shows the dot on the screen
    void render();

    void updateRender(bool isMoving, int dir);

    int getTerrainPosX();
    int getTerrainPosY();

    int getCantTraverseSize();
    int* getCantTraverse();

private:
    //The position to render the player character
    float screenPosX, screenPosY;

    //The position of the player in the terrain
    int terrainPosX, terrainPosY;

    bool isMoving;
    bool hasMoved;


    int dir;
    int lastDir;

    Texture* playerStationary[4] = {
            &gStock_Front,
            &gStock_Back,
            &gStock_Side_Right,
            &gStock_Side_Right
    };
    Texture* playerMoving[4] = {
            &gStock_Front_Walking1,
            &gStock_Back_Walking1,
            &gStock_Side_Right_Walking,
            &gStock_Side_Right_Walking,
    };

    const int cantTraverseSize = 1;
    int cantTraverse[1] = {
            TerrainTypes::Water_Ocean
    };

};


#endif //INDIVIDUALPROJECT_DOT_H
