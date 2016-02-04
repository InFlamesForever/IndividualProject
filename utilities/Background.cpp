#include "Background.h"

Background::Background() {
    //Create and initialise terrain
    for(int i = 0; i < terrainSize; i++){
           terrain[i] = new TextureInfo[terrainSize];
     }

    //Creates a random terrain
    for(int i = 0; i < terrainSize; i++){
       for(int j = 0; j < terrainSize; j++) {
           terrain[i][j].setUp(terrainChooser[rand() % 24], i, j);
       }
    }

    //So that the start position can be stored in a file eventually
    pointInTerrainX = 100;
    pointInTerrainY = 100;

    onScreenTerrain.reserve(3000);

    //Initialize moveXTo0 and moveYTo0
    //These will change with the size of the window
    int x = 0;
    int y = 0;
    convert2Dto25D(&x, &y);
    moveXTo0 = x;
    moveYTo0 = y;

    getTerrain();
    composeTerrainToTexture();
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
    tileTexture.render(moveBackgroundX, moveBackgroundY);
}

void Background::renderTile(int terX, int terY, int renX, int renY){
    terrain[terX][terY].getTexture()->render(renX, renY);
}

void Background::convert2Dto25D(int *x, int *y) {
    double t = -0; // tilt angle
    double X = *x - SCREEN_WIDTH / 2;
    double Y = *y - SCREEN_HEIGHT / 2;
    double a = (SCREEN_HEIGHT / (SCREEN_HEIGHT + Y * sin(t)));

    *x = (int) (a * X + SCREEN_WIDTH / 2) - moveXTo0;
    *y = (int) (a * Y * cos(t) + SCREEN_HEIGHT / 2) - moveYTo0;
}

void Background::composeTerrainToTexture() {
    //The texture is cleared to stop glitches with transparent textures
    //and the re-used texture
    tileTexture.clearTexture();

    tileTexture.setAsRenderTarget();

    SDL_Rect dst;
    int j = 1;
    int lastY = 0;
    int nextY = 0;
    for(int i = 0; i < onScreenTerrain.size() - 1; i++){
        int width  = onScreenTerrain[i + 1].getX() - onScreenTerrain[i].getX();
        width > 0 ? dst.w = width : dst.w = BLOCK_WIDTH;

        if(lastY != onScreenTerrain[i].getY()){
            j++;
            int u = 0;
            int v = j * BLOCK_WIDTH;

            convert2Dto25D(&u, &v);
            nextY = v;

            lastY = onScreenTerrain[i].getY();
        }

        int h = nextY - onScreenTerrain[i].getY();
        h > 0 ? dst.h = h : dst.h = BLOCK_WIDTH;

        dst.x = onScreenTerrain[i].getX();
        dst.y = onScreenTerrain[i].getY();

        onScreenTerrain[i].getTexture()->render(dst.x,dst.y);
    }

    dst.x = onScreenTerrain[onScreenTerrain.size() - 1].getX();
    dst.y = onScreenTerrain[onScreenTerrain.size() - 1].getY();
    onScreenTerrain[onScreenTerrain.size() - 1].getTexture()->render(dst.x,dst.y);


    SDL_SetRenderTarget(gRenderer, NULL);
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

        convert2Dto25D(&x, &y);

        if (x + BLOCK_WIDTH > -5 && y < SCREEN_HEIGHT) {
            TextureInfo temp;
            temp.setUp(terrain[pointX][pointY].getTexture(), x, y);

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
    //Stops movement off the edge of the map
    if(pointInTerrainX == 1 && xShift > 0 || pointInTerrainY == 1 && yShift > 0){
        return false;
    }
    if(xShift != 0){
        movedSoFar += xShift * moveConst * timeStep;
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
        movedSoFar += yShift * moveConst * timeStep;
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


Background::~Background() {
    for(int i = 0; i < terrainSize; i++){
        delete[] terrain[i];
    }
    delete[] terrain;
}