//
// Created by richard on 17/01/16.
//

#include "Update.h"

/*
 * Constructor
 */
Update::Update() {
    player = new PlayerCharacter(STARTX + ((SCREEN_WIDTH /2) / BLOCK_WIDTH), STARTY + ((SCREEN_HEIGHT/2) /BLOCK_WIDTH));
    Blob temp(1, false, 220, 220);
    enemies.push_back(temp);
    numEnemies = 1;
}

void Update::handleEventUpdate(SDL_Event e) {
    bool canChangeMove = !isMoving;
    //If a key is pressed (currently if it is held held down it keeps activating)
    const Uint8 *keys = SDL_GetKeyboardState(NULL);
    if (e.type == SDL_KEYDOWN) {
        if(keys[SDL_SCANCODE_W] || keys[SDL_SCANCODE_UP]){
            if(canChangeMove){
                move = UP;
                isMoving = true;
            }
        }
        if(keys[SDL_SCANCODE_S] || keys[SDL_SCANCODE_DOWN]){
            if(canChangeMove){
                move = DOWN;
                isMoving = true;
            }
        }
        if(keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_LEFT]){
            if(canChangeMove){
                move = LEFT;
                isMoving = true;
            }
        }
        if(keys[SDL_SCANCODE_D] || keys[SDL_SCANCODE_RIGHT]){
            if(canChangeMove){
                move = RIGHT;
                isMoving = true;
            }
        }
        if(keys[SDL_SCANCODE_E]){
            enemies[0].attack(*player);
        }
    if(isMoving){
            if(terrainCollision(*player, move)){
                isMoving = false;
            }
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
    player->updateRender(isMoving, move);
    if(enemies[0].isOnScreen(background.getPointInTerrainX(), background.getPointInTerrainY())) {
        enemies[0].chooseMove(*player, timeStep, background.getMap());
        if(!enemies[0].hitDetection(*player)){
            enemies[0].move(timeStep);
        }

    }
}

void Update::renderUpdate() {
    background.render();
    player->render();
    enemies[0].render(background.getPointInTerrainX(), background.getPointInTerrainY(),
                      background.getOffsetX(), background.getOffsetY());

}

/*
 * Destructor
 */
Update::~Update() {
    delete(player);
}



bool Update::terrainCollision(PlayerCharacter character, int dir) {
    for(int i = 0; i < character.getCantTraverseSize(); i++) {
        switch (dir) {
            case UP:
                if (character.getCantTraverse()[i] ==
                    background.getSquare(character.getPosX(),
                                         character.getPosY() - 1)) {
                    return true;
                }
                break;
            case DOWN:
                if (character.getCantTraverse()[i] ==
                        background.getSquare(character.getPosX(),
                                             character.getPosY() + 1)) {
                    return true;
                }
                break;
            case LEFT:
                if (character.getCantTraverse()[i] ==
                        background.getSquare(character.getPosX() - 1,
                                             character.getPosY())) {
                    return true;
                }
                break;
            case RIGHT:
                if (character.getCantTraverse()[i] ==
                        background.getSquare(character.getPosX() + 1,
                                             character.getPosY())) {
                    return true;
                }
                break;
        }
    }
    return false;
}
