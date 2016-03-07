//
// Created by richard on 07/03/16.
//

#ifndef INDIVIDUALPROJECT_SEARCH_H
#define INDIVIDUALPROJECT_SEARCH_H

#include "vector"
#include "../utilities/TerrainNode.h"
#include <iostream>

using namespace std;

class Search {
    /**
     * Finds the route for roads
     */
    vector<pair<int, int>> aStarSearch(int startX, int startY, int endX, int endY);

    int findBestNode(vector<TerrainNode> unExpNodes);



};


#endif //INDIVIDUALPROJECT_SEARCH_H
