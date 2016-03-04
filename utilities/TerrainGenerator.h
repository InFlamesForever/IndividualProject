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
    void placeTowns();

    /**
     * Adds roads to the map. These roads pave a way between the 4 major towns
     */
    void placeRoads();

    /**
     * Add trees around the map
     */
    void placeTrees();

    /**
     * Places waves on the ocean and lakes
     */
    void placeWaves();

    /**
     * Returns a random double value between a min and max value
     */
    double fRand(double fMin, double fMax);

    TextureInfo **terrain;
    TextureInfo **terrainDetail;

    int const MAX_OCEAN_LINE = 200;
    int const MAX_BEACH_LINE = 400;

    int const TERRAIN_SCALE = 50;

    //Number of towns on the map, between 4 and 8
    int numTowns;
    int townPositions[8][2];
};


#endif //INDIVIDUALPROJECT_TERRAINGENERATOR_H
