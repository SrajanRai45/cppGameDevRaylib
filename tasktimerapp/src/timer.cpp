#include "timer.hpp"

Timer::Timer(){
    fpscount = 0;
    spriteCount = 0;
    timeSEC = 0;
    timeMIN = 0;
}

void Timer::fpscounter(){
    fpscount++;
}

void Timer::secondCounter(){
    if (fpscount >= 60) { // Once 60 frames are counted
        timeSEC++; // Increment seconds
        fpscount = 0; // Reset the frame counter
    }
}

int Timer::timeSECReturn(){
    return timeSEC; // Return the current seconds
}

void Timer::minuteCounter(){
    if (timeSEC >= 60) { // Once seconds reach 60
        timeMIN++; // Increment minutes
        timeSEC = 0; // Reset seconds
    }
}

int Timer::timeMINreturn(){
    return timeMIN; // Return the current minutes
}

void Timer::updatetimer() {
    secondCounter();  // Update seconds
    minuteCounter();  // Update minutes
}


void Timer::resetTimer(){
    fpscount = 0;
    timeMIN = 0;
    timeSEC = 0;
}
