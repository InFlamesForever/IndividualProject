//
// Created by richard on 08/02/16.
//

#include "TerrainGenerator.h"
#include "../utilities/AStarSearch.h"

TerrainGenerator::TerrainGenerator(int **terrain, int **terrainDetail) {
    this-> terrain = terrain;
    this-> terrainDetail = terrainDetail;

    //When secret towns are implemented will use a random number of them
    numTowns = 4; //(int)fRand(4, 9);

    generateTerrain();
    placeTowns();
    decideRoads();
    placeTrees();
    placeWaves();

}

void TerrainGenerator::generateTerrain() {
    PerlinNoise perlin((unsigned)time(0));
    for(int x = 0; x < TERRAIN_SIZE; x++) {
        for (int y = 0; y < TERRAIN_SIZE; y++) {
            double value = perlin.noise((double)x/TERRAIN_SCALE,
                                                (double)y/TERRAIN_SCALE, 0);

            int texture;
            int edgeSandLine = TERRAIN_SIZE - MAX_BEACH_LINE - 1;
            //If true, generate beach!
            if(x <= MAX_BEACH_LINE || y <= MAX_BEACH_LINE
               || x >= edgeSandLine || y >= edgeSandLine){
                texture = generateOcean(x, y, edgeSandLine, value);
            } else {
                texture = generateLand(value);
            }
            terrain[x][y] = texture;
            terrainDetail[x][y] = INT32_MAX;
        }
    }

}

int TerrainGenerator::generateOcean(int x, int y,
                                    int edgeSandLine, double value) {

    //get linear gradient
    int gradientX = 0;
    int gradientY = 0;
    if(y <= MAX_BEACH_LINE && x >= edgeSandLine){
        gradientX = TERRAIN_SIZE - x - 1;
        gradientY = y;
    } else if(x <= MAX_BEACH_LINE && y >= edgeSandLine){
        gradientX = x;
        gradientY = TERRAIN_SIZE - y - 1;
    } else if(y <= MAX_BEACH_LINE || x <= MAX_BEACH_LINE){
        gradientY = y;
        gradientX = x;
    } else if(y >= edgeSandLine || x >= edgeSandLine){
        gradientX = TERRAIN_SIZE - x - 1;
        gradientY = TERRAIN_SIZE - y - 1;
    }
    double gradient = gradientX < gradientY ? gradientX : gradientY;
    gradient = gradient / MAX_OCEAN_LINE;

    double newVal = value*gradient;
    if(newVal < 0.3){
        return Water_Ocean;
    } else if( newVal < 0.4){
        return SandLight;
    } else if( newVal < 0.5){
        return SandDark;
    } else {
        return generateLand(value);
    }
}

int TerrainGenerator::generateLand(double value) {
    if(value < 0.1){
        return SandLight;
    } else if(value < 0.2){
        return SandDark;
    } else if(value < 0.22){
        return Grass_Dead;
    } else if(value < 0.26){
        return Grass_Dying;
    } else if(value < 0.3){
        return Grass_Dry;
    } else if(value < 0.35){
        return Grass_Parched;
    } else if(value < 0.45){
        return Grass_LushDeep;
    } else if(value < 0.52){
        return Grass_LushLight;
    } else if(value < 0.56){
        return Dirt_Gravel;
    } else if(value < 0.58){
        return Dirt_DirtGravel;
    } else if(value < 0.61){
        return Dirt_Dirt;
    } else if(value < 0.65){
        return Stone_Gray_VeryDark;
    }else if(value < 0.7){
        return Stone_Gray_Dark;
    }else if(value < 0.75){
        return Stone_Gray_Medium;
    }else if(value < 0.8){
        return Stone_Gray_Light;
    } else if(value < 0.9){
        return Stone_Gray_VeryLight;
    } else if(value < 1){
        return Snow;
    }
    else return Water_River;
}


void TerrainGenerator::placeTowns() {
    //4 major towns and a random number (0-4) hidden towns

    int townsPlaced = 0;
    int sandTownsRemaining = 1;
    int plainsTownsRemaining = 1;
    int mountainTownsRemaining = 1;
    int waterTownsRemaining = 1;

    int borderDisplacer = 100;
    int halfMap = TERRAIN_SIZE/2;
    int terrainBorder = TERRAIN_SIZE - borderDisplacer;

    //Top left quarter
    int startX = borderDisplacer;
    int endX = halfMap;
    int startY = borderDisplacer;
    int endY = halfMap;

    int townsThisLoop = 1;
    while(townsPlaced < 4) {
        //top right quarter
        if(townsPlaced == 1){
            startX = halfMap;
            endX = terrainBorder;
            startY = borderDisplacer;
            endY = halfMap;
            townsThisLoop++;
            //Bottom left quarter
        } else if(townsPlaced == 2){
            startX = borderDisplacer;
            endX = halfMap;
            startY = halfMap;
            endY = terrainBorder;
            townsThisLoop++;
            //Bottom right quarter
        } else if(townsPlaced == 3){
            startX = halfMap;
            endX = terrainBorder;
            startY = halfMap;
            endY = terrainBorder;
            townsThisLoop++;
        }
        //Town in the top left corner
        for (int x = startX; x < endX; x++) {
            for (int y = startY; y < endY; y++) {
                if(townsThisLoop > 0) {
                    //Place a Town in the desert
                    if (sandTownsRemaining > 0
                        && terrain[x][y] == SandDark
                        && fRand(0, 1) > 0.99) {
                        //if the sand is surrounded by grass
                        if ((unsigned) (terrain[x - 10][y] - Grass_Dry)
                            <= (Grass_Dying - Grass_Dry)
                            && (unsigned) (terrain[x + 10][y] - Grass_Dry)
                               <= (Grass_Dying - Grass_Dry)
                            && (unsigned) (terrain[x][y - 10] - Grass_Dry)
                               <= (Grass_Dying - Grass_Dry)
                            && (unsigned) (terrain[x][y + 10] - Grass_Dry)
                               <= (Grass_Dying - Grass_Dry)
                                ) {
                            terrainDetail[x][y] = TownSymbol;
                            townPositions[townsPlaced][0] = x;
                            townPositions[townsPlaced][1] = y;
                            townPositions[townsPlaced][2] = Sand;
                            townsPlaced++;
                            sandTownsRemaining--;
                            townsThisLoop--;
                        }

                        //Place a town on some plains
                    } else if (plainsTownsRemaining > 0
                               && terrain[x][y] == Grass_Parched
                               && fRand(0, 1) > 0.99) {
                        if (terrain[x - 5][y] == Grass_Parched
                            && terrain[x + 5][y] == Grass_Parched
                            && terrain[x][y - 5] == Grass_Parched
                            && terrain[x][y + 5] == Grass_Parched
                                ) {
                            terrainDetail[x][y] = TownSymbol;
                            townPositions[townsPlaced][0] = x;
                            townPositions[townsPlaced][1] = y;
                            townPositions[townsPlaced][2] = Plains;
                            townsPlaced++;
                            plainsTownsRemaining--;
                            townsThisLoop--;
                        }
                        //Place a town on a mountain
                    } else if (mountainTownsRemaining > 0
                               && terrain[x][y] == Stone_Gray_VeryLight
                               && fRand(0, 1) > 0.99) {
                        if (terrain[x - 5][y] == Stone_Gray_VeryLight
                            && terrain[x + 5][y] == Stone_Gray_VeryLight
                            && terrain[x][y - 5] == Stone_Gray_VeryLight
                            && terrain[x][y + 5] == Stone_Gray_VeryLight
                                ) {
                            terrainDetail[x][y] = TownSymbol;
                            townPositions[townsPlaced][0] = x;
                            townPositions[townsPlaced][1] = y;
                            townPositions[townsPlaced][2] = Mountain;
                            townsPlaced++;
                            mountainTownsRemaining--;
                            townsThisLoop--;
                        }

                        //Place a town in the middle of a lake
                    } else if (waterTownsRemaining > 0
                               && terrain[x][y] == Water_Ocean
                               && fRand(0, 1) > 0.99) {
                        if (terrain[x - 20][y] != Water_Ocean
                            && terrain[x + 20][y] != Water_Ocean
                            && terrain[x][y - 20] != Water_Ocean
                            && terrain[x][y + 20] != Water_Ocean
                            && terrain[x - 10][y] == Water_Ocean
                            && terrain[x + 10][y] == Water_Ocean
                            && terrain[x][y - 10] == Water_Ocean
                            && terrain[x][y + 10] == Water_Ocean
                                ) {
                            terrainDetail[x][y] = TownSymbol;
                            townPositions[townsPlaced][0] = x;
                            townPositions[townsPlaced][1] = y;
                            townPositions[townsPlaced][2] = Water;
                            townsPlaced++;
                            waterTownsRemaining--;
                            townsThisLoop--;
                        }
                    }
                }
            }
        }
    }

}

void TerrainGenerator::decideRoads() {
    for(int i = 0; i < numTowns; i++){
        int x = townPositions[i][0];
        int y = townPositions[i][1];
        //Place pavement around the towns
        terrain[x][y] = Pavement_Cobblestone;
        terrain[x][y-1] = Pavement_Cobblestone;
        terrain[x][y+1] = Pavement_Cobblestone;
        terrain[x-1][y] = Pavement_Cobblestone;
        terrain[x-1][y-1] = Pavement_Cobblestone;
        terrain[x-1][y+1] = Pavement_Cobblestone;
        terrain[x+1][y] = Pavement_Cobblestone;
        terrain[x+1][y-1] = Pavement_Cobblestone;
        terrain[x+1][y+1] = Pavement_Cobblestone;
    }
    
    AStarSearch search(terrain);

    placeRoads(search.aStarSearch(townPositions[0][0], townPositions[0][1],
                townPositions[1][0], townPositions[1][1]));
    placeRoads(search.aStarSearch(townPositions[1][0], townPositions[1][1],
                townPositions[2][0], townPositions[2][1]));
    placeRoads(search.aStarSearch(townPositions[2][0], townPositions[2][1],
                townPositions[3][0], townPositions[3][1]));
    placeRoads(search.aStarSearch(townPositions[3][0], townPositions[3][1],
                townPositions[0][0], townPositions[0][1]));
}

void TerrainGenerator::placeRoads(shared_ptr<TerrainNode> curNode) {
    //Putting roads on the terrain
    while(curNode->getPrevNode() != NULL){
        if(terrain[curNode->getX()][curNode->getY()] == Water_Ocean){
            if(curNode->getPrevNode()->getX() != curNode->getX()){
                terrain[curNode->getX()][curNode->getY()] = Bridge_Horizontal;
            } else {
                terrain[curNode->getX()][curNode->getY()] = Bridge;
            }
        } else {
            terrain[curNode->getX()][curNode->getY()] = Pavement_Cobblestone;
        }
        curNode = curNode->getPrevNode();
    }
}

void TerrainGenerator::placeTrees() {
    for(int x = 0; x < TERRAIN_SIZE; x++) {
        for (int y = 0; y < TERRAIN_SIZE; y++) {
            //Checks if there is already something in the tile
            if (terrainDetail[x][y] == INT32_MAX) {
                double random = fRand(0, 1);

                //Trees at the base of a mountain
                if (terrain[x][y] == Stone_Gray_VeryDark
                    && random > 0.95
                    || terrain[x][y] == Dirt_Dirt
                       && random > 0.8
                    || terrain[x][y] == Dirt_DirtGravel
                       && random > 0.7
                    || terrain[x][y] == Dirt_Gravel
                       && random > 0.2) {
                    terrainDetail[x][y] = Tree_Dark;
                }

                    //Trees on plains
                else if (terrain[x][y] == Grass_LushLight
                         && random > 0.98
                         //Creates forest groups
                         || terrain[x][y] == Grass_LushLight
                            &&
                            terrainDetail[x - 1][y] == Tree_Medium
                            && random > 0.3
                         || terrain[x][y] == Grass_LushLight
                            &&
                            terrainDetail[x][y - 1] == Tree_Medium
                            && random > 0.3) {
                    terrainDetail[x][y] = Tree_Medium;
                }

                else if (terrain[x][y] == Grass_LushDeep
                         && random > 0.9) {
                    terrainDetail[x][y] = Tree_MediumLittle;
                }

                    //Trees on dry land
                else if (terrain[x][y] == Grass_Dry
                         && random > 0.96
                         || terrain[x][y] == Grass_Parched
                            && random > 0.93) {
                    terrainDetail[x][y] = Tree_Light;
                }
            }
        }
    }
}

void TerrainGenerator::placeWaves() {
    for(int x = 0; x < TERRAIN_SIZE; x++) {
        for (int y = 0; y < TERRAIN_SIZE; y++) {
            //Checks if there is already something in the tile
            if (terrainDetail[x][y] == INT32_MAX) {
                if (terrain[x][y] == Water_Ocean
                    && fRand(0, 1) > 0.98
                    || terrain[x][y] == Water_Ocean
                       && x > 0 &&
                       terrainDetail[x - 1][y] == SeaWaves
                       && fRand(0, 1) > 0.6
                    || terrain[x][y] == Water_Ocean
                       && y > 0 &&
                       terrainDetail[x][y - 1] == SeaWaves
                       && fRand(0, 1) > 0.7) {
                    terrainDetail[x][y] = SeaWaves;
                }

            }
        }
    }
}
