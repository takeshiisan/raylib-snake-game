#include <iostream>
#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Game");
    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}