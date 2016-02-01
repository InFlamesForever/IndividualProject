#include "Background.h"

Background::Background() {
    for(int i = 0; i < terrainSize; i++){
           terrain[i] = new TextureInfo[terrainSize];
     }

    //Creates a random terrain
    for(int i = 0; i < terrainSize; i++){
       for(int j = 0; j < terrainSize; j++) {
           terrain[i][j].setUp(terrainChooser[rand() % NUM_TEXTURES], i, j);
       }
    }

    //So that the start position can be stored in a file eventually
    pointInTerrainX = 0;
    pointInTerrainY = 0;

    onScreenTerrain.reserve(3000);

    //Initialize moveXTo0 and moveYTo0
    //These will change with the size of the window
    int x = 0;
    int y = 0;
    convert2Dto25D(&x, &y);
    moveXTo0 = x;
    moveYTo0 = y;

    int i = pointInTerrainX;
    int j = pointInTerrainY;
    while(j >= 0) {
        //Creates 2D Coordinates
        x = i * BLOCK_WIDTH;
        y = j * BLOCK_WIDTH;

        convert2Dto25D(&x, &y);

        if (x + BLOCK_WIDTH > -15 && y < SCREEN_HEIGHT) {
            TextureInfo temp;
            temp.setUp(terrain[i][j].getTexture(), x, y);

            onScreenTerrain.push_back(temp);

        }

        i++;
        if(x + BLOCK_WIDTH> SCREEN_WIDTH){
            i = 0;
            j++;
        }
        if(y > SCREEN_HEIGHT){
            j = -1;
        }
    }
    composeTerrainToTexture();
}

void Background::render() {
    SDL_RenderCopy(gRenderer, tileTexture, NULL, NULL);
}

void Background::convert2Dto25D(int *x, int *y) {
    double t = -0; // tilt angle
    double X = *x - SCREEN_WIDTH / 2;
    double Y = *y - SCREEN_HEIGHT / 2;
    double a = (SCREEN_HEIGHT / (SCREEN_HEIGHT + Y * sin(t)));

    *x = (int) (a * X + SCREEN_WIDTH / 2) - moveXTo0;
    *y = (int) (a * Y * cos(t) + SCREEN_HEIGHT / 2) - moveYTo0;
}

Background::~Background() {
    for(int i = 0; i < terrainSize; i++){
        delete[] terrain[i];
    }
    delete[] terrain;
}

void Background::composeTerrainToTexture() {
    SDL_SetRenderTarget(gRenderer, tileTexture);

    //Cleans the screen to make sure the background to make sure nothing is held
    // from previous renders
    SDL_RenderCopy(gRenderer, gStone_Gray_VeryDarkTexture.getTexture(), NULL,
                   NULL);

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

        SDL_RenderCopy(gRenderer, onScreenTerrain[i].getTexture()->getTexture(), NULL,
                       &dst);
    }

    dst.x = onScreenTerrain[onScreenTerrain.size() - 1].getX();
    dst.y = onScreenTerrain[onScreenTerrain.size() - 1].getY();
    SDL_RenderCopy(gRenderer, onScreenTerrain[onScreenTerrain.size() - 1].getTexture()->getTexture(), NULL,
                   &dst);


    SDL_SetRenderTarget(gRenderer, NULL);
}

void Background::moveUpdate() {

}
