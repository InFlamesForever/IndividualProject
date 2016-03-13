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
    //If a key is pressed (currently if it is held held down it keeps activating)
    if (!isMoving && e.type == SDL_KEYDOWN) {
        //Adjust the velocity
        switch (e.key.keysym.sym) {
            case SDLK_w:
            case SDLK_UP:
                move = UP;
                isMoving = true;
                break;
            case SDLK_s:
            case SDLK_DOWN:
                move = DOWN;
                isMoving = true;
                break;
            case SDLK_a:
            case SDLK_LEFT:
                move = LEFT;
                isMoving = true;
                break;
            case SDLK_d:
            case SDLK_RIGHT:
                move = RIGHT;
                isMoving = true;
                break;
            case SDLK_SPACE:
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
