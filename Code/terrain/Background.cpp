#include "Background.h"
#include "TerrainGenerator.h"
#include "../media/TileInfo.h"

Background::Background() {
    //Create and initialise terrain
    for(int i = 0; i < TERRAIN_SIZE; i++){
        terrain[i] = new int[TERRAIN_SIZE];
        terrainDetail[i] = new int[TERRAIN_SIZE];
     }

    TerrainGenerator generator(terrain, terrainDetail);
    townPositions = generator.getTownLocations();
    numTowns = generator.getNumTowns();

    //So that the start position can be stored in a file eventually
    pointInTerrainX = townPositions[0][0] - ((SCREEN_WIDTH /2) / BLOCK_WIDTH);
    pointInTerrainY = townPositions[0][1] - ((SCREEN_HEIGHT/2) /BLOCK_WIDTH);

    getTerrain();
    composeTerrainToTexture();
}

Background::~Background() {
    for(int i = 0; i < TERRAIN_SIZE; i++){
        delete[] terrain[i];
        delete[] terrainDetail[i];
    }
    delete[] terrain;
    delete[] terrainDetail;

    for(int i = 0; i < 8; i++){
        delete[] townPositions[i];
    }
    delete[] townPositions;
}

void Background::render() {
    //When moving from side to side
    if(moveOffsetX != 0){
        if(moveOffsetX > 0){
            for(int i = 0; i < numOfTilesHeight; i++){
                renderTile(pointInTerrainX - 1, pointInTerrainY + i,
                           moveOffsetX - BLOCK_WIDTH, i * BLOCK_WIDTH);
            }
        } else {
            for(int i = 0; i < numOfTilesHeight; i++){
                renderTile(pointInTerrainX + numOfTilesWidth,
                           pointInTerrainY + i,
                           numOfTilesWidth * BLOCK_WIDTH + moveOffsetX,
                           i * BLOCK_WIDTH);
            }
        }
        //When moving up and down
    } else if(moveOffsetY != 0){
        if(moveOffsetY > 0){
            for(int i = 0; i < numOfTilesWidth; i++){
                renderTile(pointInTerrainX + i, pointInTerrainY - 1,
                           i * BLOCK_WIDTH, moveOffsetY - BLOCK_WIDTH);
            }
        } else {
            for(int i = 0; i < numOfTilesWidth; i++){
                renderTile(pointInTerrainX + i,
                           pointInTerrainY + numOfTilesHeight, i * BLOCK_WIDTH,
                           numOfTilesHeight * BLOCK_WIDTH + moveOffsetY);
            }
        }
    }
    terrainTexture.render(moveOffsetX, moveOffsetY);
}

void Background::renderTile(int terX, int terY, int renX, int renY){
    //Checks if the tile in question is on map or not
    // if it isn't use an ocean tile
    if(terX > TERRAIN_SIZE - 1 || terX < 0 ||
       terY > TERRAIN_SIZE - 1 || terY < 0){
        gWater_SeaTexture.render(renX, renY);
    } else {
        terrainChooser[terrain[terX][terY]]
                    ->render(renX, renY);
        renderAboveTerrainDetail(terX, terY, renX, renY);
    }
}

void Background::getTerrain() {
    onScreenTerrain.clear();
    int pointX = pointInTerrainX;
    int pointY = pointInTerrainY;
    int i = 0;
    int j = 0;
    while(j >= 0) {
        //Creates 2D Coordinates
        int x = i * BLOCK_WIDTH;
        int y = j * BLOCK_WIDTH;

        if (x + BLOCK_WIDTH > -5 && y < SCREEN_HEIGHT) {
            //Checks if the tile in question is on map or not
            // if it isn't use an ocean tile
            if(pointX < 0 || pointY < 0 ||
                    pointX + i > TERRAIN_SIZE - 1||
                    pointY + j > TERRAIN_SIZE - 1){
                onScreenTerrain.push_back(TileInfo(TerrainTypes::Water_Ocean,
                                                   pointX, pointY, i, j));
            } else {
                onScreenTerrain.push_back(TileInfo(terrain[pointX][pointY],
                                                   pointX, pointY, i, j));
            }
        }

        i++;
        pointX++;
        if(x + BLOCK_WIDTH > SCREEN_WIDTH - BLOCK_WIDTH){
            numOfTilesWidth = i;
            i = 0;
            pointX = pointInTerrainX;
            j++;
            pointY++;
        }
        if(y > SCREEN_HEIGHT - BLOCK_WIDTH){
            numOfTilesHeight = j;
            j = -1;
        }
    }
}


bool Background::move(float timeStep, int xShift, int yShift) {
    if(xShift != 0){
        movedSoFar += xShift * MOVE_SPEED * timeStep;
        if(movedSoFar > BLOCK_WIDTH || movedSoFar < -BLOCK_WIDTH) {
            moveOffsetX = 0;
            movedSoFar = 0;
            pointInTerrainX += -(xShift / 16);
            getTerrain();
            composeTerrainToTexture();
            return false;
        }
        moveOffsetX = (int) movedSoFar;
        return true;

    } else if(yShift != 0) {
        movedSoFar += yShift * MOVE_SPEED * timeStep;
        if(movedSoFar > BLOCK_WIDTH || movedSoFar < -BLOCK_WIDTH) {
            moveOffsetY = 0;
            movedSoFar = 0;
            pointInTerrainY += -(yShift / 16);
            getTerrain();
            composeTerrainToTexture();
            return false;
        }
        moveOffsetY = (int) movedSoFar;
        return true;
    }

    return false;
}

void Background::composeTerrainToTexture() {
    //The texture is cleared to stop glitches with transparent textures
    //and the re-used texture
    terrainTexture.clearTexture();

    //Target the texture rather than the window
    terrainTexture.setAsRenderTarget();

    //Go through the onScreenTerrain vector and render all textures to the
    //terrain texture
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.h = BLOCK_WIDTH;
    rect.w = BLOCK_WIDTH;
    for(int i = 0; i < onScreenTerrain.size(); i++) {
        terrainChooser[onScreenTerrain[i].getTexture()]
                ->render(onScreenTerrain[i].getXOnScreen() * BLOCK_WIDTH,
                         onScreenTerrain[i].getYOnScreen() * BLOCK_WIDTH,
                         &rect);

    }
    //Secondary for loop required otherwise the larger textures are written over
    for(int i = 0; i < onScreenTerrain.size(); i++){
        renderAboveTerrainDetail(onScreenTerrain[i].getXInTerrain(),
                                 onScreenTerrain[i].getYInTerrain(),
                                 onScreenTerrain[i].getXOnScreen() * BLOCK_WIDTH,
                                 onScreenTerrain[i].getYOnScreen() * BLOCK_WIDTH);
    }
    //Return the render target to the window
    SDL_SetRenderTarget(gRenderer, NULL);
}

void Background::renderAboveTerrainDetail(int x, int y, int renX, int renY) {
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    //Check if in bounds of map
    if(x >= 0 && x < TERRAIN_SIZE - 1
       && y >= 0 && y < TERRAIN_SIZE - 1
       //If within bounds check if there is something to display
       && terrainDetail[x][y] < INT32_MAX) {
        Texture *tex = aboveTerrainChooser[terrainDetail[x][y]];
        if (tex->getHeight() == 16) {
            rect.w = BLOCK_WIDTH;
            rect.h = BLOCK_WIDTH;
            tex->render(renX, renY, &rect);
        } else {
            rect.w = BLOCK_WIDTH * 2;
            rect.h = BLOCK_WIDTH * 2;
            tex->render(renX - BLOCK_WIDTH / 2, renY - BLOCK_WIDTH, &rect);
        }
    }
}

int Background::getSquare(int x, int y) {
    return terrain[x][y];
}

int Background::getOffsetX() {
    return moveOffsetX;
}

int Background::getOffsetY() {
    return moveOffsetY;
}

int Background::getPointInTerrainY() {
    return pointInTerrainY;
}

int Background::getPointInTerrainX() {
    return pointInTerrainX;
}

int **Background::getMap() {
    return terrain;
}

int** Background::getTownPositions() {
    return townPositions;
}

int Background::getNumTowns() {
    return numTowns;
}

void Background::setPointInTerrain(int x, int y) {
    pointInTerrainX = x;
    pointInTerrainY = y;
}
