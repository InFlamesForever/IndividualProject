//
// Created by richard on 14/03/16.
//

#include "Quest.h"

Quest::Quest() {
    numQuests = 0;
    questStartTimer.start();
}

void Quest::currentQuests() {
    SDL_Color textColour = {13, 235, 57, 255 };

    stringstream ss;
    if(questStartTimer.isStarted() && questStartTimer.getTicks() < 10000){
        for(int i = 0; i < numQuests; i++){
            ss.str("");
            ss << questsStartText[i];
            drawText(ss.str().c_str(),10, SCREEN_HEIGHT - 200 + i * 25, textColour, gFont_PlayerUI);
        }
    } else {
        questStartTimer.stop();
        for(int i = 0; i < numQuests; i++){
            ss.str("");
            ss << questsText[i];
            drawText(ss.str().c_str(),10, SCREEN_HEIGHT - 200 + i * 25, textColour, gFont_PlayerUI);
        }
    }
}

void Quest::findTownsInit(int** towns, int numTowns) {
    numQuests++;
    townPlaceInQuests = numQuests - 1;
    numTownsRemaining = numTowns;
    for(int i = 0; i < numTowns; i++){
        townPos.push_back(towns[i]);
        cout << townPos[i][0] << " " << townPos[i][1] << endl;
    }
    stringstream ss;
    ss.str("");
    ss << numTowns << " towns remaining to find!";
    questsText.push_back(ss.str().c_str());
    ss.str("");
    ss << "Your quest is to find all " << numTowns << " towns on this map that are connected by road";
    questsStartText.push_back(ss.str().c_str());
}

bool Quest::foundTown(int x, int y) {
    for(int i = 0; i < townPos.size(); i++){
        if(x == townPos[i][0] && y == townPos[i][1]){
            townPos.erase(townPos.begin() + i);
            numTownsRemaining--;
            stringstream ss;
            ss.str("");
            ss << numTownsRemaining << " towns remaining to find!";
            questsText[townPlaceInQuests] = ss.str().c_str();
            return true;
        }
    }
    return false;
}

void Quest::killEnemiesInit(int numEnemies) {
    numQuests++;
    enemyQuestPlaceInQuests = numQuests - 1;
    enemiesRemaining = numEnemies;
    stringstream ss;
    ss.str("");
    ss << numEnemies << " enemies to kill!";
    questsText.push_back(ss.str().c_str());
    ss.str("");
    ss << "Your quest is to find and kill " << numEnemies << " without dying!";
    questsStartText.push_back(ss.str().c_str());
}

bool Quest::enemyKilled() {
    enemiesRemaining--;
    stringstream ss;
    ss.str("");
    ss << enemiesRemaining << " enemies to kill!";
    questsText[enemyQuestPlaceInQuests] = ss.str().c_str();
    return enemiesRemaining <= 0;
}
