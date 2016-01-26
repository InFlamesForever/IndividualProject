//
// Created by richard on 17/01/16.
//

#include "loadMedia.h"

bool loadMedia() {
    //Load dot texture
    if (!gDotTexture.loadFromFile("textures/characters/dot.bmp")) {
        cout << "Failed to load dot texture!" << endl;
        return false;
    }

    //Load Dirt Textures
    if (!gDirt_DirtTexture.loadFromFile("textures/terrain/dirt/dirt.png")) {
        cout << "Failed to load dirt - dirt texture!" << endl;
        return false;
    }
    if (!gDirt_DirtGravelTexture.loadFromFile("textures/terrain/dirt/dirt-gravel.png")) {
        cout << "Failed to load dirt - dirt-gravel texture!" << endl;
        return false;
    }
    if (!gDirt_GravelTexture.loadFromFile("textures/terrain/dirt/gravel.png")) {
        cout << "Failed to load dirt - gravel texture!" << endl;
        return false;
    }

    //Load Grass Textures
    if (!gGrass_DeadTexture.loadFromFile("textures/terrain/grass/dead.png")) {
        cout << "Failed to load grass - dead texture!" << endl;
        return false;
    }
    if (!gGrass_DryTexture.loadFromFile("textures/terrain/grass/dry.png")) {
        cout << "Failed to load grass - dry texture!" << endl;
        return false;
    }
    if (!gGrass_DyingTexture.loadFromFile("textures/terrain/grass/dying.png")) {
        cout << "Failed to load grass - dying texture!" << endl;
        return false;
    }
    if (!gGrass_LushDeepTexture.loadFromFile("textures/terrain/grass/lush-deep.png")) {
        cout << "Failed to load grass - lush-deep texture!" << endl;
        return false;
    }
    if (!gGrass_LushLightTexture.loadFromFile("textures/terrain/grass/lush-light.png")) {
        cout << "Failed to load grass - lush-light texture!" << endl;
        return false;
    }
    if (!gGrass_ParchedTexture.loadFromFile("textures/terrain/grass/parched.png")) {
        cout << "Failed to load grass - parched texture!" << endl;
        return false;
    }

    //Load Pavement Textures
    if (!gPavement_CobblestoneTexture.loadFromFile("textures/terrain/pavement/cobblestone.png")) {
        cout << "Failed to load Pavement - cobblestone texture!" << endl;
        return false;
    }

    //Load Sand Textures
    if (!gSand_DarkTexture.loadFromFile("textures/terrain/sand/sand-dark.png")) {
        cout << "Failed to load Sand - dark texture!" << endl;
        return false;
    }
    if (!gSand_LightTexture.loadFromFile("textures/terrain/sand/sand-light.png")) {
        cout << "Failed to load Sand - light texture!" << endl;
        return false;
    }

    //Load Stone - Grey Textures
    if (!gStone_Gray_DarkTexture.loadFromFile("textures/terrain/stone/grey-stone/dark.png")) {
        cout << "Failed to load Stone - Grey - dark texture!" << endl;
        return false;
    }
    if (!gStone_Gray_LightTexture.loadFromFile("textures/terrain/stone/grey-stone/light.png")) {
        cout << "Failed to load Stone - Grey - light texture!" << endl;
        return false;
    }
    if (!gStone_Gray_MediumTexture.loadFromFile("textures/terrain/stone/grey-stone/medium.png")) {
        cout << "Failed to load Stone - Grey - medium texture!" << endl;
        return false;
    }
    if (!gStone_Gray_VeryDarkTexture.loadFromFile("textures/terrain/stone/grey-stone/very-dark.png")) {
        cout << "Failed to load Stone - Grey - very-dark texture!" << endl;
        return false;
    }
    if (!gStone_Gray_VeryLightTexture.loadFromFile("textures/terrain/stone/grey-stone/very-light.png")) {
        cout << "Failed to load Stone - Grey - very-light texture!" << endl;
        return false;
    }


    //Load Stone - Sandstone
    if (!gStone_Sand_DarkTexture.loadFromFile("textures/terrain/stone/sandstone/dark.png")) {
        cout << "Failed to load Stone - Sandstone - dark texture!" << endl;
        return false;
    }
    if (!gStone_Sand_LightTexture.loadFromFile("textures/terrain/stone/sandstone/light.png")) {
        cout << "Failed to load Stone - Sandstone - light texture!" << endl;
        return false;
    }
    if (!gStone_Sand_MediumTexture.loadFromFile("textures/terrain/stone/sandstone/medium.png")) {
        cout << "Failed to load Stone - Sandstone - medium texture!" << endl;
        return false;
    }
    if (!gStone_Sand_VeryLightTexture.loadFromFile("textures/terrain/stone/sandstone/very-light.png")) {
        cout << "Failed to load Stone - Sandstone - very light texture!" << endl;
        return false;
    }

    //Load Water Textures
    if (!gWater_RiverTexture.loadFromFile("textures/terrain/water/river.png")) {
        cout << "Failed to load Water - river texture!" << endl;
        return false;
    }
    if (!gWater_SeaTexture.loadFromFile("textures/terrain/water/sea.png")) {
        cout << "Failed to load Water - sea texture!" << endl;
        return false;
    }
    if (!gWater_SmallStreamTexture.loadFromFile("textures/terrain/water/small-stream.png")) {
        cout << "Failed to load Water - small-stream texture!" << endl;
        return false;
    }
    return true;
}