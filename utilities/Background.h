//
// Created by richard on 28/12/15.
//

#ifndef INDIVIDUALPROJECT_BACKGROUND_H
#define INDIVIDUALPROJECT_BACKGROUND_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "constants.h"
#include "textures.h"
#include "vector"
#include "TextureInfo.h"
#include "math.h"

class Background {
public:
    Background();
    ~Background();

    //Compiles all of the textures for the terrain to reduce rendering
    void composeTerrainToTexture();

    void moveUpdate();

    void render();

    //Converts 2D coordinates to 2.5D Coordinates
    void convert2Dto25D(int *X, int *Y);

private:
    vector<TextureInfo> onScreenTerrain;

    static int const terrainSize = 1000;
    TextureInfo **terrain = new TextureInfo*[terrainSize];

    //Stores where the terrain on the screen the player sees starts on the whole
    //terrain grid
    int pointInTerrainX;
    int pointInTerrainY;

    Texture* terrainChooser[24] =  {
            &gDirt_DirtTexture, &gDirt_DirtGravelTexture, &gDirt_GravelTexture,                     //00,01,02
            &gGrass_DeadTexture, &gGrass_DryTexture, &gGrass_DyingTexture,                          //03,04,05
            &gGrass_LushDeepTexture, &gGrass_LushLightTexture, &gGrass_ParchedTexture,              //06,07,08
            &gPavement_CobblestoneTexture, &gSand_DarkTexture, &gSand_LightTexture,                 //09,10,11
            &gStone_Gray_DarkTexture, &gStone_Gray_LightTexture, &gStone_Gray_MediumTexture,        //12,13,14
            &gStone_Gray_VeryDarkTexture, &gStone_Gray_VeryLightTexture, &gStone_Sand_DarkTexture,  //15,16,17
            &gStone_Sand_LightTexture, &gStone_Sand_MediumTexture, &gStone_Sand_VeryLightTexture,   //18,19,20
            &gWater_RiverTexture, &gWater_SeaTexture, &gWater_SmallStreamTexture                    //21,22,23
    };

    //These are required to move x and y to start at 00 otherwise
    //the blocks start half way down the screen
    int moveXTo0 = 0;
    int moveYTo0 = 0;

    //------------change to be texture class in future--------------------------
    Texture tileTexture;
};


#endif //INDIVIDUALPROJECT_BACKGROUND_H
