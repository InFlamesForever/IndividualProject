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

private:
    TextureInfo background [100][100];
    int numTilesWidth = SCREEN_WIDTH / 16;
    int numTilesHeight = SCREEN_HEIGHT / 16;
};


#endif //INDIVIDUALPROJECT_BACKGROUND_H
