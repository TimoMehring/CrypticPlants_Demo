#pragma once
#include "raylib.h"

enum class WeaponSelection{
    None,
    Pistol,
    Bommerang
};

class BattleUI{
    private:
    Texture2D pistolSelectedAnimation;
    Texture2D boomerangSelectedAnimation;

    WeaponSelection selectedWeapon;

    int currentFrame;
    float frameTimer;

    public:
    BattleUI();

    void UpdateWeaponSelection();
    void DrawWeaponSelection();

};