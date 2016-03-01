//
// Created by richard on 17/01/16.
//

#include "loadMedia.h"

bool loadMedia() {
    //Load Character pictures
    if (!gStock_Back.loadFromFile("textures/characters/Stock/Stock_Back.png")) {
        cout << "Failed to load Player Character - Back texture!" << endl;
        return false;
    }
    if (!gStock_Back_Walking1.loadFromFile("textures/characters/Stock/Stock_Back_Walking1.png")) {
        cout << "Failed to load Player Character - Back Walking 1 texture!" << endl;
        return false;
    }
    if (!gStock_Back_Walking2.loadFromFile("textures/characters/Stock/Stock_Back_Walking2.png")) {
        cout << "Failed to load Player Character - Back Walking 2 texture!" << endl;
        return false;
    }

    if (!gStock_Front.loadFromFile("textures/characters/Stock/Stock_Front.png")) {
        cout << "Failed to load Player Character - Front texture!" << endl;
        return false;
    }
    if (!gStock_Front_Walking1.loadFromFile("textures/characters/Stock/Stock_Front_Walking1.png")) {
        cout << "Failed to load Player Character - Front Walking 1 texture!" << endl;
        return false;
    }
    if (!gStock_Front_Walking2.loadFromFile("textures/characters/Stock/Stock_Front_Walking2.png")) {
        cout << "Failed to load Player Character - Front Walking 2 texture!" << endl;
        return false;
    }

    if (!gStock_Side_Right.loadFromFile("textures/characters/Stock/Stock_Side_Right.png")) {
        cout << "Failed to load Player Character - Side texture!" << endl;
        return false;
    }
    if (!gStock_Side_Right_Walking.loadFromFile("textures/characters/Stock/Stock_Side_Right_Walking.png")) {
        cout << "Failed to load Player Character - Walking texture!" << endl;
        return false;
    }
    if (!gStock_Side_Right_Walking2.loadFromFile("textures/characters/Stock/Stock_Side_Right_Walking2.png")) {
        cout << "Failed to load Player Character - Walking 2 texture!" << endl;
        return false;
    }if (!gStock_Side_Right_Walking3.loadFromFile("textures/characters/Stock/Stock_Side_Right_Walking3.png")) {
        cout << "Failed to load Player Character - Walking 3 texture!" << endl;
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

    //Snow Texture
    if (!gSnow.loadFromFile("textures/terrain/snow/Snow.png")) {
        cout << "Failed to load Snow texture!" << endl;
        return false;
    }

    //Load Town Logo
    if (!gTownSymbol.loadFromFile("textures/AboveTerrainElements/Town/TownSymbol.png")) {
        cout << "Failed to load Town - Town Symbol texture!" << endl;
        return false;
    }



    return true;
}