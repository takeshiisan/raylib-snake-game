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

class Food{
    
    public: 
        Vector2 position;
        Texture2D texture; 

        //Constructor for food
        Food()
        {
            Image image = LoadImage("graphics/food.png");
            texture = LoadTextureFromImage(image);
            UnloadImage(image);
            position = GenerateRandomPos();
        }

        //Deconstructor
        ~Food()
        {
            UnloadTexture(texture);
        }

        //Draws the food image
        void Draw() 
        {
            DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
        }

        //Generate random position of the food that the snake will eat
        Vector2 GenerateRandomPos()
        {
            float x = GetRandomValue(0, cellCount - 1);
            float y = GetRandomValue(0, cellCount - 1);
            return Vector2{x,y};
        }
};
    int main()
{

    InitWindow(cellSize * cellCount, cellCount * cellSize, "Game");
    SetTargetFPS(60);

    Food food = Food();

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
        food.Draw();
        ClearBackground(green);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}