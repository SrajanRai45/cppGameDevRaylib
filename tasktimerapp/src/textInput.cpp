#include "raylib.h"
#include "textInput.hpp"

void InputBox::text_Input(){
    if (CheckCollisionPointRec(GetMousePosition(), collisionRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            // Start capturing text input when clicked
            while (textLength < 255)
            {
                int key = GetCharPressed(); // Get character pressed
                if(key == KEY_ENTER || key == KEY_END){
                    return;
                }
                if (key > 0)
                {
                    // Add character to text buffer
                    text[textLength] = (char)key;
                    textLength++;
                }
            }
        }
}

InputBox::InputBox(Rectangle rec){
        collisionRec = rec;
}