//
// Created by richard on 14/03/16.
//

#include "Quest.h"

Quest::Quest() {
    numQuests = 0;
    questStartTimer.start();
}

bool Quest::currentQuests() {
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
            if(questsText[i] != "") {
                ss.str("");
                ss << questsText[i];
                drawText(ss.str().c_str(), 10, SCREEN_HEIGHT - 200 + i * 25,
                         textColour, gFont_PlayerUI);
            }
        }
    }
    cout << numQuests << endl;
    return numQuests == 0;
}

void Quest::findTownsInit(int** towns, int numTowns) {
    numQuests++;
    townPlaceInQuests = numQuests - 1;
    numTownsRemaining = numTowns;
    for(int i = 0; i < numTowns; i++){
        townPos.push_back(towns[i]);
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
    bool returnVal = false;
    for(int i = 0; i < townPos.size(); i++){
        if(x == townPos[i][0] && y == townPos[i][1]){
            townPos.erase(townPos.begin() + i);
            numTownsRemaining--;
            returnVal = true;
        }
    }
    if(returnVal){
        stringstream ss;
        ss.str("");
        if(numTownsRemaining != 0){
            ss << numTownsRemaining << " towns remaining to find!";
        } else {
            numQuests--;
        }
        questsText[townPlaceInQuests] = ss.str().c_str();
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
    ss << "Your quest is to find and kill " << numEnemies << " enemies without dying!";
    questsStartText.push_back(ss.str().c_str());
}

bool Quest::enemyKilled() {
    enemiesRemaining--;
    stringstream ss;
    ss.str("");
    if(enemiesRemaining != 0){
        ss << enemiesRemaining << " enemies to kill!";
    } else {
        numQuests--;
    }
    questsText[enemyQuestPlaceInQuests] = ss.str().c_str();
    return enemiesRemaining <= 0;
}
