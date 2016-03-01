//
// Created by richard on 08/02/16.
//

#ifndef INDIVIDUALPROJECT_TERRAINGENERATOR_H
#define INDIVIDUALPROJECT_TERRAINGENERATOR_H


#include <stdlib.h>
#include "TextureInfo.h"
#include "textures.h"
#include "PerlinNoise.h"

class TerrainGenerator {
public:
    TerrainGenerator();

    void generateTerrain(TextureInfo **terrain);

    int generateOcean(int x, int y, int edgeSandLine, double value);

    int generateLand(double value);

    double fRand(double fMin, double fMax);

private:
    int const MAX_OCEAN_LINE = 200;
    int const MAX_BEACH_LINE = 400;

    int const TERRAIN_SCALE = 50;

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
};


#endif //INDIVIDUALPROJECT_TERRAINGENERATOR_H
