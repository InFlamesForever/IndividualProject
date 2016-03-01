//
// Created by richard on 08/02/16.
//

#include "TerrainGenerator.h"

TerrainGenerator::TerrainGenerator() {}

void TerrainGenerator::generateTerrain(TextureInfo **terrain) {
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
        return TerrainTypes::Water_Ocean;
    } else if( newVal < 0.4){
        return TerrainTypes::SandLight;
    } else if( newVal < 0.5){
        return TerrainTypes::SandDark;
    } else {
        return generateLand(value);
    }
}

int TerrainGenerator::generateLand(double value) {
    if(value < 0.1){
        return TerrainTypes::SandLight;
    } else if(value < 0.2){
        return TerrainTypes::SandDark;
    } else if(value < 0.22){
        return TerrainTypes::Grass_Dead;
    } else if(value < 0.26){
        return TerrainTypes::Grass_Dying;
    } else if(value < 0.3){
        return TerrainTypes::Grass_Dry;
    } else if(value < 0.35){
        return TerrainTypes::Grass_Parched;
    } else if(value < 0.45){
        return TerrainTypes::Grass_LushDeep;
    } else if(value < 0.52){
        return TerrainTypes::Grass_LushLight;
    } else if(value < 0.56){
        return TerrainTypes::Dirt_Gravel;
    } else if(value < 0.58){
        return TerrainTypes::Dirt_DirtGravel;
    } else if(value < 0.61){
        return TerrainTypes::Dirt_Dirt;
    } else if(value < 0.65){
        return TerrainTypes::Stone_Gray_VeryDark;
    }else if(value < 0.7){
        return TerrainTypes::Stone_Gray_Dark;
    }else if(value < 0.75){
        return TerrainTypes::Stone_Gray_Medium;
    }else if(value < 0.8){
        return TerrainTypes::Stone_Gray_Light;
    } else if(value < 0.9){
        return TerrainTypes::Stone_Gray_VeryLight;
    } else if(value < 1){
        return TerrainTypes::Snow;
    }
    else return Water_River;
}
