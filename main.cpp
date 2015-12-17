#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "utilities/functions.h"
#include "utilities/Dot.h"
#include "utilities/Timer.h"


int main(int argc, char *args[]) {
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

            //The dot that will be moving around on the screen
            Dot dot;

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

                    //Handle input for the dot
                    dot.handleEvent(e);
                }

                //Calculate time step
                float timeStep = stepTimer.getTicks() / 1000.f;

                //Move for time step
                dot.move(timeStep);

                //Restart step timer
                stepTimer.start();

                //Clear screen
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(gRenderer);

                //Render dot
                dot.render();

                //Update screen
                SDL_RenderPresent(gRenderer);
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}