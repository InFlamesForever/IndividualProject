//
// Created by richard on 17/01/16.
//

#ifndef INDIVIDUALPROJECT_TEXTUREINFO_H
#define INDIVIDUALPROJECT_TEXTUREINFO_H


#include "Texture.h"
#include "../utilities/constants.h"

class TextureInfo {
public:
    TextureInfo();

    void setUp(int texture, int x, int y, int width);

    int getTexture();

    int getX();

    int getY();

    int getWidth();


private:
    int texture;

    int width;

    //2.5d Coords
    int x;
    int y;
};


#endif //INDIVIDUALPROJECT_TEXTUREINFO_H
