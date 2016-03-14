//
// Created by richard on 14/03/16.
//

#include "drawTextBox.h"

void drawTextBox(int x, int y, int w, int h) {
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = w;
    rect.h = h;

    gTextBox.render(x, y, &rect);

}
