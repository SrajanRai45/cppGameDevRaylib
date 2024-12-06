#include <raylib.h>

#include <iostream>

using namespace std;

Color amathyst = Color{153, 102, 204,255};
Color dark_amathyst = Color{120, 63, 193,255};
Color light_amathyst = Color{186, 150, 230,255};
Color yellow = Color{255, 250, 200,255};


int player_score = 0;
int cpu_score = 0;

class Ball
{
public:
    float x, y;
    int speed_x, speed_y;
    int radius;

    // methods

    void Draw()
    {
        DrawCircle(x, y, radius, WHITE);
    }

    void Update()
    {
        x += speed_x;
        y += speed_y;
        
        if (y + radius >= GetScreenHeight() || y - radius <= 0)
        {
            speed_y *= -1;
        }
        if (x + radius >= GetScreenWidth() ){
            player_score++;
            Resetball();
        }
        if( x - radius <= 0)
        {
            cpu_score++;
            Resetball();
        }
    }
    void Resetball(){
        x = GetScreenWidth()/2;
        y = GetScreenHeight()/2;

        int speedChoices[2] = {1,-1};
        speed_x *= speedChoices[(GetRandomValue(0,1))];
        speed_y *= speedChoices[(GetRandomValue(0,1))]; 
    }
};

class Paddle
{
protected:
    void LimitMovement()
    {
        if (y <= 0)
        {
            y = 0;
        }
        if (y + height >= GetScreenHeight())
        {
            y = GetScreenHeight() - height;
        }
    }

public:
    float width, height;
    float x, y;
    int speed;
    Color color;
    void Draw()
    {
        DrawRectangleRounded(Rectangle{x,y,width,height},0.8,0,color);
    }
    void Update()
    {
        if (IsKeyDown(KEY_UP))
        {
            // if (y <= 0)
            // {
            //     return;
            // }
            y = y - speed;
        }
        if (IsKeyDown(KEY_DOWN))
        {
            // if (y + height >= GetScreenHeight())
            //{
            //     return;
            //  }
            y += speed;
        } //
        LimitMovement();
    }
};

class CPU_Paddle : public Paddle
{
public:
    void Update(int ball_y)
    {
        if (y + height / 2 > ball_y)
        {
            y -= speed;
        }
        if (y + height / 2 <= ball_y)
        {
            y += speed;
        }
        LimitMovement();
    }
};

Paddle player;
CPU_Paddle cpu;
Ball ball;

int main()
{
    cout << "starting the game" << endl;
    const int window_hight = 800;
    const int window_width = 1280;
    InitWindow(window_width, window_hight, "my pong game");
    SetTargetFPS(60);

    // obj properties declaration
    // DrawRectangle(10,window_hight/2,25,120,WHITE);
    // DrawRectangle(window_width - 25 - 10, window_hight / 2, 25, 120, WHITE);
    cpu.width = 25.0;
    cpu.x = window_width - cpu.width - 10;
    cpu.y = window_hight / 2;
    cpu.height = 120.0;
    cpu.color = WHITE;
    cpu.speed = 6;

    player.x = 10;
    player.y = window_hight / 2;
    player.width = 25.0;
    player.height = 120.0;
    player.color = WHITE;
    player.speed = 6;

    ball.x = window_width / 2;
    ball.y = window_hight / 2;
    ball.speed_x = 7;
    ball.speed_y = 7;
    ball.radius = 20;

    // game loop
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        // game code down

        // update
        ball.Update();
        player.Update();
        cpu.Update(ball.y);

        // checkcollision
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height}))
        {
            ball.speed_x *= -1;
        }
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{cpu.x, cpu.y, cpu.width, cpu.height}))
        {
            ball.speed_x *= -1;
        }
        //(drawing in canvas)
        ClearBackground(dark_amathyst);
        DrawRectangle(window_width/2,0,window_width/2,window_hight,amathyst);
        DrawCircle(window_width/2,window_hight/2,150,light_amathyst);
        DrawLine(window_width / 2, 0, window_width / 2, window_hight, WHITE);
        ball.Draw();
        player.Draw();
        cpu.Draw();
        DrawText(TextFormat("%i",player_score), window_width/4 -20 ,20,80 , WHITE);
        DrawText(TextFormat("%i",cpu_score), 3 * window_width/4 -20 ,20,80 , WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
