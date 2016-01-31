//
// Created by richard on 17/12/15.
//

#include "functions.h"


bool init() {

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
    gDotTexture.free();

    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}