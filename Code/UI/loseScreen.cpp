//
// Created by richard on 14/03/16.
//


#include "loseScreen.h"
#include "drawText.h"

void drawYouDied() {
    //Red
    SDL_Color color = { 255, 0, 0, 255 };

    drawText("You Died!", SCREEN_WIDTH/4, SCREEN_HEIGHT/4, color,
             gCantarell_Bold_Large);

}
