#include "Div.hpp"
#include <raylib.h>


// Constructor
Div::Div(Rectangle r, Color c) {
    rec = r;
    color = c;
    isExpanded = true;
}

// Draw method
void Div::draw() {
    DrawRectangleRounded(rec, 0.2f, 0, color); // Draw rounded rectangle
}

// Update method
void Div::update(int screenWidth , Div &rect1 , Div &rect2 , Div &rect3 , Div &rect4 , Div &rect5,int iconwidth) {
    // Check if the rectangle is clicked/touched
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePosition = GetMousePosition();

        if (CheckCollisionPointRec(mousePosition, rec)) {
            if (isExpanded) {
                rec.width = screenWidth / 8; // Collapse to initial size
                rect1.rec.width = iconwidth ;
                rect2.rec.width = iconwidth ;
                rect3.rec.width = iconwidth ;
                rect4.rec.width = iconwidth ;
                rect5.rec.width = iconwidth ;
            } else {
                rec.width = screenWidth / 4; // Expand to larger size
                rect1.rec.width = iconwidth *2;
                rect2.rec.width = iconwidth *2;
                rect3.rec.width = iconwidth *2;
                rect4.rec.width = iconwidth *2;
                rect5.rec.width = iconwidth *2;
            }
            isExpanded = !isExpanded; // Update width to screenWidth / 4
        }
    }
}
/*void Div::update2(int iconwidth){
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePosition = GetMousePosition();

        if (CheckCollisionPointRec(mousePosition, rec)) {
            if (isExpanded) {
                rec.width = iconwidth ; // Collapse to initial size
            } else {
                rec.width = iconwidth * 2; // Expand to larger size
            }
            isExpanded = !isExpanded; // Update width to screenWidth / 4
        }
    }
}*/

