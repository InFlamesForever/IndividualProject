//
// Created by richard on 08/02/16.
//

#ifndef INDIVIDUALPROJECT_TERRAINGENERATOR_H
#define INDIVIDUALPROJECT_TERRAINGENERATOR_H


#include <stdlib.h>
#include "TextureInfo.h"
#include "textures.h"

class TerrainGenerator {
public:
    TerrainGenerator();

    void generateTerrain(TextureInfo **terrain, int terrainSize);
private:
    int waterline;
    int maxWaterLine;
    int maxSandLine;
};


#endif //INDIVIDUALPROJECT_TERRAINGENERATOR_H
