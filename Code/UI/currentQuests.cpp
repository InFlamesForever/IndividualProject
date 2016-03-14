//
// Created by richard on 14/03/16.
//

#include <sstream>
#include "currentQuests.h"
#include "drawText.h"

void currentQuests(string *quests, int numQuests) {
    SDL_Color textColour = {13, 235, 57, 255 };

    stringstream ss;
    ss.str("");
    for(int i = 0; i < numQuests; i++){
        ss << quests[i] << endl;
    }
    drawText(ss.str().c_str(),10, SCREEN_HEIGHT - 200, textColour, gFont_PlayerUI);

}
