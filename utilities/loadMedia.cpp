//
// Created by richard on 17/01/16.
//

#include "loadMedia.h"

bool loadMedia() {
    //Load Character textures
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

    //Load Enemy Blob Character
    if (!gEnemy_Blob.loadFromFile("textures/characters/Enemies/Blob/Blob-Normal.png")) {
        cout << "Failed to load Enemy Character - Blob texture!" << endl;
        return false;
    }
    if (!gEnemy_Blob_Angry.loadFromFile("textures/characters/Enemies/Blob/Blob-Angry.png")) {
        cout << "Failed to load Enemy Character - Blob Angry texture!" << endl;
        return false;
    }
    if (!gEnemy_Blob_Attack.loadFromFile("textures/characters/Enemies/Blob/Blob-Attack.png")) {
        cout << "Failed to load Enemy Character - Blob Attack texture!" << endl;
        return false;
    }

    //Load Enemy Slime Character
    if (!gEnemy_Slime.loadFromFile("textures/characters/Enemies/Slime/Slime-Normal.png")) {
        cout << "Failed to load Enemy Character - Slime texture!" << endl;
        return false;
    }
    if (!gEnemy_Slime_Angry.loadFromFile("textures/characters/Enemies/Slime/Slime-Angry.png")) {
        cout << "Failed to load Enemy Character - Slime Angry texture!" << endl;
        return false;
    }
    if (!gEnemy_Slime_Attack.loadFromFile("textures/characters/Enemies/Slime/Slime-Attack.png")) {
        cout << "Failed to load Enemy Character - Slime Attack texture!" << endl;
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
    if (!gPavement_Bridge.loadFromFile("textures/terrain/Bridges/Bridge.png")) {
        cout << "Failed to load Pavement - Bridge texture!" << endl;
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

    //Town -- Doors
    if (!gTown_Door_Closed.loadFromFile("textures/AboveTerrainElements/Town/Doors/Closed_Wood.png")) {
        cout << "Failed to load Town - Door - Closed texture!" << endl;
        return false;
    }
    if (!gTown_Door_HalfOpen.loadFromFile("textures/AboveTerrainElements/Town/Doors/Half_Open_Wood.png")) {
        cout << "Failed to load Town - Door - Half Open texture!" << endl;
        return false;
    }
    if (!gTown_Door_ThreeQuartersOpen.loadFromFile("textures/AboveTerrainElements/Town/Doors/Three_Quater_Open_Wood.png")) {
        cout << "Failed to load Town - Door - Three Quarter Open texture!" << endl;
        return false;
    }
    if (!gTown_Door_Open.loadFromFile("textures/AboveTerrainElements/Town/Doors/Open_Wood.png")) {
        cout << "Failed to load Town - Door - Open texture!" << endl;
        return false;
    }

    //Town -- Roofs
    if (!gTown_Roof_Thatched.loadFromFile("textures/AboveTerrainElements/Town/Roofs/Thatched.png")) {
        cout << "Failed to load Town - Roof - Thatched texture!" << endl;
        return false;
    }
    if (!gTown_Roof_Thatched_Corner.loadFromFile("textures/AboveTerrainElements/Town/Roofs/Thatched_Corner.png")) {
        cout << "Failed to load Town - Roof - Thatched Corner texture!" << endl;
        return false;
    }

    //Town -- Walls
    if (!gTown_Wall_Wood.loadFromFile("textures/AboveTerrainElements/Town/Walls/Wood_Wall.png")) {
        cout << "Failed to load Town - Walls - Wall texture!" << endl;
        return false;
    }
    if (!gTown_Wall_Wood_Corner_Left_Ground.loadFromFile("textures/AboveTerrainElements/Town/Walls/Wood_Corner_Left_Ground.png")) {
        cout << "Failed to load Town - Walls - Corner Left Ground texture!" << endl;
        return false;
    }
    if (!gTown_Wall_Wood_Corner_Left_Upper.loadFromFile("textures/AboveTerrainElements/Town/Walls/Wood_Corner_Left_Upper.png")) {
        cout << "Failed to load Town - Walls - Corner Left Upper texture!" << endl;
        return false;
    }
    if (!gTown_Wall_Wood_Corner_Right_Ground.loadFromFile("textures/AboveTerrainElements/Town/Walls/Wood_Corner_Right_Ground.png")) {
        cout << "Failed to load Town - Walls - Corner Right Ground texture!" << endl;
        return false;
    }if (!gTown_Wall_Wood_Corner_Right_Upper.loadFromFile("textures/AboveTerrainElements/Town/Walls/Wood_Corner_Right_Upper.png")) {

        cout << "Failed to load Town - Walls - Corner Right Upper texture!" << endl;
        return false;
    }
    if (!gTown_Wall_Wood_Window.loadFromFile("textures/AboveTerrainElements/Town/Walls/Wood_Window.png")) {
        cout << "Failed to load Town - Walls - Window texture!" << endl;
        return false;
    }

    //Water Sea Waves
    if (!gWater_SeaWaves.loadFromFile("textures/AboveTerrainElements/Water/Sea_Waves.png")) {
        cout << "Failed to load Water - Sea Waves texture!" << endl;
        return false;
    }

    //Trees
    if (!gTree_Dark.loadFromFile("textures/AboveTerrainElements/Trees/Dark.png")) {
        cout << "Failed to load Tree - Dark texture!" << endl;
        return false;
    }
    if (!gTree_Medium.loadFromFile("textures/AboveTerrainElements/Trees/Medium.png")) {
        cout << "Failed to load Tree - Medium texture!" << endl;
        return false;
    }    if (!gTree_MediumLittle.loadFromFile("textures/AboveTerrainElements/Trees/Little_Medium.png")) {
        cout << "Failed to load Tree - Medium little texture!" << endl;
        return false;
    }    if (!gTree_Light.loadFromFile("textures/AboveTerrainElements/Trees/Light.png")) {
        cout << "Failed to load Tree - Light texture!" << endl;
        return false;
    }

    return true;
}