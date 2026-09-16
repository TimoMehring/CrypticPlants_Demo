#pragma once
#include "raylib.h"
#include <string>
#include <vector>

struct BoomerangAbility
{
    std::string name;
    const char* iconPath;
    std::string description;

    // sample ideas
    float returnHitChanceBonus;
    float returnDamageBonus;
};

class Boomerang{
    private:
    float range;
    float speed;
    float energy;
    float attack;

    float secondHitChance;

    std::vector<BoomerangAbility> abilities;
    std::vector<Texture2D> abilityBackSprites;

    void LoadAbilities();

    public:
    Boomerang();

    float CalculateDamage();
    const std::vector<BoomerangAbility>& GetAbilities();
    const std::vector<Texture2D>& GetAbilityBackSprite();
};