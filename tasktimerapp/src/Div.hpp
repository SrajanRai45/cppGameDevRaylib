#ifndef DIV_H
#define DIV_H

#include "raylib.h"
#include "Div.hpp"

class Div {
private:
    Rectangle rec; // The rectangle dimensions and position
    Color color;   // The color of the rectangle
    bool isExpanded;

public:
    // Constructor
    Div(Rectangle r, Color c);

    // Method to draw the rectangle
    void draw();

    // Method to check if clicked/touched and update the rectangle width
    void update(int screenWidth , Div &rect1 , Div &rect2 , Div &rect3 , Div &rect4 , Div &rect5,int iconwidth);

    //method for a sub class but who wants to make more trouble
    //void update2(int iconwidth);
};

#endif // DIV_H
