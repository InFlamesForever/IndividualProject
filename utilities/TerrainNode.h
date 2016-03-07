//
// Created by richard on 07/03/16.
//

#ifndef INDIVIDUALPROJECT_TERRAINNODE_H
#define INDIVIDUALPROJECT_TERRAINNODE_H


#include <stddef.h>
#include <stdlib.h>

class TerrainNode {
public:
    TerrainNode(int x, int y, TerrainNode* previousNode);
    int getX();
    int getY();
    TerrainNode* getPrevNode();
    bool equals(TerrainNode* other);
private:
    int x;
    int y;
    TerrainNode* previousNode;
};


#endif //INDIVIDUALPROJECT_TERRAINNODE_H
