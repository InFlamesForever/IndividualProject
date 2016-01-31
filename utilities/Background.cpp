#include "Background.h"

Background::Background() {
    terrain.reserve(3000);
    SDL_SetRenderTarget(gRenderer, tileTexture);

    //Cleans the screen to make sure the background is correct
    SDL_RenderCopy(gRenderer, gStone_Gray_VeryDarkTexture.getTexture(), NULL,
                   NULL);
    int i = 0;
    int j = 0;

    //Initialize moveXTo0 and moveYTo0
    int x = 0;
    int y = 0;
    convert2Dto25D(&x, &y);
    moveXTo0 = x;
    moveYTo0 = y;


    while(j >= 0) {
        //Creates 2D Coordinates
        x = i * BLOCK_WIDTH;
        y = j * BLOCK_WIDTH;

        convert2Dto25D(&x, &y);

        if (x + BLOCK_WIDTH > -15 && y < SCREEN_HEIGHT) {
            TextureInfo temp;
            if (i % 2 == 0)
                temp.setUp(&gWater_SeaTexture, x, y);
            else
                temp.setUp(&gGrass_LushLightTexture, x, y);

            terrain.push_back(temp);
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

    SDL_Rect dst;
    j = 1;
    int lastY = 0;
    int nextY = 0;
    for(i = 0; i < terrain.size() - 1; i++){
        int width  = terrain[i+1].getX() - terrain[i].getX();
        width > 0 ? dst.w = width : dst.w = BLOCK_WIDTH;

        if(lastY != terrain[i].getY()){
            j++;
            int u = 0;
            int v = j * BLOCK_WIDTH;

            convert2Dto25D(&u, &v);
            nextY = v;

            lastY = terrain[i].getY();
        }

        int h = nextY - terrain[i].getY();
        h > 0 ? dst.h = h : dst.h = BLOCK_WIDTH;
        dst.x = terrain[i].getX();
        dst.y = terrain[i].getY();

        SDL_RenderCopy(gRenderer, terrain[i].getTexture()->getTexture(), NULL,
                       &dst);
    }

    dst.x = terrain[terrain.size() - 1].getX();
    dst.y = terrain[terrain.size() - 1].getY();
    SDL_RenderCopy(gRenderer, terrain[terrain.size() - 1].getTexture()->getTexture(), NULL,
                   &dst);


    SDL_SetRenderTarget(gRenderer, NULL);
}

void Background::render() {
    SDL_RenderCopy(gRenderer, tileTexture, NULL, NULL);
}

void Background::convert2Dto25D(int *x, int *y) {
    double t = -1; // tilt angle
    double X = *x - SCREEN_WIDTH / 2;
    double Y = *y - SCREEN_HEIGHT / 2;
    double a = (SCREEN_HEIGHT / (SCREEN_HEIGHT + Y * sin(t)));

    *x = (int) (a * X + SCREEN_WIDTH / 2) - moveXTo0;
    *y = (int) (a * Y * cos(t) + SCREEN_HEIGHT / 2) - moveYTo0;
}
