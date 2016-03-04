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
    TerrainGenerator(TextureInfo **terrain, TextureInfo **terrainDetail);

private:
    void generateTerrain();

    int generateOcean(int x, int y, int edgeSandLine, double value);

    int generateLand(double value);

    /**
     * Adds 4 major towns, one in each corner of the map
     * Adds between 0 and 4 random hidden towns,
     * these are not on any connecting roads
     */
    void placeTowns(int numTowns);

    /**
     * Adds roads to the map. These roads pave a way between the 4 major towns
     */
    void placeRoads();

    /**
     * Add trees around the map
     */
    void placeTrees();

    void placeWaves();

    double fRand(double fMin, double fMax);

    TextureInfo **terrain;
    TextureInfo **terrainDetail;

    int const MAX_OCEAN_LINE = 200;
    int const MAX_BEACH_LINE = 400;

    int const TERRAIN_SCALE = 50;
};


#endif //INDIVIDUALPROJECT_TERRAINGENERATOR_H
