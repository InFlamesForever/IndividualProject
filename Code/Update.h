//
// Created by richard on 17/01/16.
//

#ifndef INDIVIDUALPROJECT_RENDERPOOL_H
#define INDIVIDUALPROJECT_RENDERPOOL_H


#include <SDL_events.h>
#include "Characters/PlayerCharacter.h"
#include "terrain/Background.h"
#include "utilities/constants.h"

class Update {
public:
    Update();
    ~Update();

    void handleEventUpdate(SDL_Event e);

    void moveUpdate(float timeStep);

    void renderUpdate();

private:
    //The dot that will be moving around on the screen
    PlayerCharacter player;
    Background background;
    int move = DOWN;
    bool isMoving = false;
};


#endif //INDIVIDUALPROJECT_RENDERPOOL_H
