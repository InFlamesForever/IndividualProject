//
// Created by richard on 17/01/16.
//

#include "Update.h"

void Update::handleEventUpdate(SDL_Event e) {
    //Handle input for the dot
    dot.handleEvent(e);
}

void Update::moveUpdate(float timeStep) {
    //Move for time step
    dot.move(timeStep);
}

void Update::renderUpdate() {
    //Render dot
    background.render();
    dot.render();

}
