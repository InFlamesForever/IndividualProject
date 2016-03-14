//
// Created by richard on 08/02/16.
//

#ifndef INDIVIDUALPROJECT_TERRAINGENERATOR_H
#define INDIVIDUALPROJECT_TERRAINGENERATOR_H

#include <memory>
#include <bits/shared_ptr.h>
#include "../media/TextureInfo.h"
#include "../media/textures.h"
#include "PerlinNoise.h"
#include "TerrainNode.h"
#include "../utilities/random.h"

class TerrainGenerator {
public:
    TerrainGenerator(int **terrain, int **terrainDetail);

    int* getTownLocations();
    int getNumTowns();

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
    void decideRoads();

    void placeRoads(shared_ptr<TerrainNode>  curNode);

    /**
     * Add trees around the map
     */

    /**
     * Places trees on the map using random numbers and
     * weights depending on the terrain type
     */
    void placeTrees();

    /**
     * Places waves on the ocean and lakes
     */
    void placeWaves();



    int **terrain;
    int **terrainDetail;

    int const MAX_OCEAN_LINE = 200;
    int const MAX_BEACH_LINE = 400;

    int const TERRAIN_SCALE = 50;

    //Number of towns on the map, between 4 and 8
    int numTowns;
    //First for x coord, second for y coord, and third for type
    int townPositions[8][3];

    enum TownType {
        Sand,
        Plains,
        Mountain,
        Water
    };
};


#endif //INDIVIDUALPROJECT_TERRAINGENERATOR_H
