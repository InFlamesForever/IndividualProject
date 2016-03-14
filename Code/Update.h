//
// Created by richard on 17/01/16.
//

#ifndef INDIVIDUALPROJECT_RENDERPOOL_H
#define INDIVIDUALPROJECT_RENDERPOOL_H


#include <SDL_events.h>
#include "Characters/PlayerCharacter.h"
#include "Characters/Enemies/Blob.h"
#include "terrain/Background.h"
#include "utilities/constants.h"
#include "UI/loseScreen.h"
#include "Characters/Enemies/Slime.h"
#include "UI/renderPlayerStatBar.h"

class Update {
public:
    Update();
    ~Update();

    void handleEventUpdate(SDL_Event e);

    void moveUpdate(float timeStep);

    void renderUpdate();

    /**
     * A character is passed to this method along with a direction
     * the movement is then checked to see whether it should be based
     * on the terrain tiles that the character can move over.
     */
    bool terrainCollision(PlayerCharacter character, int dir);

private:
    void generateEnemies(int numEnemies);

    void renderUI();

    //The dot that will be moving around on the screen
    PlayerCharacter* player;
    Background background;

    vector<EnemyCharacter> enemies;

    int move = DOWN;
    bool isMoving;
};


#endif //INDIVIDUALPROJECT_RENDERPOOL_H
