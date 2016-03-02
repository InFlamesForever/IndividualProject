#include "Background.h"
#include "TerrainGenerator.h"

Background::Background() {
    //Create and initialise terrain
    for(int i = 0; i < TERRAIN_SIZE; i++){
        terrain[i] = new TextureInfo[TERRAIN_SIZE];
        terrainDetail[i] = new TextureInfo[TERRAIN_SIZE];
     }

    TerrainGenerator generator;
    generator.generateTerrain(terrain);

    //So that the start position can be stored in a file eventually
    pointInTerrainX = STARTX;
    pointInTerrainY = STARTY;

    onScreenTerrain.reserve(3000);

    //Initialize moveXTo0 and moveYTo0
    //These will change with the size of the window
    int x = 0;
    int y = 0;

    moveXTo0 = x;
    moveYTo0 = y;

    getTerrain();
    composeTerrainToTexture();
}

Background::~Background() {
    for(int i = 0; i < TERRAIN_SIZE; i++){
        delete[] terrain[i];
    }
    delete[] terrain;
}

void Background::render() {

    if(moveBackgroundX != 0){
        if(moveBackgroundX > 0){
            for(int i = 0; i < numOfTilesHeight; i++){
                renderTile(pointInTerrainX - 1, pointInTerrainY + i,
                           moveBackgroundX - BLOCK_WIDTH, i * BLOCK_WIDTH);
            }
        } else {
            for(int i = 0; i < numOfTilesHeight; i++){
                renderTile(pointInTerrainX + numOfTilesWidth,
                           pointInTerrainY + i,
                           numOfTilesWidth * BLOCK_WIDTH + moveBackgroundX,
                           i * BLOCK_WIDTH);
            }
        }
    } else if(moveBackgroundY != 0){
        if(moveBackgroundY > 0){
            for(int i = 0; i < numOfTilesWidth; i++){
                renderTile(pointInTerrainX + i, pointInTerrainY - 1,
                           i * BLOCK_WIDTH, moveBackgroundY - BLOCK_WIDTH);
            }
        } else {
            for(int i = 0; i < numOfTilesWidth; i++){
                renderTile(pointInTerrainX + i,
                           pointInTerrainY + numOfTilesHeight, i * BLOCK_WIDTH,
                           numOfTilesHeight * BLOCK_WIDTH + moveBackgroundY);
            }
        }
    }
    terrainTexture.render(moveBackgroundX, moveBackgroundY);
}

void Background::renderTile(int terX, int terY, int renX, int renY){
    //Checks if the tile in question is on map or not
    // if it isn't use an ocean tile
    if(terX > TERRAIN_SIZE || terX < 0 ||
            terX + renX + 1 > TERRAIN_SIZE ||
            terY + renY + 1 > TERRAIN_SIZE){
        gWater_SeaTexture.render(renX, renY);
    } else {
        terrainChooser[terrain[terX][terY].getTexture()]
                    ->render(renX, renY);
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
            TextureInfo temp;
            //Checks if the tile in question is on map or not
            // if it isn't use an ocean tile
            if(pointX < 0 || pointY < 0 ||
                    pointX + x + 1> TERRAIN_SIZE ||
                    pointY + y + 1> TERRAIN_SIZE){
                temp.setUp(TerrainTypes::Water_Ocean, x, y);
            } else {
                temp.setUp(terrain[pointX][pointY].getTexture(), x, y);
            }

            onScreenTerrain.push_back(temp);
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
            moveBackgroundX = 0;
            movedSoFar = 0;
            pointInTerrainX += -(xShift / 16);
            getTerrain();
            composeTerrainToTexture();
            return false;
        }
        moveBackgroundX = (int) movedSoFar;
        return true;

    } else if(yShift != 0) {
        movedSoFar += yShift * MOVE_SPEED * timeStep;
        if(movedSoFar > BLOCK_WIDTH || movedSoFar < -BLOCK_WIDTH) {
            moveBackgroundY = 0;
            movedSoFar = 0;
            pointInTerrainY += -(yShift / 16);
            getTerrain();
            composeTerrainToTexture();
            return false;
        }
        moveBackgroundY = (int) movedSoFar;
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
    for(int i = 0; i < onScreenTerrain.size(); i++){
        terrainChooser[onScreenTerrain[i].getTexture()]
                ->render(onScreenTerrain[i].getX(),onScreenTerrain[i].getY());
    }
    //Return the render target to the window
    SDL_SetRenderTarget(gRenderer, NULL);
}