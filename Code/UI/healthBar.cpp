#include "healthBar.h"


void renderHealthBar(int health, int posX, int posY) {
    //Place it above the character
    int x = posX + 5;
    int y = posY - 15;

    //The text colour is green
    SDL_Color textColor = { 13, 235, 57, 255 };
    string str = static_cast<ostringstream*>(&(ostringstream() << health))->str();

    drawText(str, x, y, textColor);
}
