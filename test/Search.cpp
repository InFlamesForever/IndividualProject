//
// Created by richard on 07/03/16.
//

#include "Search.h"

vector<pair<int, int>> Search::aStarSearch(int startX, int startY,
                                                     int endX, int endY) {
    vector<TerrainNode> unExpNodes;
    vector<TerrainNode> expNodes;
    TerrainNode curNode(NULL,NULL,NULL,NULL,NULL);

    TerrainNode temp(startX,startY,NULL, endX, endX);
    unExpNodes.push_back(temp);

    cout << startX << " start " << startY << endl;
    cout << endX << " end " << endY << endl;

    int counter = 0;
    while(!unExpNodes.empty()){

        //Finds the best node in the vector and then removes it
        int bestNode = findBestNode(unExpNodes);
        curNode = TerrainNode(unExpNodes[bestNode].getX(), unExpNodes[bestNode].getY(), unExpNodes[bestNode].getPrevNode(), endX, endY);
        unExpNodes.erase(unExpNodes.begin()+bestNode);
        expNodes.push_back(curNode);
        counter++;

        cout << curNode.getDistFromStart() << " <- dist from start | dist to goal ->" << curNode.getDistToGoal() <<   endl;
        cout << curNode.getX() << " x and y of current node " << curNode.getY() <<   endl;

        if(curNode.getX() == endX && curNode.getY() == endY){
            break;
        }

        int potentialMoves[4][2] = {
                {curNode.getX()-1, curNode.getY()},
                {curNode.getX()+1, curNode.getY()},
                {curNode.getX(), curNode.getY()-1},
                {curNode.getX(), curNode.getY()+1}
        };

        for(int i = 0; i < 4; i++){
            TerrainNode checkNode(potentialMoves[i][0], potentialMoves[i][1], &curNode, endX, endX);
            //cout << curNode.getX() << " " << curNode.getY() << " <node > " << potentialMoves[i][0] << " " << potentialMoves[i][1] << endl;
            bool foundUnexp = false;
            bool foundExp = false;
            //cout << "size " << unExpNodes.size() << endl;
            for(int j = 0; j < unExpNodes.size(); j++){
                if(unExpNodes[j].getX() == potentialMoves[i][0] && unExpNodes[j].getY() == potentialMoves[i][1]){
                    foundUnexp = true;
                    //cout << "yes" << unExpNodes[j].getX() << " " << unExpNodes[j].getY() <<  " <node > " << potentialMoves[i][0] << " " << potentialMoves[i][1] << endl;
                }
                if(expNodes[j].equals(&checkNode)){
                    foundExp = true;
                }
                if(foundUnexp && foundExp){
                    break;
                }
            }
            if(!foundExp && !foundUnexp){
                unExpNodes.push_back(checkNode);
            }
        }
    }


    cout << curNode.getX() << " found " << curNode.getY() << endl;

    return std::vector<pair<int, int>>();
}

int Search::findBestNode(vector<TerrainNode> unExpNodes) {
    int closest = INT32_MAX;
    int place = 0;
    int aStar;

    for(int i = 0; i < unExpNodes.size(); i++){
        aStar = unExpNodes[i].getDistFromStart() + unExpNodes[i].getDistToGoal();
        if(aStar < closest){
            closest = aStar;
            place = i;
        }
    }
    return place;
}