#include <iostream>
#include "raylib.h"

int main()
{
    const int screenWidth = 750;
    const int screenHeight = 750;

    Color green = { 173, 204, 96, 255 };
    Color darkgreen = { 43, 51, 24, 255 };

    int snakeX = screenWidth / 2;
    int snakeY = screenHeight / 2;

    int snakeSpeed = 10;

    InitWindow(screenWidth, screenHeight, "Game");
    SetTargetFPS(60);


    while (WindowShouldClose() == false)
    {
        if(IsKeyPressed(KEY_RIGHT))
        {
            snakeX += snakeSpeed;
        }
        if(IsKeyPressed(KEY_LEFT))
        {
            snakeX -= snakeSpeed;
        }
        if(IsKeyPressed(KEY_DOWN))
        {
            snakeY += snakeSpeed;
        }
        if(IsKeyPressed(KEY_UP))
        {
            snakeY -= snakeSpeed;
        }

        BeginDrawing();
        //Snake
        DrawRectangle(snakeX, snakeY, 10, 10, darkgreen);
        ClearBackground(green);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}