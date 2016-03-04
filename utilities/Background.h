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
#include "PlayerCharacter.h"

class Background {
public:
    Background();
    ~Background();

    //Compiles all of the textures for the terrain to reduce rendering
    void composeTerrainToTexture();

    /**
     * Takes all of the terrain tiles from the terrain array and places
     * them in a vector so that only on-screen textures are displayed
     */
    void getTerrain();

    //Moves the terrain
    bool move(float timeStep, int xShift, int yShift);

    void render();

    /**
     * A character is passed to this method along with a direction
     * the movement is then checked to see whether it should be based
     * on the terrain tiles that the character can move over.
     */
    bool terrainCollision(PlayerCharacter character, int dir);

private:
    TextureInfo onScreenTerrain[SCREEN_WIDTH/BLOCK_WIDTH][SCREEN_HEIGHT/BLOCK_WIDTH];

    TextureInfo **terrain = new TextureInfo*[TERRAIN_SIZE];
    TextureInfo **terrainDetail = new TextureInfo*[TERRAIN_SIZE];

    int numOfTilesHeight;
    int numOfTilesWidth;

    //The position of the top left of the screen in relation to the player
    int pointInTerrainX;
    int pointInTerrainY;

    //These are required to move x and y to start at 00 otherwise
    //the blocks start half way down the screen
    int moveXTo0 = 0;
    int moveYTo0 = 0;

    Texture terrainTexture;

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

    Texture* aboveTerrainChooser[18] = {
            &gTownSymbol,

            &gTown_Door_Closed, &gTown_Door_HalfOpen,
            &gTown_Door_ThreeQuartersOpen, &gTown_Door_Open,

            &gTown_Roof_Thatched, &gTown_Roof_Thatched_Corner,

            &gTown_Wall_Wood, &gTown_Wall_Wood_Corner_Left_Ground,
            &gTown_Wall_Wood_Corner_Left_Upper,
            &gTown_Wall_Wood_Corner_Right_Ground,
            &gTown_Wall_Wood_Corner_Right_Upper, &gTown_Wall_Wood_Window,

            &gWater_SeaWaves,

            &gTree_Dark, &gTree_Medium,
            &gTree_MediumLittle, &gTree_Light
    };

    //Holds the distance moved for a single block
    float movedSoFar = 0;

    //Holds the offset for the on screen map during movement
    // for smooth movement
    int moveBackgroundY = 0;
    int moveBackgroundX = 0;

    void renderTile(int terX, int terY, int renX, int renY);

    /**
     * Renders the AboveTerrain Details, changes the position depending on
     * the size of the texture
     */
    void renderAboveTerrainDetail(int x, int y, int renX, int renY);
};


#endif //INDIVIDUALPROJECT_BACKGROUND_H
