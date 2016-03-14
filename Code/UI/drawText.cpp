//
// Created by richard on 14/03/16.
//

#include "drawText.h"


void drawText(string text, int x, int y, SDL_Color color, TTF_Font* font) {
    stringstream ss;
    ss.str("");
    ss << text;

    Texture textTexture;

    //Use Default Font
    if(font == NULL){
        if(!textTexture.loadFromRenderedText(ss.str().c_str(),
                                             color, gCantarell_Regular)) {
            cout << "Unable to render drawText - texture!" << endl;
        }
    } else {
        if(!textTexture.loadFromRenderedText(ss.str().c_str(),
                                             color, font)) {
            cout << "Unable to render drawText - texture!" << endl;
        }
    }

    drawTextBox(x, y, textTexture.getWidth(), textTexture.getHeight());
    textTexture.render(x, y);

}
