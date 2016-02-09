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

    double fRand(double fMin, double fMax);

private:
    int const MAX_BEACH_LINE = 70;
    int const beachLine = 0;
    unsigned int seed;
};


#endif //INDIVIDUALPROJECT_TERRAINGENERATOR_H
