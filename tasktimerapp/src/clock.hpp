#ifndef CLOCK_H
#define CLOCK_H

#include "raylib.h"
#include "timer.hpp"

class Clock : public Timer {

    private://data members
    Timer timer;
    Vector2 pos1 , pos2;
    float radius1 , radius2;
    Color coler1 , color2;
    bool pause = true;

    public://methods
    void displayTime();
    void updateClock(Vector2 center, float radius);
    void resetClock();

};


#endif