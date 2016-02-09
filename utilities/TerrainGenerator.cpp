//
// Created by richard on 08/02/16.
//

#include "TerrainGenerator.h"

TerrainGenerator::TerrainGenerator() {
    seed= time(0);

}

void TerrainGenerator::generateTerrain(TextureInfo **terrain) {
    PerlinNoise perlin(seed);
    for(int x = 0; x < TERRAIN_SIZE; x++) {
        for (int y = 0; y < TERRAIN_SIZE; y++) {
            double value = perlin.noise((double)x/TERRAIN_SIZE,
                                        (double)y/TERRAIN_SIZE, 1);
            int texture;
            int edgeSandLine = TERRAIN_SIZE - MAX_BEACH_LINE - 1;
            if(x <= MAX_BEACH_LINE || y <= MAX_BEACH_LINE
               || x >= edgeSandLine || y >= edgeSandLine){
                texture = generateOcean(x, y, edgeSandLine, value);
                /*if(texture != 0){
                    if()
                }*/
            } else {
                texture = 6;
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
    gradient = gradient / MAX_BEACH_LINE;

    double newVal = value*gradient;
    if(newVal < 0.3){
        return 0;
    } else if(newVal > 0.5){
        return 6;
    } else {
        if (newVal > 0.45) {
            if (fRand(0, 1) < 0.1) {
                return 1;
            } else {
                return 2;
            }
        } else if (newVal > 0.35) {
            if (fRand(0, 1) > 0.1) {
                return 1;
            } else {
                return 2;
            }
        } else {
            return 1;
        }
    }

}
