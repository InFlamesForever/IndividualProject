//
// Created by richard on 17/01/16.
//

#ifndef INDIVIDUALPROJECT_TEXTUREINFO_H
#define INDIVIDUALPROJECT_TEXTUREINFO_H


#include "Texture.h"
#include "constants.h"

class TextureInfo {
public:
    void setUp(int tex, int x, int y);

    int getTexture();

    int getX();

    int getY();


private:
    int texture;

    //2.5d Coords
    int x;
    int y;
};


#endif //INDIVIDUALPROJECT_TEXTUREINFO_H
