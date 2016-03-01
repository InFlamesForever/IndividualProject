//
// Created by richard on 17/01/16.
//

#include "Update.h"

void Update::handleEventUpdate(SDL_Event e) {
    //If a key is pressed (currently if it is held held down it keeps activating)
    if (!isMoving && e.type == SDL_KEYDOWN) {
        //Adjust the velocity
        switch (e.key.keysym.sym) {
            case SDLK_UP:
                move = UP;
                isMoving = true;
                break;
            case SDLK_DOWN:
                move = DOWN;
                isMoving = true;
                break;
            case SDLK_LEFT:
                move = LEFT;
                isMoving = true;
                break;
            case SDLK_RIGHT:
                move = RIGHT;
                isMoving = true;
                break;
        }
    }
}

void Update::moveUpdate(float timeStep) {
    if(isMoving){
        switch (move){
            case UP:
                isMoving = background.move(timeStep, 0, BLOCK_WIDTH);
                break;
            case DOWN:
                isMoving = background.move(timeStep, 0, -BLOCK_WIDTH);
                break;
            case LEFT:
                isMoving = background.move(timeStep, BLOCK_WIDTH, 0);
                break;
            case RIGHT:
                isMoving = background.move(timeStep, -BLOCK_WIDTH, 0);
                break;
        }
    }
    player.updateRender(isMoving, move);
}

void Update::renderUpdate() {
    background.render();
    player.render();

}

/*
 * Destructor
 */
Update::~Update() {

}

/*
 * Constructor
 */
Update::Update() {
}
