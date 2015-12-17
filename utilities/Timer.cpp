#include "Timer.h"

Timer::Timer() {
    startTicks = 0;
    pausedTicks = 0;

    paused = false;
    started = false;
}

/*
 * Starts the timer
 */
void Timer::start() {
    started = true;
    paused = false;

    //Get the current clock time
    startTicks = SDL_GetTicks();
    pausedTicks = 0;
}

/*
 * Stops the timer and resets all variables
 */
void Timer::stop() {
    started = false;

    paused = false;

    startTicks = 0;
    pausedTicks = 0;
}

/*
 *  Pause the timer and calculate the pausedTicks
 */
void Timer::pause() {
    if (started && !paused) {
        paused = true;

        pausedTicks = SDL_GetTicks() - startTicks;
        startTicks = 0;
    }
}

/*
 * Resume the timer and reset the startTicks to their original value
 * Reset the paused ticks
 */
void Timer::resume() {
    if (started && paused) {
        paused = false;

        startTicks = SDL_GetTicks() - pausedTicks;
        pausedTicks = 0;
    }
}

/*
 * Get the number of ticks since the timer was started
 */
Uint32 Timer::getTicks() {
    if (started) {
        if (paused) {
            //Return the number of ticks when the timer was paused
            return pausedTicks;
        }
        else {
            //Return the current time minus the start time
            return SDL_GetTicks() - startTicks;
        }
    }
    //Returns 0 if the timer is not yet started
    return 0;
}

/*
 * Returns whether the timer is started or not
 */
bool Timer::isStarted() {
    return started;
}

/*
 * Returns whether the timer is paused or not
 */
bool Timer::isPaused() {
    return paused && started;
}