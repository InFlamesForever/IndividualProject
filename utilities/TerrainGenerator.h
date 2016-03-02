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
};


#endif //INDIVIDUALPROJECT_TERRAINGENERATOR_H
