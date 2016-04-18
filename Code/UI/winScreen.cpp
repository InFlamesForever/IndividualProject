//
// Created by richard on 18/04/16.
//

#include "winScreen.h"

void drawYouDied() {
    //Red
    SDL_Color color = { 0, 255, 0, 255 };

    drawText("You Win!", SCREEN_WIDTH/4, SCREEN_HEIGHT/4, color,
             gFont_YouDied);

}