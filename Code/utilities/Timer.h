#ifndef INDIVIDUALPROJECT_TIMER_H
#define INDIVIDUALPROJECT_TIMER_H


//Using SDL, SDL_image, standard IO, and, strings
#include <SDL.h>

/*
 * Last Updated 05/12/15
 */
class Timer {
public:
    Timer();

    void start();
    void stop();
    void pause();
    void resume();
    void reset();

    //Gets the timer's time
    Uint32 getTicks();

    bool isStarted();
    bool isPaused();

private:
    //The clock time when the timer started
    Uint32 startTicks;

    //The ticks stored when the timer was paused
    Uint32 pausedTicks;

    bool paused;
    bool started;
};


#endif //INDIVIDUALPROJECT_TIMER_H
