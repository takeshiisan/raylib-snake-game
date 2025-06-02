#include <iostream>
#include "raylib.h"

    const int screenWidth = 750;
    const int screenHeight = 750;

    Color green = { 173, 204, 96, 255 };
    Color darkgreen = { 43, 51, 24, 255 };

    int snakeX = screenWidth / 2;
    int snakeY = screenHeight / 2;

    int snakeSpeed = 10;
    
    //GRID
    int cellSize = 30;
    int cellCount = 25;
int main()
{

    InitWindow(cellSize * cellCount, cellCount * cellSize, "Game");
    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        if(IsKeyDown(KEY_RIGHT))
        {
            snakeX += snakeSpeed;
        }
        if(IsKeyDown(KEY_LEFT))
        {
            snakeX -= snakeSpeed;
        }
        if(IsKeyDown(KEY_DOWN))
        {
            snakeY += snakeSpeed;
        }
        if(IsKeyDown(KEY_UP))
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