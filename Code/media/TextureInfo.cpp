//
// Created by richard on 17/01/16.
//

#include "TextureInfo.h"

TextureInfo::TextureInfo() {
    texture = INT32_MAX;
    x = 0;
    y = 0;
}

void TextureInfo::setUp(int texture, int x, int y, int width) {
    this->texture = texture;
    this->x = x;
    this->y = y;
    this->width = width;

}

int TextureInfo::getTexture() {
    return texture;
}

int TextureInfo::getX() {
    return x;
}

int TextureInfo::getY() {
    return y;
}

int TextureInfo::getWidth() {
    return width;
}
