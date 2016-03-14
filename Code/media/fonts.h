//
// Created by richard on 14/03/16.
//

#ifndef INDIVIDUALPROJECT_FONTS_H
#define INDIVIDUALPROJECT_FONTS_H


//-----------------------------------------------------------------------------
//########################## Fonts ###########################################
//-----------------------------------------------------------------------------

#include <SDL_ttf.h>

//font size 12 - used for health bars
extern TTF_Font* gFont_HealthBar;

//Font size 20 - used for the UI elements such as player health
extern TTF_Font* gFont_PlayerUI;



extern TTF_Font* gCantarell_Bold;
extern TTF_Font* gCantarell_Oblique;
extern TTF_Font* gCantarell_Oblique_Bold;

//Scaled with the screen and used for the "You Died!" notification
extern TTF_Font*gFont_YouDied;


#endif //INDIVIDUALPROJECT_FONTS_H
