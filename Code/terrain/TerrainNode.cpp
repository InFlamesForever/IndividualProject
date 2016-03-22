//
// Created by richard on 07/03/16.
//

#include "TerrainNode.h"

TerrainNode::TerrainNode(int x, int y, shared_ptr<TerrainNode> prev){
    this->x = x;
    this->y = y;
    previousNode = prev;
    if(prev == NULL){
        disFromStart = 0;
    } else {
        disFromStart = prev->getDistFromStart()+1;
    }
}

int TerrainNode::getX() {
    return x;
}

int TerrainNode::getY() {
    return y;
}

shared_ptr<TerrainNode> TerrainNode::getPrevNode() {
    return previousNode;
}

TerrainNode::~TerrainNode() {

}

int TerrainNode::getDistFromStart() {
    return disFromStart;
}

void TerrainNode::setPreNodeToNULL() {
    previousNode = NULL;
}
