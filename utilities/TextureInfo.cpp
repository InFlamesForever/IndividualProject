//
// Created by richard on 17/01/16.
//

#include "TextureInfo.h"

void TextureInfo::setUp(Texture* const& tex, int x, int y, int z) {
    texture = tex;
    this->x = x;
    this->y = y;
    this->z = z;
}

Texture* TextureInfo::getTexture() {
    return texture;
}

int TextureInfo::getX() {
    return x;
}

int TextureInfo::getY() {
    return y;
}

int TextureInfo::getZ() {
    return z;
}
