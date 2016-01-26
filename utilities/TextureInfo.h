//
// Created by richard on 17/01/16.
//

#ifndef INDIVIDUALPROJECT_TEXTUREINFO_H
#define INDIVIDUALPROJECT_TEXTUREINFO_H


#include "Texture.h"

class TextureInfo {
public:
    void setUp(Texture* const& tex, int x, int y, int z);

    Texture* getTexture();

    int getX();

    int getY();

    int getZ();


private:
    Texture *texture;
    int x;
    int y;
    int z;
};


#endif //INDIVIDUALPROJECT_TEXTUREINFO_H
