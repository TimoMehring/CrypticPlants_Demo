#pragma once
#include "raylib.h"
#include "Monster.h"
#include <vector>
#include <optional>

class Battle{
    private:

    std::vector<MonsterData> monsterData;
    Monster* currentMonster = nullptr;

    void LoadMonsterData();

    public:
    // Constructor
    Battle();

    void StartTestEncounter();
    void Update();
    void Draw();
    void Unload();

};