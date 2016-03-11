//
// Created by richard on 17/12/15.
//

#include "functions.h"


bool init() {
    srand((unsigned)time(0));

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL could not initialize! SDL Error: %s"
        << SDL_GetError() << endl;

        return false;
    } else {
        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            cout << "Warning: Linear texture filtering not enabled!" << endl;
        }

        //Create window
        gWindow = SDL_CreateWindow("Individual Project Game", SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                   SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            cout << "Window could not be created! SDL Error: %s"
            << SDL_GetError() << endl;

            return false;
        } else {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1,
                                           SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL) {
                cout << "Renderer could not be created! SDL Error: %s"
                << SDL_GetError() << endl;

                return false;
            } else {
                //Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                    cout <<
                    "SDL_image could not initialize! SDL_image Error: %s"
                    << IMG_GetError() << endl;

                    return false;
                }
            }
        }
    }

    return true;
}

void close() {
    //Free loaded images
    free();

    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

void free() {
    gStock_Front.free();
    gStock_Side_Right.free();
    gStock_Side_Right_Walking.free();

    gDirt_DirtTexture.free();
    gDirt_DirtGravelTexture.free();
    gDirt_GravelTexture.free();

    gGrass_DeadTexture.free();
    gGrass_DryTexture.free();
    gGrass_DyingTexture.free();
    gGrass_LushDeepTexture.free();
    gGrass_LushLightTexture.free();
    gGrass_ParchedTexture.free();

    gPavement_CobblestoneTexture.free();

    gSand_DarkTexture.free();
    gSand_LightTexture.free();

    gStone_Gray_DarkTexture.free();
    gStone_Gray_LightTexture.free();
    gStone_Gray_MediumTexture.free();
    gStone_Gray_VeryDarkTexture.free();
    gStone_Gray_VeryLightTexture.free();

    gStone_Sand_DarkTexture.free();
    gStone_Sand_LightTexture.free();
    gStone_Sand_MediumTexture.free();
    gStone_Sand_VeryLightTexture.free();

    gWater_RiverTexture.free();
    gWater_SeaTexture.free();
    gWater_SmallStreamTexture.free();
}
