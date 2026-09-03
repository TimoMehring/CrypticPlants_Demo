#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "CrypticPlants Demo");

    SetTargetFPS(60);              

    while (!WindowShouldClose())    
    {

        BeginDrawing();

        ClearBackground(LIGHTGRAY);


        EndDrawing();
        
    }

    CloseWindow();        

    return 0;
}