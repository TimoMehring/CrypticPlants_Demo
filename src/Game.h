#pragma once
#include "raylib.h"
#include "Monster.h"
#include "Battle.h"
#include <vector>

class Game{
    private:
    Battle battle;

    public:
    Game();

    void Update();
    void Draw();
    void Unload();

};