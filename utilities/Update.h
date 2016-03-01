//
// Created by richard on 17/01/16.
//

#ifndef INDIVIDUALPROJECT_RENDERPOOL_H
#define INDIVIDUALPROJECT_RENDERPOOL_H


#include <SDL_events.h>
#include "PlayerCharacter.h"
#include "Background.h"
#include "constants.h"

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
    enum MoveType {DOWN, UP, LEFT, RIGHT};
    MoveType move = DOWN;
    bool isMoving = false;
};


#endif //INDIVIDUALPROJECT_RENDERPOOL_H
