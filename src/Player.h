#pragma once
#include "raylib.h"

enum class WeaponType{
    None,
    Pistol,
    Boomerang
};

class Player{
    private:
    float health;

    WeaponType currentWeapon;

    public:
    Player();
    
    void SwitchWeapon();
    void Update();
    void Draw();

};