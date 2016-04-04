//
// Created by richard on 17/01/16.
//

#include "TileInfo.h"

TileInfo::TileInfo(int texture, int xInTerrain, int yInTerrain, int xOnScreen,
                   int yOnScreen) {
    this->texture = texture;
    this->xInTerrain = xInTerrain;
    this->yInTerrain = yInTerrain;
    this->xOnScreen = xOnScreen;
    this->yOnScreen = yOnScreen;
}

int TileInfo::getTexture() {
    return texture;
}

int TileInfo::getXInTerrain() {
    return xInTerrain;
}

int TileInfo::getYInTerrain() {
    return yInTerrain;
}


int TileInfo::getXOnScreen() {
    return xOnScreen;
}

int TileInfo::getYOnScreen() {
    return yOnScreen;
}
