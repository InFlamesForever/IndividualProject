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

using namespace std;

class AStarSearch {
public:
    AStarSearch(int **terrain);
    ~AStarSearch();

    /**
 * Finds the route for roads
 */
    TerrainNode* aStarSearch(int startX, int startY, int endX, int endY,
                             Character* ch = NULL);
private:
    /**
 * Finds the best node to move to next for the search
 */
    int findBestNode(vector<TerrainNode*> unExpNodes,
                     int endX, int endY, TerrainNode* curNode);

    vector<TerrainNode*> expNodes;

    int **terrain;

};


#endif //INDIVIDUALPROJECT_ASTARSEARCH_H
