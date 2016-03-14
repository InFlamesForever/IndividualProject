//
// Created by richard on 14/03/16.
//

#include "healthBar.h"


void renderHealthBar(int health, int posX, int posY) {
    int x = posX + 5;
    int y = posY - 15;

    //Set text color as black
    SDL_Color textColor = { 13, 235, 57, 255 };
    stringstream text;
    text.str("");
    text << health;

    Texture textTexture;

    //Render text
    if( !textTexture.loadFromRenderedText(text.str().c_str(),
                                              textColor, gCantarell_Regular)) {
        printf( "Unable to render FPS texture!\n" );
    }

    drawTextBox(x, y, textTexture.getWidth(), textTexture.getHeight());
    textTexture.render(x, y);
}
