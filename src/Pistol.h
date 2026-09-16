#pragma once
#include "raylib.h"
#include <string>
#include <vector>
struct PistolAbility
{
    std::string name;
    const char* iconPath;
    std::string description;

    // sample ideas
    float damageBonus;
    float speedBonus;
};

class Pistol{
    private:
    float range;
    float speed;
    float energy;
    float attack;

    std::vector<PistolAbility> abilities;
    std::vector<Texture2D> abilityBackSprites;

    void LoadAbilities();

    public:
    Pistol();

    float CalculateDamage();
    const std::vector<PistolAbility>& GetAbilities();
    const std::vector<Texture2D>& GetAbilityBackSprite();
};