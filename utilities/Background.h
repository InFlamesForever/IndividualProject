//
// Created by richard on 28/12/15.
//

#ifndef INDIVIDUALPROJECT_BACKGROUND_H
#define INDIVIDUALPROJECT_BACKGROUND_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "constants.h"
#include "textures.h"
#include "vector"
#include "TextureInfo.h"
#include "math.h"

class Background {
public:
    Background();
    void render();

    //Converts 2D coordinates to 2.5D Coordinates
    void convert2Dto25D(int *X, int *Y);

private:
    vector<TextureInfo> terrain;
    int numTilesWidth = SCREEN_WIDTH / 16;
    int numTilesHeight = SCREEN_HEIGHT / 16;

    //These are required to move x and y to start at 00 otherwise
    //the blocks start half way down the screen
    int moveXTo0 = 0;
    int moveYTo0 = 0;

    SDL_Texture* tileTexture =
            SDL_CreateTexture(gRenderer, SDL_PIXELFORMAT_RGBA8888,
                              SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH,
                              SCREEN_HEIGHT);
};


#endif //INDIVIDUALPROJECT_BACKGROUND_H
