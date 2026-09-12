#pragma once
#include "raylib.h"
#include <string>
#include <vector>
struct PistolAbility
{
    std::string name;
    const char* iconPath;

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

    public:
    Pistol();

    float CalculateDamage();
    const std::vector<PistolAbility>& GetAbilities();
};