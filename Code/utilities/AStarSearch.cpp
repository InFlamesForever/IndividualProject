//
// Created by richard on 12/03/16.
//

#include "AStarSearch.h"

AStarSearch::AStarSearch(int **terrain) {
    this-> terrain = terrain;
}


shared_ptr<TerrainNode> AStarSearch::aStarSearch(int startX, int startY, int endX,
                                      int endY, int* cantTraverse, int cantTraverseSize) {
    vector<shared_ptr<TerrainNode>> unExpNodes;

    expNodes.clear();
    shared_ptr<TerrainNode> curNode(NULL);

    shared_ptr<TerrainNode> temp(new TerrainNode(startX,startY));
    unExpNodes.push_back(temp);

    int counter = 0;
    while(!unExpNodes.empty()){
        //Finds the best node in the vector and then removes it
        int bestNode = findBestNode(unExpNodes, endX, endY, curNode);

        curNode = shared_ptr<TerrainNode>(new TerrainNode(unExpNodes[bestNode]->getX(), unExpNodes[bestNode]->getY(), curNode));

        unExpNodes.erase(unExpNodes.begin()+bestNode);
        expNodes.push_back(curNode);
        counter++;

        if(curNode->getX() == endX && curNode->getY() == endY){
            break;
        }

        int potentialMoves[4][2] = {
                {curNode->getX()-1, curNode->getY()},
                {curNode->getX()+1, curNode->getY()},
                {curNode->getX(), curNode->getY()-1},
                {curNode->getX(), curNode->getY()+1}
        };

        for(int i = 0; i < 4; i++) {
            bool createNode = false;
            if(cantTraverse != NULL){
                for(int j = 0; j < cantTraverseSize; j++){
                    if(terrain[potentialMoves[i][0]]
                       [potentialMoves[i][1]] == cantTraverse[i]){
                        createNode = false;
                        break;
                    } else {
                        createNode = true;
                    }
                }
            } else {
                createNode = true;
            }
            if(createNode){
                shared_ptr<TerrainNode> checkNode(
                        new TerrainNode(potentialMoves[i][0],
                                        potentialMoves[i][1],
                                        curNode));
                bool foundUnexp = false;
                bool foundExp = false;
                for (int j = 0; j < unExpNodes.size(); j++) {
                    if (unExpNodes[j]->getX() == potentialMoves[i][0] &&
                        unExpNodes[j]->getY() == potentialMoves[i][1]) {
                        foundUnexp = true;
                        break;
                    }
                }
                for (int j = 0; j < expNodes.size(); j++) {
                    if (expNodes[j]->getX() == potentialMoves[i][0] &&
                        expNodes[j]->getY() == potentialMoves[i][1]) {
                        foundExp = true;
                        break;
                    }
                }
                if (!foundExp && !foundUnexp) {
                    unExpNodes.push_back(checkNode);
                }
            }
        }
    }

    return curNode;
}


int AStarSearch::findBestNode(vector<shared_ptr<TerrainNode>> unExpNodes, int endX,
                              int endY, shared_ptr<TerrainNode> curNode) {
    double closest = INT32_MAX;
    int place = 0;
    double aStar;

    for(int i = 0; i < unExpNodes.size(); i++){
        int x = unExpNodes[i]->getX();
        int y = unExpNodes[i]->getY();
        double manDistance = abs(x - endX) + abs(y - endY);
        if(terrain[x][y] == Water_Ocean) {
            manDistance += 1;
        } else if(terrain[x][y] == Stone_Gray_VeryLight) {
            manDistance += 0.9;
        } else if(terrain[x][y] == Stone_Gray_Light || terrain[x][y] == Stone_Gray_Medium) {
            manDistance += 0.8;
        } else if(terrain[x][y] == Stone_Gray_Dark || terrain[x][y] == Stone_Gray_VeryDark) {
            manDistance += 0.7;
        } else if(terrain[x][y] == SandDark || terrain[x][y] == SandLight){
            manDistance += 0.5;
        } else if(terrain[x][y] == Dirt_DirtGravel || terrain[x][y] == Dirt_Dirt
                  || terrain[x][y] == Dirt_Gravel){
            manDistance += 0.3;
        }
        if(curNode == NULL) {
            aStar = manDistance + 0;
        } else {
            aStar = manDistance + curNode->getDistFromStart() + 1;
        }
        if(aStar < closest){
            closest = aStar;
            place = i;
        }
    }
    return place;
}

