//
// Created by richard on 17/01/16.
//

#include "TextureInfo.h"

void TextureInfo::setUp(Texture* const& tex, int x, int y) {
    texture = tex;
    this->x = x;
    this->y = y;

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
