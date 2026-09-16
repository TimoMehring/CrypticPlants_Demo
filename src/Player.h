#pragma once
#include "raylib.h"

enum class WeaponType{
    None,
    Pistol,
    Boomerang
};

class Player{
    private:
    float currentHealth;
    float maxHealth;

    int currentLevel;
    float currentXp;
    float maxXP;

    WeaponType currentWeapon;

    public:
    Player();
    
    void SwitchWeapon();
    void Update();
    void Draw();

    float GetCurrentHealth() const;
    float GetMaxHealth() const;

    float GetLevel() const;
    float GetCurrentXp() const;
    float GetMaxXP() const;

};