#include "raylib.h"
#include "Game.h"

int main(void)
{
    const int screenWidth = 1200;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "CrypticPlants Demo");

    SetTargetFPS(60);    
    
    Game game;

    while (!WindowShouldClose())    {
        game.Update();

        BeginDrawing();

        ClearBackground(LIGHTGRAY);

        game.Draw();


        EndDrawing();
        
    }
    game.Unload();

    CloseWindow();        

    return 0;
}