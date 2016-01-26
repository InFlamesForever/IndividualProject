//
// Created by richard on 17/01/16.
//

#ifndef INDIVIDUALPROJECT_RENDERPOOL_H
#define INDIVIDUALPROJECT_RENDERPOOL_H


#include <SDL_events.h>
#include "Dot.h"
#include "Background.h"

class Update {
public:
    void handleEventUpdate(SDL_Event e);

    void moveUpdate(float timeStep);

    void renderUpdate();

private:
    //The dot that will be moving around on the screen
    Dot dot;
    Background background;
};


#endif //INDIVIDUALPROJECT_RENDERPOOL_H
