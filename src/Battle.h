#pragma once
#include "raylib.h"
#include "Monster.h"
#include "BattleUI.h"
#include "Pistol.h"
#include "Boomerang.h"
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
    Pistol pistol;
    Boomerang boomerang;

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