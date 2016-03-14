//
// Created by richard on 14/03/16.
//

#ifndef INDIVIDUALPROJECT_DRAWTEXT_H
#define INDIVIDUALPROJECT_DRAWTEXT_H


#include <SDL_pixels.h>
#include <string>
#include "../media/Texture.h"
#include "../media/fonts.h"
#include "drawTextBox.h"
#include <sstream>

using namespace std;

void drawText(string text, int x, int y, SDL_Color, TTF_Font* font);


#endif //INDIVIDUALPROJECT_DRAWTEXT_H
