//
// Created by richard on 28/12/15.
//

#include "Background.h"

Background::Background() {
    double t = -0.5; // tilt angle - try different values
    for(int i = 0; i < numTilesWidth; i++) {
        double X = i * 16 - SCREEN_WIDTH/2 ;
        double Y = 0 - SCREEN_HEIGHT/2 ;
        double a = (SCREEN_HEIGHT / (SCREEN_HEIGHT + Y * sin(t)));
        int u = (int) (a * X + SCREEN_WIDTH / 2);
        int v = (int) (a * Y * cos(t) + SCREEN_HEIGHT / 2);
        background[i][0].setUp(&gGrass_LushLightTexture, u, v, 0);

        Y = 1*16 - SCREEN_HEIGHT/2 ;
        a = (SCREEN_HEIGHT / (SCREEN_HEIGHT + Y * sin(t)));
        u = (int) (a * X + SCREEN_WIDTH / 2);
        v = (int) (a * Y * cos(t) + SCREEN_HEIGHT / 2);
        background[i][1].setUp(&gGrass_LushLightTexture, u, v, 0);

        Y = 2*16 - SCREEN_HEIGHT/2 ;
        a = (SCREEN_HEIGHT / (SCREEN_HEIGHT + Y * sin(t)));
        u = (int) (a * X + SCREEN_WIDTH / 2);
        v = (int) (a * Y * cos(t) + SCREEN_HEIGHT / 2);
        background[i][2].setUp(&gGrass_LushLightTexture, u, v, 0);

        Y = 3*16 - SCREEN_HEIGHT/2 ;
        a = (SCREEN_HEIGHT / (SCREEN_HEIGHT + Y * sin(t)));
        u = (int) (a * X + SCREEN_WIDTH / 2);
        v = (int) (a * Y * cos(t) + SCREEN_HEIGHT / 2);
        background[i][3].setUp(&gGrass_DryTexture, u, v, 0);

        Y = 4*16 - SCREEN_HEIGHT/2 ;
        a = (SCREEN_HEIGHT / (SCREEN_HEIGHT + Y * sin(t)));
        u = (int) (a * X + SCREEN_WIDTH / 2);
        v = (int) (a * Y * cos(t) + SCREEN_HEIGHT / 2);
        background[i][4].setUp(&gDirt_DirtTexture, u, v, 0);

        Y = 5*16 - SCREEN_HEIGHT/2 ;
        a = (SCREEN_HEIGHT / (SCREEN_HEIGHT + Y * sin(t)));
        u = (int) (a * X + SCREEN_WIDTH / 2);
        v = (int) (a * Y * cos(t) + SCREEN_HEIGHT / 2);
        background[i][5].setUp(&gDirt_DirtTexture, u, v, 0);

        Y = 6*16 - SCREEN_HEIGHT/2 ;
        a = (SCREEN_HEIGHT / (SCREEN_HEIGHT + Y * sin(t)));
        u = (int) (a * X + SCREEN_WIDTH / 2);
        v = (int) (a * Y * cos(t) + SCREEN_HEIGHT / 2);
        background[i][6].setUp(&gSand_DarkTexture, u, v, 0);

        Y = 7*16 - SCREEN_HEIGHT/2 ;
        a = (SCREEN_HEIGHT / (SCREEN_HEIGHT + Y * sin(t)));
        u = (int) (a * X + SCREEN_WIDTH / 2);
        v = (int) (a * Y * cos(t) + SCREEN_HEIGHT / 2);
        background[i][7].setUp(&gSand_DarkTexture, u, v, 0);

        Y = 8*16 - SCREEN_HEIGHT/2 ;
        a = (SCREEN_HEIGHT / (SCREEN_HEIGHT + Y * sin(t)));
        u = (int) (a * X + SCREEN_WIDTH / 2);
        v = (int) (a * Y * cos(t) + SCREEN_HEIGHT / 2);
        background[i][8].setUp(&gSand_LightTexture, u, v, 0);

        Y = 9*16 - SCREEN_HEIGHT/2 ;
        a = (SCREEN_HEIGHT / (SCREEN_HEIGHT + Y * sin(t)));
        u = (int) (a * X + SCREEN_WIDTH / 2);
        v = (int) (a * Y * cos(t) + SCREEN_HEIGHT / 2);
        background[i][9].setUp(&gSand_LightTexture, u, v, 0);
        
        for(int j = 10; j < numTilesHeight; j++){
            Y = j*16 - SCREEN_HEIGHT/2 ;
            a = (SCREEN_HEIGHT / (SCREEN_HEIGHT + Y * sin(t)));
            u = (int) (a * X + SCREEN_WIDTH / 2);
            v = (int) (a * Y * cos(t) + SCREEN_HEIGHT / 2);
            background[i][j].setUp(&gWater_SeaTexture, u, v, 0);
            
        }
    }
}

void Background::render() {
    for(int i = 0; i < numTilesWidth; i++){
        for(int j = 0; j< numTilesHeight; j++){
            int x = background[i][j].getX();
            int y = background[i][j].getY();

            SDL_Rect dst;
            dst.x = 0;
            dst.y = 0;
            dst.w = 16;
            dst.h = 16+j;
            background[i][j].getTexture()->render(x,y, &dst) ;
        }
    }
}
