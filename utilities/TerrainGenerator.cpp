//
// Created by richard on 08/02/16.
//

#include "TerrainGenerator.h"

TerrainGenerator::TerrainGenerator(TextureInfo **terrain, TextureInfo **terrainDetail) {
    this-> terrain = terrain;
    this-> terrainDetail = terrainDetail;
    srand(time(0));

    numTowns = (int)fRand(4, 9);

    generateTerrain();
    placeTowns();
    placeRoads();
    placeTrees();
    placeWaves();

}

void TerrainGenerator::generateTerrain() {
    PerlinNoise perlin(time(0));
    for(int x = 0; x < TERRAIN_SIZE; x++) {
        for (int y = 0; y < TERRAIN_SIZE; y++) {
            double value = value = perlin.noise((double)x/TERRAIN_SCALE,
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
            terrain[x][y].setUp(texture, x, y);
            terrainDetail[x][y].setUp(INT32_MAX,x,y);
        }
    }

}

double TerrainGenerator::fRand(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
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


}

void TerrainGenerator::placeRoads() {

}

void TerrainGenerator::placeTrees() {
    for(int x = 0; x < TERRAIN_SIZE; x++) {
        for (int y = 0; y < TERRAIN_SIZE; y++) {
            //Checks if there is already something in the tile
            if (terrainDetail[x][y].getTexture() == INT32_MAX) {
                double random = fRand(0, 1);

                //Trees at the base of a mountain
                if (terrain[x][y].getTexture() == Stone_Gray_VeryDark
                    && random > 0.95
                    || terrain[x][y].getTexture() == Dirt_Dirt
                       && random > 0.8
                    || terrain[x][y].getTexture() == Dirt_DirtGravel
                       && random > 0.7
                    || terrain[x][y].getTexture() == Dirt_Gravel
                       && random > 0.2) {
                    terrainDetail[x][y].setUp(Tree_Dark, x, y);
                }

                    //Trees on plains
                else if (terrain[x][y].getTexture() == Grass_LushLight
                         && random > 0.98
                         //Creates forest groups
                         || terrain[x][y].getTexture() == Grass_LushLight
                            &&
                            terrainDetail[x - 1][y].getTexture() == Tree_Medium
                            && random > 0.3
                         || terrain[x][y].getTexture() == Grass_LushLight
                            &&
                            terrainDetail[x][y - 1].getTexture() == Tree_Medium
                            && random > 0.3) {
                    terrainDetail[x][y].setUp(Tree_Medium, x, y);
                }

                else if (terrain[x][y].getTexture() == Grass_LushDeep
                         && random > 0.9) {
                    terrainDetail[x][y].setUp(Tree_MediumLittle, x, y);
                }

                    //Trees on dry land
                else if (terrain[x][y].getTexture() == Grass_Dry
                         && random > 0.96
                         || terrain[x][y].getTexture() == Grass_Parched
                            && random > 0.93) {
                    terrainDetail[x][y].setUp(Tree_Light, x, y);
                }
            }
        }
    }
}

void TerrainGenerator::placeWaves() {
    for(int x = 0; x < TERRAIN_SIZE; x++) {
        for (int y = 0; y < TERRAIN_SIZE; y++) {
            //Checks if there is already something in the tile
            if (terrainDetail[x][y].getTexture() == INT32_MAX) {
                if (terrain[x][y].getTexture() == Water_Ocean
                    && fRand(0, 1) > 0.98
                    || terrain[x][y].getTexture() == Water_Ocean
                       && x > 0 &&
                       terrainDetail[x - 1][y].getTexture() == SeaWaves
                       && fRand(0, 1) > 0.6
                    || terrain[x][y].getTexture() == Water_Ocean
                       && y > 0 &&
                       terrainDetail[x][y - 1].getTexture() == SeaWaves
                       && fRand(0, 1) > 0.7) {
                    terrainDetail[x][y].setUp(SeaWaves, x, y);
                }

            }
        }
    }
}
