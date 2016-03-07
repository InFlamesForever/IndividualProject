//
// Created by richard on 07/03/16.
//

#ifndef INDIVIDUALPROJECT_TERRAINNODE_H
#define INDIVIDUALPROJECT_TERRAINNODE_H


#include <stddef.h>
#include <stdlib.h>

class TerrainNode {
public:
    TerrainNode(int x, int y, TerrainNode* previousNode, int endX, int endY);
    int getX();
    int getY();
    int getDistFromStart();
    int getDistToGoal();
    TerrainNode* getPrevNode();
    bool equals(TerrainNode* other);
private:
    int x;
    int y;
    TerrainNode* previousNode;
    int distFromStart;
    int distToGoal;
};


#endif //INDIVIDUALPROJECT_TERRAINNODE_H
