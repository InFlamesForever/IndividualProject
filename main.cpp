#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "utilities/functions.h"
#include "utilities/Timer.h"
#include "utilities/loadMedia.h"
#include "utilities/Update.h"


int main(int argc, char *args[]) {
    //FPS timer
    Timer fpsTimer;

    //Start counting frames per second
    int countedFrames = 0;
    fpsTimer.start();

    //Start up SDL and create window
    if (!init()) {
        printf("Failed to initialize!\n");
    }
    else {
        //Load media
        if (!loadMedia()) {
            printf("Failed to load media!\n");
        }
        else {
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            Update update;

            //Keeps track of time between steps
            Timer stepTimer;

            //While application is running
            while (!quit) {
                //Handle events on queue
                while (SDL_PollEvent(&e) != 0) {
                    //User requests quit
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    }

                    update.handleEventUpdate(e);
                }

                //Calculate and correct fps
                float avgFPS = countedFrames / ( fpsTimer.getTicks() / 1000.f );
                if( avgFPS > 2000000 )
                {
                    avgFPS = 0;
                }

                cout << avgFPS << endl;

                //Calculate time step
                float timeStep = stepTimer.getTicks() / 1000.f;

                update.moveUpdate(timeStep);

                //Restart step timer
                stepTimer.start();

                //Clear screen
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(gRenderer);

                update.renderUpdate();

                //Update screen
                SDL_RenderPresent(gRenderer);

                countedFrames++;
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}