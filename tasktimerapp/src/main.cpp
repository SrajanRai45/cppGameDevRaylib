#include "raylib.h"
#include "Div.hpp"
#include "clock.hpp"
#include "textInput.hpp"

bool ch = true;
float icon_y_component = 132;
float subiconwidth = 34;
float icon_x_component = 8;
float icon_hight = 124;
float icon_width = 16;

Color Lilac = {197, 159, 238, 255};     // #c59fee
Color PinkBlush = {246, 206, 245, 255}; // #f6cef5
Color Aqua = {15, 214, 209, 255};       // #0fd6d1
Color SkyBlue = {162, 211, 249, 255};   // #a2d3f9
Color Rose = {238, 161, 184, 255};      // #eea1b8


//internel func
void allMULupdate(){

}




int main()
{
    const int screenWidth = 1280;
    const int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "APP");

    SetTargetFPS(60);

    // var declare
    Clock clock;

    Rectangle rec = {15.0, 15.0, float(screenWidth / 8), float(screenHeight - 30)};
    Div sidebar(rec, Lilac);

    // making 5 icons
    Rectangle icon1 = {15.0f + icon_x_component, subiconwidth, (screenWidth / 8) - icon_width, icon_hight};
    Div icon11(icon1, SkyBlue);

    //InputBox icon111(icon1);

    Rectangle icon2 = {15.0f + icon_x_component, subiconwidth + icon_y_component, (screenWidth / 8) - icon_width, icon_hight};
    Div icon22(icon2, SkyBlue);

    Rectangle icon3 = {15.0f + icon_x_component, subiconwidth + (icon_y_component * 2), (screenWidth / 8) - icon_width, icon_hight};
    Div icon33(icon3, SkyBlue);

    Rectangle icon4 = {15.0f + icon_x_component, subiconwidth + (icon_y_component * 3), (screenWidth / 8) - icon_width, icon_hight};
    Div icon44(icon4, SkyBlue);

    Rectangle icon5 = {15.0f + icon_x_component, subiconwidth + (icon_y_component * 4), (screenWidth / 8) - icon_width, icon_hight};
    Div icon55(icon5, SkyBlue);

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update

        sidebar.update(screenWidth,icon11,icon22,icon33,icon44,icon55,(screenWidth / 8) - icon_width);
        //icon11.update2((screenWidth / 8) - icon_width);
        //icon22.update2((screenWidth / 8) - icon_width);
        //icon33.update2((screenWidth / 8) - icon_width);
        //icon44.update2((screenWidth / 8) - icon_width);
        //icon55.update2((screenWidth / 8) - icon_width);
        //icon111.text_Input();

        

        // Drawing
        BeginDrawing();
        ClearBackground(PinkBlush);

        int fpsPosX = screenWidth - 100;
        int fpsPosY = 10;
        DrawFPS(fpsPosX, fpsPosY);
        clock.displayTime();

        sidebar.draw();
        icon11.draw();
        icon22.draw();
        icon33.draw();
        icon44.draw();
        icon55.draw();

        EndDrawing();
    }

    // De-initialization
    CloseWindow();

    return 0;
}
