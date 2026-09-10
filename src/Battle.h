#pragma once
#include "raylib.h"
#include "Monster.h"
#include "BattleUI.h"
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
    BattleUI battleUI;

    std::vector<MonsterData> monsterData;
    Monster* currentMonster = nullptr;

    void LoadMonsterData();

    public:
    Battle();

    void StartTestEncounter();
    void Update();
    void Draw();
    void Unload();

};