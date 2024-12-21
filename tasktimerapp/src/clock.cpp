#include "raylib.h"
#include "timer.hpp"
#include "clock.hpp"
#include <iostream>

void Clock::updateClock(Vector2 center, float radius)
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePosition = GetMousePosition();

        if (CheckCollisionPointCircle(mousePosition, center, radius))
        {
            pause = !pause;
        }
    }
}

void Clock::resetClock()
{
    if (IsKeyPressed(KEY_R))
    {
        timer.resetTimer();
    }
}

void Clock::displayTime()
{
    if (!pause)
    {
        timer.fpscounter();
        timer.updatetimer();
    }
    int a = timer.timeSECReturn();
    int b = timer.timeMINreturn();
    int y = GetScreenHeight();
    int x = GetScreenWidth();
    Vector2 posCircle = {(x / 2.0f) + 11.0f, (y / 2.0f) + 14.0f};

    updateClock(posCircle, 40.0f);
    resetClock();

    Color Rose = {238, 161, 184, 255}; // #eea1b8

    std::string text = std::to_string(b) + ":" + std::to_string(a);
    DrawCircle(posCircle.x, posCircle.y, 70.0, Rose);
    DrawText(text.c_str(), x / 2 - MeasureText(text.c_str(), 20) / 2, y / 2, 40, BLACK);
}