//
// Created by richard on 14/03/16.
//

#include "renderPlayerStatBar.h"

void renderPlayerStatBar(PlayerCharacter *player) {
    //Health

    //The text colour is green
    SDL_Color healthColour = {13, 235, 57, 255 };
    stringstream ss;
    ss.str("");
    ss << "Health: " << player->getHealthPts();

    drawText(ss.str().c_str(), 10, 10, healthColour, gFont_PlayerUI);

    //Level
    ss.str("");
    ss << "Level: " << player->getLevel();

    drawText(ss.str().c_str(), 120, 10, healthColour, gFont_PlayerUI);

    //Attack
    ss.str("");
    ss << "Attack: " << player->getAttackPts();

    drawText(ss.str().c_str(), 200, 10, healthColour, gFont_PlayerUI);

    //Defense
    ss.str("");
    ss << "Defence: " << player->getDefencePts();

    drawText(ss.str().c_str(), 300, 10, healthColour, gFont_PlayerUI);
}
