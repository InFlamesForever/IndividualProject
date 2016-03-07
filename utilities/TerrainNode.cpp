//
// Created by richard on 07/03/16.
//

#include "TerrainNode.h"

TerrainNode::TerrainNode(int x, int y, TerrainNode* previousNode, int endX, int endY){
    this->x = x;
    this->y = y;
    this->previousNode = previousNode;

    if(previousNode == NULL){
        distFromStart = 0;
    } else {
        distFromStart = previousNode->getDistFromStart() + 1;
    }

    distToGoal = abs(x - endX) + abs(y - endY);
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

int TerrainNode::getDistFromStart() {
    return distFromStart;
}

int TerrainNode::getDistToGoal() {
    return distToGoal;
}
