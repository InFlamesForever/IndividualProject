//
// Created by richard on 17/12/15.
//

#ifndef INDIVIDUALPROJECT_DOT_H
#define INDIVIDUALPROJECT_DOT_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "constants.h"
#include "textures.h"

//The dot that will move around on the screen
class Dot
{
public:
    //The dimensions of the dot
    static const int DOT_WIDTH = 16;
    static const int DOT_HEIGHT = 16;

    //Maximum axis velocity of the dot
    static const int DOT_VEL = 640;

    //Initializes the variables
    Dot();

    //Takes key presses and adjusts the dot's velocity
    void handleEvent( SDL_Event& e );

    //Moves the dot
    void move( float timeStep );

    //Shows the dot on the screen
    void render();

private:
    float mPosX, mPosY;
    float mVelX, mVelY;
};


#endif //INDIVIDUALPROJECT_DOT_H
