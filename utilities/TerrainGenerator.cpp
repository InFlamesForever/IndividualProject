//
// Created by richard on 08/02/16.
//

#include "TerrainGenerator.h"

TerrainGenerator::TerrainGenerator() {
    waterline = rand() % 10;
    maxWaterLine = waterline + rand() % 10;
    maxSandLine = maxWaterLine + rand() % 10;
    srand(time(0));

}

void TerrainGenerator::generateTerrain(TextureInfo **terrain, int terrainSize) {
    for(int i = 0; i < terrainSize; i++){
        for(int j = 0; j < terrainSize; j++) {
            //Fill outside with ocean tiles
            if(i <= waterline/2 || j <= waterline/2 || i >= terrainSize - waterline/2 || j >= terrainSize - waterline/2){
                terrain[i][j].setUp(22, i, j);
            } else if(i <= maxWaterLine || j <= maxWaterLine || i >= terrainSize - maxWaterLine || j >= terrainSize - maxWaterLine){
                if(rand() % 10 < 6){
                    terrain[i][j].setUp(22, i, j);
                } else {
                    //Add sand, much more bias towards darker texture
                    if(rand() % 10 < 7) {
                        terrain[i][j].setUp(11, i, j);
                    } else {
                        terrain[i][j].setUp(10, i, j);
                    }
                }
                //Add sand for beach around ocean
            } else if(i <= maxSandLine || j <= maxSandLine || i >= terrainSize - maxSandLine || j >= terrainSize - maxSandLine){
                //Add sand, much more bias towards darker texture
                if(rand() % 10 < 7) {
                    terrain[i][j].setUp(10, i, j);
                } else {
                    terrain[i][j].setUp(11, i, j);
                }
                //Fill rest with grass
            } else {
                terrain[i][j].setUp(8, i, j);
            }
        }
    }
}
