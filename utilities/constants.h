#ifndef INDIVIDUALPROJECT_CONSTANTS_H
#define INDIVIDUALPROJECT_CONSTANTS_H

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

const int STARTX = 00;
const int STARTY = 800;

const int BLOCK_WIDTH = 16;

const int TERRAIN_SIZE = 1000;

//Speed multiplier for movement
static int const MOVE_SPEED = 100;

enum TerrainTypes {
    SandLight, SandDark,

    Grass_Dry, Grass_Parched,
    Grass_LushLight, Grass_LushDeep,
    Grass_Dead, Grass_Dying,

    Dirt_Dirt, Dirt_DirtGravel, Dirt_Gravel,

    Stone_Gray_VeryDark, Stone_Gray_Dark,
    Stone_Gray_Medium, Stone_Gray_Light,
    Stone_Gray_VeryLight,

    Snow,

    Stone_Sand_Dark, Stone_Sand_Medium,
    Stone_Sand_Light, Stone_Sand_VeryLight,

    Water_Ocean,
    Water_River, Water_SmallStream,

    Pavement_Cobblestone
};


#endif //INDIVIDUALPROJECT_CONSTANTS_H
