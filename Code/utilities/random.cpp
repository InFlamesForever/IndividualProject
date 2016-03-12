//
// Created by richard on 11/03/16.
//

#include "random.h"

int randInteger(int min, int max){
    return rand() % (max-min + 1) + min;
}

double fRand(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}