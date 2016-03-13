//
// Created by richard on 12/03/16.
//

#ifndef INDIVIDUALPROJECT_ASTARSEARCH_H
#define INDIVIDUALPROJECT_ASTARSEARCH_H

#include "../terrain/TerrainNode.h"
#include <vector>
#include "constants.h"
#include "../Characters/Character.h"
#include <stdint.h>
#include <memory>
#include <bits/shared_ptr.h>

using namespace std;

class AStarSearch {
public:
    AStarSearch(int **terrain);

    /**
     * Finds the route for roads
     */
    shared_ptr<TerrainNode> aStarSearch(int startX, int startY, int endX, int endY,
                             int* cantTraverse = NULL, int cantTraverseSize = 0);
private:
    /**
 * Finds the best node to move to next for the search
 */
    int findBestNode(vector<shared_ptr<TerrainNode>> unExpNodes,
                     int endX, int endY, shared_ptr<TerrainNode> curNode);

    vector<shared_ptr<TerrainNode>> expNodes;

    int **terrain;

};


#endif //INDIVIDUALPROJECT_ASTARSEARCH_H
