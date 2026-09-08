#pragma once
#include "raylib.h"
#include "Monster.h"
#include <vector>
#include <optional>

enum class BattleState{
    ChooseWeapon,
    DetermineFirstAttacker,
    ChooseAttack,
    AttackSequences
};

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