//
// Created by richard on 14/03/16.
//

#ifndef INDIVIDUALPROJECT_DRAWTEXTBOX_H
#define INDIVIDUALPROJECT_DRAWTEXTBOX_H

#include <SDL_rect.h>
#include "../media/textures.h"

/**
 * Draws a black box which is 50% transparent that can be used as a
 * border for text.
 *
 *  x - x coordinate for rendering
 *  y - y coordinate for rendering
 *  w - width of the box
 *  h - height of the box
 */

void drawTextBox(int x, int y, int w, int h);


#endif //INDIVIDUALPROJECT_DRAWTEXTBOX_H
