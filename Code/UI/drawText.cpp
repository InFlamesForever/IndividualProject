//
// Created by richard on 14/03/16.
//

#include "drawText.h"


void drawText(string text, int x, int y, SDL_Color color, TTF_Font* font) {
    Texture textTexture;

    if(!textTexture.loadFromRenderedText(text,
                                         color, font)) {
        cout << "Unable to render drawText texture!" << endl;
    }

    drawTextBox(x, y, textTexture.getWidth(), textTexture.getHeight());
    textTexture.render(x, y);

}
