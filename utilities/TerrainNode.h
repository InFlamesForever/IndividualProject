//
// Created by richard on 07/03/16.
//

#ifndef INDIVIDUALPROJECT_TERRAINNODE_H
#define INDIVIDUALPROJECT_TERRAINNODE_H


#include <stddef.h>
#include <stdlib.h>
#include <bits/unique_ptr.h>

using namespace std;

class TerrainNode {
public:
    TerrainNode(int x, int y, TerrainNode* prev = NULL);
    ~TerrainNode();
    int getX();
    int getY();
    TerrainNode* getPrevNode();
private:
    int x;
    int y;
    TerrainNode* previousNode;
};


#endif //INDIVIDUALPROJECT_TERRAINNODE_H
