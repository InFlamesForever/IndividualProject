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

    void getTerrain();

    //Moves the terrain
    bool move(float timeStep, int xShift, int yShift);

    void render();

    //Converts 2D coordinates to 2.5D Coordinates
    void convert2Dto25D(int *X, int *Y);

private:
    vector<TextureInfo> onScreenTerrain;

    TextureInfo **terrain = new TextureInfo*[TERRAIN_SIZE];
    TextureInfo **terrainDetail = new TextureInfo*[TERRAIN_SIZE];

    int numOfTilesHeight;
    int numOfTilesWidth;

    //Stores where the terrain on the screen the player sees starts on the whole
    //terrain grid
    int pointInTerrainX;
    int pointInTerrainY;

    //These are required to move x and y to start at 00 otherwise
    //the blocks start half way down the screen
    int moveXTo0 = 0;
    int moveYTo0 = 0;

    Texture tileTexture;

    Texture* terrainChooser[25] =  {
            &gSand_LightTexture, &gSand_DarkTexture,

            &gGrass_DryTexture, &gGrass_ParchedTexture,
             &gGrass_LushLightTexture, &gGrass_LushDeepTexture,
            &gGrass_DeadTexture, &gGrass_DyingTexture,


            &gDirt_DirtTexture, &gDirt_DirtGravelTexture,
            &gDirt_GravelTexture,


            &gStone_Gray_VeryDarkTexture, &gStone_Gray_DarkTexture,
            &gStone_Gray_MediumTexture, &gStone_Gray_LightTexture,
            &gStone_Gray_VeryLightTexture,

            &gSnow,


            &gStone_Sand_DarkTexture, &gStone_Sand_MediumTexture,
            &gStone_Sand_LightTexture, &gStone_Sand_VeryLightTexture,

            &gWater_SeaTexture,
            &gWater_RiverTexture,  &gWater_SmallStreamTexture,
            &gPavement_CobblestoneTexture,
    };

    //Holds the distance moved for a single block
    float movedSoFar = 0;

    //Holds the offset for the on screen map during movement
    int moveBackgroundY = 0;
    int moveBackgroundX = 0;

    void renderTile(int terX, int terY, int renX, int renY);
};


#endif //INDIVIDUALPROJECT_BACKGROUND_H
