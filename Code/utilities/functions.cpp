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

                //Initialize SDL_ttf
                if( TTF_Init() == -1 )
                {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
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
    gStock_Back.free();
    gStock_Back_Walking1.free();
    gStock_Back_Walking2.free();
    gStock_Front.free();
    gStock_Front_Walking1.free();
    gStock_Front_Walking2.free();
    gStock_Side_Right.free();
    gStock_Side_Right_Walking.free();
    gStock_Side_Right_Walking2.free();
    gStock_Side_Right_Walking3.free();

    gEnemy_Slime.free();
    gEnemy_Slime_Angry.free();
    gEnemy_Slime_Attack.free();

    gEnemy_Blob.free();
    gEnemy_Blob_Angry.free();
    gEnemy_Blob_Attack.free();


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
    gPavement_Bridge.free();
    gPavement_Bridge_Horizontal.free();

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

    gSnow.free();

    gTownSymbol.free();

    gTown_Door_Closed.free();
    gTown_Door_HalfOpen.free();
    gTown_Door_ThreeQuartersOpen.free();
    gTown_Door_Open.free();

    gTown_Roof_Thatched.free();
    gTown_Roof_Thatched_Corner.free();

    gTown_Wall_Wood.free();
    gTown_Wall_Wood_Corner_Left_Ground.free();
    gTown_Wall_Wood_Corner_Left_Upper.free();
    gTown_Wall_Wood_Corner_Right_Ground.free();
    gTown_Wall_Wood_Corner_Right_Upper.free();
    gTown_Wall_Wood_Window.free();

    gWater_SeaWaves.free();

    gTree_Dark.free();
    gTree_Medium.free();
    gTree_MediumLittle.free();
    gTree_Light.free();

    //-------------------------------------------------------------------------
    //#################### Close Fonts ########################################
    //-------------------------------------------------------------------------
    //Free global fonts
    TTF_CloseFont(gFont_HealthBar);
    gFont_HealthBar = NULL;

    TTF_CloseFont(gCantarell_Bold);
    gCantarell_Bold = NULL;

    TTF_CloseFont(gCantarell_Oblique);
    gCantarell_Oblique = NULL;

    TTF_CloseFont(gCantarell_Oblique_Bold);
    gCantarell_Oblique_Bold = NULL;

}
