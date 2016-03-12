//
// Created by richard on 07/03/16.
//

#ifndef INDIVIDUALPROJECT_TERRAINNODE_H
#define INDIVIDUALPROJECT_TERRAINNODE_H


#include <stddef.h>
#include <stdlib.h>
#include <memory>
#include <bits/shared_ptr.h>

using namespace std;

class TerrainNode {
public:
    TerrainNode(int x, int y, shared_ptr<TerrainNode> prev = NULL);
    ~TerrainNode();
    int getX();
    int getY();
    int getDistFromStart();
    shared_ptr<TerrainNode> getPrevNode();
private:
    int x;
    int y;
    int disFromStart = 0;
    shared_ptr<TerrainNode> previousNode;
};


#endif //INDIVIDUALPROJECT_TERRAINNODE_H
