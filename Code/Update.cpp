//
// Created by richard on 17/01/16.
//

#include "Update.h"


/*
 * Constructor
 */
Update::Update() {
    isMoving = false;

    int startX = background.getTownPositions()[0][0];
    int startY = background.getTownPositions()[0][1];

    player = new PlayerCharacter(startX, startY, background.getPointInTerrainX(), background.getPointInTerrainY());

    int numEnemies = TERRAIN_SIZE/5;
    enemies.reserve((unsigned long) numEnemies);
    generateEnemies(numEnemies);

    quest.killEnemiesInit(5);
    quest.findTownsInit(background.getTownPositions(), 2);
}

void Update::handleEventUpdate(SDL_Event e) {
    bool canChangeMove = !isMoving;
    //If a key is pressed (currently if it is held held down it keeps activating)
    const Uint8 *keys = SDL_GetKeyboardState(NULL);
    if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN) {
        if(player->getIsAlive()) {
            if (keys[SDL_SCANCODE_W] || keys[SDL_SCANCODE_UP]) {
                if (canChangeMove) {
                    move = UP;
                    isMoving = true;
                }
            }
            if (keys[SDL_SCANCODE_S] || keys[SDL_SCANCODE_DOWN]) {
                if (canChangeMove) {
                    move = DOWN;
                    isMoving = true;
                }
            }
            if (keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_LEFT]) {
                if (canChangeMove) {
                    move = LEFT;
                    isMoving = true;
                }
            }
            if (keys[SDL_SCANCODE_D] || keys[SDL_SCANCODE_RIGHT]) {
                if (canChangeMove) {
                    move = RIGHT;
                    isMoving = true;
                }
            }
            //Change perspective
            if(keys[SDL_SCANCODE_Z]){
                if(zoom == 0 || zoom == 1) {
                    BLOCK_WIDTH = BLOCK_WIDTH/2;
                    zoom++;
                } else {
                    BLOCK_WIDTH = 16;
                    zoom = 0;
                }
                player->changeZoom(background.getPointInTerrainX(), background.getPointInTerrainY());
                background.getTerrain();
                background.composeTerrainToTexture();
            }
            //Player attack
            if(e.button.button == SDL_BUTTON_LEFT){
                for(int i = 0; i < enemies.size(); i++) {
                    if(enemies[i].getIsAlive()){
                        if (player->hitDetection(enemies[i])) {
                            if (!player->getAttackTimer()->isStarted()
                                || player->getAttackTimer()->getTicks() >
                                   player->ATTACKDELAY) {
                                enemies[i].hit(player->getAttackPts());
                                if (!enemies[i].getIsAlive()) {
                                    if(player->addExp(enemies[i].getExpOnDeath())){ //If the player levels up, level up all the enemies
                                        levelUp();
                                    }
                                    quest.enemyKilled();

                                    //To be fixed
                                    //enemies.erase(enemies.begin() );
                                }
                                player->getAttackTimer()->reset();
                                player->getAttackTimer()->start();
                            }
                        }
                    }
                }
            }
        }
    if(isMoving){
            if(terrainCollision(*player, move)){
                isMoving = false;
            } else {
                for(int i = 0; i < enemies.size(); i++){
                    if(player->hitDetection(enemies[i], &move)){
                        isMoving = false;
                        break;
                    }
                }
            }
        }
    }
}

void Update::moveUpdate(float timeStep) {
    if(player->getIsAlive() && zoom == 0) {
        if (isMoving) {
            switch (move) {
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
                default:break;
            }
        }
        player->updateRender(isMoving, move);
        quest.foundTown(player->getPosX(), player->getPosY());
        for(int i = 0; i < enemies.size(); i++) {
            if (enemies[i].getIsAlive()) {
                if (enemies[i].isOnScreen(background.getPointInTerrainX(),
                                          background.getPointInTerrainY())) {
                    enemies[i].chooseMove(*player, background.getMap());
                    if (!enemies[i].hitDetection(*player)) {
                        enemies[i].move(timeStep);
                    }
                    enemies[i].attack(player);

                }
            }
        }
        player->regenerate();
    }
}

void Update::renderUpdate() {
    background.render();
    for(int i = 0; i < enemies.size(); i++) {
        if (enemies[i].getIsAlive()) {
            enemies[i].render(background.getPointInTerrainX(),
                              background.getPointInTerrainY(),
                              background.getOffsetX(), background.getOffsetY());
        }
    }
    //Always render the player last out of the characters
    player->render();
    renderUI();
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
            default:break;
        }
    }
    return false;
}

void Update::generateEnemies(int numEnemies) {
    for(int i = 0; i < numEnemies; i++){
        bool made = false;
        while(!made) {
            int x = randInteger(100, TERRAIN_SIZE - 100);
            int y = randInteger(100, TERRAIN_SIZE - 100);
            if(background.getSquare(x,y) != Water_Ocean){
                switch(background.getSquare(x,y)){
                    case SandLight:
                    case SandDark:
                    case Stone_Gray_VeryLight:
                    case Stone_Gray_Light:
                    case Stone_Gray_Medium:
                    case Stone_Gray_Dark:
                    case Stone_Gray_VeryDark:
                        enemies.push_back(Slime(player->getLevel(), false, x, y));
                        made = true;
                        break;
                    case Grass_Dry:
                    case Grass_Parched:
                    case Grass_Dying:
                    case Grass_Dead:
                    case Grass_LushLight:
                    case Grass_LushDeep:
                        enemies.push_back(Blob(player->getLevel(), false, x, y));
                        made = true;
                        break;
                    default:break;
                }

            }
        }
    }

}

void Update::renderUI() {
    if(!player->getIsAlive()){
        drawYouDied();
    }
    renderPlayerStatBar(player);
    if(quest.currentQuests()){
        drawYouWin();
    }
}

void Update::levelUp() {
    for(int i = 0; i < enemies.size(); i++){
        if(enemies[i].getIsAlive()){
            enemies[i].rebalance();
        }
    }
}
