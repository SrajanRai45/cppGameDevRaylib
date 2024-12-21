#ifndef COUNTER_H
#define COUNTER_H


class Timer
{
private:
    int fpscount;
    int spriteCount;
    int timeSEC;
    int timeMIN;

public:
    Timer();
    void fpscounter();
    void secondCounter();
    int timeSECReturn();
    void minuteCounter();
    int timeMINreturn();
    void updatetimer();
    void resetTimer();
};

#endif
