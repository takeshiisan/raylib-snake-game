#include <iostream>
#include "raylib.h"
#include <raymath.h>
#include <deque>

const int screenWidth = 750;
const int screenHeight = 750;

Color green = { 173, 204, 96, 255 };
Color darkgreen = { 43, 51, 24, 255 };

int snakeX = screenWidth / 2;
int snakeY = screenHeight / 2;

int snakeSpeed = 10;

//GRID
float cellSize = 30;
float cellCount = 25;

double lastUpdateTime = 0;

bool eventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

class Snake
{

public:
    std::deque<Vector2> body = {Vector2{6,9},Vector2{5,9},Vector2{4,9}};
    Vector2 direction = {1, 0};

    void Draw(){
        for(unsigned int i = 0; i < body.size(); i++)
        {
            float x = body[i].x;
            float y = body[i].y;
            Rectangle segment = Rectangle{x * cellSize, y * cellSize, cellSize, cellSize};
            DrawRectangleRounded(segment, 0.5, 5, darkgreen);
        }
    }

    void Update()
    {
        body.pop_back();
        body.push_front(Vector2Add(body[0], direction));
    }

};
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
    Snake snake = Snake();

    while (WindowShouldClose() == false)
    {
        
        BeginDrawing();

        if(eventTriggered(0.2))
        {
            snake.Update();
        }

        if (IsKeyDown(KEY_UP))
        {
            snake.direction = Vector2{0, -1};
        }
        else if (IsKeyDown(KEY_DOWN))
        {
            snake.direction = Vector2{0, 1};
        }
        else if (IsKeyDown(KEY_LEFT))
        {
            snake.direction = Vector2{-1, 0};
        }
        else if (IsKeyDown(KEY_RIGHT))
        {
            snake.direction = Vector2{1, 0};
        }
        
        //drawing
        food.Draw();
        snake.Draw();
        ClearBackground(green);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}