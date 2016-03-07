//
// Created by richard on 07/03/16.
//

#include "TerrainNode.h"

TerrainNode::TerrainNode(int x, int y, TerrainNode* previousNode){
    this->x = x;
    this->y = y;
    this->previousNode = previousNode;
}

int TerrainNode::getX() {
    return x;
}

int TerrainNode::getY() {
    return y;
}

TerrainNode* TerrainNode::getPrevNode() {
    return previousNode;
}

bool TerrainNode::equals(TerrainNode *other) {
    return x == other->getX() && y == other->getY();
}
