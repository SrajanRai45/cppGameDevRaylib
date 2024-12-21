#ifndef TEXTINPUT_H
#define TEXTINPUT_H

#include "raylib.h"

class InputBox{
    private:
    Rectangle collisionRec;
    char text[256] = ""; // Buffer to hold the text
    int textLength = 0;
    public:
    void text_Input();
    InputBox(Rectangle rec);

};

#endif